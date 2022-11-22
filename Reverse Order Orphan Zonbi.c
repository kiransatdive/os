
3) ,16)
Process control system calls: The demonstration of FORK, EXECVE and WAIT system calls along with zombie and orphan states
Implement the C program in which main program accepts an array. Main program uses the FORK system call to create a new process called a child process. Parent process sorts an array and passes the sorted array to child process through the command line arguments of EXECVE system call. The child process uses EXECVE system call to load new program which display array in reverse order

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>		
void bass(int arr[30],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("\n Ascending Soring \n");
	for(i=0;i<n;i++)
		printf("\t%d",arr[i]);
	
}

void bdsc(int arr[30],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("\n Descending Sorting \n");
	for(i=0;i<n;i++)
		printf("\t%d",arr[i]);
	printf("\n\n");
	
}
void forkeg()
{
	int arr[25],arr1[25],n,i,status;
 	printf("\nEnter Size : - \n");
 	scanf("%d",&n);
 	printf("\nEnter Array : - \n");
 	for(i=0;i<n;i++)
    		scanf("%d",&arr[i]);
 	int pid=fork();
  	if(pid==0)
   	{
      		printf("\nChild Id = %d\n",getpid());
		bdsc(arr,n);
		printf("\n Bubble Sorting \n");
		printf("\n");
       		for(i=0;i<n;i++)
    			printf("\t %d,",arr[i]);
    		printf("\n");
     	}  
  	else
   	{
     		sleep(10);
     		
      		printf("Parent Id = %d\n",getppid());
     		bass(arr,n);
      		printf("\n Bubble Sort : \n");
  	   	printf("\n");
      		for(i=0;i<n;i++)
    			printf("%d,",arr[i]);
    			printf("\b");
    		system("ps -x");
       } 
 }    
 
int main()
 {
   forkeg();
   return 0;
 }  


Orphan Program Code:
#include <stdio.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{ 
 int pid;
 pid=getpid(); 
 printf("Current Process ID is : %d\n",pid); 
 printf("\n[Forking Child Process ... ] \n"); 
 pid=fork(); /* This will Create Child Process and Returns   Child's PID */
 if(pid < 0) 
 {    
  printf("\nProcess can not be created ");
 } 
 else
 {
  if(pid==0)
  { /* Child Process */
   printf("\nChild Process is Sleeping ..."); 
   sleep(5); /*Orphan Child's Parent ID is 1 */
   printf("\nOrphan Child's Parent ID : %d",getppid()); 
  }
  else
  { /* Parent Process */
   printf("\nParent Process Completed ..."); 
  } 
 }
 return 0; 
}

