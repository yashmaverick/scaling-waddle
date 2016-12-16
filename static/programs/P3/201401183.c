#include<stdio.h>
int main()
{
int i,t,n,a[100002],j,max,new;
scanf("%d",&t);
while(t--)
{
max=0;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
i=0,j=1;
while(j<n)
{
new=a[j]-a[i];
if(new>0)
{
if(new>max)
max=new;
}
else i=j;
j++;
}
printf("%d\n",max);
}
return 0;
}
