#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int sum;
  int num;
  int *arrptr;
}nodes;

int compare(const void *a,const void *b)
{
   nodes *a1=(nodes *)(a);
   nodes *b1=(nodes *)(b);
  return ((a1->sum) - (b1->sum));
}


int main()
{
  int n,mod,j;
  int **a;
  scanf("%d%d",&n,&mod);
  a=(int **)malloc(sizeof(int *)*n);
  nodes data[1000];
  int i;
  for(i=0;i<n;i++)
    {
      scanf("%d",&data[i].num);
      a[i]=(int*)malloc(sizeof(int)*(data[i].num));
      data[i].arrptr=a[i];
      data[i].sum=0;
      for(j=0;j<data[i].num;j++)
	{
	  scanf("%d",&a[i][j]);
	  data[i].sum=(data[i].sum+a[i][j])%mod;
	}
      //      printf("data[%d] sum is %d\n",i,data[i].sum);
      data[i].sum=(data[i].sum%mod);
    }
  qsort(data,n,sizeof(nodes),compare);
  // printf("starting output");
  for(i=0;i<n;i++)
    {
      printf("%d\n",data[i].sum);
      for(j=0;j<(data[i].num);j++)
	{
	  printf("%d\n",(data[i].arrptr)[j]);
	}
      printf("\n");
    }
  return 0;
}
