#include <stdio.h>
#define INF 999999
int i, j, k, n;
int G[10][10];
int prims()
{
	static int visited[10];
	int min_cost = 0, v1 = 0, v2 = 0, min;
	visited[1] = 1;
	for (k = 1; k < n; k++)
	{
		min = INF;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (G[i][j] != INF && visited[i] == 1 && visited[j] == 0 && G[i][j] < min)
				{
					min = G[i][j];
					v1 = i;
					v2 = j;
				}
			}
		}
		printf("Edge %d = (%d -> %d) and Cost: %d\n", k, v1, v2, min);
		visited[v2] = 1;
		min_cost += min;
	}
	return min_cost;
}
int main()
{
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	printf("Please provide the Graph Matrix(consider 0 as infinity distance):\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &G[i][j]);
			if (G[i][j] == 0)
				G[i][j] = INF;
		}
	}
	printf("Minimum Cost: %d", prims());
	return 0;
}
