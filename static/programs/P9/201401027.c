#include<stdio.h>
#include<stdlib.h>
typedef struct list{
	int total;
	int num;
	int* arr;
}list;
list *a;
int main()
{
	int n,mod,i,m,j,tot,w,min,minj;
	scanf("%d %d",&n,&mod);
	a=(list*)malloc(n*sizeof(list));
	for(i=0;i<n;i++)
	{	
		scanf("%d",&m);
		a[i].arr=(int*)malloc(m*sizeof(int));
		tot=0;
		for(j=0;j<m;j++)
		{
			scanf("%d",&w);
			tot=(tot+w)%mod;
			a[i].arr[j]=w;
		}
		a[i].total=tot;
		a[i].num=m;
	}
	for(i=0;i<n;i++)
	{
		min=1000000007;
		minj=-1;
		for(j=0;j<n;j++)
		{
			if(a[j].total<min)
			{
				min=a[j].total;
				minj=j;
			}
		}
		printf("%d\n",min);
		for(j=0;j<a[minj].num;j++)
			printf("%d\n",a[minj].arr[j]);
		printf("\n");
		a[minj].total=1000000007;
	}
	return 0;
}
