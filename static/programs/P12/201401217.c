#include<stdio.h>
int main()
{
	long long int n,x,i,top,count;
	scanf("%lld",&n);
	while(n!=0)
	{
		long long int a[n],stac[n],k,j;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		i=0;
		count=0;
		top=-1;
		while(i<n)
		{
			if(top==-1||a[stac[top]]>=a[i])
			{
				top++;
				stac[top]=i++;
				if(top>=2)
				{
					k=top;
					for(j=k-1;j>0;j--)
					{
						if(a[stac[j]]>a[stac[k]])
						{
							count=count+(j);
							break;
						}
					}
				}
			}
			else
			{
				count=count+(n-1-i);
				top--;
			}
		}
		printf("%lld\n",count);
		scanf("%lld",&n);
	}
	return 0;
}
