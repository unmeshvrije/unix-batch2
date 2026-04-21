#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>


int fdrd, fdwt;
char c;

void rdwrt() {
  for (;;) {
    if (read (fdrd, &c, 1) != 1) {
      return;
    }
    write(fdwt, &c, 1);
  }
}

int main(int argc, char* argv[]) {

  if (argc != 3) {
    exit(1);
  }

  if ((fdrd = open(argv[1], O_RDONLY)) == -1) {
    /* If we fail to open the file given in first command line argument, in read mode */
    exit(1);
  }

  if ((fdwt = creat(argv[2], 0666)) == -1) {
    /* If we fail to create the file whose name is given in the second command line argument */
    exit(1);
  }

  fork();
  /* Both parent and child execute the same code */

  /* Parent's UFDT will be inherited by the child */
  /*
   * File table entry of "reader" file and "writer" file
   * will be shared between parent and child.
   *
   *
   *
   *
   * */
  rdwrt();

  return 0;
}

