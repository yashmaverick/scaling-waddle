#include<stdio.h>
int main()
{
	int n,i,t,m,j,k,d,p,q;
	scanf("%d",&d);
	int a[d],b[d];
	for(i=0;i<d;i++)
		scanf("%d",&a[i]);
	for(i=0;i<d;i++)
		scanf("%d",&b[i]);
	scanf("%d",&t);
	while(t--)
	{
		int flag=0;
		scanf("%d %d",&m,&n);
		for(i=0;i<d;i++)
		{
			if(m==b[i])
				j=i;
			if(n==b[i])
				k=i;
		}
		if(j>=k)
		{
			for(p=0; a[p]!=m && a[p]!=n && flag==0 ;p++)
			{
				for(q=k;q<=j;q++)
				{
					if(a[p]==b[q])
					{
						printf("%d\n",a[p]);
						flag=1;
						break;
					}
				}
			}
		}
		else
		{
			for(p=0; a[p]!=m && a[p]!=n && flag==0 ;p++)
			{
				for(q=j;q<=k;q++)
				{
					if(a[p]==b[q])
					{
						printf("%d\n",a[p]);
						flag=1;
						break;
					}
				}
			}
		}
		if(flag==0)
		{
			for(i=0;i<d;i++)
			{
				if(a[i]==m || a[i]==n)
				{
					printf("%d\n",a[i]);
					break;
				}
			}
		}
	}
	return 0;
}
