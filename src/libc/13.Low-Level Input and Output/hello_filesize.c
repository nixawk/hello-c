#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void fseek_filesize(const char *filename)
{
	FILE *fp = NULL;
	long off;

	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("failed to fopen %s\n", filename);
		exit(EXIT_FAILURE);
	}

	if (fseek(fp, 0, SEEK_END) == -1) {
		printf("failed to fseek %s\n", filename);
		exit(EXIT_FAILURE);
	}

	off = ftell(fp);
	if (off == (long)-1) {
		printf("failed to ftell %s\n", filename);
		exit(EXIT_FAILURE);
	}

	printf("[*] fseek_filesize - file: %s, size: %ld\n", filename, off);

	if (fclose(fp) != 0) {
		printf("failed to fclose %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

void fstat_filesize(const char *filename)
{
	int fd;
	struct stat statbuf;

	fd = open(filename, O_RDONLY, S_IRUSR | S_IRGRP);
	if (fd == -1) {
		printf("failed to open %s\n", filename);
		exit(EXIT_FAILURE);
	}

	if (fstat(fd, &statbuf) == -1) {
		printf("failed to fstat %s\n", filename);
		exit(EXIT_FAILURE);
	}

	printf("[*] fstat_filesize - file: %s, size: %lld\n", filename,
	       statbuf.st_size);

	if (close(fd) == -1) {
		printf("failed to fclose %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

void stat_filesize(const char *filename)
{
	struct stat statbuf;

	if (stat(filename, &statbuf) == -1) {
		printf("failed to stat %s\n", filename);
		exit(EXIT_FAILURE);
	}

	printf("[*] stat_filesize - file: %s, size: %lld\n", filename,
	       statbuf.st_size);

}

void seek_filesize(const char *filename)
{
	int fd;
	off_t off;

	if (filename == NULL) {
		printf("invalid filename\n");
		exit(EXIT_FAILURE);
	}

	fd = open(filename, O_RDONLY, S_IRUSR | S_IRGRP);
	if (fd == -1) {
		printf("failed to open %s\n", filename);
		exit(EXIT_FAILURE);
	}

	off = lseek(fd, 0, SEEK_END);
	if (off == (off_t) - 1) {
		printf("failed to lseek %s\n", filename);
		exit(EXIT_FAILURE);
	}

	printf("[*] seek_filesize - file: %s, size: %lld\n", filename, off);

	if (close(fd) == -1) {
		printf("failed to close %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

int main(int argc, const char *argv[])
{
	int i;

	if (argc < 2) {
		printf("%s <file1> <file2>...\n", argv[0]);
		exit(0);
	}

	for (i = 1; i < argc; i++) {
		seek_filesize(argv[i]);
		stat_filesize(argv[i]);
		fstat_filesize(argv[i]);
		fseek_filesize(argv[i]);
	}

	return 0;
}

// http://man7.org/linux/man-pages/man2/lseek.2.html
// https://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c
