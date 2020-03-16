#include<stdio.h>
#include<pthread.h>
	int a[10][10];
	int b[10][10];
	int c[10][10];
	int r1;
	int c1;
	int r2;
	int c2;
	int r3;
	int c3;
	int s;
	int t;
void *multi(void *arg)
{
	int i,j,k;
	for(i=s;i<t;i++)
		for(j=0;j<r2;j++)
			for(k=0;k<r2;k++)
				c[i][j]+=a[i][k]*b[k][j];
	s++;
	t++;
	r3=r1;
	c3=c2;
}

void input1(int arr[10][10])
{
	int i,j;
	printf("Enter the order of the matrix : ");
	scanf("%d",&r1);
	scanf("%d",&c1);
	printf("Enter the elements of the matrix : \n"); 
	for(i=0;i<r1;i++)
		for(j=0;j<c1;j++)
			scanf("%d",&arr[i][j]);
}
void input2(int arr[10][10])
{
	int i,j;
	printf("Enter the order of the matrix : ");
	scanf("%d",&r2);
	scanf("%d",&c2);
	printf("Enter the elements of the matrix : \n"); 
	for(i=0;i<r2;i++)
		for(j=0;j<c2;j++)
			scanf("%d",&arr[i][j]);
}
void display1(int arr[10][10])
{
	int i,j;
	printf("\nMatrix : \n");
	for(i=0;i<r1;i++)
	{
		printf("\n");
		for(j=0;j<c1;j++)
			printf("%d\t",arr[i][j]);
	}
	printf("\n");
}
void display2(int arr[10][10])
{
	int i,j;
	printf("\nMatrix : \n");
	for(i=0;i<r2;i++)
	{
		printf("\n");
		for(j=0;j<c2;j++)
			printf("%d\t",arr[i][j]);
	}
	printf("\n");
}
void display3(int arr[10][10])
{
	int i,j;
	printf("\nMatrix : \n");
	for(i=0;i<r3;i++)
	{
		printf("\n");
		for(j=0;j<c3;j++)
			printf("%d\t",arr[i][j]);
	}
	printf("\n");
}
void main()
{
	int i;	
	input1(a);
	input2(b);
	display1(a);
	display2(b);
	s=0;
	t=1;
	if(r2==c1)
	{
		pthread_t tid[5];
		for(i=0;i<r1;i++)
		pthread_create(&tid[i],NULL,multi,NULL);
		
		for(i=0;i<r1;i++)
		pthread_join(tid[i],NULL);
		printf("\nProduct matrix : \n");
		display3(c);
	}
	else
		printf("\nCannot multiply...!!!\n");
}

