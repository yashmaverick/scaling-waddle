#include<stdio.h>
typedef struct node
{
	int val;
	int ind;
	int res;
}node;
int main()
{
	node q[100004];
	int t,n,k,top,end,range,i,el;
	node a[100001];
	scanf("%d",&t);
	while(t--)
	{
		top=0;
		end=0;
		el=0;
		int min=99999999;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i].val);
			a[i].ind=i;
		}
		int j;
		for(i=0;i<=n-k;i++)
		{
			min=999999999;
			for(j=i;j<i+k;j++)
			if(a[j].val<min)
				min=a[j].val;
		
			if(i!=n-k)
			printf("%d ",min);
			else
				printf("%d",min);
		}
			printf("\n");
		
	}
	return 0;
}
