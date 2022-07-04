#include <stdio.h>
#include <limits.h>
int A[100];
int mid,n,i,j;
int greater(int a, int b)
{
	return a>b?a:b;
}
int smaller(int a, int b)
{
	return a<b?a:b;
}
void max_min(int low, int high, int *max, int *min)
{
	if(high-low<2)
	{
		*max = greater(*max,greater(A[high],A[low]));
		*min = smaller(*min,smaller(A[high],A[low]));
	}
	else
	{
		mid = (low+high)/2;
		max_min(low,mid,max,min);
		max_min(mid+1,high,max,min);
	}
}
int main()
{
	printf("Enter size of the array: ");
	scanf("%d",&n);
	printf("Enter array elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	int max=INT_MIN,min=INT_MAX;	
	max_min(0,n-1,&max,&min);
	printf("Maximum Number: %d\n",max);
	printf("Minimum Number: %d",min);
	return 0;
}
