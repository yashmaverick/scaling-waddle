#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,mod,i,j,k,m;
	int **ar,br[1000][3];
	scanf("%d%d",&n,&mod);
	ar=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		ar[i]=(int *)malloc((m)*sizeof(int));
		br[i][0]=0;
		br[i][1]=i;
		br[i][2]=m;
		for(j=0;j<m;j++)
		{
			scanf("%d",&ar[i][j]);
			br[i][0]=(br[i][0]+ar[i][j]%mod)%mod;
		}
	}
	int t1,t2,t3;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(br[j][0]<br[i][0])
			{
				t1=br[j][0];
				t2=br[j][1];
				br[j][0]=br[i][0];
				br[j][1]=br[i][1];
				br[i][0]=t1;
				br[i][1]=t2;
				t3=br[j][2];
				br[j][2]=br[i][2];
				br[i][2]=t3;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",br[i][0]);
		for(j=0;j<br[i][2];j++)
			printf("%d\n",ar[br[i][1]][j]);
		printf("\n");
	}
	return 0;
}
		




