#include<stdio.h>
int main()
{
	int n,l,k,t,x,y,start,end,z,w,f,i,m,p,ans,set;
	int a[1000000],b[1000000];
	scanf("%d",&n);
	for(l=0;l<n;l++)
	{
		scanf("%d",&a[l]);
	}
	for(k=0;k<n;k++)
	{
		scanf("%d",&b[k]);
	}
	scanf("%d",&t);
	for(m=0;m<t;m++)
	{
		set=0;
		scanf("%d",&x);
		scanf("%d",&y);
		for(p=0;p<n;p++)
		{
			if(b[p]==x)
			{
				z=p;
			}
			if(b[p]==y)
			{
				w=p;
			}
		}
		if(z>=w)
		{
			start=w;
			end=z;
		}
		else
		{
			start=z;
			end=w;

		}
		//printf("start is %d end is %d\n",start,end);
		for(f=0;f<n;f++)
		{
			for(i=start;i<=end;i++)
			{
				if(a[f]==b[i])
				{
					ans=a[f];
					//printf("matched at %d\n",a[f]);
					set=1;
					break;
				}
				else
					continue;
			}
			if(set==1)
				break;

		}
		printf("%d\n",ans);
	}
	return 0;
}
