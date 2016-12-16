#include<stdio.h>
int in[1000006],pre[1000006];
int main()
{
	int n,first,second,inter,start,end,ans,flag,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		for(i=0;i<n;i++)
		{
			if(in[i]==x)
				first=i;
			if(in[i]==y)
				second=i;
		}
		if(first>second)
		{
			start=first;
			first=second;
			second=start;
		}
		start=0;
		end=n;
		inter=0;
		flag=0;
		while(1)
		{
			for(i=start;i<end;i++)
			{
				if(in[i]==pre[inter])
				{
					if(first<=i&&i<=second)
					{
						ans=i;
						flag=1;
						break;
					}
					else if(first<i&&second<i)
					{
						inter++;
						end=i;
					}
					else if(first>i&&second>i)
					{
						inter=inter+i+1-start;
						start=i+1;
					}
				}
			}
			if(flag==1)
				break;
		}
		printf("%d\n",in[ans]);
	}
}
