#include<stdio.h>
#include<string.h>
long long int diff=-1;
long long int b[1000000];
void push(long long int first)
{
	diff++;
	b[diff]=first;
	return ;
}
void pop()
{
	if(diff<0)
	{
		return;
	}
	diff--;
	return ;
}
int main()
{
	long long int  C,n,i,a[1000000],top,val,ll;
	scanf("%lld",&n);
	while(n!=0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		i=1;
		diff=-1;
		push(0);
		long long int Result=0;
		while(i<n)
		{
			top=a[b[diff]];
			if(diff==-1 || a[i]<=top)
			{
				C=0;
				if(diff>0)
				{
					long long int tt=diff;
					while(tt>=0&&a[b[tt]]==a[i])
					{
						C++;
						tt--;
					}
				}
				if(diff-C>0)
				Result+=(diff)-(C);
				push(i);
				i++;
			}
			else
			{
				Result+=n-i-1;
				C=0;
				pop();
			}
		}
		//	for(i=0;i<n;i++)
		//	{
		//		printf("%d ",c[i]);
		//	}
		printf("%lld\n",Result);
		scanf("%lld",&n);
	}
	return 0;
}
