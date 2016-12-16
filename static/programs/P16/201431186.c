#include<stdio.h>
int main()
{
	long long int N,q,i,j;
	scanf("%lld",&N);
        for(i=0;i<N;i++)
	{
           scanf("%lld",&q);
	   if(q==1)
	   {
	   printf("0\n");
	   continue;
	   }
	   if(q==2)
	   {
	    printf("1\n");
	    continue;
	   }
	   if(q==3)
	   {
		   printf("2\n");
		   continue;
	   }
	   j=0;
	   while(1)
	   {
		   q=q/2;
		   j++;
		   if(q==2)
		   {
		   j=2*j+1;
		   break;
		   }
		   if(q==3)
		   {
		     j=2*(j+1);
		     break;
		   }
	   }
	   printf("%lld\n",j);
	}
	return 0;
}

			   



