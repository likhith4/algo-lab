//design and implement  program to solve discrete knapsack and continuous knapsack problems using greedy approximation method 

#include<stdio.h>
#define MAX 50
int p[MAX],w[MAX],x[MAX];
double maxprofit;
int n,m,i,j;
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
