// To design and implement program to find the minimum cost spanning tree of a given connected undirected graph using prim's algorithm
/*The Prim's algorithm build the MST by starting from a selected vertex(the source)and repeatedly adding the smallest edge that connects a vertex in the MST to a vertex outside the MST.
The process continues untill all vertices are included in the MST.
*/
#include<stdio.h>
#define INF 999
/*INF: a constant  representing an infinite cost, used to comparison when searching for minimum edge.
stdio.h : this library includes standard input and output library for I/O operation.
*/
int prim(int c[10][10],int n,int s)
{
	int v[10],i,j,sum=0,ver[10],d[10],min,u;
	/*
	c: a 2D array representing the cost (weight ) of edges between vertices.
	- n: the number of vertices in the graph
	- s: the source vertex from which to start building the MST.
	- v: An array to track whether a vertex is included in the MST(1 if included, 0 otherwise)
	- sum: A variable to accumulate the total cost of MST.
	- ver: An array to store the last vertex added to the MST for each vertex.
	-d : An array to store the minimum cost to connect each vertex to the MST.
	- min and u: Variables used to find the minimum edge and the corresponding vertex. 
	*/
	for(i=1;i<=n;i++)
	{
		ver[i]=s;
		d[i]=c[s][i];
		v[i]=0;
	}
	v[s]=1;
	/*
	#Initialization:
	The above loop initializes the arrays:
	- ver[i] is set to the source vertex for all vertices initially;
	- d[i] is set to the cost of connecting each vertex to the source vertex
	- v[i] is intialized to 0, indicating that no vertices are included in the MST to start.
	*/
	for(i=1;i<=n-1;i++)
	{
		min=INF;
		for(j=1;j<=n;j++)
			if(v[j]==0&&d[j]<min)
			{
				min=d[j];
				u=j;
			}
		/*
	The above is the main loop to construct the MST.
	- the outer loop runs n-1 times , as an MST for n vertices contains exactly n-1 edges.
	- the inner loop searches for the vertex u that is not yet included in the MST (v[j]==0)and has minimim cost to connect to the MST ('d[j]<min').
	- The minimum cost edge found is stored in the min and corresponding vertex is stored in u.
	*/
		v[u]=1;
		sum=sum+d[u];
		printf("\n %d -> %d sum=%d",ver[u],u,sum);
		/*Adding the minimum edge to the MST.
		- After finding the minimum edge, vertex u is marked included in the MST.
		- The cost of the edge connecting ver[u](the last vertex added to the MST) to u is added to sum
		- The program prints the edge added and current total cost of the MST*/
		for(j=1;j<=n;j++)
			if(v[j]==0 && c[u][j]<d[j])
			{
				d[j]=c[u][j];
				ver[j]=u;
			}
			/*Updating the costs:
			- This loop updates teh cost array d for each vertex j that is not yet included in the MST.
			- If the cost of connecting vertex u to vertex j is less than the current minimum cost d[j], it updates and sets ver[j] to u, indicating that the best way to reach j is through u.*/
	}
	return sum;
}
void main()
{
	int c[10][10],i,j,res,s,n;
	printf("\n Enter n value:");
	scanf("%d",&n);
	printf("\n Enter the graph data: \n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&c[i][j]);
	printf("\n Enter the source node:");
	scanf("%d",&s);
	res=prim(c,n,s);
	printf("\nCost=%d",res);
	getch();
}
/*
- The main function prompts the user for the number of vertices 'n'.
- It collects the graph data (cost matrix) from the user, where c[i][j] represents the weight of the edge between vertices 'i' and 'j'.
- The user is then asked to enter the source node 's'
- The prim() function is called withthe cost matrix, number of vertices and the source node to computer the MST.
- Finally, it prints the total cost of the MST.
*/
