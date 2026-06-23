#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
      unsigned int pid = getpid();
     printf("Parent code ... \n");
     printf("[Parent] my pid is %u \n",pid);
    unsigned int child_pid = fork();
   if(child_pid == 0){
   printf("child code ..\n");
   unsigned int ppid = getppid();
   unsigned int pid = getpid();
   printf("[child] my pid is %u \n",pid);
   printf("[child] my parent is %u \n",ppid);
  execl("mycp","mycp",argv[1],argv[2]);
  }
  printf("[parent] my child is %u \n",child_pid);
  wait((int *) 0);
  printf("[parent] copy done !! \n");
}

