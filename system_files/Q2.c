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
    char *newfile="check.txt";
    char *oldfile=argv[2];
    char *directory=argv[3];
    int fd2=open(oldfile,O_RDONLY,0700);
    if(fd2==-1){                 //new file in directory
        perror("Error");
    }
    int fd1=open(argv[1],O_RDONLY); //old file
    if(fd1==-1){
        perror("Error");
    }
    int fd3=open(newfile,O_RDWR|O_CREAT,0600);  
    int size=lseek(fd1,0,SEEK_END);
    char byte;
    char perbuff[102];
    int stable=size,perc;
    if(fd1!=-1){
        while(size!=0){
            lseek(fd1,size-1,SEEK_SET);
            read(fd1,&byte,1);
            write(fd3,&byte,1);
            perc=(((stable-size)/(float)stable)*100)+1;
            sprintf(perbuff,"\rPercentage: %d",perc);  
            write(1,perbuff,strlen(perbuff));
            fflush(stdout);
            //usleep(0.5);
            size--; 
        }
        write(1,"\n",sizeof("\n"));
    }
  
    int fd4=open(directory,O_RDONLY);
    if(fd4!=-1){
        puts("Directory is created: Yes");
    }
    else{
        puts("Directory is created: No");
    }

    char dif[]="diff check.txt ";
    strcat(dif, oldfile);
    //printf("%s",dif);
    if(!system(dif)){
        puts("Whether file contents are reversed in newfile: Yes");
    }
    
    struct stat new;
    if(stat(argv[1],&new)!=-1){
        
        if(new.st_mode& S_IRUSR){
           puts("User has read permissions on newfile: Yes");
        }
        else
        {
            puts("User has read permissions on newfile: No");
        }
        
        if(new.st_mode& S_IWUSR){
           puts("User has write permissions on newfile: Yes");
        }
        else
        {
             puts("User has write permissions on newfile: No");
        }
        
        if(new.st_mode& S_IXUSR){
           puts("User has execute permissions on newfile: Yes");
        }
        else
        {
            puts("User has execute permissions on newfile: No");
        }
        
        if(new.st_mode& S_IRGRP){
           puts("Group has read permissions on newfile: Yes");
        }
        else
        {
            puts("Group has read permissions on newfile: No");
        }
        
        if(new.st_mode& S_IWGRP){
           puts("Group has write permissions on newfile: Yes");
        }
        else
        {
            puts("Group has write permissions on newfile: No");
        }
        
        if(new.st_mode& S_IXGRP){
           puts("Group has execute permissions on newfile: Yes");
        }
        else
        {
            puts("Group has execute permissions on newfile: No");
        }
        
        if(new.st_mode& S_IROTH){
           puts("Others has read permissions on newfile: Yes");
        }
        else
        {
            puts("Others has read permissions on newfile: No");
        }
        
        if(new.st_mode& S_IWOTH){
           puts("Others has write permissions on newfile: Yes");
        }
        else
        {
            puts("Others has write permissions on newfile: No");
        }
        
        if(new.st_mode& S_IXOTH){
           puts("Others has execute permissions on newfile: Yes");
        }
        else
        {
            puts("Others has execute permissions on newfile: No");
        }
        

        
    }

    struct stat old;
    if(stat(argv[2],&old)!=-1){
        
        if(old.st_mode& S_IRUSR){
           puts("User has read permissions on oldfile: Yes");
        }
        else
        {
            puts("User has read permissions on oldfile: No");
        }
        
        if(old.st_mode& S_IWUSR){
           puts("User has write permissions on oldfile: Yes");
        }
        else
        {
             puts("User has write permissions on oldfile: No");
        }
        
        if(old.st_mode& S_IXUSR){
           puts("User has execute permissions on oldfile: Yes");
        }
        else
        {
            puts("User has execute permissions on oldfile: No");
        }
        
        if(old.st_mode& S_IRGRP){
           puts("Group has read permissions on oldfile: Yes");
        }
        else
        {
            puts("Group has read permissions on oldfile: No");
        }
        
        if(new.st_mode& S_IWGRP){
           puts("Group has write permissions on oldfile: Yes");
        }
        else
        {
            puts("Group has write permissions on oldfile: No");
        }
        
        if(old.st_mode& S_IXGRP){
           puts("Group has execute permissions on oldfile: Yes");
        }
        else
        {
            puts("Group has execute permissions on oldfile: No");
        }
        
        if(old.st_mode& S_IROTH){
           puts("Others has read permissions on oldfile: Yes");
        }
        else
        {
            puts("Others has read permissions on oldfile: No");
        }
        
        if(old.st_mode& S_IWOTH){
           puts("Others has write permissions on oldfile: Yes");
        }
        else
        {
            puts("Others has write permissions on oldfile: No");
        }
        
        if(old.st_mode& S_IXOTH){
           puts("Others has execute permissions on oldfile: Yes");
        }
        else
        {
            puts("Others has execute permissions on oldfile: No");
        }
        

        
    }

    struct stat direc;
    if(stat(argv[3],&direc)!=-1){
        
        if(direc.st_mode& S_IRUSR){
           puts("User has read permissions on directory: Yes");
        }
        else
        {
            puts("User has read permissions on directory: No");
        }
        
        if(direc.st_mode& S_IWUSR){
           puts("User has write permissions on directory: Yes");
        }
        else
        {
             puts("User has write permissions on directory: No");
        }
        
        if(direc.st_mode& S_IXUSR){
           puts("User has execute permissions on directory: Yes");
        }
        else
        {
            puts("User has execute permissions on directory: No");
        }
        
        if(direc.st_mode& S_IRGRP){
           puts("Group has read permissions on directory: Yes");
        }
        else
        {
            puts("Group has read permissions on directory: No");
        }
        
        if(direc.st_mode& S_IWGRP){
           puts("Group has write permissions on directory: Yes");
        }
        else
        {
            puts("Group has write permissions on directory: No");
        }
        
        if(direc.st_mode& S_IXGRP){
           puts("Group has execute permissions on directory: Yes");
        }
        else
        {
            puts("Group has execute permissions on directory: No");
        }
        
        if(direc.st_mode& S_IROTH){
           puts("Others has read permissions on directory: Yes");
        }
        else
        {
            puts("Others has read permissions on directory: No");
        }
        
        if(direc.st_mode& S_IWOTH){
           puts("Others has write permissions on directory: Yes");
        }
        else
        {
            puts("Others has write permissions on directory: No");
        }
        
        if(direc.st_mode& S_IXOTH){
           puts("Others has execute permissions on directory: Yes");
        }
        else
        {
            puts("Others has execute permissions on directory: No");
        }   
    }
    return 0;
 
}
