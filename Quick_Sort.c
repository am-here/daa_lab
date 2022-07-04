#include <stdio.h>
#include <limits.h>
int A[100];
int n,i,j;
int random();
int partition();
void Quick_Sort();
void swap();
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int random(int low, int high)
{
	return rand()%(high-low+1)+low;
}
int partition(int low, int high)
{
//	int ind = random(low,high);
	int ind = high;
	int pivot = A[ind];
//	swap(&A[ind],&A[high]);
	i=low-1,j=high;
	while(i<=j)
	{
		while(A[++i]<pivot);
		while(A[--j]>pivot);
		if(i<j)
			swap(&A[i],&A[j]);
	}
	swap(&A[i],&A[high]);
	return i;
}
void Quick_Sort(int low, int high)
{
	int x;
	if(low>=high)
		return;
	x = partition(low,high);
	Quick_Sort(low,x-1);
	Quick_Sort(x+1,high);
}
int main()
{
	printf("Enter size of the array: ");
	scanf("%d",&n);
	printf("Enter array elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	Quick_Sort(0,n-1);
	printf("Sorted Array: ");
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	return 0;
}
