#include<stdio.h>
long long int pu[100003],su,count;
void push(long long int a)
{
	su++;
	pu[su]=a;
}
void pop()
{
	su--;
}
long long int main()
{
	while(1)
	{
		long long int n;
		scanf("%lld",&n);
		count=0;
		su=-1;
		if(n==0)
		{
			break;
		}
		else
		{
			long long int h[n];
			long long int i,j,k;
			for(i=0;i<n;i++)
				scanf("%lld",&h[i]);
			push(h[0]);
			for(i=1;i<n;i++)
			{
				if(h[i]<pu[su])
				{
					push(h[i]);
					if(su>1)
					{
						for(k=su;k>=0;k--)
						{
							if(h[i]<pu[k])
							{
								count=count+k;
								break;
							}
						}
					}
				}
				else
				{
					for(j=su;j>=0;j--)
					{
						if(h[i]>pu[su])
						{
							count=count+n-i-1;
							pop();
						}
						else
							break;
					}
					push(h[i]);
					if(su>1)
					{
						for(k=su;k>=0;k--)
						{
							if(h[i]<pu[k])
							{
								count=count+k;
								break;
							}
						}
					}
				}
			}
		}
		printf("%lld\n",count);
	}
	return 0;
}
