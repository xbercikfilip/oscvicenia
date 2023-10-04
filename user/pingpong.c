#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"
int 
main(int argc ,char  *argv[]){
  int p[2];
  int c[2];
  char buf[100];
  pipe(p);
  pipe(c);
  int pid=fork();
  if(pid==0){
    //child
    read(c[0],buf,1);
    printf("%d: received ping\n",getpid());
    write(p[1],"x",1);
  }
  else {
    //parent
    write(c[1],"y",1);
    read(p[0],buf,1);
    printf("%d: received pong\n",getpid());
  }
  exit(0);
}
