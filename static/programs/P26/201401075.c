#include<stdio.h>
int primes[10000],ptr=0,ans=20000;
int q[1000000],str,end,visited[1000000],d[1000000];
int func(int n,int m)
{
	visited[n]=1;
	q[0]=n;
	d[n]=0;
	str=0;
	end=1;
	ans=200000000;
	while(str!=end)
	{
		n=q[str];
		int i;
		int t=n;
		t=n-n%10;
		for(i=0;i<10;i++)
		{
			if(t+i>9973)
				break;
			if(primes[t+i]==1 && visited[t+i]!=1)
			{
				q[end]=t+i;
				visited[t+i]=1;
				end++;
				d[t+i]=d[n]+1;
			}
		}
		t=n-n%100+n%10;
		for(i=0;i<100;i+=10)
		{
			if(t+i>9973)
				break;
			if(primes[t+i]==1 && visited[t+i]!= 1)
			{
				q[end]=t+i;
				visited[t+i]=1;
				end++;
				d[t+i]=d[n]+1;
			}
		}
		t=n-n%1000+n%100;
		for(i=0;i<1000;i+=100)
		{
			if(t+i>9973)
				break;
			if(primes[t+i]==1 && visited[t+i] != 1)
			{
				q[end]=t+i;
				visited[t+i]=1;
				end++;
				d[t+i]=d[n]+1;
			}
		}
		t=n%1000;
		for(i=1000;i<10000;i+=1000)
		{
			if(t+i>9973)
				break;
			if(primes[t+i]==1 && visited[t+i] != 1)
			{
				q[end]=t+i;
				visited[t+i]=1;
				end++;
				d[t+i]=d[n]+1;
			}
		}
		if(n==m && d[q[str]]<ans)
		{
			ans=d[q[str]];
			break;
		}
		str++;
	}
	return ans;
}


int main()
{
	int i,j,state;
	i=1001;
	while(i<9999)
	{
		state=1;
		for(j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				state=0;
				break;
			}
		}
		if(state!=0)
		{
			primes[i]=1;
		}
		else
			primes[i]=0;
		i=i+2;
		if(i%5==0)
			i=i+2;
	}//correct
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i;
		for(i=1000;i<10000;i++)
			visited[i]=0;
		int n,m;
		scanf("%d%d",&n,&m);
		ans=func(n,m);
		if(ans==200000000)
			printf("Impossible\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
