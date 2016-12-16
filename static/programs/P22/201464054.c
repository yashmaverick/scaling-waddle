#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define ll long long int
#define sint(n); scanf("%d",&n);
#define pint(n); printf ("%d\n",n);
#define sll(n); scanf("%lld",&n);
#define pll(n); printf("%lld\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define TEST ll test;scanf("%lld",&test);while(test--)
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
#define f1r(i,n) for(i=n;i>=1;i--)
#define f0r(i,n) for(i=n;i>0;i--)
#define set(x,y) memset(x,y,sizeof(x));
#define mod 1000000007
#define SIZE 200005

/* min heap starts*/

ll heap[SIZE];
ll end;
void insertheap(ll x)
{
	end++;
	heap[end]=x;
	ll currind;
	ll t;
	currind=end;
	while (currind!=1)
	{
		if (heap[currind/2]>heap[currind])
		{
			t=heap[currind/2];
			heap[currind/2]=heap[currind];
			heap[currind]=t;
			currind=currind/2;
		}
		else
			break;
	}
	return;
}
ll delroot()
{
	ll ret;
	ret=heap[1];
	heap[1]=heap[end];
	end--;
	ll currind;
	ll t;
	currind=1;
	while (1)
	{
		if (2*currind>end)
			break;
		if (2*currind == end)
		{
			if (heap[currind]>heap[2*currind])
			{
				t=heap[2*currind];
				heap[2*currind]=heap[currind];
				heap[currind]=t;
				currind=2*currind;
			}
			else
				break;
		}
		else
		{
			if (heap[currind]<=heap[2*currind] && heap[currind]<=heap[(2*currind)+1])
				break;
			else
			{
				if (heap[2*currind]<=heap[(2*currind)+1])
				{
					t=heap[2*currind];
					heap[2*currind]=heap[currind];
					heap[currind]=t;
					currind=2*currind;
				}
				else if (heap[2*currind]>heap[(2*currind)+1])
				{
					t=heap[(2*currind)+1];
					heap[(2*currind)+1]=heap[currind];
					heap[currind]=t;
					currind=(2*currind)+1;
				}
			}
		}
	}
	return ret;
}
void printheap()
{
	ll i;
	printf ("Heap : ");
	for (i=1;i<=end;i++)
		printf ("%lld --> ",heap[i]);
	printf ("\n");
	return;
}
/*min heap ends*/

/*max heap starts*/



ll maxheap[SIZE];
ll maxend;
void insertmaxheap(ll x)
{
	maxend++;
	maxheap[maxend]=x;
	ll currind;
	ll t;
	currind=maxend;
	while (currind!=1)
	{
		if (maxheap[currind/2]<maxheap[currind])
		{
			t=maxheap[currind/2];
			maxheap[currind/2]=maxheap[currind];
			maxheap[currind]=t;
			currind=currind/2;
		}
		else
			break;
	}
	return;
}
ll maxdelroot()
{
	ll ret;
	ret=maxheap[1];
	maxheap[1]=maxheap[maxend];
	maxend--;
	ll currind;
	ll t;
	currind=1;
	while (1)
	{
		if (2*currind>maxend)
			break;
		if (2*currind == maxend)
		{
			if (maxheap[currind]<maxheap[2*currind])
			{
				t=maxheap[2*currind];
				maxheap[2*currind]=maxheap[currind];
				maxheap[currind]=t;
				currind=2*currind;
			}
			else
				break;
		}
		else
		{
			if (maxheap[currind]>=maxheap[2*currind] && maxheap[currind]>=maxheap[(2*currind)+1])
				break;
			else
			{
				if (maxheap[2*currind]>=maxheap[(2*currind)+1])
				{
					t=maxheap[2*currind];
					maxheap[2*currind]=maxheap[currind];
					maxheap[currind]=t;
					currind=2*currind;
				}
				else if (maxheap[2*currind]<maxheap[(2*currind)+1])
				{
					t=maxheap[(2*currind)+1];
					maxheap[(2*currind)+1]=maxheap[currind];
					maxheap[currind]=t;
					currind=(2*currind)+1;
				}
			}
		}
	}
	return ret;
}
void printmaxheap()
{
	ll i;
	printf ("Max Heap : ");
	for (i=1;i<=maxend;i++)
		printf ("%lld --> ",maxheap[i]);
	printf ("\n");
	return;
}

/*max heap ends*/


int main()
{
	TEST{
		ll a,b,c,n,i;
		sll(a);	sll(b);	sll(c);	sll(n);
		if (n==1){pll(n);}
		else
		{
			end=0;	maxend=0;
			ll sum,m,temp;
			sum=1;	insertmaxheap(1);
			f1(i,n){
				if (i==1){continue;}
				if (maxend>=end){m=maxheap[1];}
				else{m=heap[1];}
				temp=(((((a%mod)*(m%mod))%mod)+(((b%mod)*(i%mod))%mod)+(c%mod))%mod);	sum=sum+temp;
				if (temp>heap[1]){insertheap(temp);}
				else{insertmaxheap(temp);}

				if ((maxend-end)>1){insertheap(maxdelroot());}
				else if ((end-maxend)>1){insertmaxheap(delroot());}
			}
			pll(sum);
		}
	}
	return 0;
}
