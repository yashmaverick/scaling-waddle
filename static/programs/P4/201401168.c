#include<stdio.h>
#include<string.h>
void merge(long long int arr[],int lb,int mid,int ub)
{
  long long int a[100000];
  int m=mid+1,i=0,low=lb,high=ub;
  while(lb<=mid&&m<=ub)
    {
      if(arr[lb]>=arr[m])
	a[i++]=arr[lb++];
      else
	a[i++]=arr[m++];
    }
  if(lb<=mid)
    while(lb<=mid)
      a[i++]=arr[lb++];
  else
    while(m<=ub)
      a[i++]=arr[m++];
  i=0;
  for(m=low;m<=high;m++)
    {
      arr[m]=a[i];
      i++;
    }
}
void sort(long long int arr[],int low,int high)
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
  int t,j=10001,r=1,m=-10002,n,i;
  long long int a[1000000],count,sum;
  char s[100000],p;
  scanf("%d",&t);
  while(t--)
    {
      a[0]=0;i=1;
      scanf("%s",s);   	
      if(s[0]=='J')
	a[i]=j;
      else
	if(s[0]=='R')
	  a[i]=r;
	else
	  if(s[0]=='M')
	    a[i]=m;
      i=2;
      n= strlen(s);
      //  printf("n=%d\n",n);
      //printf("%d %d ",a[0],a[1]);
      for(i=2;s[i-1]!='\0';i++) //SHOULDN'T i be = 1
	{
	  if(s[i-1]=='J')
	    a[i]=a[i-1]+j;
	  else
	    if(s[i-1]=='R')
	      a[i]=a[i-1]+r;
	    else
	      if(s[i-1]=='M')
		a[i]=a[i-1]+m;
	  //printf("%d ",a[i]);  //to remove
	}
      // printf("i=%d\n",i);
      //printf("\n");
      sort(a,0,i-1);
      //for(x=0;x<i;x++)
	//printf("%d ",a[x]);
      n=i-1;count=1;sum=0;
      for(i=1;i<n+1;i++)
	{
	  // printf("%d ",a[i]);//to remove
	  if(a[i-1]==a[i])
	      count++;
	  else
	    {
	      sum=sum+count*(count-1)/2;
	      // if(a[i-1]==0)//?
		//	c++;       //?
	      count=1;
	    }
	}
      printf("%lld\n",sum+count*(count-1)/2);
    }
  return 0;
}
      
	    
