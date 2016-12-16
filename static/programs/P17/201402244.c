#include<stdio.h>
int b[100100],c[100100];
int main()
{
	int a,i;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<a;i++)
	{
		scanf("%d",&c[i]);
	}
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int r,h,d[a];
		scanf("%d%d",&r,&h);
		for(i=0;i<a;i++)
		{
			if(r!=c[i]&&h!=c[i])
			{
				continue;
			}
			else
				break;
		}
		int j,k,count=-1;
		if(r!=h)
		{
		if(c[i]==r)
		{
			for(j=i;j<a;j++)
			{
				/*if(c[j]!=h)
				{
					count++;
					d[count]=c[j];
				}
				else
				{
					count++;
					d[count]=c[j];
					break;
				}*/
				if(c[j]==h)
					break;
			}
		}
		if(c[i]==h)
		{
			for(j=i;j<a;j++)
			{
				/*if(c[j]!=r)
				{
					count++;
					d[count]=c[j];
				}
				else
				{
					count++;
					d[count]=c[j];
					break;
				}*/
				if(c[j]==r)
					break;
			}
		}
	/*	for(j=0;j<=count;j++)
		{
		printf("%d ",d[j]);
		}*/
		int l;
		for(l=0;l<a;l++)
		{
			for(k=i;k<j;k++)
			{
				if(b[l]==c[k])
				{
				break;
				}
			}
			if(b[l]==c[k])
				break;
		}
		printf("%d\n",c[k]);
		}
		else
		printf("%d\n",h);
	}
	return 0;
}
