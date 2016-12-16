#include<stdio.h>
#include<stdlib.h>
int V[1005];
int count;
void dfs(int g[1005][1005],int v,int s[])
{
    V[v]=1;
    count++;
 //   printf("%d ",v);
    int i,j;
    for(i=0;i<s[v];i++)
    {
        if(V[g[v][i]]==0)
            dfs(g,g[v][i],s);
    }
}
int main()
{
    //int* v;
    int i,x,n,j,t,temp;
    scanf("%d",&t);
    int g[1005][1005];
    	int re[1005][1005];
    	int s[1005];
    	int index[1005];
    while(t--)
    {   
    	
    	scanf("%d",&n);
        for(i=1;i<=n;i++)
            V[i]=0;
        count=0;
        
        for(i=1;i<=n;i++)
            index[i]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&s[i]);
            for(j=0;j<s[i];j++)
            {
                scanf("%d",&x);
                re[x][index[x]++]=i;
                g[i][j]=x;
            }
        }
/*        for(i=1;i<=n;i++)
        {
            printf("Adjacent vertices of %d are:\n",i);
            for(j=0;j<s[i];j++)
                printf("%d ",g[i][j]);
            printf("\n");
        }
        printf("Reverse\n");
        for(i=1;i<=n;i++)
        {
            printf("Adjacent vertices of %d are:\n",i);
            for(j=0;j<index[i];j++)
                printf("%d ",re[i][j]);
            printf("\n");
        }*/
//        dfs(re,3,index);
  //      printf("jhdfcs=%d\n",count);
        temp=0;
        for(i=1;i<=n;i++)
        {   
            count=0;
            dfs(re,i,index);
//            printf("count=%d\n",count);
            if(count==n)
            {   
  //              printf("jfh\n");
                temp=i;
                break;
            }
        for(j=1;j<=n;j++)
            V[j]=0;
            
        }
        count=0;
        for(i=1;i<=n;i++)
            V[i]=0;
        if(temp)
        dfs(g,temp,s);
           // printf("\n");
        printf("%d\n",count);
    }
        return 0;
}
