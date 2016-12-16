#include<stdio.h>

int main()
{
  long long int A[100100];
  long long int profit,max,a,b,n,c,i,j,k;
  long long int t;
  scanf("%lld", &t);
  for(i=0;i<t;i++)
  {
    scanf("%lld", &n);
    for(j=0;j<n;j++)
      scanf("%lld", &A[j]);
    profit=0;
    k=n-2;
    max=A[n-1];
    while(k>=0)
    {
      if(max-A[k]>profit)
        profit=max-A[k];
      if(A[k]>max)
        max=A[k];
      k--;
    }
    printf("%lld\n", profit);
  }
  return 0;
}
