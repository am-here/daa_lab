#include <stdio.h>
int m,n,i,j,dup;
int slots,Tasks[100],Profits[100],Deadlines[100],Slots[100];
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
			if(Profits[j]<Profits[j+1])
			{
				swap(&Profits[j],&Profits[j+1]);
				swap(&Tasks[j],&Tasks[j+1]);
				swap(&Deadlines[j],&Deadlines[j+1]);
			}
		}	
	}
}
int job_sequencing()
{
	int profit = 0;
	i=0;
	while(slots>0 && i<n)
	{
		while(Deadlines[i]>=0 && Slots[--Deadlines[i]]!=0);
		i++;
		if(Deadlines[i-1]<0)
			continue;
		Slots[Deadlines[i-1]]=Tasks[i-1];
		profit += Profits[i-1];
		slots--;
	}
	return profit;
}
int main()
{
	int max_dead=0;
	printf("Enter the number of tasks: ");
	scanf("%d",&n);
	printf("\n-------------------------------------------------------------------------\n\tTasks\t\t|\tProfits\t\t|\tDeadlines\t|\n-------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		Tasks[i]=i+1;
		printf("\t  %d\t\t\t   ",i+1);
		scanf("%d",&Profits[i]);
		scanf("%d",&Deadlines[i]);
		if(max_dead<Deadlines[i])
			max_dead = Deadlines[i];
		printf("-------------------------------------------------------------------------\n");
	}
	slots = max_dead;
	for(i=0;i<max_dead;i++)
		Slots[i]=0;
	sort();
	printf("\nMaximum Profit: %d",job_sequencing());
	printf("\nSolution Slots\n");	
	for(i=0;i<max_dead;i++)
		printf("Slot %d:\tTask %d\n",i+1,Slots[i]);
	return 0;
}
