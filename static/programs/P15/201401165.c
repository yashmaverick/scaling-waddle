#include<stdio.h>
#include<stdlib.h>
int main()
{
//test
int t;
scanf("%d",&t);
while(t>0)
{
//scaning
int n,k,r,m,i,x;
long long int min;
scanf("%d%d",&n,&k);
long long int *a;
a=malloc(n*sizeof(long long int));
for(x=0;x<n;x++)
{
scanf("%lld",&a[x]);
}
//min
min=99999999;
m=0;
r=0;
while(m<n-k+1)
{
if(r==0)
{
for(i=0;i<k;i++)
{

if(a[i+m]<min)
{
min=a[i+m];
}	

}

}
if(m==n-k)
{
printf("%lld",min);
}
else
{
printf("%lld ",min);
}
if(a[m]==min)
{
r=0;
min=99999999;
}
else
{
if(min>a[m+k])
{
min=a[m+k];
}
r=1;
}
m++;
}
printf("\n");
t--;
}
return 0;
}
