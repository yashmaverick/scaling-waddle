#include<stdio.h>
int main()
{
	int node,pre[10000],in[10000],test,i,j,m,n,a,b,p,q,temp,flag;
	scanf("%d",&node);
	for(i=0;i<node;i++)
	{
		scanf("%d",&pre[i]);
	}
	for(i=0;i<node;i++)
	{
		scanf("%d",&in[i]);
	}
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&a,&b);
		for(i=0;i<node;i++)
		{
			if(in[i]==a)
			{
				p=i;
			}
			if(in[i]==b)
			{
				q=i;
			}
		}
		if(p>q)
		{
			temp=p;
			p=q;
			q=temp;
		}
		flag=0;
		for(j=0;j<node;j++)
		{
			for(i=p;i<=q;i++)
			{
				//printf("%d<-->%d ",pre[j],in[i]);
				if(pre[j]==in[i])
				{	printf("%d\n",in[i]);
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
	}
	return 0;
}
