#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <sys/types.h> 
#include <string.h> 
#include <stdlib.h> 
  
int main(int argc,char *argv[]) 
{ 
    pid_t pid; 
    int i,k=2,n; 
    n=atoi(argv[1]); 
    int arr[n];

    if(argc!=2) 
    { 
        printf("arguement is missing\n"); 
        exit(0); 
    } 

    if(atoi(argv[1])<0) 
    { 
        printf("negative number\n"); 
        exit(0); 
    } 
  
    pid=fork(); 


    arr[0]=1; 

    for (i=1;i<n;i++) 
    { 
        arr[i]=arr[i-1]*k; 
        k++; 
    }

    if(pid<0) 
    { 
        printf("Error\n"); 
        exit(0); 
    } 
  
    else if(pid==0) 
    { 
		printf("Child process--------------------------------\n");

        printf("%d\n",arr[n-1]);
        
    } 
    else
    { 
        
   		printf("Parent process-------------------------------\n");  
 
        for(i=0;i<n;i++)
		{
	    	printf("%d  ",arr[i]);	
		}
        printf("\n");   
    } 
} 
