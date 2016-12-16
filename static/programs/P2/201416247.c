#include<stdio.h>
int main()
{
int i,j,k,a[100000],b[100000],c[100000],t,m;
scanf("%d",&m);
	for(t=0;t<m;t++){
int count=0,n1,n2,n3;
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	scanf("%d",&a[i]);
	scanf("%d",&n2);
	for(i=0;i<n2;i++)
	scanf("%d",&b[i]);
	scanf("%d",&n3);
	for(i=0;i<n3;i++)
	scanf("%d",&c[i]);
for(k=0;k<n3;k++)
for(j=0;j<=k;j++)
for(i=0;i<=j;i++)
if(b[j]<=c[k])
if(a[i]<=b[j])
count++;
printf("%d\n",count);
}
return 0;
}


