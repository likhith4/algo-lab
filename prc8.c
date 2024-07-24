//Design and implement C/C++ Program to find a subset of a given set S = {sl , s2,.....,sn} of n positive integers whose sum is equal to a given positive integer d
/*Subset Sum Problem:
	is a classical problem in Computer Science and Combinatorial Optimization it is to find all the subsets of S (where S is a set )such that the sum of the elements in each subset equals a given positive integer d*/
#include<stdio.h>
#define MAX 10
int s[MAX],x[MAX],d;
/*
- s[MAX]:An array that stores the elements of the set S
- x[MAX]: An array used to keep track of which element are included in the current subset begin considered
- d: the target sum that we want to acheive with the subsets*/
void sumofsub(int p,int k, int r)
{
	int i;
	x[k]=1;
	if((p+s[k])==d)
	{
		for(i=1;i<=k;i++)
			if(x[i]==1)
				printf("%d",s[i]);
		printf("\n");
	}
	else if(p+s[k]+s[k+1]<=d)
		sumofsub(p+s[k],k+1,r-s[k]);
	if((p+r-s[k]>=d) && (p+s[k+1]<=d))
	{
		x[k]=0;
		sumofsub(p,k+1,r-s[k]);
	}
}
/*
This recursive function is responsible for exploring the subsets of the set S.
-It takes three parameter:
	-p:The current sum of the selected elements.
	-k: The current index in the set S being considered;
	- r: The remaining sum of the elements from the current index to the end of the set.
Key steps in the function:
	1. x[k]=1; here the current element s[k] is included in the subset.
	2. Check for target sum: in the if-for-if --> if the current sum p+a[k] equals the target sum d, the current subset is printed.
	3. Check feasibility to continue: else-if(in this section)--> if adding the current element and the next element still keeps the sum within d . the function recursively calls itself to consider the next element.
	4.Exclude current elements:
			if ((p + r - s[k] >= d) && (p + s[k + 1] <= d))
		{
			x[k] = 0;
			sumofsub(p, k + 1, r - s[k]);
		} -- here if the current sum plus the remaining elements can still reach d, the function explores the option of excluding the current element by setting x[k]=0 and calling itself with next index.

*/
int main()
{
	int i,n,sum=0;
	printf("\n Enter the n value:");
	scanf("%d",&n);
	printf("\n Enter the set in increasing order:");
	for(i=1;i<=n;i++)
		scanf("%d",&s[i]);
	printf("\n Enter the max subset value:");
	scanf("%d",&d);
	for(i=1;i<=n;i++)
		sum=sum+s[i];
	if(sum<d || s[1]>d)
		printf("\n No subset possible ");
	else
		sumofsub(0,1,sum);
	return 0;
}
/*
- The user is prompted to enter the number of elements n in the set.
- The user inputs the elements of the set S in increasing order.
- The user is prompted to enter the target sum d.
- The total sum of the elements is calculated. If the total sum is less than d or the smallest element is greater than d, it prints " No subset possible"
- If the conditions are satisfied , the sumsub() function is called to find and print all subsets.
*/
/*
	Applications of Subset Sum : cryptography,resource allocation and decision making.
*/