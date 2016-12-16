#include<stdio.h>
typedef struct kam{
    long long int chote;
    long long int equal;
    long long int greaterindex;
}name;
name jarurat[500005];
long long int mystack[500005];
long long int A[500005];
long long int last=1;
void push(long long int n)
{
    mystack[last]=n;
    last++;
}
void pop()
{
    last--;
}
long long int Ans(int n)
{
    long long int ans=0;
    mystack[0]=-1;
    long long int countchote;
    long long int countequal;
    long long int i;
    jarurat[0].chote=0;
    jarurat[0].equal=0;
    jarurat[0].greaterindex=mystack[last-1];
    push(0);
    for(i=1;i<n;i++)
    {
	countchote=0;
	countequal=0;
	if(A[i]<A[mystack[last-1]])
	{
	    jarurat[i].chote=0;
	    jarurat[i].equal=0;
	    jarurat[i].greaterindex=mystack[last-1];
	    push(i);
	}
	else
	{
	    while(A[i]>=A[mystack[last-1]]&&last!=1)
	    {
		if(A[i]>A[mystack[last-1]])
		{
		    countchote++;
		    countchote=countchote+jarurat[mystack[last-1]].chote+jarurat[mystack[last-1]].equal;
		    ans=ans+jarurat[mystack[last-1]].chote;
		    pop();
		}
		else if(A[i]==A[mystack[last-1]])
		{
		    countequal++;
		    countchote=countchote+jarurat[mystack[last-1]].chote;
		    countequal=countequal+jarurat[mystack[last-1]].equal;
		    ans=ans+jarurat[mystack[last-1]].chote;
		    pop();
		}
	    }
	    jarurat[i].chote=countchote;
	    jarurat[i].equal=countequal;
	    jarurat[i].greaterindex=mystack[last-1];
	    push(i);
	}
    }
    for(i=0;i<n;i++)
    {
	if(jarurat[i].greaterindex==-1)
	{
	    ans=ans+0;
	}
	else
	{
	    ans=ans+jarurat[i].greaterindex;
	}
    }
    return ans;
}
void print(long long int n)
{
    long long int i;
    for(i=0;i<n;i++)
    {
	printf("greaterindex%lld %lld\n",i,jarurat[i].greaterindex);
	printf("chote%lld %lld\n",i,jarurat[i].chote);
	printf("equal%lld %lld\n",i,jarurat[i].equal);
    }
}
int main()
{
    long long int n,i;
    scanf("%lld",&n);
    while(n)
    {
	last=1;
	for(i=0;i<n;i++)
	{
	    scanf("%lld",&A[i]);
	}
	printf("%lld\n",Ans(n));
//	print(n);
	scanf("%lld",&n);
    }
    return 0;
}
