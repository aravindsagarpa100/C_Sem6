#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
  
void main() 
{ 
    int pid,pid1,pid2; 
 
    pid=fork(); 

    if(pid==0) 
    { 
        sleep(2);
        printf("Child 1 is terminated \n");
    } 
  
    else if (pid>0)
    { 
        pid1=fork(); 

        if (pid1==0) 
        { 
            sleep(1); 
            printf("Child 2 is terminated\n"); 
        } 
        else if(pid>0)
        { 
            pid2=fork(); 
            if (pid2==0) 
            { 
                printf("Child 3 is terminated\n"); 
            } 
            else if(pid>0) 
            { 
                sleep(3); 
                printf("Parent is terminated\n"); 
            } 
            else
	        {
				printf("Error\n");
	        }
       }
       else
	   {
            printf("Error\n");
	   } 
    }
    else
    {
       printf("Error\n");
    } 
  
} 
