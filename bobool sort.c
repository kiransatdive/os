

2) ,15) 
Process control system calls: The demonstration of FORK, EXECVE and WAIT system calls along with zombie and orphan states
Implement the C program in which main program accepts the integers to be sorted. Main program uses the FORK system call to create a new process called a child process. Parent process sorts the integers using sorting algorithm and waits for child process using WAIT system call to sort the integers using any sorting algorithm. Also demonstrate zombie and orphan states.

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void bubblesort()
{
int i,j,a[50],n,temp;
printf("\nBubble sort\n");
printf("Enter size of array\t");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
{
int temp;
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("\nSorted array is\t");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}  
}
void selectionsort()
{
int i,j,a[50],n,min;
printf("Selection sort\n");
printf("\nEnter size of array\t");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
 for (i = 0; i < n-1; i++)
 { 
 min= i;
 for (j = i+1; j < n; j++)
 if (a[j] < a[min])
 min= j;
if(i<min)
{
int temp;
temp=a[min];
a[min]=a[i];
a[i]=temp;
}
}
printf("\nSorted array is\t");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
}

int main()
{
pid_t pid;
pid=fork();

if(fork()==0)
{
bubblesort();
}
else
{
wait(NULL);
selectionsort();
}
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



Zombie Program Code:
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
int pid;
printf("Current Process ID is: %d\n", pid);
printf("[Forking Child Process ... ]\n");
pid=fork();

if(pid < 0)
	{
		printf("Process can not br cretaed");
 	}
if(pid > 0)
	{
		printf("Parent Process is Sleeping ...");
		sleep(5);
		printf("\nID : %d", getppid());
 	}
else
	{
		exit(0);
	}
return 0;
}

