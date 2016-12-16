#include<stdio.h>
#define mod 1000000007

typedef long long int ll;

ll minheap[200005];
ll maxheap[200005];
ll pmax=1;
ll pmin=1;

ll a,b,c,n;

ll min(ll a, ll b )
{
		if( minheap[a]>minheap[b] )
				return b;
		return a;
}

ll max(ll a, ll b )
{
		if( maxheap[a]<maxheap[b] )
				return b;
		return a;
}

void shuffleup(ll pos)
{
		if(minheap[pos/2]>minheap[pos] && pos!=1)
		{
				ll temp;
				temp=minheap[pos/2];
				minheap[pos/2]=minheap[pos];
				minheap[pos]=temp;

				shuffleup(pos/2);
		}   
}

void shuffledown(ll pos)
{
		if(minheap[pos*2]!=0)
		{   
				ll posd=pos*2;
				if(minheap[pos*2+1]!=0)
						posd=min(2*pos,2*pos+1);
				if(minheap[posd]<minheap[pos])
				{
						ll temp;
						temp=minheap[pos];
						minheap[pos]=minheap[posd];
						minheap[posd]=temp;

						shuffledown(posd);
				}
		}

}

void insert(ll num)
{
		minheap[pmin]=num;
		shuffleup(pmin);
		pmin++;
}

ll pop()
{
		ll temp=minheap[1];
		minheap[1]=minheap[pmin-1];
		minheap[pmin-1]=0;
		pmin--;
		shuffledown(1);
		return temp;
}

void mshuffleup(ll pos)
{
		if(maxheap[pos/2]<maxheap[pos] && pos!=1)
		{
				ll temp;
				temp=maxheap[pos/2];
				maxheap[pos/2]=maxheap[pos];
				maxheap[pos]=temp;

				mshuffleup(pos/2);
		}   
}

void mshuffledown(ll pos)
{
		if(maxheap[pos*2]!=0)
		{   
				ll posd=pos*2;
				if(maxheap[pos*2+1]!=0)
						posd=max(2*pos,2*pos+1);
				if(maxheap[posd]>maxheap[pos])
				{
						ll temp;
						temp=maxheap[pos];
						maxheap[pos]=maxheap[posd];
						maxheap[posd]=temp;

						mshuffledown(posd);
				}
		}

}

void minsert(ll num)
{
		maxheap[pmax]=num;
		mshuffleup(pmax);
		pmax++;
}

ll mpop()
{
		ll temp=maxheap[1];
		maxheap[1]=maxheap[pmax-1];
		maxheap[pmax-1]=0;
		pmax--;
		mshuffledown(1);
		return temp;
}

ll func(ll i)
{
		ll temp = ((b%mod*i%mod)%mod+c%mod)%mod;
		ll diff = pmin-pmax;
		ll yo;
		if ( diff ==1)
				yo = minheap[1];
		else
				yo = maxheap[1];
//		printf("yo=%lld	pmax=%lld	pmin=%lld\n",yo,pmax,pmin);
		temp = (temp%mod + (a%mod*yo%mod)%mod)%mod;
		if ( temp < minheap[1] )
		{
//				printf("maxheap\n");
				minsert(temp);
		}
		else
		{
//				printf("minheap\n");
				insert(temp);
		}

//		printf("pmax=%lld pmin=%lld\n",pmax,pmin);

		if( pmin-pmax > 1)
		{
				ll tm=pop();
				minsert(tm);
		}
		else if( pmax-pmin > 1)
		{
				ll tm=mpop();
				insert(tm);
		}

		return temp;
}

int main()
{
		ll test;
		scanf("%lld",&test);
		while( test-- )
		{
				ll sum = 1;
				scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
				ll i;
				pmax=pmin=1;
				for(i=0;i<=n;i++)
				{
						minheap[i]=maxheap[i]=0;
				}
				insert(1);
				for(i=2;i<=n;i++)
				{
						ll lol = func(i);
		//				printf("%lld\n",lol);
						sum=sum+lol;
				}
				printf("%lld\n",sum);
		}
		return 0;
}
