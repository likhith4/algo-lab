//Design and implement C/C++ Program to solve 0/1 Knapsack problem using Dynamic Programming method.
/*0/1 Knapsack Problem:
	is a classic optimization problem in computer science.
	Given a set of items, each with a weight and a profit , and a knapsack with a limited capacity, the goal is to determine the set of items to include in the knapsack such that the total profit is maximized while the total weight does not exceed the knapsack capacity*/

#include<stdio.h>
int w[10],p[10],n;
/*
- w: An array to store the weights of the items.
- p: An array to store the profits of the items.
- n: The number of items.*/
int max(int a,int b)
{
	return a>b?a:b;
}
// This function returns the maximum of two integers a and b.
int knap(int i,int m)
{
	if(i==n)return w[i]>m?0:p[i];
	if(w[i]>m)return knap(i+1,m);
	return max(knap(i+1,m),knap(i+1,m-w[i])+p[i]);
}
/*
This function solves 0/1 Knapsack problem recursively.
- It takes two parameters:
	- i: The current item index.
	- m: The remaining capacity of the knapsack.
- The function returns the maximum profit that can be obtained using the items from index i to n

The key steps:
	1. If the current index i is equal to n , it means we have considered all the items. If the weight of the current item is greater than the remaining capacity m then we return 0(no profit). Otherwise we return the profit of the current item p[i]
	2. If the weight of the current item w[i] is greater than the remaining capacity m , we cannot include it in knapsack . We recursively call function with the next item(i+1) and the same capacity m.
	3. If we include the current item, we have two choices:
		- We can exclude the current item and recursively call the function with the next item(i+1) and the same capacity 'm'.
		- We can include the current item and recursively call the function with the next item(i+1) and the reduced capacity (m-w[i]). We add the profit of the current item p[i] to the result of the recursive call.
	4. We return the maximum of two choices using the max() function.*/
int main()
{
	int m,i,max_profit;
	printf("\n Entter the no.of objects:");
	scanf("%d",&n);
	printf("\n Enter the knapsack capacity:");
	scanf("%d",&m);
	printf("\n Enter profit followed by weight:\n");
	for(i=1;i<=n;i++)
		scanf("%d %d",&p[i],&w[i]);
	max_profit=knap(1,m);
	printf("\n Max profit= %d",max_profit);
	return 0;
			
}
/*
- The user is prompted to enter the number of items n.
- The user is asked to enter the capacity of the knapsack m.
- The user is asked to enter the profit and weight of each item.
- The knap function is called with the starting index 1 and the knapsack capacity m.
- The maximum profit is stored in  the max_profit variable and printed.
*/
