//desing and implement C program to solve 0 or 1 Knapsack problem using Dynamic  Programming method

#include<stdio.h>
int w[10],p[10],n;
int max(int a,int b)
{
	return a>b?a:b;
}
int knap(int i,int m)
{
	if(i==n)return w[i]>m?0:p[i];
	if(w[i]>m)return knap(i+1,m);
	return max(knap(i+1,m),knap(i+1,m-w[i])+p[i]);
}
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
