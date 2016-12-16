#include<stdio.h>
long long int a[1000000],b[1000000],c[1000000],sumb[1000000];
int bs(long long int a[],int low,int high,int searc);

int main()
{
  int x,t;
  scanf("%d",&t);
  for(x=0;x<t;x++)
    {
      int p,q,r,i,j,k,index1,index2;
      long long int suma=0;
      scanf("%d",&p);
      for(i=0;i<p;i++)
	{
	  scanf("%lld",&a[i]);
	}
      scanf("%d",&q);
      for(j=0;j<q;j++)
	{
	  scanf("%lld",&b[j]);
	}
      scanf("%d",&r);
      for(k=0;k<r;k++)
	{
	  scanf("%lld",&c[k]);
	}
      for(j=q-1;j>=0;j--)
	{
	  index1=bs(c,j,r,b[j]);
	  // printf("came for %d got %d whose index is:%d\n",b[j],c[index1],index1);
	  //printf("sumbj+1 is :%d\n",sumb[j+1]);
	  sumb[j]=r-index1+sumb[j+1];
	  //printf("sumb[%d] is:%d\n",j,sumb[j]);
	}
      for(i=0;i<p;i++)
	{
	  index2=bs(b,i,q,a[i]);
	  //printf("came with a for %d got %d whose index is:%d\n",a[i],b[index2],index2);
	  suma+=sumb[index2];
	}
      printf("%lld\n",suma);
    }
  return 0;
}

int bs(long long int a[],int low,int high,int search)
{
  int mid=(low+high)/2;
  int i,j,k;
  if(low >= high)
    {
      return high;
    }
  else if(a[mid] < search)
    {
      return bs(a,mid+1,high,search);
    }
  else if(a[mid] >= search && a[mid-1] >= search)
    {
      return bs(a,low,mid,search);
    }
  else if(a[mid] >= search && a[mid-1] < search)
    {
      return mid;
    }
}
