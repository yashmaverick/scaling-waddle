#include <stdio.h>
#include <stdlib.h>
#define MAX 500100


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
	long long int arv[MAX],i,j,k,n,count,mc,temp;
	scanf("%lld",&n);
	while(n!=0)
	{
		top=-1;
		count=mc=0;
		for(i=0;i<n;i++)
			scanf("%lld",&arv[i]);
		i=0;
		while(i<n)
		{
			if(top==-1 || arv[i]<arv[topp()])
				{
					push(i++);
					temp=count;
					count++;
					if(temp>1)
					{
						//temp=count-2;
						mc+=(temp-1);
					}
				}
			else if(arv[i]==arv[topp()])
				{
					for(k=top;k>-1&&arv[arr[k]]==arv[i];k--);
					temp=k+1;
					push(i++);
					count++;
					if(temp>1)
					{
						mc+=(temp-1);
					}
				}
			else
				{
					pop();
					count--;				
					mc+=(n-i-1);
				}
		}
		printf("%lld\n",mc);
		scanf("%lld",&n);
	}
	return 0;
} 