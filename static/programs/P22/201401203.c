#include<stdio.h>
#include<stdlib.h>
#define ll long long int

ll heap1[200001],heap2[200001];//heap1 max heap2 min
ll c;
   int k1,k2;
ll m,mod=1000000007;
int max(int a,int b)
{
	return a>b?a:b;
}
void deletemax()
{
	int p,y;
	p=1;
	heap1[p]=heap1[k1];
	k1--;
	while(2*p+1<=k1)
	{

		if(heap1[2*p]>heap1[2*p+1])
			y=2*p;
		else
			y=2*p+1;
		if(heap1[p]<heap1[y])
		{
			c=heap1[p];
			heap1[p]=heap1[y];
			heap1[y]=c;
		}
		else 
			break;
		p=y;
	}
	if(2*p<=k1)
	{
		if(heap1[2*p]>heap1[p])
		{
			c=heap1[2*p];
			heap1[2*p]=heap1[p];
			heap1[p]=c;
		}
	}
}

void deletemin()
{
	int p,y;
	p=1;
	heap2[p]=heap2[k2];
	k2--;
	while(2*p+1<=k2)
	{

		if(heap2[2*p]<heap2[2*p+1])
			y=2*p;
		else
			y=2*p+1;
		if(heap2[p]>heap2[y])
		{
			c=heap2[p];
			heap2[p]=heap2[y];
			heap2[y]=c;
		}
		else
			break;
		p=y;
	}
	if(2*p<=k2)
	{
		if(heap2[2*p]<heap2[p])
		{
			c=heap2[2*p];
			heap2[2*p]=heap2[p];
			heap2[p]=c;
		}
	}
}

void insert2(int i)
{
	int p;

	heap2[k2]=i;
	p=k2;
	while(p>1&&heap2[p/2]>heap2[p])
	{
		c=heap2[p];
		heap2[p]=heap2[p/2];
		heap2[p/2]=c;
		p=p/2;
	}
	return;
}

void insert1(int i)//maxheap
{
	int p;

	heap1[k1]=i;
	p=k1;
	while(p>1&&heap1[p/2]<heap1[p])
	{
		c=heap1[p];
		heap1[p]=heap1[p/2];
		heap1[p/2]=c;
		p=p/2;
	}
	return;
}


int main()
{
	ll a,b,e,sum,pv,y;
	ll t,i,n;
	scanf("%lld",&t);
	while(t--)
	{
		k1=0;k2=0;
		sum=0;
		scanf("%lld %lld %lld %lld",&a,&b,&e,&n);
		heap1[1]=1;
		sum+=1;
		k1=1;
		for(i=2;i<=n;i++)
		{
			//finding median
			if(k1>=k2)
				m=heap1[1];
			else
				m=heap2[1];
			//inserting f[k]
			pv=((a*m)%mod+(b*i)%mod+e)%mod;
			if(k1>k2)
			{
				if(heap1[1]<=pv)
				{
				//	printf("a %lld\n",pv);
					k2++;
					insert2(pv);
				}
				else
				{
				//	printf("b %lld\n",pv);
					y=heap1[1];
					deletemax();
					k2++;
					insert2(y);
					k1++;
					insert1(pv);
				}
			}
			else if(k1<k2)
			{
				if(pv<=heap2[1])
				{
				//	printf("c %lld\n",pv);
					k1++;
					insert1(pv);
				}
				else
				{
				//	printf("d %lld\n",pv);
					y=heap2[1];
					deletemin();
					k1++;
					insert1(y);
					k2++;
					insert2(pv);
				}
			}
			else if(k1==k2)
			{
				if(pv<=heap2[1])
				{
				//	printf("e %lld\n",pv);
					k1++;
					insert1(pv);
				}
				else
				{
				//	printf("f %lld\n",pv);
					k2++;
					insert2(pv);
				}
			}
		/*	printf("heap1\n");
			for(j=1;j<=k1;j++)
				printf("%lld ",heap1[j]);
			printf("\n");
			printf("heap2\n");
			for(j=1;j<=k2;j++)
				printf("%lld ",heap2[j]);
			printf("\n");
		*/	sum+=pv;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
