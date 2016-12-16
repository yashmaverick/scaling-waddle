#include<stdlib.h>
#include<stdio.h>
struct package
{
  int *arr;
  int W;
  int noe;
};

int cf(const void *p,const void *q)
{
   const int left=((struct package*)p)->W;
   const int right=((struct package*)q)->W;
   return left>right;
}
int main()
{
    int n,mod,i,j;
    scanf("%d %d",&n,&mod); 
    
    struct package a[n]; 
    for(j=0;j<n;j++)
    {
	a[j].W=0;
	scanf("%d",&a[j].noe);
	a[j].arr = malloc(sizeof(int)*a[j].noe);
	for(i=0;i<a[j].noe;i++)
	{
	    scanf("%d",&a[j].arr[i]);
	    a[j].W=(a[j].W%mod+a[j].arr[i]%mod)%mod;
	}
    }
    qsort(a,n,sizeof(struct package),cf);
    for(j=0;j<n;j++)
   {
      printf("%d\n",a[j].W);
      for(i=0;i<a[j].noe;i++)
        printf("%d\n",a[j].arr[i]);
     printf("\n");
   }
	return 0;
}
