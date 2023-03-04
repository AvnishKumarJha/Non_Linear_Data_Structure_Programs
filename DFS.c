// Recursive DFS Method
#include <stdio.h>
#define N 5
int a[N][N];
int visited[N];

void print_array(int arr[])
{

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}

void DFS(int i)
{
    int j;
    printf("\n%d", i);
    visited[i] = 1;

    for (int j = 0; j < N; j++)
    {
        if (visited[j]==0 && a[i][j] == 1)
        {
            DFS(j);
        }
    }
}

int main()
{
    printf("******* Enter the Element in the Matrix ***********\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("\nMatrix Element a[%d][%d] : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < N; i++)
    {
        visited[i] = 0;
    }
    DFS(0);
    printf("\nVisited Nodes are : \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", visited[i]);
    }

    return 0;
}
