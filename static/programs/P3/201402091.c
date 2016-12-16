#include<stdio.h>
int main()
{
	int i,t,n,j,max,pro,profit,a[100005]; 
		scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);
//		printf("%d\n",j);
		max=a[j-1];
//		printf("max initial=%d\n",max);
		pro=0;profit=0;
		for(j=n-2;j>=0;j--)
		{
			if(max>a[j])
			{
				pro=max-a[j];
				if(pro>profit)
					{
						profit=pro;
//						printf("%d\n",profit);
}
			}
			else
				max=a[j];
		}
		printf("%d\n",profit);
	}
	return 0;
}
