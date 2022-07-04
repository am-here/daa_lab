#include <stdio.h>
int i, j, k, q, n, x, c = 65;
int M[10][10], S[10][10], D[10];
void paran(int i, int j)
{
	if (i == j)
		printf("%c", c++);
	else
	{
		printf("(");
		paran(i, S[i][j]);
		paran(S[i][j] + 1, j);
		printf(")");
	}
}
int main()
{

	printf("Enter value of n: ");
	scanf("%d", &n);
	printf("Enter Elements: ");
	for (i = 0; i < n; i++)
		scanf("%d", &D[i]);
	printf("Matrices:\n");
	for (i = 1; i < n; i++)
		printf(" %c \t", c + i - 1);
	printf("\n");
	for (i = 1; i < n; i++)
		printf("%dx%d\t", D[i - 1], D[i]);
	printf("\n\n");
	for (q = 2; q < n; q++)
	{
		for (i = 1; i < n - q + 1; i++)
		{
			j = q + i - 1;
			M[i][j] = 99999;
			for (k = i; k < j; k++)
			{
				x = M[i][k] + M[k + 1][j] + (D[i - 1] * D[k] * D[j]);
				if (x < M[i][j])
				{
					M[i][j] = x;
					S[i][j] = k;
				}
			}
		}
	}
	printf("Multiplication Matrix:\n");
	for (i = 1; i < n; i++)
	{
		for (j = 1; j < n; j++)
			if (i > j)
				printf("\t");
			else
				printf("%d\t", M[i][j]);
		printf("\n");
	}
	printf("\n");
	printf("Path Matrix:\n");
	for (i = 1; i < n; i++)
	{
		for (j = 1; j < n; j++)
			if (i >= j)
				printf(" \t");
			else
				printf("%d\t", S[i][j]);
		printf("\n");
	}
	printf("Minimum Solution: %d\nSolution: ", M[1][n - 1]);
	paran(1, n - 1);
	return 0;
}
