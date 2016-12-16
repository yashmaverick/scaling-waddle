#include <stdio.h>
long long int c[200010],count=0;
void max_in(long long int n)
{
	count++;
	c[count]=n;
	long long int w=count;
	while(c[w]>c[w/2] && w > 1)
	{
		long long int t=c[w];
		c[w]=c[w/2];
		c[w/2]=t;
		w=w/2;
	}
}

long long int max1(long long int re,long long int rt)
{
	if(re>rt)
		return re;
	else
		return rt;
}

void max_del()
{
	c[1]=c[count];
	count--;
	long long int i=1,ind;
	while( max1(c[2*i],c[2*i+1]) > c[i])
	{
		if(c[2*i]>c[2*i+1])
			ind=2*i;
		else
			ind=2*i+1;
		if(ind>count)
			break;
		long long int t=c[ind];
		c[ind]=c[i];
		c[i]=t;
		i=ind;
	}
}

long long int b[200010],countmin=0;
void min_in(long long int n)
{
	countmin++;
	b[countmin]=n;
	long long int w=countmin;
	while(b[w]<b[w/2] && w>1)
	{
		long long int t=b[w];
		b[w]=b[w/2];
		b[w/2]=t;
		w=w/2;
	}
}


long long int min1(long long int re,long long int rt)
{
	if(re > rt)
		return rt;
	else
		return re;
}
void min_del()
{
	b[1]=b[countmin];
	countmin--;
	long long int i=1,ind;
	while( min1(b[2*i],b[2*i+1]) < b[i])
	{
		if(b[2*i]< b[2*i+1])
		{
			ind=2*i;
		}
		else
			ind=2*i+1;
		if(ind>countmin)
			break;
		long long int t=b[ind];
		b[ind]=b[i];
		b[i]=t;
		i=ind;
	}
}

void blank(long long int n,long long int f[])

{
	int i;
	for(i=1;i<=n;i++)
	{
		f[i]=0;
		b[i]=0;
		c[i]=0;
	}
}
int main()
{
	int jaa,test;
	scanf("%d",&test);
	for(jaa=0;jaa<test;jaa++)
	{
		long long int a1,b1,c1,n,i,f[200010],q,m,sum=1;		
		scanf("%lld %lld %lld %lld",&a1,&b1,&c1,&n);
		blank(n,f);
		countmin=0;
		count=0;
		f[1]=1;
		for(i=2;i<=n;i++)
		{
			if(i==2)
			{
				max_in(f[1]);
			}
			else
			{
				if(f[i-1]>c[1])
					min_in(f[i-1]);
				else
					max_in(f[i-1]);
				if(countmin > count+1)
				{
					q=b[1];
					min_del();
					max_in(q);
				} 
				else if(count > countmin +1)
				{
					q=c[1];
					max_del();
					min_in(q);
				}
			}
			if(countmin>count)
				m=b[1];
			else //if(count> countmin)
				m=c[1];
			f[i]=(((a1*m)%1000000007+(b1*i)%1000000007)%1000000007+c1)%1000000007;
			sum+=f[i];
		}
		printf("%lld\n",sum);
	}
	return 0;
}
