#include<stdio.h>

long long int expon(long long int a,long long int b)
{
  if(b==0)
    return 1;
  if(b==1)
  {
    return (a);
  }
  long long int x=expon(a,b/2);
  long long int y=(x*x);
  if(b%2==0) // i is even
    return((y));

  if(b%2!=0)
    return((y*a));

}

int counter(int x,int count)
{
  if(x==1)
  {
    return(count);
  }
  else
  {
 //   printf("count in function for x %d: %d\n",x,count);
    count=counter(x/2,count+1);
  }
}

int main()
{
  int count,q,test,t;
  long long int limit;
  scanf("%d",&test);
  for(t=0;t<test;t++)
  {
    count=0;
    scanf("%d",&q);
    count=counter(q,count);
//   printf("%d\n",count);
    long long int value=expon(2,count);
    limit=value+(value/2)-1;
    if(q<=limit)
      count=(2*count)-1;
    else 
      count=2*count;
    
    printf("%d\n",count);
  }
  return 0;
}
