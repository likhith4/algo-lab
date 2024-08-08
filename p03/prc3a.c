//Design and implement C/C++ Program to solve All-Pairs Shortest Paths problem using Floyd's algorithm
/*The Floyd-Warshall algorithm solves the all-pairs shortest path problem by iteratively updating a distance matrix. It considers each vertex as a potential intermediate vertex in the shortest path between two other vertices. The algorithm compares the direct path between two vertices with the path that goes through the intermediate vertex and updates the distance matrix accordingly.*/
#include<stdio.h>

#define INF 999
/*INF: A constant representing an infinite cost used for comparison when searching for mminimum path.
The program includes the standard I/O library for basic I/O and conio.h library for console I/O functions.*/
int min(int a,int b)
{
    return(a<b)?a:b;
}
//The function returns the minimum of two integers 'a' and 'b' using a ternery operator.
void floyd(int p[][10],int n)
{
    int i,j,k;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}
/*
- p: A 2D array representing the cost (weight) of edges between vertices.
- n: the number of vertices in the graph.
- The function performs the Floyd warshall algorithm to update the distance matrix 'p'
1. For each verte k from 1 to n , it considers k as potential intermediate vertex.
2. For  each pair of vertices i and j it checks if the path from i to j through k is shorter than the current path stored in p[i][j].
3. If the path through k is shorter it updates p[i][j] with the minimum of the current value and the sum of 'p[i][k]'and p[i][j].
- After the algorithm completes the distance matrix p contains the minimu costs between all pirs of vertices.
*/
void main()
{
    int a[10][10],n,i,j;
    printf("\nEnter the n value:");
    scanf("%d",&n);
    printf("\nEnter the graph data:\n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d",&a[i][j]);
    floyd(a,n);
    printf("\nShortest path matrix\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    getchar();
}
/*
- The main  function prompts the user for the number of vertices 'n'.
- It collects the graph data (cost matrix ) from the user , where a[i][j] represents the weight of the eedge between vertices i and j . if there is no direct edge between i and j , a[i] is set to INF.
- The floyd() function is called with the cost matrix and number of vertices to computer the shortest paths between all pairs of vertices.
- After the algorithm completes, the program prints the sesulting shortest path matrix whre a[i][j] represents the minimum cost to  reach vertex j from vertex i.

*/
