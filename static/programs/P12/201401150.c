#include <stdio.h>
#define ll long long
#define stack struct stack
#define s(n) scanf("%lld",&n)
stack
{
	ll array[100001], tp;
};

void stackinit(stack *S)
{
	S->tp=-1;
}

int empty(stack* S)
{
	if(S->tp==-1)
		return 1;
	else
		return 0;
}
void push(stack* S,ll a)
{
	//if(tp==MAX-1)
	//	return -1;
	S->tp++;
	S->array[S->tp]=a;
	//return S;
}
void pop(stack* S)
{
	S->tp--;
	//return S;
}
ll top(stack* S)
{
	return S->array[S->tp];
}

ll beforetop(stack* S)
{
	if(S->tp-1<0)
		return -1;
	return S->array[S->tp-1];
}

ll nCr(ll n,ll r)
{
    ll ans=1;
    r=r>n-r?n-r:r;
    ll j;
    for(j=1;j<=r;j++,n--)
    {
        if(n%j==0)        
            ans*=n/j;
        else if(ans%j==0)
            ans=ans/j*n;
        else        
            ans=(ans*n)/j;      
    }
    return ans;
}

int main()
{	
	ll N,i,M;//A[500001];
	stack S;
	s(N);ll count=0;
	while(N!=0)
	{	
		count=0;stackinit(&S);
		for(i=0;i<N;i++)
		{
			s(M);
			if(empty(&S))
			{
				push(&S,M);
			}
			else
			{
				if(M>top(&S))
				{	
					while(!empty(&S) && M>top(&S))
					{
						count++;
						pop(&S);
					}
					//push(&S,M);
				}
				if(!empty(&S) && M==top(&S))
				{
					stack T;stackinit(&T);
					while(!empty(&S) && M==top(&S))
					{
						count++;
						push(&T,top(&S));
						pop(&S);
					}
					if(!empty(&S))
						count++;
					while(!empty(&T))
					{
						push(&S,top(&T));
						pop(&T);
					}
					//push(&S,M);
				}
				if(!empty(&S) && M<top(&S))
				{
					count++;
				}
				push(&S,M);
				
			}
		}
		ll notsee=(nCr(N,2)-count);
		printf("%lld\n",notsee);
		s(N);
	}
	return 0;
}