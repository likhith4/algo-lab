//Design and implement C/C++ Program to solve discrete Knapsack and continuous Knapsack problems using greedy approximation method.
/*Knapsack Problem:
	is an optimization problem in which a set of items, each with a weight and a profit , must be selected to include in a knapsack of limited capacity. The goalis to maximize the total profit while ensuring that the total weight does not exceed the knapsack capacity.
There are two variants of Knapsack problem
	1. Discrete Knapsack: In  this variant , each item can be selected either zero or one time.
	2. Continuous Knapsack: In this variant , each item can be selected any number of times , including fractional amounts! */
#include<stdio.h>
#define MAX 50
int p[MAX],w[MAX],x[MAX];
double maxprofit;
int n,m,i,j;
/*
- p: An array to store the profits of the items;
- w: An array to store the weights of the items;
- x: An array to store the solution vector ( the number of times each item is selected.);
- maxprofit : a variable to store the maximum profit.
- n: The number of items;
- m: The maximum capacity of the knapsack.
- i,j: looping variables;
*/
void greedyKnapsack(int n,int w[],int p[], int m)
{
	double ratio[MAX];

	//to calculate the ration of profit to weight for each item
	for(i=0;i<n;i++)
	{
		ratio[i]=(double)p[i]/w[i];
	}
	//sort items based on the ratio in non-increasing order
	
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ratio[i]<ratio[j])
			{
				double temp=ratio[i];
				ratio[i]=ratio[j];
				ratio[j]=temp;

				int temp2=w[i];
				w[i]=w[j];
				w[j]=temp2;
			
			}
		}
	}
	int currentWeight=0;
	maxprofit=0.0;
	for(i=0;i<n;i++)
	{
		if(currentWeight+w[i]<=m)
		{
			x[i]=1;
			currentWeight+=w[i];
			maxprofit+=p[i];
		}
		else
		{
			x[i]=(m-currentWeight)/(double)w[i];
			maxprofit+=x[i]*p[i];
			break;
		}
	}
	printf("Optimal solution for greedy method :%.1f\n",maxprofit);
	printf("Solutioin vector for greedy method:");
	for(i=0;i<n;i++)
	printf("%d\t",x[i]);
}
/*
This function solves the Knapsack problem using the greedy approximation method.
It takes four parameters:
	- n: The number of items;
	- w: An array of weights;
	- p: An array of profits;
	- m: The maximum capacity of knapsack;
The key steps:
	1. Calculate the ration of profit to weight for each item and store it in the ratio array.
	2. Sort the items based on the profit-to-weight ration in non increasing order.
	3. Initialize the current weight to 0 and the maximum profit to 0.
	4. Iterate through the sorted items:
		- If the item can be fully included without exceeding the remaining capacity, add it to the solution vector and update the current weight and profit.
		- If the current item cannot be fully included , add a fractional amount to the solution vector and update the profit accordingly
	5. Print the maximum profit and solution vector.
*/
int main()
{
	printf("Enter the number of objects:");
	scanf("%d",&n);
	printf("Enter the objects' weights:");
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	printf("Enter the objects' profits:");
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	printf("Enter the maximum capacity:");
	scanf("%d",&m);
	greedyKnapsack(n,w,p,m);
	return 0;
}
/*
- The user is prompted to enter the number of items n.
- The user is asked to enter the weights of the items.
- The user is asked to enter the profits of the times.
The user is asked to enter the maximum capacity of the knapsack m.
- The greedyKnapsack function is called with the provided inputs.
*/
/*Application of Knapsack problem 
resource allocation, investment planning , and cargo loading.*/
