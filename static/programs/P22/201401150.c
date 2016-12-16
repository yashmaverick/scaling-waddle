#include <stdio.h>
#include <limits.h>
#define MAX 200007
#define MOD 1000000007
#define s(n) scanf("%lld",&n)
#define ll long long
ll M[MAX],F[MAX],maxHeapSize,minHeapSize,curMedian,minH[MAX],maxH[MAX];

void printheaps()
{
	int i;
	printf("MAX:\n");
	for(i=1;i<=maxHeapSize;i++)
		printf("%lld ",maxH[i]);
	printf("\n");
	printf("MIN:\n");
	for(i=1;i<=minHeapSize;i++)
		printf("%lld ",minH[i]);
	printf("\n");
}

void insertMin(ll x)
{
	//printf("insertMin\n");
	if(minHeapSize==0)
	{
		minH[1]=x;
		minHeapSize++;
	}
	else
	{
		minHeapSize++;
		int i;
		for(i=minHeapSize;x<minH[i/2];i/=2)
			minH[i]=minH[i/2];
		minH[i]=x;
	}
}

void insertMax(ll x)
{
	//printf("insertMax\n");
	if(maxHeapSize==0)
	{
		maxH[1]=x;
		maxHeapSize++;
	}
	else
	{
		maxHeapSize++;
		int i;
		for(i=maxHeapSize;x>maxH[i/2];i/=2)
			maxH[i]=maxH[i/2];
		maxH[i]=x;
	}
}

void swap(ll A[],int i,int j)
{
	ll t=A[i];
	A[i]=A[j];
	A[j]=t;
}

void delete_min()
{
	ll bot=minH[minHeapSize--];
	//M[1]=bot;
	int i,j;
	for(i=1;2*i<=minHeapSize;i=j)
	{
		j=2*i;
		if(j!=minHeapSize && minH[j+1]<minH[j])
			j++;
		if(bot>minH[j])
			minH[i]=minH[j];
		else
			break;
	}
	minH[i]=bot;
}

void delete_max()
{
	ll bot=maxH[maxHeapSize--];
	//M[1]=bot;
	int i,j;
	for(i=1;2*i<=maxHeapSize;i=j)
	{
		j=2*i;
		if(j!=maxHeapSize && maxH[j+1]>maxH[j])
			j++;
		if(bot<maxH[j])
			maxH[i]=maxH[j];
		else
			break;
	}
	maxH[i]=bot;
}

ll peek(ll M[])
{
	return M[1];
}

ll OLmedian(ll newElem)
{
	if(maxHeapSize==0 && minHeapSize==0)
		insertMax(newElem);
	else
	{
		if(newElem>curMedian)
			insertMin(newElem);
		else
			insertMax(newElem);
		if(minHeapSize-maxHeapSize>1)
		{
			insertMax(peek(minH));
			delete_min();
		}
		else if(maxHeapSize-minHeapSize>1)
		{
			insertMin(peek(maxH));
			delete_max();
		}
	}
	ll median = (minHeapSize>maxHeapSize) ? peek(minH):peek(maxH);
	curMedian=median;
	return median;
}

ll Fsum(ll a,ll b,ll c,ll n)
{
	if(n==1)
		return 1;
	ll FS,m;
	FS=1;
	int i;
	//insertMax(1);
	//m=1;
	for(i=2;i<=n;i++)
	{
		m=OLmedian(F[i-1]);
		//printheaps();
		//printf("MI : %lld, i: %d\n",m,i);
		F[i]=(a*m + b*i + c)%MOD;
		//printf("Fi: %lld, FS:%lld\n",F[i],FS);
	};
	for(i=2;i<=n;i++)
		FS+=F[i];
	return FS;
}

void init()
{
	minHeapSize=maxHeapSize=0;
}



int main()
{
	maxH[0]=LLONG_MAX;
	minH[0]=LLONG_MIN;
	ll t,a,b,c,n,i,j;
	s(t);F[1]=1;
	for(i=0;i<t;i++)
	{
		s(a);s(b);s(c);s(n);

		printf("%lld\n",Fsum(a,b,c,n));

		init();
	}


	return 0;
}