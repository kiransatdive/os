9)
Inter process communication in Linux using following.
FIFOS: Full duplex communication between two independent processes. First process accepts sentences and writes on one pipe to be read by second process and second process counts number of characters, number of words and number of lines in accepted sentences, writes this output in a text file and writes the contents of the file on second pipe to be read by first process and displays on standard output.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>


#define MAX_BUF 1024

int main()
{
    int fd,c=0;
    char * myfifo1="myfifo1";
    int fd1;
    char * myfifo2="myfifo2";
    
    char buf1[MAX_BUF];
    //printf("\nlets start"); //for checking
    // create fifo
    
    mkfifo(myfifo1,0777);//(for creating fifo,prmision to user 0777)
     printf("\nEnter the Sentence : \n");
    fd=open(myfifo1,O_WRONLY);
    
    char str;
   
    while((str=getchar())!='#')
   
        buf1[c++]=str;
	buf1[c]='\0';
	
	write(fd,buf1,sizeof(buf1)); //write input to buffer
	close(fd);
	
	fd1=open(myfifo2,O_RDONLY);
	read(fd1,&buf1,sizeof(buf1));
       
        printf("\nThe contents of the file are as follows : %s\n ",buf1);
	
	  close(fd1);
	   
	       unlink(myfifo2);
	       return (0);

    
}
