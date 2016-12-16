#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[100000];
	int b[100000];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int C,d;
		scanf("%d %d",&C,&d);
		int j,k;
		for(i=0;i<n;i++)
		{
			if(C==b[i])
				j=i;
			if(d==b[i])
				k=i;
		}
		int s;
		int c[100000];
		if(j>k)
		{	s=j-k+1;
			for(i=0;i<s;i++)
			{
				c[i]=b[k];
				k++;
			}
		}	
		else
		{
			s=k-j+1;
			for(i=0;i<s;i++)
			{
				c[i]=b[j];
				j++;
			}
		}
		int y,ans,flag=0;
		for(i=0;i<n;i++)
		{
			for(y=0;y<s;y++)
			{
				if(a[i]==c[y])
				{
					ans=c[y];
					flag=1;
					break;						
				}
			}
			if(flag==1)
				break;

		}
		printf("%d\n",ans);
	}	
	return 0;
}
