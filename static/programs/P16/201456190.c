#include<stdio.h>
int a[35];
int main()
{
    int i;
    a[0]=1;
    for(i=1;i<35;i++)
    {
      a[i]=2*(a[i-1]);
    }
    int q;
    int test;
    scanf("%d",&test);
    for(q=0;q<test;q++)
    {
	int ans;
	int Q;
	scanf("%d",&Q);
        for(i=0;i<31;i++)
	{
	    if(Q<a[i])
	    {
               ans=i-1;
	       break;
	    }
	    else if(Q==a[i])
	    {
		ans=i;
		break;
	    }
	}
	
	int value;
	if(Q==1)
	{
	    value=0;
	}
	else
	{
	int g=a[ans+1] - a[ans-1];
	if( Q>=g)
	{
	  value=2*(ans) ;
	}
	else
	value=(2*ans)-1;
	}

	printf("%d\n",value);
    }
	return 0;
	}
