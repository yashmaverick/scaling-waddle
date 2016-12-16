#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int prime[10009];
long long int head,len,level[10009],a[1000009],visited[10009];
void seive()
{
	long long int i,j,k;
	prime[0]=1;
	prime[1]=1;
	for(i=2;i<=100;i++)
	{
		if(!prime[i])
		{
			for(j=(i*i);j<10009;j+=i)
			{
				prime[j]=1;
			}
		}
	}
	return ;
}
void insert(long long int x)
{
	a[(head+len)]=x;
	len++;
}
long long int delete()
{
	long long int p=a[head];
	head++;
	len--;
	return p;
}
int main()
{
	memset(prime,0,sizeof(prime));
	seive();
	long long int i,t,n,x,y[5],j,k,new,m,ans,flag,z[5];
	scanf("%lld",&t);
	while(t--)
	{
		flag=0;
		memset(visited,0,sizeof(visited));
		head=0;
		len=0;
		scanf("%lld %lld",&n,&m);
		insert(n);
//		memset(level,-1,sizeof(level));
		level[n]=0;
		visited[n]=1;
		if(m==n)
		{
			printf("0\n");
			continue;
		}
		while(len>0)
		{
			x=delete();
			for(i=0;i<4;i++)
			{
				y[i]=x%10;
				z[i]=y[i];
				x/=10;
//				printf("%lld ",y[i]);
			}
			x=y[3]*1000+y[2]*100+y[1]*10+y[0];
//			printf("%lld\n",x);
			for(j=0;j<4;j++)
			{
				if(j!=0)
					y[j-1]=z[j-1];
				for(i=0;i<=9;i++)
				{
					y[j]=i;
					if(j==3 && y[j]==0)
						continue;
					new=y[3]*1000+y[2]*100+y[1]*10+y[0];
					if(!prime[new] && (visited[new]==0))
					{
		//				printf("%lld ",new);
						if(new==m)
						{
							flag=1;
							visited[new]=1;
							level[new]=level[x]+1;
							break;
						}
						insert(new);
						level[new]=level[x]+1;
						visited[new]=1;
					}
				}
				if(flag==1)
					break;
			}
			if(flag==1)
				break;
		}
			printf("%lld\n",level[m]);
	}
	return 0;
}
