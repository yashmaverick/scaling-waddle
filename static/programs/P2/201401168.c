#include<stdio.h>
#include<stdio.h>
int f;
int binary(long long int arr[],int ub,long long int item,int m)
{
  int lb=m,mid;
  f=0;
  while(lb<=ub&&f==0)
    {
      mid=(lb+ub)/2;
      if(item<arr[mid])
	ub=mid-1;
      if(item>arr[mid])
	lb=mid+1;
      if(item==arr[mid]||(arr[mid-1]<item&&arr[mid]>item))
	{f=1;}
    }
  return mid;
}
int main()
{
  long long int a[100002],b[100002],c[100002],sum;
  int i,j,k,n1,n2,n3,t;
  scanf("%d",&t);
  while(t!=0)
    {
      sum=0;
      long long int d[100002]={0};
      scanf("%d",&n1);
      for(i=0;i<n1;i++)
	scanf("%lld",&a[i]);
      scanf("%d",&n2);
      for(i=0;i<n2;i++)
	scanf("%lld",&b[i]);
      scanf("%d",&n3);
      for(i=0;i<n3;i++)
	scanf("%lld",&c[i]);
      for(j=n2-1;j>=0;j--)
	{
	  if(j<=n3-1&&c[j]>=b[j])
	    {k=j;f=1;}
	  else
	    k=binary(c,n3-1,b[j],j);
	  if(f==1)
	    {
	      while(c[k-1]==c[k]&&k>j)
		k--;
	      sum=sum+(n3-k);
	      d[j]=sum;
	    }
	}
      sum=0;
      for(i=n1-1;i>=0;i--)
	{
	  if(i<=n2-1&&b[i]>=a[i])
	    {k=i;f=1;}
	  else
	    k=binary(b,n2-1,a[i],i);
	  if(f==1)
	    {
	      while(b[k-1]==b[k]&&k>i)
		k--;
	      sum=sum+d[k];
	    }
	}
      printf("%lld\n",sum);
      t--;
    }
}
