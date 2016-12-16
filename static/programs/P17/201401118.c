#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],b[n],i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y,in_x,in_y,c,flag=0,index,j;
		scanf("%d %d",&x,&y);
		for(i=0;i<n;i++)
		{
			if(b[i]==x)
			{
				in_x=i;
				break;
			}
		}
		for(i=0;i<n;i++)
		{
			if(b[i]==y)
			{
				in_y=i;
				break;
			}
		}
		if(in_y<in_x)
		{
			c=in_x;
			in_x=in_y;
			in_y=c;
		}
		for(i=0;i<=n;i++)
		{
			for(j=in_x;j<=in_y;j++)
			{
				if(a[i]==b[j])
				{
					flag=1;
					index=i;
					break;
				}
			}
			if(flag==1)
				break;
		}
		printf("%d\n",a[index]);
	}
	return 0;
}
