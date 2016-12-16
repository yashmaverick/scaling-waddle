#include<stdio.h>
int main()
{
int n,q,i;
scanf("%d",&n);
for(i=0;i<n;i++)
{int count=0;
int f=0;
scanf("%d",&q);
while(q>1)
{
if(q==2)
 f=1;
q=q/2;
count++;
}
if(f==1)
printf("%d\n",2*count-1);
else
printf("%d\n",2*count);
}
return 0;
}
