#include<stdio.h>
#include<stdlib.h>

int MOD;

typedef struct dabba
{
  int *arr;
  int sum;
  int size;
}node;


void printlist(node array[],int n)
{
  int a,b;
  for(a=0;a<n;a++)
    {
      printf("%d\n",array[a].sum);
      for(b=0;b<array[a].size;b++)
      {
	printf("%d\n",array[a].arr[b]);
      }
      printf("\n");
    }
}

void selectionsort(node array[],int n)
{
  int a,b,min,pos;
  node temp;
  for(a=0;a<n;a++)
    {
      min=array[a].sum;
      pos=a;
      for(b=a;b<n;b++)
	{
	  if(array[b].sum<min)
	    {
	      min=array[b].sum;
	      pos=b;
	    }
	}
      temp=array[pos];
      array[pos]=array[a];
      array[a]=temp;
    }
}

void insertionsort(node array[],int n)
{
  node temp;
  int a,b;

  for(a=1;a<n;a++)
    {
      b=a-1;
      while(b>=0 && array[a].sum>array[b].sum)
	{
	  
	  b--;
	}
      temp=array[b+1];
      array[b+1]=array[a];
      array[a]=temp;
    }
}

int main()
{
  int n,m,item,a,b,sum;
  node array[1005];
  scanf("%d",&n);
  scanf("%d",&MOD);
  
  for(a=0;a<n;a++)
    {
      sum=0;
      scanf("%d",&m);
      array[a].arr=(int *)malloc(m*sizeof(int));
      array[a].size=m;
      for(b=0;b<m;b++)
	{
	  scanf("%d",&item);
	  array[a].arr[b]=item;
	  sum=(sum+(item%MOD))%MOD;
	}
      array[a].sum=sum;
    }
  selectionsort(array,n);
  printlist(array,n);
  return 0;
}
	  
