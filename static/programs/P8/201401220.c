#include<stdio.h>
#define modulo 1000000007
int exponent(int a,int b,int c)
{
  if(a==0)
    return 0;
  if(b==0)
    return 1;
  else if(b==1)
    return a;
  int temp=exponent(a,b/2,c);
  if(b%2==0)
    return (temp*temp)%c;
  return (temp*temp*a)%c;
}
int main()
{
  int upper=0,d=0,m=0,n=0;
  int modn=0,i=0,j=0,k=0;
  long long int temp=0,temp1=0,temp2=0;
  int t=0;
  scanf("%d",&t);
  while(t--)
  {
      scanf("%d%d%d%d",&upper,&d,&m,&n);
      int values[n];
      modn = upper%n;
      temp = upper/n;
      long long int ans=0;
      temp1 = (temp*temp)%modulo;
      temp2 = (temp1*temp)%modulo;

      for(i = 0;i < n;i = i+1)
        values[i] = exponent(i,d,n); // Getting the modular exponent value

      for(i = 0;i < n;i = i+1)
      {
        for(j = 0;j < n;j = j+1)
        {
            for(k = 0;k < n;k = k+1)
            {
                int x = values[i] + values[j] + values[k];
                if(x%n == m)
                {
                    ans += (temp2);
                    ans %= modulo;
                }
            }
        }
      }

      for(i = 0;i < modn + 1;i = i+1)
      {
        for(j = 0;j < modn + 1;j = j+1)
        {
            for(k = 0;k < modn + 1;k = k+1)
            {
                int x = values[i] + values[j] + values[k];
                if(x%n == m)
                {
                    ans++;
                    ans %= modulo;
                }
            }
        }
      }

      for(i = 0;i < modn + 1;i = i+1)
      {
        for(j = 0;j < n;j = j+1)
        {
            for(k = 0;k < n;k = k+1)
            {
                int x = values[i] + values[j] + values[k];
                if(x%n == m)
                {
                    ans += (3*temp1);
                    ans %= modulo;
                }
            }
        }
      }

      for(i = 0;i < modn + 1;i = i+1)
      {
        for(j = 0;j < modn + 1;j = j+1)
        {
            for(k = 0;k < n;k = k+1)
            {
                int x = values[i] + values[j] + values[k];
                if(x%n == m)
                {
                    ans += (3*temp);
                    ans %= modulo;
                }
            }
        }
      }

      printf("%lld\n",ans);
    }
  return 0;
}
