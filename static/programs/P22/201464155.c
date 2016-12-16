#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long int
#define sc(x) scanf("%lld",&x);

ll heap[1000005]={0},end=0,newend=0,newheap[1000005]={0};

ll min(ll i,ll k)
{
	if(heap[i]<heap[k])
		return i;
	else
		return k;
}
ll max(ll i,ll k)
{
	if(newheap[i]>newheap[k])
		return i;
	else
		return k;
}
void insertmin(ll x)
{
//	printf("111\n");
	end++;
	heap[end]=x;
	ll last=end;
	//ll j=last/2;
	while(x<heap[last/2]&&last/2!=0)
	{
		heap[last]=heap[last/2];
		last=last/2;
	}
	heap[last]=x;
	return;
}

void insertmax(ll x)
{
//	printf("222");
	newend++;
	newheap[newend]=x;
	ll last=newend;
	//ll j=last/2;
	//if(newend!=1){
	while(x>newheap[last/2]&&last/2!=0)
	{
		newheap[last]=newheap[last/2];
		last=last/2;
	}
	newheap[last]=x;//}
return;
}

ll deletemin()
{
	//printf("333333333\n");
	ll x=heap[end],child;
	end--;
	ll w=heap[1];
	heap[1]=x;
	ll j=1;
	for(j=1;j*2<=end;j=child)
	{ //printf("5");
		//printf("%lld\n",heap[j*2]);
		child=j*2;
		if(child!=end&&heap[child+1]<heap[child])
			child++;
		if(x>heap[child])
			heap[j]=heap[child];
		else
			break;
	}
	heap[j]=x;
	return w;
}
ll deletemax()
{
	ll x=newheap[newend],child;
	newend--;
	ll w=newheap[1];
	newheap[1]=x;
	ll j=1;
	for(j=1;j*2<=newend;j=child)
	{ //printf("5");
		//printf("%lld\n",heap[j*2]);
		child=j*2;
		if(child!=newend && newheap[child+1]>newheap[child])
			child++;
		if(x<newheap[child])
			newheap[j]=newheap[child];
		else
			break;
	}
	newheap[j]=x;
	return w;
}

int main()
{
	ll t;
	sc(t);
	//newheap[0]=1000000007;
	while(t--)
	{
		end=0;
		newend=0;
		ll a,b,c,n;
		ll i,j,sum=1;
		sc(a);
		sc(b);
		sc(c);
		sc(n);
		newheap[0]=1000000007;
		heap[0]=-1;
		ll mod=1000000007;
		insertmax(1);
			/*for(j=1;j<=end;j++)
				printf("%lld ",heap[j]);
			printf("\nMAX\n");
			for(j=1;j<=newend;j++)
				printf("%lld ",newheap[j]);
			printf("\n");*/
		ll median,d;
		for(i=2;i<=n;i++)
		{

			if(newend>=end)
				median=newheap[1];
			else
				median=heap[1];
			//printf("Here\n");
			d=((((a*(median%mod))%mod+((i)*b)%mod)%mod)+c)%mod;
			sum=(sum+d);
			/*while(sum<0)
			  sum=sum+mod;
			  if(sum<0)*/
		//	printf("D=%lld\n",d);
			if(d<=newheap[1])
			{
				//printf("HERE\n");
				insertmax(d);
			}
			else
			{
				//printf("THERE\n");
				insertmin(d);
			}

			if(newend-end>1)
			{
				ll p=deletemax();
				insertmin(p);
			}
			/*for(j=1;j<=end;j++)
			  printf("Check : %lld ",heap[j]);
			  printf("\n");*/
			else if(end-newend>1)
			{
				//printf("Check above\n");
				ll p=deletemin();
				//printf("Check below\n");
				insertmax(p);

			}


			/*printf("Median : %lld\nMIN\n",median);
			for(j=1;j<=end;j++)
				printf("%lld ",heap[j]);
			printf("\nMAX\n");
			for(j=1;j<=newend;j++)
				printf("%lld ",newheap[j]);
			printf("\n");*/
			//printf("%lld %lld\n",heap[0],newheap[0]);

		}
		printf("%lld\n",sum);
		/*for(i=0;i<=200000;i++)
		  {
		  heap[i]=-1;
		  newheap[i]=-1;
		  }*/
	}
	return 0;
}

