#include<stdio.h>
int cmpfunc (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main()
{
  int a[1500],t,n,i,k,f;
  char c[100];
  scanf("%d",&t);
  while(t!=0)
    {
      scanf("%d %d",&n,&k);
      for(i=0;i<n;i++)
	scanf("%s %d",c,&a[i]);
      qsort(a,n,sizeof(int),cmpfunc);
      int i,j,l,sum=0;
      f=0;
      for(i=0;i<(n-2)&&f==0;i++)
	{
	  j=i+1;l=n-1;
       	  while(j<l&&f==0)
	    {
	      sum=a[i]+a[j]+a[l];
	      if(sum<k)
		j++;
	      else
		if(sum>k)
		  l--;
		else
		  f=1;
	    }
	}
      if(f==1)
	printf("YES\n");
      else
	printf("NO\n");
      t--;
    }
}	
			
