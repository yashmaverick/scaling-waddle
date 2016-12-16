#include <stdio.h>

int main()
{
	int pre[100000];
	int in[100000];
	int index[100000];
	int val[100000];
	int n,t;
	int x,y;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
		index[pre[i]]=i;
	}
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		int i1,i2;
		for(i=0;i<n;i++)
		{
			if(in[i]==x)
				i1=i;
			if(in[i]==y)
				i2=i;
		}
		if(i1>i2)
		{
			int temp=i1;
			i1=i2;
			i2=temp;
		}
		int j=0;
			for(i=i1;i<=i2;i++)
			{
				val[j]=in[i];
				j++;
			}

		int min=index[val[0]];
		int v=val[0];
		for(i=1;i<j;i++)
		{ 
			if(min>index[val[i]])
			{
				min=index[val[i]];
				v=val[i];
			}
		}
		printf("%d\n",v);
	}
}



