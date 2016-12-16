#include<stdio.h>
int main()
{
int t;
scanf("%d\n",&t);
while(t>0)
{
long long int n,k,q,e,zx,j;
long long int b[1000];
scanf("%lld%lld",&n,&k);
for(q=0;q<n;q++)
{
e=2;
while(e!=' ')
{
scanf("%c",&e);
}
scanf("%lld",&b[q]);
}
long long int r,temp;
for(r=1;r<n;r++)
{
temp=b[r];
for(e=r;e>0 && temp<b[e-1]  ;e--)
{
b[e]=b[e-1];
b[e-1]=temp;
temp=b[e-1];
}
}
//for(j=0;j<n;j++)
//{
//printf("%d",b[j]);
//}
long long int numa,numb,numc,re;
for(numa=0;numa<n;numa++)
{
re=0;
numb=numa+1;
numc=n-1;
while(numb<numc && numb!=numc)
{
if(b[numa]+b[numb]+b[numc]>k)
{
numc--;
}
else if(b[numa]+b[numb]+b[numc]<k)
{
numb++;
}
else if(b[numa]+b[numb]+b[numc]==k)
{
re=1;
break;
}
}
if(re==1)
{
break;
}
}
if(re==1)
{
printf("YES\n");
}
else
{
printf("NO\n");
}
t--;
}
return 0;
}
