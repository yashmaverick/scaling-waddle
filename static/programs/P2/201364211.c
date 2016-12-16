#include<stdio.h>
#include<stdlib.h>
int main()
{
	int p,q,r,i,j,k,x,y,z;
	int test,count;
	scanf("%d",&test);
	while(test>0)
	{
	scanf("%d",&p);
	int a[p];
	for(i=0;i<p;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&q);
	int b[q];
	for(i=0;i<q;i++)
	{
		scanf("%d",&b[i]);
	}
	scanf("%d",&r);
	int c[r];
	for(i=0;i<r;i++)
	{
		scanf("%d",&c[i]);
	}
	count =0 ;
		for(j=0;j<q;j++)
		{
			if(b[j] > a[0])
				break;
		}
		for(k=0;k<r;k++)
		{
			if(c[k]>b[j])
				break;

		}
	for(x=0;x<p;x++)
	{
		for(y=j;y<q ;y++)
		{
			for(z=k;z<r;z++)
			{
				if(a[x] <= b[y] && b[y] <= c[z] && x<=y && y<=z)
				
				{
					count ++;}
			}
		}
	}
	printf("%d\n",count);
	test--;
	}
	return 0;
}
