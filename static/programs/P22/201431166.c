#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007
long long f[200007];
long long int maxcount=0;
long long int mincount=0;
long long int n;
long long int med;
long long int maxh[200007];
long long int minh[200007];
void shuffledownmax(long long int number);
void shuffledownmin(long long int number);

void insertmax(long long int number)
{
	long long int x;
	x=maxcount+1;
	maxh[x]=number;
	long long int parent=x/2,temp;
	while(maxh[parent]<=maxh[x] && x!=1 && parent!=0)
	{
		temp=maxh[x];
		maxh[x]=maxh[parent];
		maxh[parent]=temp;
		parent=parent/2;
		x=x/2;
	}
}

void insertmin(long long int number)
{
	long long int x;
	x=mincount+1;
	minh[x]=number;
	long long int parent=x/2,temp;
	while(minh[parent]>=minh[x] && x!=1 && parent!=0)
	{
		temp=minh[x];
		minh[x]=minh[parent];
		minh[parent]=temp;
		x=x/2;
		parent=parent/2;
	}
}

long long int deletemin()
{
	long long int tmp;
	tmp=minh[1];
	minh[1]=minh[mincount];
	mincount=mincount-1;
	shuffledownmin(minh[1]);
	return tmp;
}

void shuffledownmin(long long int num)
{
	long long int i=1,mini,temp,j;
	while(i<=mincount/2 && (num >= minh[2*i] || num >= minh[2*i+1]) && (2*i+1)<=mincount)
	{
		if(2*i<mincount)
		{
			mini=min(minh[2*i],minh[2*i+1]);
			if(mini==minh[2*i])
				j=2*i;
			else j=2*i+1;
		}
		else 
		{
			mini=minh[2*i];
			j=2*i;
		}	
		temp=mini;
		minh[j]=minh[i];
		minh[i]=temp;
		i=j;
	}
	if(2*i == mincount) 
		if(num>minh[2*i]) 
		{ 
			temp=minh[i]; minh[i]=minh[2*i]; minh[2*i]=temp;
		}
}

long long int deletemax()
{
	long long int tmp;
	tmp=maxh[1];
	maxh[1]=maxh[maxcount];
	maxcount=maxcount-1;
	shuffledownmax(maxh[1]);
	return tmp;
}

void shuffledownmax(long long int num)
{
	long long int i=1,maxim,temp,j;
	while(i<=maxcount/2 && (num <= maxh[2*i] || num <= maxh[2*i+1]) && (2*i+1)<=maxcount)
	{
		if(2*i<maxcount)
		{
			maxim=max(maxh[2*i],maxh[2*i+1]);
			if(maxim==maxh[2*i])
				j=2*i;
			else j=2*i+1;
		}
		else
		{
			maxim=maxh[2*i];
			j=2*i;
		}
		temp=maxim;
		maxh[j]=maxh[i];
		maxh[i]=temp;
		i=j;
	}
	if(2*i == maxcount) if(num<maxh[2*i]) { temp=maxh[i]; maxh[i]=maxh[2*i]; maxh[2*i]=temp;}
}

int min(long long int a,long long int b)
{
	if(a<=b)
		return a;
	return b;
}

int max(long long int a,long long int b)
{
	if(a>=b)
		return a;
	return b;
}

int main()
{
	long long int t;
	scanf("%lld",&t);
	long long int a,b,c;
	while(t--)
	{	maxh[0]=200000000000;
		minh[0]=-1;
		long long int i;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
		maxcount=0;
		mincount=0;
/*		for(i=1;i<=n;i++)
		{
			maxh[i]=0;
			minh[i]=0;
			mincount=0;
			maxcount=0;
		}*/

		long long int l;
		f[1]=1;
		insertmax(f[1]);
		maxcount++;
		for(i=2;i<=n;i++)
		{

			if(maxcount==mincount)
			{
				med=maxh[1];
				f[i]=(((((a*med)%MOD) + ((b*i)%MOD))%MOD +(c%MOD))%MOD)%MOD;
				if(f[i] <= maxh[1])
				{
					insertmax(f[i]);
					maxcount++;
				}
				else 
				{
					insertmin(f[i]);
					mincount++;
				}
			}
			else if(maxcount-mincount==1)
			{
				med=maxh[1];
				f[i]=(((((a*med)%MOD) + ((b*i)%MOD))%MOD +(c%MOD))%MOD)%MOD;
				if(f[i] <= maxh[1])
				{
					insertmax(f[i]);
					maxcount++;
					l=deletemax();
					insertmin(l);
					mincount++;
				}
				else 
				{
					insertmin(f[i]);
					mincount++;
				}
			}
			else if(mincount-maxcount==1)
			{
				med=minh[1];
				f[i]=(((((a*med)%MOD) + ((b*i)%MOD))%MOD +(c%MOD))%MOD)%MOD;
				if(f[i] > minh[1])
				{
					insertmin(f[i]);
					mincount++;
					l=deletemin();
					insertmax(l);
					maxcount++;
				}
				else 
				{
					insertmax(f[i]);
					maxcount++;
				}
			}
		//printf("%d ",mincount-maxcount);
		}
		long long int ans=0;
		for(i=1;i<=n;i++)
			ans=ans+f[i];
		printf("%lld\n",ans);
	}
	return 0;
}
