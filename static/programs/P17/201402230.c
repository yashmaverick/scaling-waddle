#include<stdio.h>
void post_order(int in[],int pre[],int size);
int post[1000000];
int front_post=0;
int main()
{
	int t,n,i,x,y;
	scanf("%d",&n);
	int in[n],pre[n];
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
//	for(i=0;i<n;i++)
//	{
//		if(in[i]==pre[0])
//			break;
//	}
//	index=i;
	post_order(in,pre,n);
//	for(i=0;i<front_post;i++)
//		printf("%d ",post[i]);
//	printf("\n");
	scanf("%d",&t);
	while(t--)
	{
		int j,max=0;
		scanf("%d %d",&x,&y);
		for(i=0;i<n;i++)
		{
			if(in[i]==x)
				break;
		}
		for(j=0;j<n;j++)
		{
			if(in[j]==y)
				break;
		}
//		printf("%d %d",i,j);
		int k,l;
		if(i>j)
		{
			for(k=j;k<=i;k++)
			{
				for(l=0;l<front_post;l++)
				{
					if(in[k]==post[l])
					{
						if(max<l)
						{
							max=l;
							break;
						}
						//break;
					}
				}
			}
		}
		else if(j>=i)
		{
			for(k=i;k<=j;k++)
			{
				for(l=0;l<front_post;l++)
				{
					if(in[k]==post[l])
					{
						if(max<l)
						{	
							max=l;
							break;
						}
						//break;
					}
				}
			}
		}
		printf("%d\n",post[max]);
		max=0;
	}
return 0;
}
void post_order(int in[],int pre[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(in[i]==pre[0])
			break;
	}
	if(i!=0)
		post_order(in,pre+1,i);
	if(i!=size-1 && size>=0)
		post_order(in+i+1,pre+i+1,size-i-1);
	post[front_post]=pre[0];
	front_post++;
}
			
