#include<stdio.h>
#include<stdlib.h>
#define MAX 200009
#define mod 1000000007
long long int sizemin=0,sizemax=0;
long long int minheap[MAX],maxheap[MAX],F[MAX];
void shuffleup_max(long long int x)
{
	long long int temp;
	while(x>0 && maxheap[x/2]<maxheap[x])
	{
		temp=maxheap[x];
		maxheap[x]=maxheap[x/2];
		maxheap[x/2]=temp;
		x=x/2;
	}
}
void shuffledown_max(long long int x)
{
	long long int temp;
	while(1)
	{
		long long int j=2*x;
		if(j>sizemax)
			return;
		if(j+1<=sizemax && maxheap[j+1]>maxheap[j])
			j++;
		if(maxheap[x]<maxheap[j])
		{
			temp=maxheap[x];
			maxheap[x]=maxheap[j];
			maxheap[j]=temp;
			x=j;
		}
		else
			return;
	}
}
void insert_max(long long int x)
{
	maxheap[++sizemax]=x;
	shuffleup_max(sizemax);
}
long long int delete_max()
{
	long long int v=maxheap[1];
	//printf("%lld\n",minheap[1]);
	long long int temp=maxheap[sizemax];
	sizemax--;
	maxheap[1]=temp;
	shuffledown_max(1);
	return v;
}

void shuffleup_min(long long int x)
{
	long long int temp;
	while(x>0 && minheap[x/2]>minheap[x])
	{
		temp=minheap[x];
		minheap[x]=minheap[x/2];
		minheap[x/2]=temp;
		x=x/2;
	}
}
void shuffledown_min(long long int x)
{
	long long int temp;
	while(1)
	{
		long long int j=2*x;
		if(j>sizemin)
			return;
		if(j+1<=sizemin && minheap[j+1]<minheap[j])
			j++;
		if(minheap[x]>minheap[j])
		{
			temp=minheap[x];
			minheap[x]=minheap[j];
			minheap[j]=temp;
			x=j;
		}
		else
			return;
	}
}
void insert_min(long long int x)
{
	minheap[++sizemin]=x;
	shuffleup_min(sizemin);
}
long long int delete_min()
{
	long long int v=minheap[1];
	//printf("%lld\n",minheap[1]);
	long long int temp=minheap[sizemin];
	sizemin--;
	minheap[1]=temp;
	shuffledown_min(1);
	return v;
}

long long int main()
{
	long long int tc,M,i,temp,a,b,c,n,j;
	long long int sum;
	scanf("%lld",&tc);
	while(tc--)
	{
		M=1;
		sum=0;
		sizemin=0,sizemax=0;
		minheap[0]=-mod,maxheap[0]=mod;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		F[1]=1;
		insert_max(1);
		for(i=2;i<n;i++)
		{
			F[i]=((a*M)%mod+(b*i)%mod+c)%mod;
			if(F[i]>M)
			{
				insert_min(F[i]);
				if(sizemin>sizemax+1)
				{
					temp=delete_min();
					insert_max(temp);
				}
			}
			else
			{
				insert_max(F[i]);
				if(sizemax>sizemin+1)
				{
					temp=delete_max();
					insert_min(temp);
				}
			}
		/*	printf("MAx heap:\n");
			for(j=1;j<=sizemax;j++)
				printf("%lld ",maxheap[j]);
			printf("\nMIn heap:\n");
			for(j=1;j<=sizemin;j++)
				printf("%lld ",minheap[j]);
			printf("\n");*/
			if(sizemax<sizemin)
				M=minheap[1];
			else
				M=maxheap[1];
		}
		if(n!=1)
		F[n]=((a*M)%mod+(b*n)%mod+c)%mod;
		for(i=1;i<=n;i++)
		{
		//	printf("%lld ",F[i]);
			sum+=F[i];
		}
		printf("%lld\n",sum);
	}
	return 0;
}

