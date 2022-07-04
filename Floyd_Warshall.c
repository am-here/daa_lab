#include <stdio.h>
#define INF 999999
int i, j, k, n;
int D[10][10];
static int P[10][10];
void floyd_babu()
{
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (D[i][j] > D[i][k] + D[k][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = k;
				}
			}
		}
	}
}
void path(int a, int b)
{
	if (P[a][b] == 0)
		printf(" -> %d", b);
	else
	{
		path(a, P[a][b]);
		path(P[a][b], b);
	}
}
int main()
{
	int source, destination;
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	printf("Please provide the Graph Matrix(consider -1 as infinity distance):\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &D[i][j]);
			if (D[i][j] == -1)
				D[i][j] = INF;
		}
	}
	floyd_babu();
	printf("D-Matrix:\n");
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			printf("%d\t", D[i][j]);
	printf("\n");
	printf("Path-Matrix:\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (P[i][j] != 0)
				printf("%d\t", P[i][j]);
			else
				printf("x\t");
		}
		printf("\n");
	}
	printf("Enter starting: ");
	scanf("%d", &source);
	printf("Enter destination: ");
	scanf("%d", &destination);
	printf("Path from %d to %d: %d", source, destination, source);
	path(source, destination);
	return 0;
}