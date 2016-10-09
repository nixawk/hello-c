#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

/*

$ gcc -o random_seed random_seed.c
$ for run in {1..10}; do num=$(./random_seed); echo ${num:0:6} ;done

From ftp://ftp.gnu.org/gnu/macchanger/

*/

static void
random_seed (void)
{
  int            fd;
  struct timeval tv;
  unsigned int seed;

  if ((fd = open("/dev/urandom", O_RDONLY)) >= 0 ||
      (fd = open("/dev/random", O_RDONLY))  >= 0)
  {
    read(fd, &seed, sizeof(seed));
    close(fd);
  } else {
    gettimeofday(&tv, NULL);
    seed = (getpid() << 16) ^ tv.tv_sec ^ tv.tv_usec;
  }

  srandom(seed);
}


int
main(int argc, const char *argv[])
{
  random_seed();

  printf("%ld\n", random());
  return 0;
}
