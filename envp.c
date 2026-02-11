#include<stdio.h>


extern char **environ;

int main(void) {

  char **env = environ;


  /**
   * arr = int*
   * [1, 2, 3, 4]
   *
   *
   * env (char**)
   *
   * one ++ will make move by (char*)
   *
   *      PATH =(type char*)
   *      SYSPATH (type char*)
   *      LOGIN (type char*)
   *      NULL
   *
   *
   * */
  while (*env != NULL) {
  
    printf("%s\n", *env);
    ++(env);
  }

  return 0;
}
