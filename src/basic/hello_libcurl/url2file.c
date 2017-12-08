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
 * Download a given URL into a local file named page.out.
 * </DESC>
 */ 

/* <USAGE>
 *  $ gcc -lcurl url2file.c -o url2file 
 *  $ ./url2file http://httpbin.org/user-agent
 *  $ cat cat page.out
 *  {
 *    "user-agent": "Dark Secret Ninja/1.0"
 *  }
 * <USAGE>
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <curl/curl.h>


static size_t
write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    /*
        ptr
            Pointer to the array of elements to be written, converted to a
            const void*

        size
            Size in bytes of each element to be written.

        count
            Number of elements, each one with a size of size bytes.

        stream
            Pointer to a FILE object that specifies an output stream.
    */

    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}


void
url2file(const char *url)
{
    CURL *curl_handle;
    static const char *pagefilename = "page.out";
    FILE *pagefile;

    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();

    /* set HTTP HEADER */
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "Dark Secret Ninja/1.0");

    /* set URL to get here */
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);

    /* switch on full protocol/debug output while testing */
    curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);

    /* disable progress meter, set to 0L to enable and disable debug output */
    curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

    /* send all data to this function */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

    /* open the file */
    pagefile = fopen(pagefilename, "wb");
    if (pagefile) {
        /* write the page body to this file handle */
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, pagefile);

        /* get it */
        curl_easy_perform(curl_handle);

        /* close the heander file */
        fclose(pagefile);
    }

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);
}


int
main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    /* Download a given URL into a local file named page.ou. */
    url2file(argv[1]);

    return 0;
}

// https://curl.haxx.se/libcurl/c/url2file.html
// https://curl.haxx.se/libcurl/c/CURLOPT_USERAGENT.html
// https://curl.haxx.se/libcurl/c/CURLOPT_WRITEDATA.html
// https://curl.haxx.se/libcurl/c/CURLOPT_WRITEFUNCTION.html
// http://www.cplusplus.com/reference/cstdio/fwrite/