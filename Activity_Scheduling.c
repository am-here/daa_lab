#include <stdio.h>
int m,n,i,j,dup;
int slots,TASK[100],START[100],END[100],SLOTS[100];
void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void sort()
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(END[j]>END[j+1])
			{
				swap(&END[j],&END[j+1]);
				swap(&START[j],&START[j+1]);
				swap(&TASK[j],&TASK[j+1]);
			}
		}	
	}
}
int activity_scheduling()
{
	SLOTS[0]=TASK[0];
	j=1;
	for(i=0;i<n;i++)
	{
		printf("%d ",END[i]);
	}
	printf("\n ");
	for(i=0;i<n;i++)
	{
		printf("%d ",START[i]);
	}
	for(i=1;i<n;i++)
	{
		
	}
	return j;
}
int main()
{
	int slots;
	printf("Enter the number of tasks: ");
	scanf("%d",&n);
	printf("\n-------------------------------------------------------------------------\n\tTASKS\t\t|\tSTART TIME\t|\tEND TIME\t|\n-------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		TASK[i]=i+1;
		printf("\t  %d\t\t\t   ",i+1);
		scanf("%d",&START[i]);
		scanf("%d",&END[i]);
		printf("-------------------------------------------------------------------------\n");
	}
	sort();
	slots = activity_scheduling();
	printf("\nSolution Slots\n");	
	for(i=0;i<slots;i++)
		printf("Slot %d:\tTask %d\n",i+1,SLOTS[i]);
	return 0;
}
