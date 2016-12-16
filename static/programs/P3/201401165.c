#include<stdio.h>
int main()
{
int t,i;
scanf("%d",&t);

for (i=0;i<t;i++)
{
int n,a,pro,max,least,j,b;
scanf("%d",&n);
scanf("%d",&a);
max=pro=0;
least=a;
for(j=1;j<n;j++)
{
scanf("%d",&b);
if(b>least)
{
pro=b-least;
}
else
{
least=b;
}
if(pro>max)
{
max=pro;
}
}
printf("%d\n",max);
}
return 0;
}
