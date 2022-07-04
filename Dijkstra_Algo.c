#include <stdio.h>
#define INF 999999
int i, j, k, n, source;
static int dist[10], pred[10], G[10][10];
void path(int a, int b)
{
	if (pred[b] == a)
	{
		printf(" -> %d", b);
	}
	else
	{
		path(a, pred[b]);
		path(pred[b], b);
	}
}
void djikstra()
{
	static int visited[10];
	int u, min = INF;
	for (i = 1; i <= n; i++)
	{
		dist[i] = G[source][i];
		if (dist[i] < INF)
			pred[i] = source;
	}
	visited[source] = 1;
	for (k = 1; k < n; k++)
	{
		min = INF;
		for (i = 1; i <= n; i++)
		{
			if (dist[i] < min && !visited[i])
			{
				min = dist[i];
				u = i;
			}
		}
		visited[u] = 1;
		for (i = 1; i <= n; i++)
		{
			if (dist[u] + G[u][i] < dist[i] && !visited[i])
			{
				dist[i] = dist[u] + G[u][i];
				pred[i] = u;
			}
		}
	}
}
int main()
{
	int d;
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
	printf("Enter the source vertex: ");
	scanf("%d", &source);
	djikstra(source);
	printf("\nPRED ARRAY: ");
	for (i = 1; i <= n; i++)
		printf("%d ", pred[i]);
	for (i = 1; i <= n; i++)
	{
		if (i != source)
		{
			printf("\nPath from %d to %d vertex: %d", source, i, source);
			path(source, i);
			printf("\nMinimum Cost of the journey: %d", dist[i]);
		}
	}
	return 0;
}
