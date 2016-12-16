#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a,const void *b)
{
  return (*(int *)a - *(int *)b);
}
int flag=0;
void bs(int a[],int low,int high,int search);


int main()
{
  int i,t;
  scanf("%d",&t);
  for(i=0;i<t;i++)
    {
      int n,k,a[1000000];
      flag=0;
      char d,s[1000000];
      scanf("%d%d",&n,&k);
      int j;
      for(j=0;j<n;j++)
	{
	  scanf("%c%s%d",&d,s,&a[j]);
	}
      qsort(a,n,sizeof(int),cmpfunc);
      //  for(j=0;j<n;j++)
      //printf("%d ",a[j]);
      //printf("\n");
      int l;
      for(j=0;j<n;j++)
	{
	  for(l=j+1;l<n;l++)
	    {
	      int search=k-a[j]-a[l];
	      bs(a,l+1,n,search);
	      if(flag==1)
		{
		  printf("YES\n");
		  break;
		}
	    }
	  if(flag==1)
	    break;
	}
      if(flag==0)
	{
	  printf("NO\n");
	}
    }
  return 0;
}

void bs(int a[],int low,int high,int search)
{
  int mid=(low+high)/2,i,j;
  if(low>=high)
    return;
  else if(a[mid]==search)
    {
      flag=1;
      return;
    }
  else if(a[mid] > search)
    {
      bs(a,low,mid,search);
    }
  else if(a[mid] < search)
    {
      bs(a,mid+1,high,search);
    }
}
