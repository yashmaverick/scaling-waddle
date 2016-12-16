#include<stdio.h>
typedef long long int ll;
void sort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high)
{
  ll mid;
  if(low<high){
    mid=(low+high)/2;
    partition(arr,low,mid);
    partition(arr,mid+1,high);
    sort(arr,low,mid,high);
  }
}

void sort(int arr[],int low,int mid,int high)
{
  int i,m,k,l,temp[1000000];
  l=low;
  i=low;
  m=mid+1;
  while((l<=mid)&&(m<=high))
  {
    if(arr[l]<=arr[m]){
      temp[i]=arr[l];
      l++;
    }
    else{
      temp[i]=arr[m];
      m++;
    }
    i++;
  }

  if(l>mid){
    for(k=m;k<=high;k++){
      temp[i]=arr[k];
      i++;
    }
  }
  else{
    for(k=l;k<=mid;k++){
      temp[i]=arr[k];
      i++;
    }
  }

  for(k=low;k<=high;k++){
    arr[k]=temp[k];
  }
}
ll counter(int A[],int n)
{
  /*  printf("ENTERED\n");
      if(i==n-1)
      {
      printf("%d\n",count);
      return ;
      }
      int c=0,counti;
      while(A[i]==A[i+1])
      {
      c++;
      i++;
      }
      printf("ENTERED COUNTER!\n");
      counti=((c*(c-1))/2);
      count+=counti;
      i++;
      counter(A,count,i,n);*/
 ll i,flag=0,count=0,pairc=0;
  for(i=0;i<n;i++)
  {
    if(A[i]==A[i+1]&&i<n-1)
    {
      flag=1;
      count++;
//      printf("%lld\n",count);
    }
    else if(A[i]!=A[i+1]||A[n-2]==A[n-1])
    {
      count++;
      flag=0;
      pairc+=(((count)*(count-1))/2);
  //    printf("%lld\n",pairc);
      count=0;
    }
  }

  return(pairc);
} 

int main()
{
  int i,test,t,A[1000000],n,flag=1;
  long long int ans=0,countz;
  scanf("%d",&test);
  for(t=0;t<test;t++)
  {
    flag=1;
    countz=ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
     /* if(A[i]==0&&flag==1)
      {
        countz++;
        flag=1;
      }
      else
        flag=0; */
    }
    partition(A,0,n-1);
  // for(i=0;i<n;i++)
    //printf("%d",A[i]);
   // printf("\n");
    //printf("GOING TO\n");
/*    if(flag==1)
      ans=((countz*(countz-1))/2);*/
     ans+=counter(A,n);
  printf("%lld\n",ans);
  }
  return 0;
}
