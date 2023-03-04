// BFS

#include <stdio.h>
#define max 5
int arr_adj[max][max];
int visited[max];
void BFS(int start)
{
    int queue[max], rear = -1, front = -1, i;
    queue[++rear] = start;
    visited[start] = 1;
    while (rear != front)
    {
        start = queue[++front];
        printf("%d ", start);
        for (int i = 1; i <= max; i++)
        {
            if (arr_adj[start][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}
int main()
{
    printf("Enter the matrix Element : \n");
    for (int i = 1; i <= max; i++)
    {
        for (int j = 1; j <= max; j++)
        {
            scanf("%d", &arr_adj[i][j]);
        }
    }
    printf("BFS Search --------------> \n");
    BFS(1);
    return 0;
}
