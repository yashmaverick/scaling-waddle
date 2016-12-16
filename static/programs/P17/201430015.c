#include<stdio.h>

int main()
{
	int pre[100001],in[100001],c[100001];
	int n,i,a,b,x,t,min;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		pre[x]=i;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
		in[c[i]]=i;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		a=in[a];
		b=in[b];
		if(a>b)
		{
			i=a;
			a=b;
			b=i;
		}
//		printf("a:%d b:%d\n",a,b);
		for(i=a;i<=b;i++)
		{
			if(i==a)
			{
				min=a;
			}
			else
			{
				if(pre[c[i]]<pre[c[min]])
				{
					min=i;
				}
			}
		}
		printf("%d\n",c[min]);
	}
	return 0;
}


