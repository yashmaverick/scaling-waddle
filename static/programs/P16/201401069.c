#include<stdio.h>
int main()
{
    int n,q,x=1,i=0;
    scanf("%d",&n);
    while(n--)
    {
    	   i=0;
    	   x=1;
	   scanf("%d",&q);
	   while(x<=q)
	   {
		  x*=2;
		  i++;
	   }
	   i--;
	   x=x/2;
//	   printf("%d %d\n",i,x);
	   if(q>=(x+(x/2)))
	   {
		  printf("%d\n",(2*i));
	   }
	   else
	   {
		  printf("%d\n",((2*i)-1));
	   }
    }
    return 0;
}
