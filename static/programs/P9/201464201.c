#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{	return ( *(int*)a - *(int*)b );
}
int main()
{
	int i,j,k,n,mod,tot=0,p,m;
	scanf("%d %d", &n,&mod);
	int *full[n];
	int wt[n];		
	for(i=0;i<n;i++)
	{
		tot=0;
		scanf("%d", &m);
		full[i]=(int *)malloc((m+2)*sizeof(int));
		for(j=1;j<=m;j++)
		{
			scanf("%d", &full[i][j]);
			tot=(tot+full[i][j])%mod;
		}
		full[i][0]=tot%mod;
		full[i][j]=-1;
		wt[i]=tot%mod;
//			printf("%d ", wt[i]);
	}
	qsort(wt, n, sizeof(int), cmpfunc);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(wt[i]==full[j][0])
			{
				p=1;
				printf("%d\n", wt[i]);
				while(full[j][p]!=-1)
				{
					printf("%d\n", full[j][p]);
					p++;
				}
				full[j][0]=-3;
				break;
			}
		}
		printf("\n");
	}
	return 0;
}
