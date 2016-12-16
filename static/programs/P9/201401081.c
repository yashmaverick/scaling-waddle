#include<stdio.h>
#include<stdlib.h>

typedef struct stuff
{
  long int m;
  long int* w;
  long int sum;
}weight_bag;

int n;
weight_bag bag[1005];

void insertion_sort()
{
  int i,j;
  weight_bag temp;
  for(i=2;i<=n;i++)
    {
      j=i-1;
      temp=bag[i];
      while(j>=1&&temp.sum<bag[j].sum)
	{
	  bag[j+1]=bag[j];
	  j--;
	}
      bag[j+1]=temp;
    }
}

int main()
{
  long int MOD;  
  long int i,j;
  scanf("%d",&n);
  scanf("%ld",&MOD);
  for(i=1;i<=n;i++)
    {
      bag[i].sum=0;
      scanf("%ld",&bag[i].m);
      bag[i].w=(long int*)malloc(sizeof(long int)*bag[i].m);
      for(j=0;j<bag[i].m;j++)
	{
	  scanf("%ld",&bag[i].w[j]);
	  bag[i].sum=(bag[i].sum+bag[i].w[j])%MOD;
	}
    }
  insertion_sort();  
  for(i=1;i<=n;i++)
    {
      printf("%ld\n",bag[i].sum);
      for(j=0;j<bag[i].m;j++)
	printf("%ld\n",bag[i].w[j]);
      printf("\n");
    }  
  return 0;
}
