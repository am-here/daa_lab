#include <stdio.h>
#define INF 999999
int i,j,n,ch,source,f=1,r=0;
static int Q[10], visited[10], G[10][10];
void DFS(int a)
{
	int i;
	visited[a]=1;
	for(i=1;i<=n;i++)
	{
		if(!visited[i] && G[a][i]==1)
		{
			printf(" -> %d",i);
			DFS(i);
		}
	}
}
void BFS()
{
	if(f>r)
		return;
	printf(" -> %d",Q[f++]);
	for(i=1;i<=n;i++)
	{
		if(!visited[i] && G[f-1][i]==1)
		{
			visited[i]=1;
			Q[++r]=i;
		}
	}
	BFS();
}
int main()
{
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	printf("Please provide the Graph Matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&G[i][j]);
		}
	}
	do{
		printf("By which method you want to traversal?\n1.DFS\n2.BFS\n");
		scanf("%d",&ch);
		printf("Enter the source vertex: ");
		scanf("%d", &source);
		switch(ch){
			case 1:
				printf("Using DFS Algorithm: %d",source);
				DFS(source);
				break;
			case 2:
				printf("Using BFS Algorithm: %d",source);
				for(i=1;i<=n;i++)
				{
					Q[i]=0;
					visited[i]=0;
				}
				for(i=1;i<=n;i++)
				{
					if(i==source)
					{
						visited[source]=1;
						continue;
					}
					if(!visited[i])
					{
						visited[i]=1;
						Q[++r]=i;
						BFS();
					}	
				}
				break;
			default:
				printf("Invalid Input Dear!");
		}
		printf("\nDo you want to continue bro? (yes:1,no:0)");
		scanf("%d",&ch);	
	}while(ch==1);
	return 0;
}
