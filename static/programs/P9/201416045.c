#include<stdio.h>
#include<stdlib.h>
typedef struct item item;
struct item {
	int weight;
	int index;
	int noi;
};

int fun( const void *a ,const void *b)
{
	item *aa=( item*)a;
	item *bb=( item*)b;

	return (aa->weight - bb->weight);
}
int main()
{
	item l[1001];
	int **a,c[1001],i,j,sum,s=0,m,n,mod,i1;
	int *d,i2;
	scanf("%d%d",&n,&mod);
	a = (int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
	{
		scanf("%d",&l[i].noi);
		//	printf("%d\n",b[i]);
		//l[i].noi=b[i];
		a[i]=(int *) malloc(sizeof (int)*(l[i].noi+1));
		sum=0;
		for(j=0;j<l[i].noi;j++)
		{
			scanf("%d",&a[i][j+1]);
			//	printf("%d\n",a[i][j+1]);
			//scanf("%d",&d[j]);
			//for(i=0;i<n;i++)
			//	{
			//		a[i]=(int*)malloc(n*sizeof(int));
			//	}

			//	a[s][j+1]=d[j];

			sum=(sum%mod+(a[i][j+1])%mod)%mod;
			//sum=sum%mod;
		}
		//		sum = sum%mod;
		c[i]=sum;
		l[i].weight=sum;
		l[i].index=i;
	}
	for(i2=0;i2<n;i2++)
	{
		a[i2][0]=c[i2];
	}
	qsort(l,n,sizeof(item),fun);
	i=0;
	int a1,a2;
	//	printf("\n");
	for(a1=0;a1<n;a1++)
	{
		for(a2=0;a2<=l[a1].noi;a2++)
		{
			printf("%d\n",a[l[i].index][a2]);
		}
		i++;
		//if(a1<(n-1))
		//	{
		printf("\n");
	}
	//for(j=l[i].index;j<n;i++)
	//{
	//	for(i1=0;i1<l[i].noi;i1++)
	//	{
	//		{
	//			printf("%d\n",a[l[i].index][i1]);
	//		}
	//	}
	//}

	return 0;
	}
