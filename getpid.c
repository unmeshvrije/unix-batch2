#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

/**
 * 
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
   * exec (  , mycp, hello.c, hello_again.c)
   *
   * */

  unsigned int pid = getpid();
  printf("My PID is %u\n", pid);
  int ret_id = fork();
  if (ret_id == 0) {
    /*      path    arg0   */
    /*     ./mycp          */
    unsigned int ppid = getppid();
    printf("My parent is %u\n", ppid);
    execl("mycp", "mycp", argv[1], argv[2], 0);
  }

  wait((int*) 0);
  printf("Copy done!\n");
  /* Discreetly exit() */
}
