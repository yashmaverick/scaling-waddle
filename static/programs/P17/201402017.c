#include<stdio.h>
#include<stdlib.h>
int srch(int in[],int x,int n);
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
int main()
{
	int flag=0,t,n,i,pre[100004],in[100004];
	int j,x1,x2,x3,x4,p,n1,n2;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n1,&n2);
		flag=0;
		x1=srch(in,n1,n);
		x2=srch(in,n2,n);
		x3=max(x1,x2);
		x4=min(x1,x2);
		for(i=0;i<n;i++)
		{
			for(j=x4;j<=x3;j++)
			{
				if(pre[i]==in[j])
				{
					p=i;
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		printf("%d\n",pre[p]);
	}
	return 0;

}
int srch(int in[],int x,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(in[i]==x)
			return i;
	}
	return -1;
}

