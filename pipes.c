#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include <stdlib.h>

void main()
{
 int pipearg1[2];
 int pipearg2[2];
 int returnvalue1;
 int returnvalue2;
 int pid;
 char writesentence[50]="I am fond of what I do. hello world";
 char readsentence[50],x[50];
 char pos;
 int c,w=1,l=1;
 FILE *fptr;

 returnvalue1=pipe(pipearg1);


 if (returnvalue1 == -1) 
 {
   printf("Unable to create pipe\n");
  
 }
 returnvalue2=pipe(pipearg2);
 if (returnvalue2 == -1)
 {
   printf("Unable to create pipe\n");
   
 }

 pid=fork();
if(pid==0)
{
 write(pipearg1[1],writesentence,sizeof(writesentence));
 printf("The message is %s\n",writesentence);
 exit(0);
}

else
{
	sleep(1);
	read(pipearg1[0],readsentence,sizeof(readsentence));

	c = strlen(readsentence);
	
	
	for(int i=0;i<strlen(readsentence);i++)
	{
		if(readsentence[i]==' ')
		{
			w++;		
		}		
	}
	

	for(int i=0;i<strlen(readsentence);i++)
	{
		if(readsentence[i]=='.')
		{
			l++;		
		}		
	}
	


}

fptr=fopen("sentence.txt","w");
fprintf(fptr, "No of characters is %d\nNo of words is %d\nNo of sentences is %d",c,w,l);
fclose(fptr);

fptr=fopen("sentence.txt","r");
for(int z=0;z<3;z++)
{
	fgets(x,50,fptr);
	write(pipearg2[1],x,sizeof(x));
	read(pipearg2[0],readsentence,sizeof(readsentence));
	puts(readsentence);
}
}
