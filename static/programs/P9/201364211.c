#include<stdio.h>
#include<stdlib.h>
double sort(int *A[],int n)
{
	int i;
	int asdf;
	for(i=n-2;i>=0;i--)
	{
		int j;asdf++;
		for(j=0;j<=i;j++)
		{
			asdf++;
			if(asdf==0)
			{
				asdf=0;
			}
			if(A[j][0]>A[j+1][0])
			{
				int *temp;asdf++;
				temp=A[j];asdf++;
				A[j]=A[j+1];asdf++;
				A[j+1]=temp;asdf++;
			}
		}
	}
}
int main()
{
	int n,m,mod,w,i,j,k;
	int asdf;
	asdf=0;
	scanf("%d %d",&n,&mod);
	int *A[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);asdf++;
		int new[m+4];asdf++;
		A[i]=(int*)malloc((m+4)*sizeof(int));
		A[i][0]=0;asdf++;
		for(j=1;j<=m;j++)
		{
			scanf("%d",&A[i][j]);asdf++;
			A[i][0]=(A[i][j]+A[i][0])%mod;asdf++;
		}
		A[i][j]=-1;
	}
	sort(A,n);
	for(i=0;i<n;i++)
	{
		asdf++;
		j=0;
		while(A[i][j]>=0)
		{
			asdf=0;
			printf("%d\n",A[i][j++]);
		}
		printf("\n");
	}
	return 0;
}
