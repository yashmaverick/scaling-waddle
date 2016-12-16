#include<stdio.h>
int a[1000005],b[1000005],c[1000005];
int main()
{
	int i,n,p,q,t;//,a[100005],b[100005],c[100005];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	scanf("%d",&t);
	int j,k,top,bottom;
	while(t--)
	{
		scanf("%d %d",&p,&q);
		if(p==q)
			printf("%d\n",p);
		else
		{
			for(i=0;i<n;i++)
			{
				c[i+1]=0;
				if(b[i]==p)
				{
					j=i;
					top=p;
					//printf("%d %d\n",j,top);
				}
				if(b[i]==q)
				{
					k=i;
					bottom=q;
					//printf("%d %d\n",k,bottom);
				}
			}
			if(j<k)
			{
				for(i=j;i<=k;i++)
				{
					c[b[i]]=1;
				}

			}
			else if(k<j)
			{
				for(i=k;i<=j;i++)
				{
					c[b[i]]=1;
				}
			}
			for(i=0;i<n;i++)
			{
				if(c[a[i]]==1)
				{
					printf("%d\n",a[i]);
					break;
				}
			}
		}
	}
	return 0;
}




