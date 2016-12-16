#include<stdio.h>
#include<math.h>
int main()
{
int t,i,n,j,p;
scanf("%d",&t);
for(i=0;i<t;i++)
{
scanf("%d",&n);
if(n!=1)
{
for(j=0;pow(2,j)<=n;j++)
{}
p=j-1;
if(n<(pow(2,p)+pow(2,p+1))/2)
printf("%d\n",2*p-1);
else
printf("%d\n",2*p);
}
else
printf("0\n");
}
return 0;
}






