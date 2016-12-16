#include<stdio.h>

long long int A[1000010];
long long int B[1000010]={0};

int main()
{
  long long int min=10000001,max=-10000001,a,b,c,n,i,j,k,t;
  long long int sum;
  scanf("%lld", &t);
  for(i=0;i<t;i++)
  {
     sum=0;
     for(j=0;j<1000010;j++)
        B[j]=0;
     min=10000001;
     max=-10000001;
     scanf("%lld", &n);
     for(j=0;j<n;j++)
     {
        scanf("%lld", &A[j]);
        if(A[j]<min)
          min=A[j];
        if(A[j]>max)
          max=A[j];
     }
     for(j=0;j<n;j++)
     {
       A[j]-=min;
       B[A[j]]++;
     }
     for(j=0;j<max-min+1;j++)
       if(B[j]>1)
         sum=sum+B[j]*(B[j]-1)/2;
     printf("%lld\n", sum);
  }
  return 0;
}
