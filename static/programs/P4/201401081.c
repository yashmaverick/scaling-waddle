#include<stdio.h>

long long int a[100009];
long long int n;

long long int part(long long int beg,long long int end)
{
  long long int key;
  long long int wall;
  long long int temp;
  key=a[end];
  wall=beg-1;
  long long int i;
  for(i=beg;i<=end;i++)
    if(a[i]<key)
      {
	temp=a[i];
	a[i]=a[wall+1];
	a[wall+1]=temp;
	wall++;
      }
  temp=a[wall+1];
  a[wall+1]=a[end];
  a[end]=temp;
  wall++;
  return wall;
}

void quick_s(long long int beg,long long int end)
{
  if(beg>=end)
    return;
  long long int p;
  p=part(beg,end);
  quick_s(p+1,end);
  quick_s(beg,p-1);
}

void mergesort(long long int arr[],long long int beg,long long int end)
{
  long long int mid;
  long long int i,j,k;
  long long int temp[100000];
  if(beg>=end-1)
    return;
  else
    {
      mid=(beg+end)/2;
      mergesort(arr,beg,mid);
      mergesort(arr,mid,end);
      i=beg,j=mid,k=beg;
      while(i<mid&&j<end)
	{	  
	  if(arr[i]<arr[j])
	    temp[k++]=arr[i++];
	  else
	    temp[k++]=arr[j++];
	}
      while(i<mid)
	temp[k++]=arr[i++];
      while(j<end)
	temp[k++]=arr[j++];
      for(i=beg;i<end;i++)
	arr[i]=temp[i];
    }
}

int main()
{
  int t;
  long long int i,count;
  char input[100009];
  scanf("%d",&t);
  while(t--)
    {
      long long int sum;
      i=0;
      sum=0;
      count=1;
      scanf("%s",input);
      for(i=1;input[i-1]!='\0';i++)
	{
	  if(input[i-1]=='J')
	    a[i]=a[i-1]+100000;
	  else if(input[i-1]=='M')
	    a[i]=a[i-1]-1;
	  else if(input[i-1]=='R')
	    a[i]=a[i-1]-99999;
	}
      n=i;
      //quick_s(0,n-1);
      /* for(i=0;i<n;i++) */
      /* 	printf("%lld ",a[i]); */
      /* printf("\n"); */
      mergesort(a,0,n);
      /* for(i=0;i<n;i++) */
      /* 	printf("%lld ",a[i]); */
      /* 	  printf("\n");	    */
      for(i=1;i<n;i++)
      	{
      	  if(a[i]==a[i-1])
      	    count++;
      	  else
      	    {
      	      sum+=count*(count-1)/2;
      	      count=1;
      	    }
      	}
      sum=sum+count*(count-1)/2;
      printf("%lld\n",sum);
    }
  return 0;
}

