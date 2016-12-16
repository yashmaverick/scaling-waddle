#include<stdio.h>
int main()
{
	int t,i,ar[100000],n;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int pt=0,j,k,min=0,max=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&ar[j]);
			if(ar[j]<ar[min])
				min=j;
			max=j;
			if(ar[max]-ar[min]>pt)
				pt=ar[max]-ar[min];
		}
		printf("%d\n",pt);
	}
	return 0;
}































