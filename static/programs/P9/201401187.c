#include<stdio.h>
#include<stdlib.h>
typedef struct b{
	int m;
	int s;
	int *v;
}b;
int main()
{
	int n,i,j,mod;
	scanf("%d%d",&n,&mod);
	b temp;
	b sack[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&sack[i].m);
		sack[i].v=(int*)malloc(sack[i].m*sizeof(int));
		sack[i].s=0;
		for(j=0;j<sack[i].m;j++)
		{
			scanf("%d",&sack[i].v[j]);
			sack[i].s=(sack[i].s%mod+sack[i].v[j]%mod)%mod;
		}
	}

/*	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(sack[j].s>sack[j+1].s)
			{
				temp=sack[j];
				sack[j]=sack[j+1];
				sack[j+1]=temp;
			}
		}
	}*/
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(sack[i].s>sack[j].s)
			{
				temp=sack[i];
				sack[i]=sack[j];
				sack[j]=temp;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		printf("%d\n",sack[i].s);
		for(j=0;j<sack[i].m;j++)
			printf("%d\n",sack[i].v[j]);
		printf("\n");
	}
	return 0;
}

