#include<stdio.h>
int main()
{
	int  n,last,first,c,i,j,ans=-9999999,a,b,in[100001],pre[100001],new[100001],test,t=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&a,&b);
		t=1;
		if(a==b)
			printf("%d\n",a);
		else
		{
			if(a==pre[0])
			{
				printf("%d\n",a);
			}
			else if(b==pre[0])
			{
				printf("%d\n",b);
			}
			else if(a!=pre[0]&&b!=pre[0])
			{
				for(i=0;i<n;i++)
				{
					if(in[i]==a)
						first=i;
					if(in[i]==b)
						last=i;
				}
				if(last<first)
				{
					c=last;
					last=first;
					first=c;
				}
				for(i=0;i<=last-first;i++)
					new[i]=in[i+first];
				for(i=0;i<n;i++)
				{
					for(j=0;j<=last-first;j++)
					{
						if(pre[i]==new[j])
						{
							ans=pre[i];
							t=0;
							break;
						}
					}
					if(t==0)
						break;
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}






