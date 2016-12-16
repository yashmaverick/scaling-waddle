#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int sum;
	int *inp;
}node;
int main()
{
	int n,mod,w,i,j,sum;
	scanf("%d",&n);
	scanf("%d",&mod);
	node a[n];
	node t; 
	for(i=0;i<n;i++)
	{
		scanf("%d",&w);
		a[i].inp=(int *)malloc(sizeof(int)*w+1);
		sum=0;
		for(j=0;j<w;j++)
		{
			scanf("%d",&a[i].inp[j]);
			sum=((sum)%mod+((a[i].inp[j]))%mod)%mod;
		}
		a[i].sum=sum;
		a[i].inp[j]=-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if((a[j].sum) < (a[j-1].sum))
			{
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		j=0;
		printf("%d\n",a[i].sum);
		while(a[i].inp[j]>=0)
		{
			printf("%d\n",a[i].inp[j]);
			j++;
		}
		printf("\n");
	}
return 0;
}


