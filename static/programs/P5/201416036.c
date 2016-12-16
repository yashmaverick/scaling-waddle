#include<stdio.h>
void quick(int night[],int low,int high)
{
  if(low<high)
  {
    int divide,pivot,i,temp;
    divide=low;
    pivot=high;
    for(i=low;i<high;i++)
    {
      if(night[i]<night[pivot])
      {
        temp=night[i];
        night[i]=night[divide];
        night[divide]=temp;
        divide++;
      }
    }
    temp=night[pivot];
    night[pivot]=night[divide];
    night[divide]=temp;
    quick(night,low,divide-1);
    quick(night,divide+1,high);
  }
}
int main()
{
  int test;
  scanf("%d",&test);
  while(test--)
  {
    char s[1000];
    int night[1007],n,sum,found=0,i,start,end;
    scanf("%d%d",&n,&sum);
    for(i=0;i<n;i++)
    {
      scanf("%s%d",s,&night[i]);
    }
    quick(night,0,n-1);
    for(i=0;i<n-2;i++)
    {
      start=i+1;
      end=n-1;
      while(start<end)
      {
        if(night[i]+night[start]+night[end]==sum)
        {
          found=1;
          break;
        }
        else if(night[i]+night[start]+night[end]>sum)
          end--;
        else
          start++;
      }
      if(found)
        break;
    }
    if(found)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
