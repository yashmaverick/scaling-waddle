#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int sum;
	int m;
	int* pt;
}ll;
int comp( const void *p, const void *q)
{
	int l=((ll*)p)->sum;
	int r=((ll*)q)->sum;
	return (l-r);
}
void print(ll *b,int n)
{
	int i=0;
	printf("b.sum\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",b[i].sum);
		}
	}
int main()
{
  	int n,m,mod,i,j,sum;
		scanf("%d %d",&n,&mod);
		int **a;
		int *k;
		ll *b;
		a=(int**)malloc(sizeof(int*)*n);
		b=(ll*)malloc(sizeof(ll)*n);
		for(i=0;i<n;i++)
		{
      scanf("%d",&m); 
			a[i]=(int*)malloc(sizeof(int)*m);
			sum=0;
			for(j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
        sum=(sum+a[i][j])%mod; 
			}
		
     b[i].sum=sum;
		 b[i].m=m;
		 b[i].pt=a[i];
	//	 print(b,i+1);
		}
		 qsort(b,n,sizeof(ll),comp);
		// print(b,n);
		 for(i=0;i<n;i++)
      {
        printf("%d\n",b[i].sum);
				k=b[i].pt;
				for(j=0;j<b[i].m;j++)
				{
          printf("%d\n",k[j]);
				}
				printf("\n");
			}	
		return 0;	
}
