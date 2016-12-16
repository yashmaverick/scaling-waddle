#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
	   return ( *(int*)a - *(int*)b );
}
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
int n,i;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
qsort(a,n,sizeof(int),cmpfunc);
int temp=a[0];
long long int count=1;
long long int sum=0;
long long int ans;
for(i=1;i<n;i++)
{
if(temp==a[i])
{	count++;
//printf("if loop  a[i]: %d i: %dcount: %d\n",a[i],i,count);
}
else
{	sum+=(count*(count-1))/2;
      count=1;
temp=a[i];
//printf("else loop a[i]: %dsum: %lldi: %d\n",a[i],sum,i);
}
}
ans=sum+(count*(count-1))/2;
printf("%lld\n",ans);
}
return 0;
}



