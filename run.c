#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

/**
 * current directory of a process
 *
 * Start directory for all paths that DO NOT BEGIN with "/" (file system's root)
 *
 * */


int main(int argc, char *argv[]) {

  /**
   * ./run hello.c hello_again.c
   *
   *
   *
   * argv[0] = run
   * argv[1] = hello.c
   * argv[2] = hello_again.c
   *
   * ./mycp = we want to run this program
   *
   *
   * exec (mycp , mycp, hello.c, hello_again.c)
   *
   *  1st mycp = path to the program that is to be executable
   *
   *  2nd mycp = First argument (arg0) of that program
   *
   *  By coincidence, they are both same, because we are running "run"
   *  from the directory where "mycp" binary exists.
   *
   *
   *  If the executable has a different path somewhere, then
   *  execl ("/some/other/path/mycp", "mycp", ...)
   * */

  /* assume 2 args: src and target file */
  if (fork() == 0) {
    /*      path    arg0   */
    /*     ./mycp          */
    execl("mycp", "mycp", argv[1], argv[2], 0);
  }

  wait((int*) 0);
  printf("Copy done!\n");
  /* Discreetly exit() */
}
