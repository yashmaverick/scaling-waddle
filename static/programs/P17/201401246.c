#include<stdio.h>
int a[1000000],b[1000000],n;
int finda(int p)
{
	int k;
	for(k=1;k<=n;k++)
	{
		if(a[k]==p)
			return k;
	}
}
int findb(int p)
{
	int k;
	for(k=1;k<=n;k++)
	{
		if(b[k]==p)
			return k;
	}
}
int main()
{
	int i,t,p,q,x1,x2,y1,y2,temp,j,flag;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		scanf("%d%d",&p,&q);
		x1=finda(p);
		y1=finda(q);
		x2=findb(p);
		y2=findb(q);
		if(y1<x1)
		{
			temp=y1;
			y1=x1;
			x1=temp;
		}
		if(y2<x2)
		{
			temp=y2;
			y2=x2;
			x2=temp;
		}
		//printf("(%d,%d);(%d,%d)\n",x1,y1,x2,y2);
		for(i=1;i<=x1;i++)
		{
			for(j=x2;j<=y2;j++)
			{
				if(a[i]==b[j])
				{
					printf("%d\n",a[i]);
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		//printf("end\n");
	}
	return 0;
}