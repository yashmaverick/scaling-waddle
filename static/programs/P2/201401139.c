#include<stdio.h>

int binarysearch(int arr[],int low,int item,int n)
{
  int lb=low,ub=n-1,mid;
  
  if(arr[n-1]<item)
    return n;
  
  while(lb<ub)
    {
      mid=(lb+ub)/2;
      if(arr[mid]>item)
	ub=mid;
      else if(arr[mid]<item)
	lb=mid+1;
      else
	return mid;
    }
  
  return ub;
}


int main()
{
  int arr1[100005],arr2[100005],arr3[100005];
  long long int arr4[100005];
  int p,q,r,j;
  int a,b,c,t,k;
  long long int count=0;
  scanf("%d",&t);
  while(t>0)
    {
      scanf("%d",&p);

      for(a=0;a<p;a++)
	scanf("%d",&arr1[a]);

      scanf("%d",&q);

      for(a=0;a<q;a++)
	scanf("%d",&arr2[a]);

      scanf("%d",&r);

      for(a=0;a<r;a++)
	scanf("%d",&arr3[a]);
      
      
      if(q>r)
	q=r;
      if(p>q)
	p=q;
      count=0;

      arr4[q]=0;

      for(a=q-1,b=p-1;a>=0;a--)
	{
	  j=binarysearch(arr3,a,arr2[a],r);
	  arr4[a]=(r-j)+arr4[a+1];
	  if(a<=b)
	    {
	      k=binarysearch(arr2,a,arr1[a],q);
	      count+=arr4[k];
	      b--;
	    }
	}
      
      printf("%lld\n",count);
      t--;
    }
  return 0;
}
