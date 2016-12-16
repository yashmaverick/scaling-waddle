#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int p,q,r,i;
		scanf("%d",&p);
		int a[p];
		for(i=0;i<p;i++)
			scanf("%d",&a[i]);
		scanf("%d",&q);
		int b[q];
		for(i=0;i<q;i++)
			scanf("%d",&b[i]);
		scanf("%d",&r);
		int c[r];
		for(i=0;i<r;i++)
			scanf("%d",&c[i]);
		int j,k=0,count=0,ans=0,flag=0;i=0;
		for(j=0;j<q,k<r;j++)
		{	
			i=0;
			flag=0;
			if(k<j)
				k=j;
			while(k<r && flag==0)
			{
				if(c[k]>=b[j])
				{
					flag=1;

				}
				else
					k++;
			}
			while(i<=j && i<p)
			{
				if(a[i]<=b[j])	
				{
					count++;
					i++;
				}
				else
					break;
			}
			ans+=(r-k)*count;
		//	printf("##%d##\n",ans);
			count=0;
		//	printf("##%d %d %d##\n",i,j,k);
		}
		printf("%d\n",ans);
	}
	return 0;
}
