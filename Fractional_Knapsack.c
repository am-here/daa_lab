#include <stdio.h>
int m,n,i,j,dup;
float profit,W[100],P[100],X[100],ANS[100];
void swap(float *a,float *b)
{
	float temp = *a;
	*a = *b;
	*b = temp;
}
void sort()
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(X[j]<X[j+1])
			{
				swap(&X[j],&X[j+1]);
				swap(&W[j],&W[j+1]);
				swap(&P[j],&P[j+1]);
			}
		}	
	}
}
void profit_sort()
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(P[j]<P[j+1])
			{
				swap(&W[j],&W[j+1]);
				swap(&P[j],&P[j+1]);
			}
		}	
	}
}
void weight_sort()
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(W[j]>W[j+1])
			{
				swap(&W[j],&W[j+1]);
				swap(&P[j],&P[j+1]);
			}
		}	
	}
}
void knapsack()
{
	profit = 0.0;
	dup = m;
	for(i=0;i<n;i++)
	{
		if(dup<=W[i])
		{
			ANS[i]=dup/W[i];
			break;
		}
		dup-=W[i];
		ANS[i]=1.0;
	}
	printf("\nWEIGHT array:\t");
	for(i=0;i<n;i++)
		printf("%.2f ",W[i]);
	printf("\nPROFIT array:\t");
	for(i=0;i<n;i++)
		printf("%.2f ",P[i]);
	printf("\nANSWER array:\t");
	for(i=0;i<n;i++)
		printf("%.2f ",ANS[i]);
	for(i=0;i<n;i++)
		profit+=ANS[i]*P[i];
	printf("\nMaximum Profit: %.2f\n",profit);
}
int main()
{
	printf("Enter the capacity of the Knapsack: ");
	scanf("%d",&m);
	printf("Enter the number of items: ");
	scanf("%d",&n);
	printf("Enter Details of the Items: \n");
	for(i=0;i<n;i++)
	{
		printf("Enter Weight of the Item %d: ", i+1);
		scanf("%f",&W[i]);
		printf("Enter Profit gained the Item %d: ", i+1);
		scanf("%f",&P[i]);
	}
	profit_sort();
	printf("\nUsing Maximum Profit First Logic:\n");
	knapsack();
	weight_sort();
	printf("\nUsing Least Weight First Logic:\n");
	knapsack();
	for(i=0;i<n;i++)
		ANS[i]=0.0;
	for(i=0;i<n;i++)
		X[i]=P[i]/W[i];
	sort();
	printf("\nUsing Profit by Weight Ratio Logic:\n");
	knapsack();
	return 0;
}
