#include<stdio.h>

long long int a[1000005],n;
int MAX=1000005;

void print_arr()
{
  long int i;
  for(i=0;i<n;i++)
    printf("%lld ",a[i]);
  printf("\n");
}



void mergeSort(long long int arr[],int low,int mid,int high){

  int i,m,k,l,temp[MAX];

  l=low;
  i=low;
  m=mid+1;

  while((l<=mid)&&(m<=high)){

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

void partition(long long int arr[],int low,int high){

  int mid;

  if(low<high){
    mid=(low+high)/2;
    partition(arr,low,mid);
    partition(arr,mid+1,high);
    mergeSort(arr,low,mid,high);
  }
}

long int find_poss(long int count)
{
  long int temp;
  temp=count*(count-1);
  temp/=2;
  return temp;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      long int i;
      scanf("%lld",&n);
      for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
      partition(a,0,n-1);
      //print_arr();
      long int count;
      long int sum;
      sum=0;
      a[n]=0;
      for(i=0;i<n;i++)
	{
	  count=1;
	  while(a[i+1]==a[i])
	    {
	      count++;
	      i++;
	    }
	  sum+=find_poss(count);
	}
      printf("%ld\n",sum);
    }
  return 0;
}  
