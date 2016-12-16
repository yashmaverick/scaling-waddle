#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,mod,m,i,j,k,c,r;
	scanf("%d %d",&n,&mod);
	int *a[n];
	int b[n];
	for( i=0;i<n;i++)
	{
		scanf("%d",&m);
		int s=0;
		a[i]=(int *)malloc((m+2)*sizeof(int));
		for(j=2;j<m+2;j++)
		{
			scanf("%d",&a[i][j]);
			s=(s + a[i][j])%mod;
		}
		a[i][0]=s;
		a[i][1]=m;
		b[i]=s;
//		for(j=0;j<m+2;j++)
//			printf("%d ",a[i][j]);
//		printf("\n");

	}
//	for(i=0;i<n;i++)
//		printf(" %d ",a[i][0]);
	int x;
	for(j=0;j<n;j++)
	{
	
	for(i=0;i<n;i++)
	{
		if(b[i]>0)
		{
			x=i;
			break;
		}
	}
	int min;
//	printf("  %d    ",b[x]);
	for(i=0;i<n;i++)
	{
		if(b[i]<b[x] && b[i]!= -1)
			x=i;
	}
	min=b[x];
	b[x]=-1;
//	printf("   %d    ",min);
	for(k=0;k<n;k++)
	{        	
		if(a[k][0]==min)
			{
				r=k;
				printf("%d\n",a[r][0]);
				a[k][0]=-1;
				break;
			}
	}
	for(c=0;c<a[r][1];c++)
		printf("%d\n",a[k][c+2]);
	printf("\n");
	}

return 0;
}




