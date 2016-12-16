#include<stdio.h>
#include<math.h>

int powmod(int a,int b)
{
  
  if(b==0)
    return 1;
  if(a==0)
    return 0;

  int x=powmod(a,b/2);
  int y=x*x;
  if(b%2)
    return a*y;
  return y;
    
}

int main()
{
  int n,count,count2,num,temp,ans;
  scanf("%d",&n);
  while(n>0)
    {
      scanf("%d",&num);
      temp=log2(num);
      ans=2*temp;
      //printf("%d\n",temp);
      count=powmod(2,temp);
      count=(count+2*count)/2;
      if(num<count)
	ans--;
      printf("%d\n",ans);
      n--;
    }
  return 0;
}
