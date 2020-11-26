#include<stdio.h> 
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h> 
#include<sys/types.h> 
#include<time.h>
 
int main(int argc, char *argv[])
{
    int fd=open(argv[1],O_RDONLY);
    if(fd==-1){
        perror("Error");
    }
    int yes=mkdir("Assignment",0755);
    if(yes==-1){
        perror("Error");
    }
    chdir("Assignment");
    int fd2=open(argv[1],O_RDWR|O_CREAT,0655);
    if(fd2==-1){
        perror("Error");
    }
    int size=lseek(fd,0,SEEK_END);
    char byte;
    char perbuff[102];
    int stable=size,perc;
    if(fd!=-1){
        while(size!=0){
            lseek(fd,size-1,SEEK_SET);
            read(fd,&byte,1);
            write(fd2,&byte,1);
            perc=(((stable-size)/(float)stable)*100)+1;
            sprintf(perbuff,"\rPercentage: %d",perc);  
            write(1,perbuff,strlen(perbuff));
            //fputs(perbuff,stdout);
            fflush(stdout);
            //sleep(1);
            size--; 
        }
        write(1,"\n",sizeof("\n"));
    }
    close(fd2);
    close(fd);
    chdir("../");
    return 0;
}