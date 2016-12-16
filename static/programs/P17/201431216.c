#include<stdio.h>
int main()
{
	int m,n,i,q,j,k,a[100010],b[100010],c[100010],flag=0,n1,n2;
	scanf("%d",&n);
	for(j=0;j<n;j++)
	{
		scanf("%d",&b[j]);
	}
	for(j=0;j<n;j++)
	{
		scanf("%d",&a[j]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{

		scanf("%d%d",&n1,&n2);
		for(j=0;j<n;j++)
		{
			if(a[j]==n1 || a[j]==n2)
				break;
		}
		m=0;
		if(a[j]==n1)
		{
			for(k=j;a[k]!=n2;k++)
			{
				c[m]=a[k];
				m++;
			}
			c[m]=n2;
		}
		if(a[j]==n2)
		{

			for(k=j;a[k]!=n1;k++)
			{
				c[m]=a[k];
				m++;
			}
			c[m]=n1;
		}
		flag=0;
		for(k=0;k<n;k++)
		{
			for(j=0;j<=m;j++)
			{
				if(b[k]==c[j])
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		printf("%d\n",b[k]);
		//}
         }
return 0;
}











