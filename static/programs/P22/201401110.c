#include<stdio.h>
typedef long long int LL;
long long int a,b,c;
LL n;
LL mod;
LL temp;
LL minheap[200005];
LL maxheap[200005];
LL minsize,maxsize;
LL f[200005];
void insertmin(LL value)
{
	minsize++;
	minheap[minsize]=value;
	LL i=minsize;
	while((i>1 )&&minheap[i]<minheap[i/2])
	{
		LL tempi=minheap[i];
		minheap[i]=minheap[i/2];
		minheap[i/2]=tempi;
		i=i/2;
	}
}
void insertmax(LL value)
{
	maxsize++;
	maxheap[maxsize]=value;
	if(maxsize-1==0)
		return;
	LL i=maxsize;
	while((i>1) && maxheap[i]>maxheap[i/2])
	{
		LL tempi=maxheap[i/2];
		maxheap[i/2]=maxheap[i];
		maxheap[i]=tempi;
		i=i/2;
	}
}
void deletemin()
{
	LL child,i;
	if(minsize==1)
	{
		minsize--;
		return;
	}
	LL last=minheap[minsize];
	minsize--;
	minheap[1]=last;
	for(i=1;i<=minsize/2 && ((minheap[i]>minheap[2*i]) || (minheap[i]>minheap[(2*i)+1] )) ;i=child)
	{
		child=i*2;
		if(child+1<=minsize && minheap[child+1]<minheap[child])
			child++;
		LL tempi=minheap[i];
		minheap[i]=minheap[child];
		minheap[child]=tempi;
	}
}
void deletemax()
{
	LL child,i;
	if(maxsize==1)
	{
		maxsize--;
		return;
	}
	LL last=maxheap[maxsize];
	maxsize--;
	maxheap[1]=last;
	for(i=1;(i<=maxsize/2 && ((maxheap[i]<maxheap[2*i])|| maxheap[i]<maxheap[(2*i)+1]));i=child)
	{
		child=i*2;
		if(child+1<=maxsize && maxheap[child+1]>maxheap[child])
			child++;
		LL tempi=maxheap[i];
		maxheap[i]=maxheap[child];
		maxheap[child]=tempi;
	}
}
LL median()
{
	LL med;
	if(minsize>maxsize)
	{
		med=minheap[1];
	}
	else 
	{
		med=maxheap[1];
	}
	return med;
} 
void update(LL value,LL med)
{
	if(value>med)
	{
		insertmin(value);
	}
	else
	{
		insertmax(value);
	}
	return;
}
void func(LL i,LL med)
{
	LL value=(((a*med)%mod+(b*i)%mod)%mod+c)%mod;
	f[i]=value;
	update(value,med);
	if(minsize>maxsize+1)
	{
		insertmax(minheap[1]);
		deletemin();
	}
	else if(maxsize>minsize+1)
	{
		insertmin(maxheap[1]);
		deletemax();
	}
	return ;
}
void insert()
{
	LL i,p;
	f[1]=1;
	insertmax(1);
	LL med=1;
	for(i=2;i<=n;i++)
	{
		//printf("initial med =%lld\n",med);
		func(i,med);
		med=median();
		//printf("final med =%lld\n",med);
	}
	return ;
}
int main()
{
	LL i;
	LL test,t;
	mod=1000000007;
	scanf("%lld",&test);
	for(t=0;t<test;t++)
	{
		maxsize=minsize=0;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
		insert();
		long long int ssum=1;
		LL j;
		ssum=0;
		for(j=1;j<=n;j++)
		{
			//printf("%lld\n",f[j]);
			ssum = ssum + f[j];
		}
		printf("%lld\n",ssum);
	}
	return 0;
}
