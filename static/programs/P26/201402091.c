#include<stdio.h>
#define NUM 10000
int S[10005];
int L[10005];
int V[10005];
int found;
void sieve()
{
    int i,j;
    for(i=0;i<=NUM;i++)
        S[i]=1; 
    S[1]=0;
    S[0]=0;
    for(i=2;i*i<=NUM;i++)
    {
        for(j=i*i;j<=NUM;j+=i)
            S[j]=0;
    }
}
void init()
{
    int i;
    for(i=1000;i<=NUM;i++)
    {
        L[i]=0;
        V[i]=0;
    }
}
int bfs(int src,int des)
{
    int n,j,i,x,temp,st=0,re=0,q[100005],A[5];
    q[re++]=src;
    V[src]=1;
    if(src==des)
    {
        found=1;
        return 0;
    }
    while(st<re)
    {   
        x=q[st++];
        temp=x;
        A[1]=temp%10;
        temp/=10;
        A[2]=temp%10;
        temp/=10;
        A[3]=temp%10;
        temp/=10;
        A[4]=temp%10;
//        printf("%d %d %d %d\n",A[1],A[2],A[3],A[4]);
        for(j=0;j<=9;j++)
        {
            if(j==A[1])
                continue;
            n=1000*A[4]+100*A[3]+10*A[2]+j;
            if(S[n]==1 && V[n]==0)
            {   
                V[n]=1;
                L[n]=L[x]+1;
                if(n==des)
                {
                    found=1;
                    return L[n];
                }
                q[re++]=n;
            }
        }
        for(j=0;j<=9;j++)
        {   
            if(j==A[2])
                continue;
            n=1000*A[4]+100*A[3]+10*j+A[1];
            if(S[n]==1 && V[n]==0)
            {   
                L[n]=L[x]+1;
                V[n]=1;
                if(n==des)
                {
                    found=1;
                    return L[n];
                }
                q[re++]=n;
            }
        }
        for(j=0;j<=9;j++)
        {
            if(j==A[3])
                continue;
            n=1000*A[4]+100*j+10*A[2]+A[1];
            if(S[n]==1 && V[n]==0)
            {   
                V[n]=1;
                L[n]=L[x]+1;
                if(n==des)
                {
                    found=1;
                    return L[n];
                }
                q[re++]=n;
            }
        }
        for(j=1;j<=9;j++)
        {
            if(j==A[4])
                continue;
            n=1000*j+100*A[3]+10*A[2]+A[1];
            if(S[n]==1 && V[n]==0)
            {   
                V[n]=1;
                L[n]=L[x]+1;
                if(n==des)
                {   
                    found=1;
                    return L[n];
                }
                q[re++]=n;
            }
        }
    }   
}
int main()
{   
    sieve();
    int t,ans,src,des;
    scanf("%d",&t);
    while(t--)
    {   
        init();
        found=0;
        scanf("%d%d",&src,&des);
        ans=bfs(src,des);
        if(found==1)
            printf("%d\n",ans);
        else
            printf("Impossible\n");
    }
        return 0;
}
