#include<stdio.h>
#define MOD 1000000007
long long minheap[1000006],maxheap[1000006],minfront=0,maxfront=0;
long long mindeleteheap()
{
	long long temp,delel;
	long long newcrap;
	//printf("deled el is %d\n",heap[1]);
	delel=minheap[1];
	temp=minheap[minfront];
	minfront--;
	long long crap=1;
	for(crap=1;2*crap<=minfront;crap=newcrap)
	{
		newcrap=crap*2;
		if(newcrap!=minfront&&minheap[newcrap+1]<minheap[newcrap])
			newcrap++;
		if(temp> minheap[newcrap])
			minheap[crap]=minheap[newcrap];
		else
			break;
	}
	minheap[crap]=temp;
	//printf("about to return\n");
	return delel;
}
void minheapinsert(long long x)
{
	minfront++;
	minheap[minfront]=x;
	long long t=minfront;
	while(minheap[t/2]>minheap[t]&&(t/2)!=0)
	{
		int temp;
		temp=minheap[t/2];
		minheap[t/2]=minheap[t];
		minheap[t]=temp;
		t=t/2;
	}
}
long long maxdeleteheap()
{
	long long temp,delel;
	long long newcrap;
	//printf("deled el is %d\n",heap[1]);
	delel=maxheap[1];
	temp=maxheap[maxfront];
	maxfront--;
	long long crap=1;
	for(crap=1;2*crap<=maxfront;crap=newcrap)
	{
		newcrap=crap*2;
		if(newcrap!=maxfront&&maxheap[newcrap+1]>maxheap[newcrap])
			newcrap++;
		if(temp< maxheap[newcrap])
			maxheap[crap]=maxheap[newcrap];
		else
			break;
	}
	maxheap[crap]=temp;
	//printf("about to return\n");
	return delel;
}
void maxheapinsert(long long x)
{
	maxfront++;
	maxheap[maxfront]=x;
	long long t=maxfront;
	while(maxheap[t/2]<maxheap[t]&&(t/2)!=0)
	{
		long long temp;
		temp=maxheap[t/2];
		maxheap[t/2]=maxheap[t];
		maxheap[t]=temp;
		t=t/2;
	}
}
int main()
{
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		long long temp,i,a,b,c,el,n;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
		maxfront=0,minfront=0;
		maxheapinsert(1);
		long long flag=1,sum=1;
	//	printf("%d\n",n);
		for(i=2;i<=n;i++)
		{
	//		printf("eneteretf\n");
			if(flag>0)
			{
				temp=(((a*maxheap[1])%MOD)+((b*i)%MOD)+c)%MOD;
				sum=sum+temp;
				//printf("%d\n",sum);
				if(temp<maxheap[1])
				{
					maxheapinsert(temp);
					el=maxdeleteheap();
					minheapinsert(el);
				}
				else
				{
					minheapinsert(temp);
				}
				flag*=-1;
			}
			else
			{
				temp=(((a*maxheap[1])%MOD)+((b*i)%MOD)+c)%MOD;
				sum=sum+temp;
				//printf("%d\n",sum);
				if(temp<maxheap[1])
				{
					maxheapinsert(temp);
				}
				else
				{
					minheapinsert(temp);
					el=mindeleteheap();
					maxheapinsert(el);
				}
				flag*=-1;

			}
			
		}
		printf("%lld\n",sum);
	}
	return 0;
}
