#include<stdio.h>
#include<stdlib.h>

typedef struct bag
{
	int m;
	int *w;
	int sum;
}bag;

int main()
{
	int n,i,j,mod;
	scanf("%d %d",&n,&mod);
	bag bags[n],c;
	for(i=0;i<n;i++)
	{
		bags[i].sum=0;
		scanf("%d",&bags[i].m);
		bags[i].w=(int *)malloc(sizeof(int)*bags[i].m);
		j=0;
		while(j<bags[i].m)
		{
			scanf("%d",&bags[i].w[j]);
			bags[i].sum=(bags[i].sum%mod+bags[i].w[j]%mod)%mod;
			j++;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(bags[j].sum<bags[i].sum)
			{
				c=bags[j];
				bags[j]=bags[i];
				bags[i]=c;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",bags[i].sum);
		j=0;
		while(j<bags[i].m)
		{
			printf("%d\n",bags[i].w[j]);
			j++;
		}
		printf("\n");
	}
	return 0;
}
