#include<stdio.h>
int a[1000101],b[1000101],c[1000101];
int main()
{
	int tt;
	int t=0,ans;

	int n,i,j,s,h;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	scanf("%d",&tt);
	int e,f;
	while(tt--)
	{
		scanf("%d%d" , &e , &f);
		i=0;
		while(i<n)
		{
			if(e==b[i])
			{
				s=1;
				break;
			}

			if(f==b[i])
			{
				s=2;
				break;
			}
			i++;
		}
		j=0;
		if(s==1)
		{
//			printf("%d %d\n",b[i],i);
			while(f!=b[i])
			{
				c[j++]=b[i++];
			}
			c[j]=f;
//			printf("%d %d\n",c[j],j);
		}
		t=0;
		if(s==2)
		{
//			printf("%d %d\n",b[i],i);
			while(e!=b[i])
			{
				c[j++]=b[i++];
			}
			c[j]=e;
//			printf("%d %d\n",c[j],j);
		}
		for(i=0;i<n;i++)
		{
			for(h=0;h<=j;h++)
			{
				if(a[i]==c[h])
				{
					ans=a[i];
					t=1;
					break;
				}
			}
				if(t==1)
					break;
		}
		printf("%d\n",ans);
	}
	return 0;
}

