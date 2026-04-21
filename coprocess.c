#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

char string [] = "Hello World";

int main(int argc, char* argv[]) {

  int count, i;
  int to_parent[2], to_child[2];
  char buf[256];
  int sadhi_file_fd;

  /* Create two pipes */

  pipe(to_parent); // [0] reader FD [1] write FD
  pipe(to_child);

  printf("fork() is about to be called...\n");
  printf("%d, %d\n", to_parent[0], to_parent[1]);
  printf("%d, %d\n", to_child[0], to_child[1]);
  if (fork() == 0) {
    /* Child executes here */

    printf("Child running...\n");
    close(0) ; // close stdin
    dup(to_child[0]); // dup child-pipe read to stdin
    close(1); // close stdout
    dup(to_parent[1]); // dup parent-pipe write to stdout

    close(to_parent[1]); // Close opposite side's FD first
    close(to_child[0]);
    close(to_parent[0]);
    close(to_child[1]);

    sleep(2);
      for (;;) {
        if ((count = read(0, buf, sizeof(buf))) == 0) {
          exit(0);
        }
        buf[255] = '\0';
        printf("Child Reading %s\n", buf);
        write(1, buf, count);
      }
    }

    /* Parent executes here */

    printf("Parent running...\n");
    close(1); // close stdout
    int dret1 = dup(to_child[1]);
    close(0);
    int dret2 = dup(to_parent[0]);

    printf("dupped = %d, %d\n", dret1, dret2);

    close(to_child[1]);
    close(to_parent[0]);
    close(to_parent[1]);
    close(to_child[0]);

    sadhi_file_fd = creat("sadhi.txt", 0666); 
    for (i = 0; i < 15; ++i) {
      write(1, string, strlen(string));
      
      /* This will never be displayed because stdout has been closed *
       * diverted to the pipe file */
      printf("Writing...");

      write(sadhi_file_fd, string, strlen(string));
      read(0, buf, sizeof(buf));
    }

  return 0;
}

