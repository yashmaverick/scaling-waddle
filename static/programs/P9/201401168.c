#include<stdio.h>
#include<stdlib.h>
typedef struct troy
{
  long int sum;
  int weight;
  long int *a;
}car;
void merge(car *arr,int lb,int mid,int ub)
{
  int m=mid+1,i=0,low=lb,high=ub;
  car a[ub-lb+1];
  while(lb<=mid&&m<=ub)
    {
      if(arr[lb].sum<arr[m].sum)
	a[i++]=arr[lb++];
      else if(arr[m].sum<arr[lb].sum)
	a[i++]=arr[m++];
      else
      {
          a[i++]=arr[lb++];
          a[i++]=arr[m++];
      }
    }
    while(lb<=mid)
      a[i++]=arr[lb++];
    while(m<=ub)
      a[i++]=arr[m++];
  i=0;
  for(m=low;m<=high;m++)
    {
      arr[m]=a[i];
      i++;
    }
}
void sort(car arr[],int low,int high)
{
  if(low<high)
    {
      int mid=(low+high)/2;
      sort(arr,low,mid);
      sort(arr,mid+1,high);
      merge(arr,low,mid,high);
    }
}
int main()
{
  int n,m,i,j;
  long int mod;
  car arr[1001];
  scanf("%d %ld",&n,&mod);
  for(i=0;i<n;i++)
    {
      scanf("%d",&m);
      arr[i].a=(long int*)malloc(m*sizeof(long int));
      arr[i].weight=m;
      arr[i].sum=0;
      for(j=0;j<m;j++)
	{
	  scanf("%ld",&(arr[i].a[j]));
          arr[i].sum=(arr[i].sum+arr[i].a[j])%mod;
	}
    }
  sort(arr,0,n-1);
  for(i=0;i<n;i++)
    {
      printf("%ld\n",arr[i].sum);
      for(j=0;j<arr[i].weight;j++)
	{
	  printf("%ld\n",(arr[i].a[j]));
	}
      printf("\n");
    }
  return 0;
}

