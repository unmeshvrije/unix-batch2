#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>

#define BUF_SIZE 512
int main(void) {

  int fd1, fd2;
  char buf1[BUF_SIZE], buf2[BUF_SIZE];
  int ret1, ret2;

  memset(buf1, 0, BUF_SIZE);
  memset(buf2, 0, BUF_SIZE);

  fd1 = open("/Users/unmeshjoshi/programming/personal/unix-batch2/README.md", O_RDONLY);
  fd2 = open("/Users/unmeshjoshi/programming/personal/unix-batch2/README.md", O_RDONLY);

  /* Reserve last byte for '\0' */
  ret1 = read(fd1, buf1, BUF_SIZE-1);
  ret2 = read(fd2, buf2, BUF_SIZE-1);
  close(fd1);
  close(fd2);

  printf("Read %d bytes: [%s]\n", ret1, buf1);
  printf("Read %d bytes: [%s]\n", ret2, buf2);

  int comp = strcmp(buf1, buf2);
  printf("%d\n", comp);

  if (comp == 0) {
    printf("Both buffer are equal.\n");
  }

  return 0;
}
