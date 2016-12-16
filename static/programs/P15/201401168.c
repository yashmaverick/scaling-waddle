#include<stdio.h>
int main()
{
  int t,n,k,i,index,len,c,j;
  long long int a[10100],min;
  scanf("%d",&t);
  while(t!=0)
    {
      scanf("%d %d",&n,&k);
      len=n-k+1;min=1000000001,index=-1;c=0;
      for(i=0;i<n;i++)
	{
	  scanf("%lld",&a[i]);
	  c++;
	  if(c<=k&&a[i]<min)
	    {min=a[i];index=i;}
	}
      if(k<n)
	printf("%lld ",min);
      else
	printf("%lld\n",min);
      for(i=k;i<n;i++)
	{
	  //	  printf("(i-k)=%d , index=%d\n",i-k,index);
	  if(a[i]<min)
	    {min=a[i];index=i;}
	  else
	    if(index==(i-k))
	      {
		min=a[i-k+1];index=i-k+1;
		for(j=i-k+1;j<=i;j++)
		  if(a[j]<min)
		    {
		      //		      printf("a[%d]=%lld < min[%d]=%lld\n",j,a[j],index,min);
		      min=a[j];
		      index=j;
		    }
	      }
	  if(i==n-1)
	    printf("%lld\n",min);
	  else
	    printf("%lld ",min);
	}
      t--;
    }
  return 0;
}
