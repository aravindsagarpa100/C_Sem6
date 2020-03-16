#include <stdlib.h> 
#include <stdio.h>
#include <unistd.h> 
#include <pthread.h> 

    int arr[30]; 
    int arr_size;
  
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  printf("Enter n:");
scanf("%d",&arr_size);
printf("Enter array elements:");
for(int j=0;j<arr_size;j++)
{
scanf("%d",&arr[j]);
}
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

void *X(void *arg)
{
	int m=(arr_size - 1)/2;
	mergeSort(arr, 0, m); 
}

void *Y(void *arg)
{
	int m=(arr_size - 1)/2;
	mergeSort(arr, m+1, arr_size-1); 
}
 
void Z()
{
	int m=(arr_size - 1)/2;
	merge(arr, 0, m, arr_size-1); 
}

void main() 
{ 

	int m=(arr_size - 1)/2;
	pthread_t tid; 
printf("Enter n:");
scanf("%d",&arr_size);
printf("Enter array elements:");
for(int j=0;j<arr_size;j++)
{
scanf("%d",&arr[j]);
}


	
    printf("Given array is \n"); 
    printArray(arr, arr_size);
	pthread_create(&tid,NULL,X,NULL); 
	printf("\nSorted array by first thread is: \n"); 
    for(int i=0;i<m+1;i++)
	{
		printf("%d ",arr[i]);	
	}

	pthread_create(&tid,NULL,Y,NULL); 

	printf("\nSorted array by second thread is: \n"); 
    for(int i=m+1;i<arr_size;i++)
	{
		printf("%d ",arr[i]);	
	}

	pthread_join(tid, NULL);
	Z();
      
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 

} 

