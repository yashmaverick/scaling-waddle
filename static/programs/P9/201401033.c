#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,m,s=0,temp;
	long long int mod,n;
	scanf("%lld%lld",&n,&mod);
	long long int *size,*b;
	size=(long long int *)malloc(n*sizeof(long long int));
	b=(long long int *)malloc(n*sizeof(long long int));
	long long int **a=(long long int **)malloc(n*sizeof(long long int));
	for(i=0;i<n;i++)
	{
	//	printf("hi\n");
		s=0;
		scanf("%d",&m);
		a[i]=(long long int *)malloc((m+1)*sizeof(long long int));
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			s=(s+a[i][j])%mod;
		}
		a[i][0]=s;
		size[i]=m+1;
	}
	for(i=0;i<n;i++)
		b[i]=i;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[b[i]][0]>a[b[j]][0])
			{
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%lld\n",a[b[i]][0]);
		for(j=1;j<size[b[i]];j++)
		{
			printf("%lld\n",a[b[i]][j]);
		}
		printf("\n");
	}
	return 0;
}
