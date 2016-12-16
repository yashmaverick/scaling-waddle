#include<stdio.h>
int main()
{
int t,j;
scanf("%d",&t);
for(j=0;j<t;j++)
{
long long int n,i,min;
long long int a[100001];
long long int max=0;
scanf("%lld",&n);
for(i=0;i<n;i++)
{
scanf("%lld",&a[i]);
if(i!=0 && min>a[i])
{
min=a[i];
}
if(i==0)
{
min=a[0];
}
//printf("%lld\n",b[i-1]);
if((a[i]-min)>max && i!=0)
{
max=a[i]-min;
}
}
printf("%lld\n",max);
}
return 0;
}
