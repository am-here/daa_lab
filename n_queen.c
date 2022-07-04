#include <stdio.h>
#include <stdbool.h>
static int B[10][10];
int n, i, j;
void print()
{
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("----");
        printf("-");
        printf("\n");
        for (j = 0; j < n; j++)
        {
            if (B[i][j] == 0)
                printf("| x ");
            else
                printf("| Q ");
        }
        printf("|");
        printf("\n");
    }
    for (j = 0; j < n; j++)
        printf("----");
    printf("-");
    printf("\n");
}
bool check(int r, int c)
{
    for (i = 0; i <= c; i++)
        if (B[r][i])
            return false;
    i = r, j = c;
    while (i >= 0 && j >= 0)
        if (B[i--][j--])
            return false;
    i = r, j = c;
    while (i < n && j >= 0)
        if (B[i++][j--])
            return false;
    return true;
}
void solve(int c)
{
    int r;
    if (c == n)
        print();
    else
    {
        for (r = 0; r < n; r++)
        {
            if (check(r, c))
            {
                B[r][c] = 1;
                solve(c + 1);
                B[r][c] = 0;
            }
        }
    }
}
int main()
{
    printf("Enter the value of n of n X n chessboard: ");
    scanf("%d", &n);
    solve(0);
    return 0;
}