#include<stdio.h>
void swap(int *x,int *y)
{int t;
  t=*x;
  *x=*y;
  *y=t;
}
int main()
{int t,i,n,j,dif,a[100010];
scanf("%d",&t);
for(i=0;i<t;i++)
{ scanf("%d",&n);
  for(j=0;j<n;j++)
   scanf("%d",&a[j]);
int max=0;
for(j=n-1;j>0;j--)
{   if(a[j]>=a[j-1])
  {   dif=a[j]-a[j-1];
         swap(&a[j],&a[j-1]);
   
      if(dif>=max)
        max=dif;
}
}
  printf("%d\n",max);
}
return 0;
}
   
