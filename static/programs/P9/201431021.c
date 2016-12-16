#include<stdio.h>
#include<stdlib.h>	
typedef struct 
{
	int total;
	int *c;
	int count;
	
}try;
int main()
{
	int n,j,mod,m,i,k;
	scanf("%d %d",&n,&mod);
	try a[1000];
	for (i = 0; i < n; ++i)
	{
		int temp=0;
		scanf("%d",&m);
		a[i].c=(int *)(malloc(m * sizeof(int)));
		for(j=0;j<m;j++)

		{
			scanf("%d",&(a[i].c[j]));
			temp=(temp+a[i].c[j])%mod;
		}
		a[i].total=temp;
		a[i].count=m;

	}
	for(i = n-1; i > 0; --i )
	for (k = 0; k< i;++k)
	{
				
		if (a[k].total>a[k+1].total)
		{
			try temp=a[k];
			a[k]=a[k+1];
			a[k+1]=temp;
		}
		
	}
	for (i= 0;i < n; ++i)
	{
		printf("%d\n",a[i].total);
		for (k= 0; k < a[i].count; ++k)
		{
			printf("%d\n",a[i].c[k]);	
			/* code */
		}
		printf("\n");
		
	}

		
	return 0;
}