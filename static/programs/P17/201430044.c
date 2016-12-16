#include<stdio.h>
#include<stdlib.h>
int main()
{
int *a,*b,n,i,j,x,y,f,l,min,k,t;
scanf("%d",&n);
a=(int *)malloc(sizeof(int)*n);
b=(int *)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
scanf("%d",&b[i]);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
scanf("%d",&t);
while(t--)
{
scanf("%d%d",&x,&y);
for(i=0;i<n;i++)
if(a[i]==x)
{
f=i;
break;
}
for(i=0;i<n;i++)
if(a[i]==y)
{
l=i;
break;
}
if(f>l)
{
int k=l;
l=f;
f=k;
}
for(i=f;i<=l;i++)
{
	int r=a[i];
	for(j=0;j<n;j++)
	{
	if(b[j]==r)
	{
	break;
	}
	}
	if(i==f)
	min=j;
	else
	if(j<min)
	min=j;

}
printf("%d\n",b[min]);
}
return 0;
}
