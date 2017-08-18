#include <sys/syscall.h>
#include <linux/memfd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <errno.h>

static inline int memfd_create(const char *name, unsigned int flags) {
      return syscall(__NR_memfd_create, name, flags);
}

static void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char **argv){
  const int shm_size = 1024;
  int fd, ret;

  fd = memfd_create("Server memfd", MFD_ALLOW_SEALING);
  if (fd == -1)
    error("memfd_create()");

  ret = ftruncate(fd, shm_size);
  if (ret == -1)
    error("ftruncate()");

  return 0;
}
