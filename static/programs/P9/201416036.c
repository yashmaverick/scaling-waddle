#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **ans;
	int MOD, n, i=0, t=0, p ,k;
	long long z;
	scanf("%d%d", &n,&MOD);
	ans=(int **)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
	{
		z=0;
		scanf("%d", &p);
		ans[i]=(int*)malloc(sizeof(int)*(p+2));
		t=0;
		ans[i][t]=p;
		ans[i][p+1]=0;
		t++;
		while(p--)
		{
			scanf("%d", &ans[i][t]);
			z+= ans[i][t];
			z%= MOD;
			t++;
		}
		ans[i][ans[i][0]+1] = z;
	}
	int b[1005];
	for(k=0;k<n;k++)
		b[k]=k;
	for(k=0;k<n;k++)
	{
		for(t=k+1;t<n;t++)
		{
			if(ans[b[k]][ans[b[k]][0]+1]>ans[b[t]][ans[b[t]][0]+1])
			{
				int temp=b[t];
				b[t]=b[k];
				b[k]=temp;
			}

		}	
	}
	for(k=0;k<n;k++)
	{
		int kk=b[k];
		printf("%d\n",ans[kk][ans[kk][0]+1]);
		for(t=1;t<=ans[kk][0];t++)
			printf("%d\n",ans[kk][t]);
		printf("\n");
	}
	return 0;

}
