#include <stdio.h>
#include <limits.h>
#define s(n) scanf("%d",&n)
#define range struct range
#define stack struct stack

range
{
	int llb,lub;
	int rlb,rub;
};

stack
{
	int array[100001], tp;
	range R[100001];
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
void push(stack* S,int a,range r)
{
	//if(tp==MAX-1)
	//	return -1;
	S->tp++;
	S->array[S->tp]=a;
	S->R[S->tp].llb=r.llb;
	S->R[S->tp].lub=r.lub;
	S->R[S->tp].rlb=r.rlb;
	S->R[S->tp].rub=r.rub;
	//return S;
}
void pop(stack* S)
{
	S->tp--;
	//return S;
}
int top(stack* S)
{
	return S->array[S->tp];
}

range topRange(stack* S)
{
	return S->R[S->tp];
}

int inRange(int a,range r)
{
	if(a>r.llb && a<r.lub)
		return 1;
	if(a>r.rlb && a<r.rub)
		return 1;
	return 0;
}

int inRight(int a,range r)
{
	if(a>r.rlb && a<r.rub)
		return 1;
	return 0;
}
int inLeft(int a,range r)
{
	if(a>r.llb && a<r.lub)
		return 1;
	return 0;
}


void init(int A[],int n)
{

}
int main()
{
	int t,i,n,j;
	s(t);int A[100001];
	for(i=0;i<t;i++)
	{
		int maxDepth=0,node=INT_MAX;
		s(n);stack S;stackinit(&S);
		if(n!=0){
		for(j=0;j<n;j++)
			s(A[j]);
		if(n==1)
		node=A[0];
		range ini;
		ini.llb=INT_MIN;
		ini.lub=A[n-1];
		ini.rlb=A[n-1];
		ini.rub=INT_MAX;
		int depth=0;
		for(j=n-1;j>=0;j--)
		{
			if(empty(&S))
				push(&S,A[j],ini);
			else if(!empty(&S) && !inRange(A[j],topRange(&S)))
			{
				while(!empty(&S) && !inRange(A[j],topRange(&S)))
				{
					depth--;
					pop(&S);
				}
			}
			if(!empty(&S) && inRange(A[j],topRange(&S)))
			{
				depth++;
				range curr=topRange(&S);
				if(inLeft(A[j],topRange(&S)))
				{
					curr.lub=A[j];
					curr.rlb=A[j];
					curr.rub=top(&S);
				}
				if(inRight(A[j],topRange(&S)))
				{
					curr.llb=top(&S);
					curr.lub=A[j];
					curr.rlb=A[j];
				}
				if(depth>maxDepth || (depth==maxDepth && A[j]<node))
				{
					maxDepth=depth;
					node=A[j];
				}
				push(&S,A[j],curr);
			}
		}
		printf("%d %d\n",node,maxDepth);
		}
	}

	return 0;
}
