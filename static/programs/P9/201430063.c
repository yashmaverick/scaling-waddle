#include<stdio.h>
#include<stdlib.h>
typedef struct p1
{
int s;
int *arr;
long long int sum;
}p1;
int main()
{
int n,m;
scanf("%d %d",&n,&m);
p1 a[n];
int i,j;
for(i=0;i<n;i++)
{scanf("%d",&a[i].s);
a[i].arr=(int*)malloc(a[i].s*sizeof(int));
a[i].sum=0;
for(j=0;j<a[i].s;j++)
{
scanf("%d",&a[i].arr[j]);
a[i].sum=(a[i].sum+a[i].arr[j])%m;
}
}
//for(i=0;i<n;i++)
//printf("%lld\n",a[i].sum);
 int c[1000][2];
for(i=0;i<n;i++)
{c[i][0]=a[i].sum;
c[i][1]=i;
}
//for(i=0;i<n;i++)
//printf("%d\n",c[i][0]);
int temp;
int temp1;
for(i=0;i<n;i++)
for(j=0;j<n-1;j++)
if(c[j][0]>c[j+1][0])
{temp=c[j+1][0];
c[j+1][0]=c[j][0];
c[j][0]=temp;
temp1=c[j+1][1];
c[j+1][1]=c[j][1];
c[j][1]=temp1;
}
//for(i=0;i<n;i++)
//printf("%d %d\n",c[i][0],c[i][1]);


int d;

for(i=0;i<n;i++)
{d=c[i][1];
printf("%lld\n",a[d].sum);
for(j=0;j<a[d].s;j++)
printf("%d\n",a[d].arr[j]);
printf("\n");
}
return 0;
}





