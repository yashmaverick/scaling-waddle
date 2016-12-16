#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
#define s(n) scanf("%lld",&n)
#define M 1000000007
//ll m[200001];
ll f[200001];
ll maxheap[200001];
ll minheap[200001];
ll s1,s2;

void insertmin(ll x,ll j)
{
	ll t;
	minheap[j]=x;
	if(j>1)
	{
		while(minheap[j]<minheap[j/2] && j>1)
		{
			t=minheap[j];
			minheap[j]=minheap[j/2];
			minheap[j/2]=t;
			j=j/2;
		}
	}
}
void deleteMin()
{
	ll t,temp;
	t=minheap[1];
	minheap[1]=minheap[s2];
	minheap[s2]=t;
	s2=s2-1;
	ll k=1;
	ll j;
	while(2*k<=s2 && (minheap[k]>minheap[2*k] || minheap[k]>minheap[2*k + 1]))
	{
		j=2*k;
		if(2*k!=s2 && minheap[2*k+1]<minheap[2*k])
			j++;
		if(minheap[k]>minheap[j])
		{
			t=minheap[k];minheap[k]=minheap[j];minheap[j]=t;
		}
		k=j;
	}
	//return min;
}
void insertmax(ll x,ll j)
{
	ll t;
	maxheap[j]=x;
	if(j>1)
	{
		while(maxheap[j]>maxheap[j/2] && j>1)
		{
			t=maxheap[j];
			maxheap[j]=maxheap[j/2];
			maxheap[j/2]=t;
			j=j/2;
		}
	}
}
void deleteMax()
{
	ll t,temp;
	t=maxheap[1];
	maxheap[1]=maxheap[s1];
	maxheap[s1]=t;
	s1=s1-1;
	ll k = 1;
	ll j;
	while(2*k<=s1 && ((maxheap[k]<maxheap[2*k] || maxheap[k]<maxheap[2*k+1])))
	{
		j=2*k;
		if(2*k!=s1 && maxheap[2*k+1]>maxheap[2*k])
			j++;
		if(maxheap[k]<maxheap[j])
		{
			temp=maxheap[k];maxheap[k]=maxheap[j];maxheap[j]=temp;
		}
		k=j;
	}
}

int main()
{
	ll t;s(t);
	while(t--)
	{
		s1 = s2 = 0;
		ll a,b,c,n;
		ll i,sum;
		s(a);s(b);s(c);s(n);
		for(i=0;i<200001;i++)
		{
			f[i]=0;
			maxheap[i]=0;
			minheap[i]=0;
		}
		ll med;
		f[1]=1;
		if(n==1)
			printf("%lld\n",f[1]);
		else
		{
			s1++;
			insertmax(1,s1);
			for(i=2;i<=n;i++)
			{
				if(s2>s1)
					med=minheap[1];
				else
					med = maxheap[1];
				//		printf("Median at this stage is: %lld\n",med);
				f[i] = ((a*med) + (b*i) + c)%M;  // check for mod 
				//	   	printf("f(%lld) = %lld\n",i,f[i]);
				if(f[i]>=maxheap[1])
				{
					s2++;
					insertmin(f[i],s2);
				}
				else if(f[i]<maxheap[1])
				{
					s1++;
					insertmax(f[i],s1);
				}
				if(s2-s1>1)
				{
					s1++;
					insertmax(minheap[1],s1);
					deleteMin();
				}
				else if(s1-s2>1)
				{
					s2++;
					insertmin(maxheap[1],s2);
					deleteMax();
				}
			}
			sum = 1;
			for(i=2;i<=n;i++)
			{
				sum+=f[i];
				//sum = sum%M;
			}	//optional mod here???
			//	    printf("FINAL ANSWER:\n");
			printf("%lld\n",sum);
		}
	}
	return 0;
}
