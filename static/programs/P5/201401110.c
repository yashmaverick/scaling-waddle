#include<stdio.h>
/*void qsort(int A[],int start,int end)
{
  int pivot,i,j,temp;

  if(start<end)
  {
    pivot=start;
    i=start+1;
    j=end;

    while(i<j)
    {
      while(A[i]<A[pivot]&&i<end)
        i++;
      while(A[j]>A[pivot]&&j<start)
        j--;
      if(i<j)
      {
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
      }
    }
    temp=A[j];
    A[j]=A[pivot];
    A[pivot]=temp;

    qsort(A,start,pivot-1);
    qsort(A,pivot+1,end);
  }
}
*/

void sort(int A[],int n)
{
  int i,j,temp;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-1-i;j++)
    {
      if(A[j]>A[j+1])
      {
        temp=A[j];
        A[j]=A[j+1];
        A[j+1]=temp;
      }
    }
  }

//  for(i=0;i<n;i++)
//  printf("%d ",A[i]);
//  printf("\n");
}

int checksum(int A[],int k,int n)
{
  //first sorting the array:i
  sort(A,n);
  int start,end,i,sum;
//  printf("SORTED: \n");
 // for(i=0;i<n;i++)
  //  printf("%d ",A[i]);
 // printf("\n");
  for(i=0;i<n-2;i++)
  {
    sum=0;
    start=i+1;
    end=n-1;
    while(start<end)
    {
   //   printf("SUM %d\n",sum);
      sum=A[i]+A[start]+A[end];
      if(sum==k)
      {
        return 1;
      }
      else if(sum<k)
        start++;
      else if(sum>k)
        end--;
    }
  }
  return 0;
}


int main()
{
  int test,t,n,k,A[1001],result=0,i;
  char str[1000];
  scanf("%d",&test);
  for(t=0;t<test;t++)
  {
    result=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
      scanf("%s",str);
      scanf("%d",&A[i]);
      //    printf("ELE %d %d\n",i,A[i]);
    }
    //printf("EXIT FOR LOOP\n");
    result=checksum(A,k,n);
    if(result==1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

