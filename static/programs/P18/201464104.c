#include<stdio.h>
#include<stdlib.h>
#define N 1002
int a[N][N],b[N][N],x[N],v[N],v1[N],sum=0;
void zero()
{
        int i,j;
        for(i=0;i<N;i++)
        {
                v[i]=0;
                v1[i]=0;
                x[i]=0;
                for(j=0;j<N;j++)
                {
                        b[i][j]=0;
                        a[i][j]=0;
                }
        }
}
void dfs(int vertex,int n)
{
        sum++;
//        printf("v:%d sum:%d\n",vertex,sum);
        int i;
        v[vertex]=1;
        for(i=1;i<=n;i++)
        {
                if(v[i]==0 && a[vertex][i]==1)
                        dfs(i,n);
        }
}
/*void s(int n)
{
        int i;
        sum=0;
        for(i=1;i<=n;i++)
                if(v[i]==1)
                        sum++;
}*/
/*void s1(int n)
{
        int i;
        sum=0;
        for(i=1;i<=n;i++)
                if(v1[i]==1)
                        sum++;
}*/
void dfs1(int vertex,int n)
{
        sum++;
        int i;
        v1[vertex]=1;
       // printf("%d",vertex);
        for(i=1;i<=n;i++)
                if(v1[i]==0 && b[vertex][i]==1)
                        dfs1(i,n);
}
int main()
{
        int t,n,i,j,tmp;
        scanf("%d",&t);
        while(t--)
        {
                zero();
                scanf("%d",&n);
                for(i=1;i<=n;i++)
                {
                        scanf("%d",&x[i]);
                        for(j=1;j<=x[i];j++)
                        {
                                scanf("%d",&tmp);
                                a[tmp][i]=1;
                                b[i][tmp]=1;
                        }
                }
                for(i=1;i<=n;i++)
                {
                        sum=0;
                        for(j=0;j<=n;j++)
                                v[j]=0;
                        dfs(i,n);
                      //  s(n);
                        if(sum==n)
                                break;
                }
                if(i>n)
                        printf("0\n");
                else
                {
                        sum=0;
                        dfs1(i,n);
                       // s1(n);
                        printf("%d\n",sum);
                }
        }
        return 0;
}
