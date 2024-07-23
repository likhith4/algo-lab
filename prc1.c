#define INF 999  //a constant representing an infinite cost(used for comparison)
#define MAX 100
#include<stdio.h>
int p[MAX], c[MAX][MAX], t[MAX][2]; 
// p[MAX] used for the union-find data structure to keep track of the parent of each vertex.
// c[MAX][MAX] --used for the 2D representation of the cost of edges between the weights.
// t[MAX] -- a 2D array to store the edges included MST Minimum Spanning Tree
int find(int v)
{
    while (p[v])
        v = p[v];
    return v;
}
// This function returns the root parent of a vertex v. It follows the parent pointer until it reaches a vertex that is its own parent(root).
void union1(int i, int j)
{
    p[j] = i;
}// this function performs the union operation by making j a child of vertex i. This effectively connects two sets in the union-find structure.
void kruskal(int n)
{
    int i, j, k, u, v, min, res1, res2, sum = 0;
    for (k = 1; k < n; k++)
    {
        min = INF;
        for (i = 1; i < n - 1; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (i == j) continue;
                if (c[i][j] < min)
                {
                    u = find(i);
                    v = find(j);
                    if (u != v)
                    {
                        res1 = i;
                        res2 = j;
                        min = c[i][j];
                    }
                }
            }
        }
        /* Explanation of Kruskal Function;
        1. Initialization : The function initializes variables to keep track of the minimum edge and the cost of the Minimum spanning tree
        2. Outer Loop: the outer loop runs exactly n-1 times , as spanning tree for n vertices contains exactly n-1 edges;
        3.Finding Minimum Edge:
            - The inner loops iterate through all pairs of vertices (i,j)
            - It checks if the edge c[i][j] is the minimum found so far and ensures that it does not form a cycle by checking if u and v (the roots of i and j ) are different.
            - If a valid edge is found, it updates the minimum cost and store the vertices in `res1` and `res2`
        */
        union1(res1, find(res2)); //4. Union Operation: After finding the minimum edge that does not create a cycle. it performs a union operation to connect 
        t[k][1] = res1;
        t[k][2] = res2;
        sum = sum + min;
        // Storing the results: the edges included in the MST are stored in the array `t`.
    }
    printf("\nCost of spanning tree is=%d", sum);
    printf("\nEdgesof spanning tree are:\n");
    for (i = 1; i < n; i++)
        printf("%d -> %d\n", t[i][1], t[i][2]);
        //Output finally it prints the total cost of the spanning tree and the edges included.
}





int main()
{
    int i, j, n;
    printf("\nEnter the n value:");
    scanf("%d", & n);
    for (i = 1; i <= n; i++)
        p[i] = 0;
    printf("\nEnter the graph data:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", & c[i][j]);
    kruskal(n);
    return 0;
}
/* the main function startsby prompting the use to enter the number of vertices n.
- it initializes the parent array p to zero (indicating that each vertex is its own parent)
- then it collects the graph data (cost matrix from the user.)
- Finally it calls kruskal functionto compute and display the MST.
*/
