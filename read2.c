#include<stdio.h>
#include<stdlib.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
#include <time.h>

sem_t full,empty,mutex; 

int a[3][3]; 

struct fun
{
    int x;
}z[3];

 
void* producer(void* arg)
{
int j=*((int* )arg),i;
while(1)
{ 
	sem_wait(&empty);	
	sem_wait(&mutex); 
	
		
	a[j][z[j].x]=rand()%8;
	printf("\nProducer %d produces item %d\n",j+1,a[j][z[j].x]);
	z[j].x++;
	printf("Buffer: \n");
	for(i=0;i<z[0].x;i++)
	{
	    printf("%d\t",a[0][i]);
	}
	printf("\n");
	for(i=0;i<z[1].x;i++)
	{
	    printf("%d\t",a[1][i]);
	}
	printf("\n");
	for(i=0;i<z[2].x;i++)
	{
	    printf("%d\t",a[2][i]);
	}
	printf("\n");
	
	
	sem_post(&mutex);
    sem_post(&full);
sleep(1);
}
pthread_exit(0);
}
 
 
 
void* consumer(void* arg)
{
int j=*((int* )arg),i;
while(1)
{
	sem_wait(&full);	
	sem_wait(&mutex); 
	
	int m=rand()%3;
	printf("\nConsumer %d consumes item %d of producer %d\n",j+1,a[m][z[m].x-1],m+1);
	z[m].x--;
	
	printf("Buffer: \n");
	for(i=0;i<z[0].x;i++)
	{
	    printf("%d\t",a[0][i]);
	}
	printf("\n");
	for(i=0;i<z[1].x;i++)
	{
	    printf("%d\t",a[1][i]);
	}
	printf("\n");
	for(i=0;i<z[2].x;i++)
	{
	    printf("%d\t",a[2][i]);
	}
	printf("\n");
	
	
	sem_post(&mutex);
	sem_post(&empty);
sleep(1);
}
pthread_exit(0);
}



void main()
{
int b[3]={0,1,2};
srand(time(NULL));		
sem_init(&mutex, 0, 1); 
sem_init(&empty, 0, 3); 
sem_init(&full, 0, 0); 
pthread_t t1,t2,t3,t4,t5,t6;  

pthread_create(&t1,NULL,producer,&b[0]);
pthread_create(&t2,NULL,producer,&b[1]);
pthread_create(&t3,NULL,producer,&b[2]);

pthread_create(&t4,NULL,consumer,&b[0]);
pthread_create(&t5,NULL,consumer,&b[1]);
pthread_create(&t6,NULL,consumer,&b[2]);

pthread_join(t1,NULL);
pthread_join(t2,NULL);
				
}
 

