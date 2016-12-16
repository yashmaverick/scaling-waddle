#include<stdio.h>
#include<stdlib.h>
double sort(int *A[],int n)
{
	int i;
	for(i=n-2;i>=0;i--)
	{
		int j;
		for(j=0;j<=i;j++)
		{
			if(A[j][0]>A[j+1][0])
			{
				int *temp;
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
}
int main()
{
	int n,m,mod,w,i,j,k;
	scanf("%d %d",&n,&mod);
	int *A[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		int new[m+4];
		A[i]=(int*)malloc((m+4)*sizeof(int));
		A[i][0]=0;
		for(j=1;j<=m;j++)
		{
			scanf("%d",&A[i][j]);
			A[i][0]=(A[i][j]+A[i][0])%mod;
		}
		A[i][j]=-1;
	}
	sort(A,n);
	for(i=0;i<n;i++)
	{
		j=0;
		while(A[i][j]>=0)
			printf("%d\n",A[i][j++]);
		printf("\n");
	}
	return 0;
}
