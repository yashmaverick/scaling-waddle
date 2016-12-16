#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
struct node
{
	int elm;
	int wgt;
	int ind;
	//	node* pnt;
};

int compare (const void * a, const void * b)
{
	node *aa = (node *)a;
	node *bb = (node *)b;
	return aa->wgt - bb->wgt;
}
int main()
{
	int n,mod,i,j,m,sum;
	scanf("%d%d",&n,&mod);
	int **a;
	a = (int **)malloc(n * sizeof(int *));
	node b[1000];
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		a[i] = (int*)malloc(m*sizeof(int));
		sum=0;
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
			sum=(sum+a[i][j])%mod;
		}
		b[i].elm=m;
		b[i].wgt=(sum)%mod;
		//b[i].pnt=&a[i][0];
		b[i].ind=i;
		//printf("pnt:%d\n",b[i].pnt);
	}

	qsort(b,n,sizeof(node),compare);

	for(i=0;i<n;i++)
	{
		//	int r=*b[i].pnt;
		printf("%d\n",b[i].wgt);
		for(j=0;j<b[i].elm;j++)
		{
			int r=b[i].ind;
			printf("%d\n",a[r][j]);
		}
	//	if(i<n-1)
			printf("\n");
	}
	return 0;
}
