#include<stdio.h>
int main()
{
int t,n,i,a[100001],ans,diff,sp;
scanf("%d",&t);
while(t--)
{
ans=0;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
sp=a[n-1];

for(i=n-2;i>=0;i--)
{
diff=sp-a[i];
if(diff>ans)
ans=diff;
if(diff<0)
sp=a[i];
}
printf("%d\n",ans);
}
return 0;
}


