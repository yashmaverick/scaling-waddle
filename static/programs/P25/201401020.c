#include<stdio.h>
#include<stdlib.h>
typedef struct set
{
	int l,k;
	int wt;
}set;
set arr[100005];
int parent[100005];
int father(int a)
{
	if(parent[a]==a)
		return a;
	parent[a]=father(parent[a]);
	return father(parent[a]);
//	while(parent[a]!=a)
//		a=parent[a];
//	return a;
}
void print(int n)
{
	int j;
	printf("par ");
	for(j=1;j<=n;j++)
		printf("%d ",parent[j]);
	printf ("\n");
}


int srt(const void *x,const void *y)
{
	set *A=(set *)x;
	set *B=(set *)y;
	return(A->wt-B->wt);
}
int main()
{
	int n,m,i,j;
	int index[1000005];
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		parent[i]=i;
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&arr[i].l,&arr[i].k,&arr[i].wt);
	//	parent[arr[i].l]=arr[i].k;
	}

//	printf("hello\n");
	qsort(arr,m,sizeof(set),srt);
//	for(i=0;i<m;i++){
//		printf("%d ",arr[i].wt);
//	}
//	printf("\n");
	long long int sum=0;
	int num=0;
	for(i=0;i<=m;i++)
	{
	//	print(n);
		if( father(arr[i].l) != father(arr[i].k) )
		{
			parent[father(arr[i].l)]=father(arr[i].k);
		//	printf("a");
			sum+=arr[i].wt;
			num++;
		//	print(n);
		//	printf("sum=%d\n",sum);
		}
	}
	if(num==n-1)
		printf("%lld\n",sum);
	else
		printf("-1\n");
	return 0;
}
