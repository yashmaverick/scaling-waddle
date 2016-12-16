#include<stdio.h>
int main()
{
   int test;
   scanf("%d",&test);
   while(test--)
   {
           long long int a,min,i,j,max=0,value=0;
	   scanf("%lld",&a);
	   long long int b[a],c[1000000];
	   scanf("%lld",&b[0]);
	   min=b[0];
           for(i=1;i<a;i++)
	   {
	     scanf("%lld",&b[i]);
             if(b[i]<min)
	     {
	     min=b[i];
	     }
	   }
	   for(i=0;i<a;i++)
	   {
	     b[i]=b[i]-min;
	     if(max<b[i])
	     {
	     max=b[i];
	     }
	   }
	   for(i=0;i<1000000;i++)
	   c[i]=0;
	   for(i=0;i<a;i++)
	   {
		   j=b[i];
	       c[j]++;
	   }
	   for(i=0;i<=max;i++)
	   {
	   value=value+(c[i]*(c[i]-1))/2;
	   }
	   printf("%lld\n",value);

   }
   return 0;
}
