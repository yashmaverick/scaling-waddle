//GABBAR STUDIOWORKS
//9 APR 2015
//DS class
#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
#define mod 1000000007
ll sum;
ll minheap[200004];
ll maxheap[200004];
ll minhead=1;
ll maxhead=1;
ll jhanda=0;
ll flag=0;
ll nodemax=0;
ll nodemin=0;
void deletemin(ll i)
{
	ll temp;
	minheap[i]=minheap[minhead-1];
	minheap[minhead-1]=9999999999;
	minhead--;
	//now to check whether the new heap maintains the property
	while((minheap[i]>minheap[2*i] || minheap[i]>minheap[2*i+1])&&(2*i)<=minhead-1)
	{
		//swap heap[i] & heap[2*i+1]
		if(minheap[2*i]>minheap[2*i+1])
		{
			temp=minheap[i];
			minheap[i]=minheap[2*i+1];
			minheap[2*i+1]=temp;
			i=2*i+1;
		}
		else
		{
			temp=minheap[i];
			minheap[i]=minheap[2*i];
			minheap[2*i]=temp;
			i=2*i;
		}
		
	}
}
void deletemax(ll i)
{
	ll temp;
	maxheap[i]=maxheap[maxhead-1];
	maxheap[maxhead-1]=-1;
	maxhead--;
	//now to check whether the new heap maintains the property
	while((maxheap[i]<maxheap[2*i] || maxheap[i]<maxheap[2*i+1])&&(2*i)<=maxhead-1)
	{
		//swap heap[i] & heap[2*i+1]
		if(maxheap[2*i]<maxheap[2*i+1])
		{
			temp=maxheap[i];
			maxheap[i]=maxheap[2*i+1];
			maxheap[2*i+1]=temp;
			i=2*i+1;
		}
		else
		{
			temp=maxheap[i];
			maxheap[i]=maxheap[2*i];
			maxheap[2*i]=temp;
			i=2*i;
		}
		
	}
}
void insertmin(ll p)
{
	if(flag==0)
	{
		minheap[minhead++]=p;
		flag=1;

	}
	else
	{
		ll j,temp;
		minheap[minhead]=p;
		j=minhead;
		while(minheap[j]<minheap[j/2] && j>1)
		{
			//	swap(heap[j],heap[j/2]);
			temp=minheap[j];
			minheap[j]=minheap[j/2];
			minheap[j/2]=temp;
		
			j=j/2;
		}
		minhead++;
	}
}
void insertmax(ll p)
{
	if(jhanda==0)
	{
		maxheap[maxhead++]=p;
		jhanda=1;

	}
	else
	{
		ll j,temp;
		maxheap[maxhead]=p;
		j=maxhead;
		while(maxheap[j]>maxheap[j/2] && j>1)
		{
			//	swap(heap[j],heap[j/2]);
			temp=maxheap[j];
			maxheap[j]=maxheap[j/2];
			maxheap[j/2]=temp;
			j=j/2;
		}
		maxhead++;
	}
}
int main()
{
	ll test,i,x;
	scanf("%lld",&test);
	while(test--)
	{
		ll n,t,mdn,a,b,c;
		nodemin=0;
		nodemax=0;
		minhead=1;
		maxhead=1;
		flag=0;
		jhanda=0;
		
		//	printf("enter t5he no. of elements you want to enter\n");
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		for(i=1;i<=n;i++)
		{
			minheap[i]=9999999999;
			maxheap[i]=-1;
		}
		insertmax(1);
		nodemax++;
		ll temp=0;
		sum=1;
		for(i=2;i<=n;i++)
		{
			if(nodemax>nodemin)
				mdn=maxheap[1];
			else if(nodemin>nodemax)
				mdn=minheap[1];
			else
				mdn=maxheap[1];
			/*f[2]*/temp=((a*mdn)%mod+(b*i)%mod+c)%mod;
			sum=sum+temp;
			if(temp>=maxheap[1])
			{
				insertmin(temp);
				nodemin++;
			}
			else
			{
				insertmax(temp);
				nodemax++;
			}
			if(nodemax-nodemin>1)
			{
				ll tst=maxheap[1];
				deletemax(1);//index-1
				nodemax--;
			//	maxhead--;
				insertmin(tst);//value temp
				nodemin++;
			}
			else if(nodemin-nodemax>1)
			{
				ll tst=minheap[1];
				deletemin(1);
				nodemin--;
			//	minhead--;
				insertmax(tst);
				nodemax++;
			}
		}
		printf("%lld\n",sum);
	/*	for(i=1;i<=nodemin;i++)
			printf("%lld--",minheap[i]);
		printf("\n");
		for(i=1;i<=nodemax;i++)
			printf("%lld--",maxheap[i]);
		printf("\n");
*/
	}
	return 0;
}

