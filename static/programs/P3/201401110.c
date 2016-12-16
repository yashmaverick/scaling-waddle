#include<stdio.h>
int main()
{
  int t,n,small,large,na,flag=1,i,p[100001],profit;

  scanf("%d",&n);
  for(t=0;t<n;t++)
  {
    profit=0;
    flag=1;
    scanf("%d",&na);
    for(i=0;i<na;i++)
    {
      scanf("%d",&p[i]);
      if(i==0)
      {
        small=p[0];
        large=p[0];
      }
      if(p[i]<small)
        small=p[i];
      else if(p[i]>large)
        large=p[i];

      if(i==0||(p[i-1]>=p[i]&&flag==1))
      {
//        printf("DEBUG! I= %d FLAG= %d\n",i,flag);
        flag=1;
      }
      else if(p[i-1]>=p[i])
      {
        large=0;
      }
      else
        flag=0;
    if(profit<large-small)
      profit=large-small;
    }
    if(flag==1)
      printf("0\n");
    else
      printf("%d\n",profit);

  }
  return 0;
}

