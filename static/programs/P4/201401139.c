#include<stdio.h>

void mergesort(int arr[],int lb,int ub)
{
  if(lb<ub-1)
    {
      int mid=(lb+ub)/2;
      mergesort(arr,lb,mid);
      mergesort(arr,mid,ub);
      int i=lb,j=mid,k=ub,r=lb;
      int arr2[100000];
      while(i<mid&&j<ub)
	{
	  
	  if(arr[i]<arr[j])
	    arr2[r++]=arr[i++];
	  else
	    arr2[r++]=arr[j++];
	}
      while(i<mid)
	arr2[r++]=arr[i++];
      while(j<ub)
	arr2[r++]=arr[j++];
      int a=0;
      for(a=lb;a<ub;a++)
	arr[a]=arr2[a];
    }
}

int main()
{
  int a,b,c,t,sum,count;
  char str[100005];
  int arr[100005];
  scanf("%d",&t);
  while(t>0)
    {
      scanf("%s",str);
      arr[0]=0;
      a=0,sum=0;
      while(str[a])
	{
	  if(str[a]=='J')
	    arr[a+1]=10000;
	  else if(str[a]=='M')
	    arr[a+1]=1;
	  else if(str[a]=='R')
	    arr[a+1]=-10001;
	  a++;
	}
      
      for(b=1;b<a+1;b++)
	{
	  arr[b]=arr[b-1]+arr[b];
	}
      mergesort(arr,0,a+1);
      arr[a+1]=216;
      count=0;
      for(b=0;b<a+1;b++)
	{
	  count++;
	  if(arr[b+1]!=arr[b])
	    {
	      sum+=(count*(count-1))/2;
	      count=0;
	    }
	}
            
      printf("%d\n",sum);
      t--;
    }
  
  return 0;
}
  
