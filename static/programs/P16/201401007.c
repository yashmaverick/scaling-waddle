#include<stdio.h>
int power(int a,int n)
{
    int result=1;
    while(n)
    {
	if(n&1)
	{
	    result=result*a;
	}
	n=n>>1;
	a=a*a;
    }
    return result;
}
int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
	scanf("%d",&n);
	if(n==1)
	{
	    printf("0\n");
	}
	else
	{
	    for(i=0;(power(2,i)-1)<(n);i++)
	    {
		continue;
	    }
	    //	printf("%d\n",i-1);
	    if(n>(3*power(2,i-2))-1)
	    {
		printf("%d\n",2*(i-1));
	    }
	    else
	    {
		printf("%d\n",2*i-3);
	    }
	}
    }
    return 0;
}





