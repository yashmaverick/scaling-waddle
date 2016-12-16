#include<stdio.h>
#include<math.h>
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
int a,b,c,d,n,i;
scanf("%d",&n);
i=log2(n);
b=pow(2,i-1);
c=2*i-1;
d=2*i;
if(n!=0)
{
if(n>=b && n<(3*b))
printf("%d\n",c);
else
printf("%d\n",d);
}
else 
printf("0\n");
}
return 0;
}


