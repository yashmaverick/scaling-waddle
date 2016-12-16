#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int p,q,r,i,j,k,count=0;
		scanf("%d",&p);
		int a[p],A[p];
		for(i=0;i<p;i++)
		{
			scanf("%d",&a[i]);
			A[i]=0;
		}
		scanf("%d",&q);
		int b[q],B[q];
		for(i=0;i<q;i++)
		{
			scanf("%d",&b[i]);
			B[i]=0;
		}
		scanf("%d",&r);
		int c[r];
		for(i=0;i<r;i++)
			scanf("%d",&c[i]);
		/*for(i=p-1;i>=0;i--)
		  {
		  for(j=q-1;j>=0;j--)
		  {
		  if((a[i]<=b[j])&&(i<j))
		  {
		  A[i]++;
		  }
		  else 
		  break;
		  }
		  }*/
		for(i=q-1;i>=0;i--)
		{
			for(j=r-1;j>=i;j--)
			{
				if((b[i]<=c[j])&&(i<=j))
				{
					B[i]++;
				}
				else
					break;
			}
		}
	//	for(i=q-1;i>=0;i--)
	//	printf("%d ",B[i]);
		for(i=p-1;i>=0;i--)
		{
			for(j=q-1;j>=i;j--)
			{
				if((a[i]<=b[j])&&(i<=j))
				{
					count=count+B[j];
				}
				else 
					break;
			}
		}

		printf("%d\n",count);

	}
	return 0;
}

