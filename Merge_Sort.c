#include <stdio.h>
int A[100],M[100];
int n,i,j,k;
void merge();
void Merge_Sort();
int main()
{
	printf("Enter size of the array: ");
	scanf("%d",&n);
	printf("Enter array elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	Merge_Sort(0,n-1);
	printf("Sorted Array: ");
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	return 0;
}
void Merge_Sort(int low, int high)
{
	if(low>=high)
		return;
	Merge_Sort(low,(low+high)/2);
	Merge_Sort((low+high)/2+1,high);
	merge(low,(low+high)/2,high);
}
void merge(int low, int mid, int high)
{
	i=low,j=mid+1,k=0;
	while(i<=mid && j<=high)
	{	
		if(A[i]<=A[j])
			M[k++]=A[i++];
		else
			M[k++]=A[j++];
	}
	while(i<mid+1)
		M[k++]=A[i++];
	while(j<=high)
		M[k++]=A[j++];
	j=low;
	for(i=0;i<k;i++)
		A[j++]=M[i];
	printf("Auxillary Array:");
	for(i=low;i<=high;i++)
		printf("%d ",A[i]);
	printf("\n");
}
