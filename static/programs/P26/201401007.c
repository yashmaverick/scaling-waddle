#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int queue[10005];
int first=0;
int last=0;
int marker[10005];
int dist[10005];
int seive[10005];
inline void push(int n)
{
    queue[last]=n;
    last++;
}
inline void pop()
{
    first++;
}
int array[7];
int bfs(int s,int des)
{
    first=0;
    last=0;
    memset(marker,0,sizeof(marker));
    memset(dist,0,sizeof(dist));
    int i,j,n,cu;
    push(s);
    marker[s]=1;
    dist[s]=0;
    while(first!=last)
    {
	cu=queue[first];
	array[3]=cu%10;
	cu=cu/10;
	array[2]=cu%10;
	cu=cu/10;
	array[1]=cu%10;
	cu=cu/10;
	array[0]=cu%10;
	cu=cu/10;
	for(i=3;i>=0;i--)
	{

	    for(j=0;j<=9;j++)
	    {
		n=queue[first];
		if(i==3)
		{
		    n=array[0]*1000+array[1]*100+array[2]*10+j;
		}
		else if(i==2)
		{
		    n=array[0]*1000+array[1]*100+j*10+array[3];
		}
		else if(i==1)
		{
		    n=array[0]*1000+j*100+array[2]*10+array[3];
		}
		else if(i==0)
		{
		    if(j!=0)
		    {
			n=j*1000+array[1]*100+array[2]*10+array[3];
		    }
		}
		if(seive[n]==0&&marker[n]==0&&((i!=0)||j!=0))
		{
		    push(n);
		    marker[n]=1;
		    dist[n]=dist[queue[first]]+1;
		}
		if(n==des)
		{
		    return dist[des];
		}
	    }
	}
	marker[queue[first]]=2;
	if(queue[first]==des)
	{
	    return dist[des];
	}
	pop();
    }
    return 0;
}
int main()
{
    unsigned long long int i,j,p,l;
    memset(seive,0,sizeof(marker));
    for(i=2;i<=100;i++)
    {
	if(!seive[i])
	{
	    for(j=i*i;j<=10000;j+=i)
		seive[j] = 1;
	}
    }
    int s,d;
    int t,ans;
    scanf("%d",&t);
    while(t--)
    {
	scanf("%d %d",&s,&d);
	if(s==d)
	{
	    printf("0\n");
	}
	else
	{
	    ans=bfs(s,d);
	    if(ans==0)
	    {
		printf("Impossible\n");
	    }
	    else
	    {
		printf("%d\n",ans);
	    }
	}
    }
    return 0;
}
