#include<stdio.h>
long long int a[10005];

int main()
{
    long long int test,q;
    scanf("%lld",&test);
    for(q=0;q<test;q++)
    {
    long long int n,k,m;
    scanf("%lld%lld",&n,&k);

    long long int i,j;
    for(i=1;i<=n;i++)
    {
	scanf("%lld",&a[i]);
    }

    long long int min=a[1];
    long long int index=1;
    for(i=2;i<=k;i++)
    {
      if(a[i]<min)
      {
	  min=a[i];
	  index=i;
      }
    }
    if((i-1)==n)
	printf("%lld",min);
    else
    printf("%lld ",min);
    for(i=2;;i++)
    {
	j=i+k-1;
	if(j>n)
	    break;
	if(a[j]<min)
	{
	    min=a[j];
	   index=j;
	   if(j==n)
	        printf("%lld",min);
	   else
	       printf("%lld ",min);
	 
	}
	else if(a[j]>min && index>=i)
	{
	    if(j==n)
	    printf("%lld",min);
	    else
		printf("%lld ",min);
	}
        
	else
	{
	    min=a[i];
	    index=i;
	    for(m=i+1;m<=j;m++)
	    {
              if(a[m]<min)
	      {
		  min=a[m];
		  index=m;
	      }
	    }
	    if(j==n)
	    printf("%lld",min);
	    else
		printf("%lld ",min);

	}
	if(j==n)
	{  
	    break;
	}

    }
    
   printf("\n");
    }
    return 0;
}
