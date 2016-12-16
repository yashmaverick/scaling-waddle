#include<stdio.h>
int main()
{
int n,i,j,f;
scanf("%d",&n);
for(i=0;i<n;i++)
{
long long int min=1000000001;
scanf("%d",&f);
int a[f];
int b[f];
for(j=0;j<f;j++)
scanf("%d",&a[j]);
for(j=0;j<f;j++)
{
if(a[j]<min)
min=a[j];
b[j]=min;
}
 int max=0;
 int c;
 for(j=0;j<f;j++)
{c=a[j]-b[j];
if(c>max)
max=c;
}
printf("%d\n",max);
}
return 0;
}


