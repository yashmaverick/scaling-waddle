#include<stdlib.h>
#include<stdio.h>

int main()
{
  long long int ii,ptr1,ptr2,ptr3,val,sum,a,b,c,i,j,k;
  long long int t,p,q,r;
  long long int A[100010]={0};
  long long int AA[100010]={0};
  long long int B[100010]={0};
  long long int BB[100010]={0};
  long long int C[100010]={0};
  long long int CC[100010]={0};
  scanf("%lld", &t);
  for(ii=0;ii<t;ii++)
  {
    for(j=0;j<100010;j++)
    {
      A[j]=0; AA[j]=0; B[j]=0; BB[j]=0; C[j]=0; CC[j]=0;
    }
    sum=0;
    scanf("%lld", &a);
    for(j=0;j<a;j++)
      scanf("%lld", &A[j]);
    scanf("%lld", &b);
    for(j=0;j<b;j++)
      scanf("%lld", &B[j]);
    scanf("%lld", &c);
    for(j=0;j<c;j++)
      scanf("%lld", &C[j]);
    ptr1=0;
    ptr2=0;
    while(ptr1<a && ptr2<b)
    {
      if(ptr1>ptr2)
        ptr2++;
      if(A[ptr1]<=B[ptr2])
      {
        BB[ptr2]+=1;
        ptr1++;
      }
      else
        ptr2++;
    }
    ptr2=1;
    while(ptr2<b)
    {
      BB[ptr2]+=BB[ptr2-1];
      ptr2++;
    }
    ptr2=0;
    ptr3=0;
    while(ptr2<b && ptr3<c)
    {
        if(ptr2>ptr3)
            ptr3++;
        if(B[ptr2]<=C[ptr3])
        {
            CC[ptr3]+=BB[ptr2];
            ptr2++;
        }
        else
            ptr3++;
    }
    ptr3=1;
    while(ptr3<c)
    {
      CC[ptr3]+=CC[ptr3-1];
      ptr3++;
    }
    //printf("%lld%lld%lld\n", BB[0], BB[1]);
    //printf("%lld%lld%lld%lld%lld\n", CC[0], CC[1], CC[2], CC[3], CC[4], CC[5]);
    for(i=0;i<c;i++)
      sum+=CC[i];
    printf("%lld\n", sum);
  }
    return 0;
}
