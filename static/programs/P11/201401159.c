#include <stdio.h>
#include <stdlib.h>
#define MAX 100100


long long int arr[MAX];
long long int top=-1;

void push(long long int k)
{
	if(top==(MAX-1))
		return;
	else
	{
		top++;
		arr[top]=k;
	}		
	return;
}

void pop()
{
	if(top==-1)
		return;
	else
		top--;
}

long long int topp()
{
return arr[top];
}

int main()
{
	long long int arv[MAX],i,j,k,n;
	long long max=0,area;
	scanf("%Ld",&n);
	while(n!=0)
	{
		area=max=0;
		top=-1;
		for(i=0;i<n;i++)
			scanf("%lld",&arv[i]);
		i=0;
		while(i<n)
		{
			if(top==-1 || arv[i]>=arv[topp()])
				push(i++);
			else
			{
				j=topp();
				pop();
				area=arv[j]*((top==-1)? i :  i - topp()-1);
				if(area>max)
					max=area;
			}
		}
		while(top!=-1)
		{
			j=topp();
			pop();
			area=arv[j]*((top==-1)? i :  i - topp()-1);
			if(area>max)
				max=area;
		}
		printf("%lld\n",max);
		scanf("%lld",&n);
	}
	return 0;
}