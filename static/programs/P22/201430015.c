#include<stdio.h>
long long int maxheap[1000000],nmaxheap;
long long int minheap[1000000],nminheap;
void supmax(long long int p)
{
	long long int temp,i;
	i=p;
	while(maxheap[i]>maxheap[i/2])
	{
		if(i==1)
		{
			break;
		}
		temp=maxheap[i];
		maxheap[i]=maxheap[i/2];
		maxheap[i/2]=temp;
		i=i/2;
	}
}
void sdownmax(long long int p)
{
	long long int i,temp;
	i=p;
	if(2*i>nmaxheap)
	{
		return;
	}
	else
	{
		while((maxheap[i]<maxheap[2*i])||(maxheap[i]<maxheap[2*i+1]))
		{
			if(maxheap[2*i]>maxheap[2*i+1])
			{
				temp=maxheap[2*i];
				maxheap[2*i]=maxheap[i];
				maxheap[i]=temp;
				i=2*i;
			}
			else
			{
				temp=maxheap[2*i+1];
				maxheap[2*i+1]=maxheap[i];
				maxheap[i]=temp;
				i=2*i+1;
			}
			if(2*i>nmaxheap)
			{
				break;
			}
		}
	}

}

long long int remmax()
{
	long long int val;
	val=maxheap[1];
	maxheap[1]=maxheap[nmaxheap];
	nmaxheap=nmaxheap-1;
	sdownmax(1);
	return val;
}
void supmin(long long int p)
{
	long long int temp,i;
	i=p;
	while(minheap[i]<minheap[i/2])
	{
		if(i==1)
		{
			break;
		}
		temp=minheap[i];
		minheap[i]=minheap[i/2];
		minheap[i/2]=temp;
		i=i/2;
	}
}
void sdownmin(long long int p)
{
	long long int i,temp;
	i=p;
	if(2*i>nminheap)
	{
		return;
	}
	else
	{
		while((minheap[i]>minheap[2*i])||(minheap[i]>minheap[2*i+1]))
		{
			if(minheap[2*i]<minheap[2*i+1])
			{
				temp=minheap[2*i];
				minheap[2*i]=minheap[i];
				minheap[i]=temp;
				i=2*i;
			}
			else
			{
				temp=minheap[2*i+1];
				minheap[2*i+1]=minheap[i];
				minheap[i]=temp;
				i=2*i+1;
			}
			if(2*i>nminheap)
			{
				break;
			}
		}
	}

}

long long int remmin()
{
	long long int val;
	val=minheap[1];
	minheap[1]=minheap[nminheap];
	nminheap=nminheap-1;
	sdownmin(1);
	return val;
}

void insert_max(long long int x)
{
	nmaxheap=nmaxheap+1;
	maxheap[nmaxheap]=x;
	supmax(nmaxheap);
}

void insert_min(long long int x)
{
	nminheap=nminheap+1;
	minheap[nminheap]=x;
	supmin(nminheap);
}
void dis1()
{
	long long int i;
	for(i=1;i<=nmaxheap;i++)
		printf("%lld ",maxheap[i]);
	printf("\n");
}

void dis2()
{
	long long int i;
	for(i=1;i<=nminheap;i++)
		printf("%lld ",minheap[i]);
	printf("\n");
}

long long int median;
int main()
{
	long long int a,b,c,n,i,sum,f,mod;
	int test;
	scanf("%d",&test);
	while(test--)
	{
		nmaxheap=0;
		nminheap=0;
		mod=1000000007;
		median=1;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
		sum=1;
		for(i=2;i<=n;i++)
		{	
			f=((a*median)+(b*i)+c)%mod;
			sum+=f;
			if(f<median)
			{
				insert_max(f);
			}
			else 
			{
				insert_min(f);
			}
			if((nmaxheap-nminheap)>0)
			{
				insert_min(median);
				median=remmax();
			}
			else if((nmaxheap-nminheap)<-1)
			{
				insert_max(median);
				median=remmin();
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
