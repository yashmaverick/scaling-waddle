#include<stdio.h>
long long int max[200000],maxsize=0,min[200000],minsize=0;
#define mod 1000000007
void insertmax()
{
	long long int c=maxsize,p=maxsize/2,t;
	while(p>0 && max[p]<max[c])
	{
		t=max[p];
		max[p]=max[c];
		max[c]=t;
		c=p;
		p=c/2;
	}
}
void deletemax()
{
	int t=max[1];
	max[1]=max[maxsize];
	max[maxsize]=t;
	maxsize--;
	int p=1,c=2;
	while(c<=maxsize)
	{
		if(c+1<=maxsize && max[c]<max[c+1])
			c++;
		if(max[p]<max[c])
		{
			t=max[p];
			max[p]=max[c];
			max[c]=t;
		}
		else
			break;
		p=c;
		c=2*p;
	}
}
void insertmin()
{
	long long int c=minsize,p=minsize/2,t;
	while(p>0 && min[p]>min[c])
	{
		t=min[p];
		min[p]=min[c];
		min[c]=t;
		c=p;
		p=c/2;
	}
}
void deletemin()
{
	int t=min[1];
	min[1]=min[minsize];
	min[minsize]=t;
	minsize--;
	int p=1,c=2;
	while(c<=minsize)
	{
		if(c+1<=minsize && min[c]>min[c+1])
			c++;
		if(min[p]>min[c])
		{
			t=min[p];
			min[p]=min[c];
			min[c]=t;
		}
		else
			break;
		p=c;
		c=2*p;
	}
}
int main()
{
	long long int a,b,c,i,n,tc,median,j,t,num,res;
	scanf("%lld",&tc);
	for(i=0;i<tc;i++)
	{
		maxsize=minsize=0;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		max[++maxsize]=1;
		median=max[1];
		res=1;
		for(j=2;j<=n;j++)
		{
			num=(((a*(median%mod))%mod)+(b*j)%mod+c)%mod;
			res+=num;
			if(num>median)
			{
				min[++minsize]=num;
				insertmin();
			}
			else
			{
				max[++maxsize]=num;
				insertmax();
			}
			if(minsize==maxsize+2)
			{
				t=min[1];
				deletemin();
				max[++maxsize]=t;
				insertmax();
			}
			else if(maxsize==minsize+2)
			{
				t=max[1];
				deletemax();
				min[++minsize]=t;
				insertmin();
			}
			if(maxsize>=minsize)
				median=max[1];
			else
				median=min[1];
		}
		printf("%lld\n",res);
	}
	return 0;
}
