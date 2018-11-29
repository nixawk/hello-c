/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2017, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
/* <DESC>
 * HTTP PUT upload with authentiction using "any" method. libcurl picks the
 * one the server supports/wants.
 * </DESC>
 */

#include <stdio.h>
#include <fcntl.h>

#ifdef WIN32
#include <io.h>
#else
#include <unistd.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>

#include <curl/curl.h>

#if LIBCURL_VERSION_NUM < 0x070c03
#error "upgrade your libcurl to no less than 7.12.3"
#endif

// gcc -lcurl -o anyauthput anyauthput.c
// Usage: ./anyauthput <file> <url>

/* function gets called by libcurl when something special I/O-related
 * needs to be done that the library can't do by itself. */
curlioerr ioctl_callback(CURL * handle, curliocmd cmd, void *userp)
{
	int *fdp = (int *)userp;
	int fd = *fdp;

	// (void)handle;  /* not used in here */

	switch (cmd) {
	case CURLIOCMD_RESTARTREAD:
		if (-1 == lseek(fd, 0, SEEK_SET))
			return CURLIOE_FAILRESTART;
		break;

	default:		/* ignore unknown commands */
		return CURLIOE_UNKNOWNCMD;
	}

	return CURLIOE_OK;
}

/* function gets called by libcurl as soon as it needs to read data
 * in order to send it to the peer like if you ask it to upload or
 * post data to the server. */
size_t read_callback(void *buffer, size_t size, size_t nmemb, void *instream)
{
	ssize_t retcode;
	curl_off_t nread;

	int *fdp = (int *)instream;
	int fd = *fdp;

	retcode = read(fd, buffer, size * nmemb);
	nread = (curl_off_t) retcode;

	fprintf(stderr, "read %llu bytes from files\n", nread);

	return retcode;
}

void anyauthput(const char *file, const char *url)
{
	CURL *curl;
	CURLcode res;
	int rfd;
	struct stat file_info;

	char *page_outfile = "page.out";

	/* get the file size of the local file */
	rfd = open(file, O_RDONLY);
	fstat(rfd, &file_info);

	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);

	/* get a curl handle */
	curl = curl_easy_init();
	if (curl) {
		/* use custom read function */
		curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);

		/* which file to upload */
		curl_easy_setopt(curl, CURLOPT_READDATA, (void *)&rfd);

		/* set the ioctl function */
		curl_easy_setopt(curl, CURLOPT_IOCTLFUNCTION, ioctl_callback);

		/* pass the file descriptor to the ioctl callback as well */
		curl_easy_setopt(curl, CURLOPT_IOCTLDATA, (void *)&rfd);

		/* enable "uploading" (which means PUT when doing HTTP) */
		curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

		/* specify target URL, and note that this URL should also
		   include a file name, not only a directory (as you can do with
		   GTP uploads) */
		curl_easy_setopt(curl, CURLOPT_URL, url);

		/* give the size of the upload, this supports large file sizes
		   on systems that have general support for it. */
		curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE,
				 (curl_off_t) file_info.st_size);

		/* tell libcurl we can use "any" auth, which lets the lib pick
		   one, but it also costs one extra round-trip and possibly sending
		   of all the PUT data twice !!! */
		curl_easy_setopt(curl, CURLOPT_HTTPAUTH, (long)CURLAUTH_ANY);

		/* set user name and password for the authentication */
		curl_easy_setopt(curl, CURLOPT_USERPWD, "user:password");

		/* send request */
		res = curl_easy_perform(curl);
		if (res != CURLE_OK) {
			fprintf(stderr,
				"curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res)
			    );
		}

		/* always cleanup */
		curl_easy_cleanup(curl);
	}

	/* close the local file */
	close(rfd);

	curl_global_cleanup();
}

int main(int argc, const char *argv[])
{
	if (argc < 3) {
		printf("Usage: %s <file> <url>\n", argv[0]);
		return 1;
	}

	/* anyauthput(char *file, char *url); */
	anyauthput(argv[1], argv[2]);
	return 0;
}

// https://curl.haxx.se/libcurl/c/anyauthput.html
// https://curl.haxx.se/libcurl/c/CURLOPT_READFUNCTION.html
// https://curl.haxx.se/libcurl/c/CURLOPT_IOCTLFUNCTION.html
// https://curl.haxx.se/libcurl/c/CURLOPT_WRITEFUNCTION.html
