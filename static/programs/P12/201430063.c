#include<stdio.h>
int main()
{
int n;
n=-1;
int max;
while(n!=0)
{
long long int count=0;
scanf("%d",&n);
int a[n];
int i,j;
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n-1;i++)
{max=a[i+1];
for(j=i+1;j<n;j++)
{
//printf("j is %d\n",j);
if(a[j]>a[i])
{count+=n-j-1;
break;
}
if(a[j]>max)
max=a[j];
if(a[j]<max)
{count++;
//printf("j is %d a[j]is %d\n",j,a[j]);
}
}
//printf("i is %d count is %lld\n",i,count);
}
if(n!=0)
printf("%lld\n",count);
}
return 0;
}

