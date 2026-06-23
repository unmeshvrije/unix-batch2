#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char *argv[]){
unsigned int pid = getpid();

printf(" My pid is %u \n",pid);
int ret_id = fork();

if(ret_id == 0)
{
  unsigned int pid = getpid();
  printf("my pid is %u \n",pid);
  execl("mycp","mycp",argv[1],argv[2],0);
}
wait((int *)0);
printf("copy done\n");
}
