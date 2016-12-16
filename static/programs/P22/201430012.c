#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MOD 1000000007
#define MAX 200000
long long f;
long long minheap[MAX], maxheap[MAX];
int minitr=0, maxitr=0;

inline void fast(long long *a)
{
	register char c=0;
	while (c<33) c=getchar_unlocked();
	*a=0;
	while (c>33)
	{
		*a=*a*10+c-'0';
		c=getchar_unlocked();
	}
}
void shuffle_up_min(int x)
{
	long long temp;
	while(x>0 && minheap[x/2]>minheap[x])
	{
		temp=minheap[x/2];
		minheap[x/2]=minheap[x];
		minheap[x]=temp;
		x=x/2;
	}
}
void shuffle_down_min(int x)
{
	int p;
	long long temp;
	while((((2*x)<=minitr && minheap[2*x]<minheap[x]) || (((2*x)+1)<=minitr && minheap[(2*x)+1]<minheap[x])))
	{
		if((((2*x)+1)<=minitr)&& minheap[2*x]>minheap[(2*x)+1])
			p=2*x+1;
		else
			p=(2*x);
		temp=minheap[p];
		minheap[p]=minheap[x];
		minheap[x]=temp;
		x=p;
	}
}
void insert_min(long long x)
{
	minheap[++minitr]=x;
	shuffle_up_min(minitr);
}
void delete_min()
{
	minheap[1]=minheap[minitr--];
	shuffle_down_min(1);
}
void shuffle_up_max(int x)
{
	long long temp;
	while(x>0 && maxheap[x/2]>maxheap[x])
	{
		temp=maxheap[x/2];
		maxheap[x/2]=maxheap[x];
		maxheap[x]=temp;
		x=x/2;
	}
}

void shuffle_down_max(int x)
{
	int p;
	long long temp;
	while((((2*x)<=maxitr && maxheap[2*x]<maxheap[x]) || (((2*x)+1)<=maxitr && maxheap[(2*x)+1]<maxheap[x])))
	{
		if((((2*x)+1)<=maxitr) && maxheap[2*x]>maxheap[(2*x)+1])
			p=2*x+1;
		else
			p=(2*x);
		temp=maxheap[p];
		maxheap[p]=maxheap[x];
		maxheap[x]=temp;
		x=p;
	}
}
void insert_max(long long x)
{
	maxheap[++maxitr]=x;
	shuffle_up_max(maxitr);
}
void delete_max()
{
	maxheap[1]=maxheap[maxitr--];
	shuffle_down_max(1);
}
int main()
{
	int t, i;
	long long a,b,c,n,ans,temp1,temp2,temp3,cnt1,cnt2;
	scanf("%d",&t);
	maxheap[0]=-10000000000;minheap[0]=-10000000000;
	//fast(&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		//	fast(&a);fast(&b);fast(&c);fast(&n);
		//	a%=MOD;b%=MOD;c%=MOD;
		maxitr=minitr=0;
		insert_max(-1);
		ans=f=1;
		cnt1=1;
		cnt2=0;
		for(i=2;i<=n;i++)
		{
			temp1=-1*maxheap[1];
//			printf("%lld\n",temp1);
			f=((a*temp1)+(b*i)+c);
			if(f>=MOD) f%=MOD;
			ans=(ans+f);
			if(cnt1>cnt2)
			{
				if(f<temp1)
				{
					delete_max();
					insert_min(temp1);
					insert_max(-1*f);
				}
				else
					insert_min(f);
				cnt2++;
			}
			else
			{
				temp1=minheap[1];
				if(f>temp1)
				{
					delete_min();
					insert_max(-1*temp1);
					insert_min(f);
				}
				else
					insert_max(-1*f);
				cnt1++;
			}
		}
		printf("%lld\n",ans);	
	}
	return 0;
}
