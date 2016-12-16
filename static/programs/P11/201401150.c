
#include <stdio.h>
#define ll long long
#define stack struct stack
ll LEFT[100001],RIGHT[100001];

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
void	 pop(stack* S)
{
	S->tp--;
	//return S;
}
ll top(stack* S)
{
	return S->array[S->tp];
}

void init(ll n)
{
	ll i;
	for(i=0;i<n;i++)
	{
		LEFT[i]=0;
		RIGHT[i]=0;
	}
}
int main()
{

	ll n;
	ll h[100001];
	stack height;
	stack index,index2;
	stackinit(&height);
	stackinit(&index);
	stackinit(&index2);
	scanf("%lld",&n);
	while(n!=0)
	{		
		ll A=0;ll i;
		//from left start
		for(i=0;i<n;i++)
		{
			scanf("%lld",&h[i]);
			if(empty(&index) || top(&height)<h[i])
			{
				push(&height,h[i]);
				push(&index,i);
			}
			while(!empty(&index) && h[i]<top(&height))
			{
				ll h=top(&height);
				ll w=(i-top(&index));
				ll area=h*w;
				LEFT[top(&index)]=area;
				//if(area>A)
				//	A=area;
				pop(&height);
				pop(&index);
			}
			if(empty(&index) || top(&index)!=h[i])
			{
				push(&height,h[i]);
				push(&index,i);
			}
		}
	
		while(!empty(&index))
		{	
			ll h,w,area;
			h=top(&height);
			w=i-top(&index);
			area=h*w;
			LEFT[top(&index)]=area;
			//if(area>A)
			//	A=area;
			pop(&height);
			pop(&index);
		}
		// left end
		//right start
		ll k=n-1;
		for(i=0;i<n;i++)
		{
			if(empty(&index) || top(&height)<h[k])
			{
				push(&height,h[k]);
				push(&index,i);
				push(&index2,k);
			}
			while(!empty(&index) && h[k]<top(&height))
			{
				ll h=top(&height);
				ll w=(i-top(&index));
				ll area=h*w;
				RIGHT[top(&index2)]=area;
			//	if(area>A)
			//		A=area;
				pop(&height);
				pop(&index);
				pop(&index2);
			}
			if(empty(&index) || top(&index)!=h[k])
			{
				push(&height,h[k]);
				push(&index,i);
				push(&index2,k);
			}
			k--;
		}
		while(!empty(&index))
		{	
			ll h,w,area;
			h=top(&height);
			w=i-top(&index);
			area=h*w;
			RIGHT[top(&index2)]=area;
			//if(area>A)
			//	A=area;
			pop(&height);
			pop(&index);
			pop(&index2);
		}
		//right end
		for(i=0;i<n;i++)
		{
			//printf("LEFT = %lld; RIGHT = %lld\n",LEFT[i],RIGHT[i]);
			ll area;
			if(LEFT[i]!=0 && RIGHT[i]!=0)
				area=LEFT[i]+RIGHT[i]-h[i];
			else
					area=LEFT[i]+RIGHT[i];
			if(area>A)
				A=area;
		}
		printf("%lld\n",A);
		init(n);
		scanf("%lld",&n);
		
	}
	return 0;
}	