#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	long long int sum;
	int val;
	int index;
};
int compare(const void *a,const void *b)  //stable
{
	node *q,*w;
	q=(node *)a;
	w=(node *)b;
	if(q->sum>w->sum)
		return 1;
	else if(q->sum<w->sum)
		return -1;
	else
		return 0;
}

int main()
{
	int a[1000000];
	long long int j=0;
	int b,i;
	node c[10000];
	int mod;
	scanf("%d %d",&b,&mod);
	for(i=0;i<b;i++)
	{
		int l;
		scanf("%d",&c[i].val);
		c[i].index=j;
		for(l=j;l<j+c[i].val;l++)
		{
			scanf("%d",&a[l]);
			c[i].sum+=a[l]%mod;
			c[i].sum=c[i].sum%mod;
		}
		j+=c[i].val;
	}
	qsort(c,b,sizeof(node),compare);
//	quick_sort(c,0,b-1);
	for(i=0;i<b;i++)
	{
		int l;
		printf("%lld\n",c[i].sum);
		j=c[i].index;
		for(l=j;l<j+c[i].val;l++)
		{
			printf("%d\n",a[l]);
		}
		printf("\n");
	}
	return 0;
}


