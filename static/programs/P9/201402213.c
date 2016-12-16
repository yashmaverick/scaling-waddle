#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int val;
	int size;
	int *arr;
}node;
int n,mod;
node a[1001];
int main()
{
	scanf("%d%d",&n,&mod);
	int i,j;
	for(i=1;i<=n;i++)
	{
		int m;
		a[i].val=0;
		scanf("%d",&m);
		a[i].size=m;
		a[i].arr=(int *)malloc((m+1)*sizeof(int));
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i].arr[j]);
			a[i].val=(a[i].val+a[i].arr[j])%mod;
		}
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(a[j].val<a[i].val)
			{
				node temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
	for(i=1;i<=n;i++)
	{
		printf("%d\n",a[i].val);
		for(j=0;j<a[i].size;j++)
			printf("%d\n",a[i].arr[j]);
		printf("\n");
	}
	return 0;
}
