#include <stdio.h>
int A[100], n, key;
int rec_binary_search(int l, int u)
{
	int mid;
	if(l>u) 
		return -1;
	mid = (l+u)/2;
	if(A[mid]==key)
		return mid;
	else if(A[mid]<key)
		return rec_binary_search(mid+1,u);
	else
		return rec_binary_search(l,mid-1);
}
int iter_binary_search()
{
	int l=0,u=n-1,mid;
	while(l<=u)
	{
		mid = (l+u)/2;
		if(A[mid]==key)
			return mid;
		else if(A[mid]<key)
			l=mid+1;
		else
			u=mid-1;
	}
	return -1;
}
void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;	
}
int main()
{
	int i,j,ch,x;
	printf("Enter value of n: ");
	scanf("%d",&n);
	printf("Enter array elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	//sorting
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
			if(A[j]>A[j+1])
				swap(&A[j],&A[j+1]);
	//printing
	printf("Sorted array: ");
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
	while(1)
	{
		printf("1. Using Recursive Method\n2. Using Iterative Method\n3. Exit\nEnter Choice: ");
		scanf("%d",&ch);
		if(ch==3)
			break;
		printf("Enter value of key: ");
		scanf("%d",&key);
		switch(ch)
		{
			case 1:
				x = rec_binary_search(0,n-1);
				break;
			case 2:
				x = iter_binary_search();
				break;
			default:
				printf("Invalid Choice");
		}
		if(x==-1)
		printf("Element not found\n");
		else
		printf("Element found at %d\n",x+1);
	}
	return 0;
}

