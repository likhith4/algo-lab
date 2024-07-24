//Design and implement C/C++ Program to find shortest paths from a given vertex in a weighted connected graph to other vertices using Dijkstra's algorithm.
/*Dijkstra's Algorithm:
    is a greedy algorithm used to find the shortest path from single source vertex to all other vertices in a weighted graph. It works by iteratively selecting the unvisited vertex with the smallest known distance from the source and updating the distances of the neighbours*/
#include<stdio.h>
#define INF 999
void dijkstra(int c[10][10],int n,int s,int d[10])
{
    int v[10],min,u,i,j;
    for(i=1; i<=n; i++)
    {
        d[i]=c[s][i];
        v[i]=0;
    }
    v[s]=1;
    for(i=1; i<=n; i++)
    {
        min=INF;
        for(j=1; j<=n; j++)
            if(v[j]==0 && d[j]<min)
            {
                min=d[j];
                u=j;
            }
        v[u]=1;
        for(j=1; j<=n; j++)
            if(v[j]==0 && (d[u]+c[u][j])<d[j])
                d[j]=d[u]+c[u][j];
    }
}
/*This function takes four parameters:
    - c: A 2D array representing the cost (weight) matrix of the graph
    - n : the number of vertices in the graph
    - s: the source vertex.
    - d: An array to store the shortest distances from the source to each vertex
Initialization:
    - The d array is initialized with the direct costs from the source vertex s to each vertex i.
    -The v array is used to keep trackof visited vertices. Initially all vertices are marked as unvisited(v[i]=0)
    - The source vertex s is marked as visited (v[s]=1)
The Main Loop:
    -Outer Loop (i): iterates n times where n is the number of vertices.
    - Inner Loop 1: finds the unvisited vertex u with the smalles known distance fromthe source.
    - Inner Loop 2: Updates the distances of unvisited neighbors of the vertex u.
The key operations:
    -if(v[j]==0&& d[j]<min):Checks if vertexj is unvisited and has a smaller distance that the current minimum
    -v[u]=1:Marks the selected vertex u as visited.
    - if(v[j]==0 && (d[u]+c[u][j])<d[j]) : Checks if vertex j is unvisited and the sum of the distance from the source to u and cost from u to j is less than the current distance from the source to j
    -d[j]=d[u]+c[u][j] : Updates the distance of vertex j if a shorter path is found. */
int main()
{
    int c[10][10],d[10],i,j,s,sum,n;
    printf("\nEnter n value:");
    scanf("%d",&n);
    printf("\nEnter the graph data:\n");
    for(i=1; i<=n; i++)	
        for(j=1; j<=n; j++)
            scanf("%d",&c[i][j]);
    printf("\nEnter the souce node:");
    scanf("%d",&s);
    dijkstra(c,n,s,d);
    for(i=1; i<=n; i++)
        printf("\nShortest distance from %d to %d is %d",s,i,d[i]);
    return 0;
}
/*- The user is prompte to enter the number of vertices.
- The user is asked to input the cost matrix of the graph . The matrix should be filled with the weights of the edges.
- The user is asked to enter the source vertex s.
Calling the Dijkstra's Algorithm:
    - The dijkstra() functionis called with the cost matrix c , the number of vertices n , the source vertex s and the d array to store the shortest distances.
    - The shortest distances from the source vertex s to each vertex i are printed using the values stored in the d array.
*/