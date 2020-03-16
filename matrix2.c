#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

struct a
{
	int a[10][10];
	int b[10][10];
	int c[10][10];
	int d[200];
	int r1;
	int c1;
	int r2;
	int c2;
	int r3;
	int c3;
	int s;
	int t;
	int x;
};

void* multi(void* nm)
{
    struct a *m = (struct a*)nm;
	int i,j,k;
	
	for(i=(*m).s;i<(*m).t;i++)
	{
		for(j=0;j<(*m).r2;j++)
		{
			for(k=0;k<(*m).r2;k++)
			{
				(*m).d[(*m).x]=((*m).a[i][k])*((*m).b[k][j]);
				(*m).x++;
			}
		}
	}
	(*m).s++;
	(*m).t++;
	(*m).r3=(*m).r1;
	(*m).c3=(*m).c2;
}


void main()
{
	int i,j,v,u=0,sum,r,s,w;	
	struct a *nm;
	nm=malloc(sizeof(struct a));
	(*nm).x=0;
	
	printf("Enter matrix1 order: ");
	scanf("%d",&(*nm).r1);
	scanf("%d",&(*nm).c1);
	printf("Enter elements of the matrix1:\n"); 
	for(i=0;i<(*nm).r1;i++)
	{
		for(j=0;j<(*nm).c1;j++)
		{
			scanf("%d",&(*nm).a[i][j]);
		}
	}
		
	printf("Enter matrix2 order: ");
	scanf("%d",&(*nm).r2);
	scanf("%d",&(*nm).c2);
	printf("Enter elements of the matrix2: \n"); 
	for(i=0;i<(*nm).r2;i++)
	{
		for(j=0;j<(*nm).c2;j++)
		{
			scanf("%d",&(*nm).b[i][j]);
		}
	}
	
	printf("\nMatrix1 is: \n");
	
	for(i=0;i<(*nm).r1;i++)
	{
		printf("\n");
		for(j=0;j<(*nm).c1;j++)
		{
			printf("%d\t",(*nm).a[i][j]);
		}
	}
	printf("\n");
	
	printf("\nMatrix2 is: \n");
	
	for(i=0;i<(*nm).r2;i++)
	{
		printf("\n");
		for(j=0;j<(*nm).c2;j++)
		{
			printf("%d\t",(*nm).b[i][j]);
		}
	}
	printf("\n");
	
	(*nm).s=0;
	(*nm).t=1;

	if((*nm).r2==(*nm).c1)
	{
		pthread_t tid[5];
		for(i=0;i<(*nm).r1;i++)
		{
		    pthread_create(&tid[i],NULL,multi,(void*) nm);
		}
		
		for(i=0;i<(*nm).r1;i++)
		{
		    pthread_join(tid[i],NULL);
		}
		w=(*nm).c1;
		for(r=0;r<(*nm).r1;r++)
		{
		    for(s=0;s<(*nm).c2;s++)
		    {
		        sum=0;
		        for(v=u;v<w;v++)
		        {
		            sum+=(*nm).d[v];    
		        }
		        (*nm).c[r][s]=sum;
		        u+=(*nm).r2;
		        w+=(*nm).c1;
		    }
		}
		
		printf("\nProduct matrix is: \n");
		for(i=0;i<(*nm).r3;i++)
	    {
		    printf("\n");
		    for(j=0;j<(*nm).c3;j++)
		    {
			    printf("%d\t",(*nm).c[i][j]);
	        }
	    }
	    printf("\n");
	}
	else
	{
		printf("\nMatrices cannot be multiplied\n");
	}
}

