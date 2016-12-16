#include<stdio.h>
int pre[100000],in[100000],n;
int sch(int x)
{
	int i;
	for(i=0;i<n;i++)
		if(in[i]==x)
			break;
	return i;
}
int main()
{
	int i,t,a,b,hash[100000],temp,max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
		if(pre[i]>max)
			max=pre[i];
	}
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<=max;i++)
			hash[i]=0;
		scanf("%d%d",&a,&b);
		int x=sch(a);
		int y=sch(b);
	//	printf("x=%d y=%d\n",x,y);
		if((x-y)==1||(y-x)==1)
		{
			hash[a]=1;
			hash[b]=1;
			for(i=0;i<n;i++)
				if(hash[pre[i]]==1)
					break;
			x=pre[i];
		}
		else
		{
			if(x>y)
			{
				temp=x;
				x=y;
				y=temp;
			}
			for(i=x;i<=y;i++)
				hash[in[i]]=1;
			for(i=0;i<n;i++)
				if(hash[pre[i]]==1)
					break;
			x=pre[i];
		}
		printf("%d\n",x);
	}
	return 0;
}
