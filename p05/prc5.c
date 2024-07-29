// Design and implement C/C++ Program to obtain the Topological ordering of vertices in a given digraph
/*Topological Sorting:
	Topological Sorting is a linear ordering of the vertices in a directed graph such that for every directed edge from A to vertex B. A comes before B in the ordering .
	It is only applicable to directed acyclic graphs (DAGs)because a graph with a cycle cannot have a topological ordering.
*/
#include<stdio.h>
#include<conio.h>
int temp[10],k=0;
/*Global variables:
	- temp: an array to store the topological ordering of the vertices.
	-k: a variable to keep track of the current index in the temp array*/
void sort(int a[][10],int id[],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(id[i]==0)
		{
			id[i]=-1;
			temp[++k]=i;
			for(j=1;j<=n;j++)
			{
				if(a[i][j]==1 && id[j]!=-1)
					id[j]--;
			}
			i=0;

		
		}
	}
}
/*This function takes three parameters:
	- a: a 2D array representing the adjacency matrix of the graph
	- id: an array to store the in-degree of each vertex
	- n: the number of vertices in the graph
The Main Loop:
	-The function iterates over each vertex i
	- If the in-degree of vertex is zero(id[i]==0),it means the vertex has no incoming edges and can be included in the topological ordering.
	- The in-degree of vertex i is set to -1 to mark it as visited.
	- The vertex i is added to temp array and k is incremented.
	- For each neighor j of vertex i , if there is an edge from i to j (a[i][j]==1)and j is not visited (id[j]!=-1), then the in-degree of j is decremented.
	- The loop counter i is reset to 0 to start the iteration again from the beginning
*/
void main()
{
	int a[10][10],id[10],n,i,j;
	printf("\n Enter the n value:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		id[i]=0;
	printf("\n Enter the graph data: \n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==1)
				id[j]++;
		}
	sort(a,id,n);
	if(k!=n)
		printf("\n Topological ordering is not possible");
	else
		printf("\n Topological ordering is:");
		for(i=1;i<=k;i++)
			printf("%d",temp[i]);

	getch();
}
/*
- The user is prompted to enter the number of vertices 'n'.
- The id array is initialized with zeros , representing the in-degree of each vertex.
- The user is asked to input the adjacency matrix of the graph. The matrix should be filled with 0 and 1 where 1 indicates the presence of a direct edge from vertex i to vertex j.
- While reading the adjacency matrix , the in-degree of each vertex is calculated and stored in the id array.
- The sort() is called with the adjacency matrix a , the in-degree arry id and number of vertices n.

Output Result:
	- if the final value k is not equal to n, it means a topological ordering is not possible and an appropriate message is printed.
	- Otherwise the topological ordering is printed using the values stored in the temp array.
*/
/*Applications of Topological Sorting
scheduling tasks, dependency management , and data processing. */