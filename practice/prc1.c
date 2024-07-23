#define INF 999
#define MAX 100
#include <stdio.h>
int p[MAX],c[MAX][MAX],t[MAX][2];
int find(int v){
    while (p[v])
    {
        v=p[v];
    }
    return v; //returns the root parent of a vertex v by following parent pointer.
}
void union1(int i, int j){
    p[j]=i;
    // makes j child of i
}

void kruskal(int n){
    int i,j,k,u,v,min,res1,res2,sum=0;
    for (k=1; k <n; k++)
    {
        min=INF;
        for(i=1;i<n-1;i++){
            for(j=1;j<=n;j++){
                if(i==j)continue;
                if(c[i][j]<min){
                    u=find(i);
                    v=find(j);
                    if(u!=v){
                        res1=i;
                        res2=j;
                        min=c[i][j];
                    }
                }
            }
        }
        union1(res1,find(res2));
        t[k][1]=res1;
        t[k][2]=res2;
        sum+=min;

    }
    printf("The minimum cost of spanning tree is=%d",sum);
    printf("The edges of spanning tree are :");
    for (i = 1; i < n; i++)
        
        printf("%d--> %d \n ",t[i][1],t[i][2]);
    
}

int main(){
    int i,j,n;
    printf("\n Enter the n value:");scanf("%d", &n);
    for ( i = 1; i <=n; i++)
    {
        p[i]=0;
    }
    printf("\n Enter the graph data: \n");
    for ( i = 1; i <=n; i++)
    {
        for (j = 0; j <=n; j++)
        {
            scanf("%d",&c[i][j]);
        }
        
    }
    kruskal(n);
    return 0;
    
    

}