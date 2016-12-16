#include<stdio.h>
int binarylower(int a[],int m,int l,int u)
{
 int mid,c=0;
  if(l<=u)
  {
    mid=(l+u)/2;
    if(m==a[mid])
    {
      c=m;
      return binarylower(a,m,l,mid-1);
    }
    else if(m<a[mid])
      return binarylower(a,m,l,mid-1);
    else
      return binarylower(a,m,mid+1,u);
  }
  else
    return l;
}

void print(int a[],int len)
{
  int i;
  for(i=0;i<len;i++)
  printf("%d ",a[i]);
  printf("\n");
}

int main()
{
  int t,i,n,m,j,k,p,q,r,sum;
  int a[100000],b[100000],c[100000],d[100000];
  scanf("%d",&t);
  for(i=0;i<t;i++)
  {
    sum=0;
    scanf("%d",&p);
    for(j=0;j<p;j++)
      scanf("%d",&a[j]);
    scanf("%d",&q);
    for(j=0;j<q;j++)
      scanf("%d",&b[j]);
    scanf("%d",&r);
    for(j=0;j<r;j++)
      scanf("%d",&c[j]);
    //print(a,p);
    //print(b,q);
    //print(c,r);
    if(q-1<=r)
    {
      if(r-binarylower(c,b[q-1],q-1,r)!=-1)
        d[q-1]=r-binarylower(c,b[q-1],q-1,r);
      else
        d[q-1]=0;
    }
    else
      d[q-1]=0;
    //printf("%d\n",d[q-1]);
    for (j=q-2;j>=0;j--)
    {
      if(j<=r)
      {
        if(r-binarylower(c,b[j],j,r)!=-1)
          d[j]=(r-binarylower(c,b[j],j,r))+d[j+1];
        else
          d[j]=0;
      }
      else
	  d[j]=0;
    }
    //print(d,q);
    for(j=0;j<p;j++)
      sum+=d[binarylower(b,a[j],j,q)];
    printf("%d\n",sum);
  }
  return 0;
}
