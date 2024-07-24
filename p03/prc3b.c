// Design and implement C/C++ Program to find the transitive closure using Warshal's algorithm.
// This algorithm is used to find the transitive closure of a directed graph represented by an adjacency matrix . The transitive closure indicates wheter there is a path between every pair of vertices in the graph.
#include<stdio.h>
void warsh(int p[][10],int n)
{
    int i,j,k;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                p[i][j]=p[i][j] || p[i][k] && p[k][j];
}
/*This function takes two parameters:
    - p: a 2D array representing the adjacency matrix of the graph
    - n: The number of vertices in the graph
    Triple nested loops :
    OuterLoop (k):iterates over each vertex as an intermediate point
    Middle loop(i):iterates over the starting vertex
    Inner Loop(j):iterates over the endin vertex.
The key operation here :
- p[i][j]=p[i][j]||(p[i][k]&&p[k][j]);
    - This line updates the adjacency matrix p to reflect wheter there is a path from vertex i to vertex j through vertex k.
    - If there is already a direct path from i to j then (p[i][j] is true)it remains true.
    - If there is a path from i to k and from k to j then from i to j  is established*/
int main()
{
    int a[10][10],n,i,j;
    printf("\nEnter the n value:");
    scanf("%d",&n);
    printf("\nEnter the graph data:\n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d",&a[i][j]);
    warsh(a,n);
    printf("\nResultant path matrix\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
/*The user is asked to input the adjacecy matrix of the graph . The matrix should be filled with 0 or 1 where 1 indicates the presence of a directed edge from vertex i to  j
- the warsh function is called to compute the transitive closure of the graph represented by the adjacency matrix a 
- Finally, the resultant matrix, which now contains information about the reachability of vertices, is printed. Each entry a[i][j] will be 1 if there is a path from vertex i to vertex j, and 0 otherwise.
*/

