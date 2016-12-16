#include<stdio.h>
int main()
{
   int t;
   scanf("%d",&t);
   while(t>0)
   {
           long long int num,least,i,j,high=0,ans=0;
	   scanf("%lld",&num);
	   long long int b[num],c[1000000],h;
	   scanf("%lld",&b[0]);
	  least=b[0];
	   i=0;
	   while(i<1000000)
	   {
	   c[i]=0;
	   i++;
	   }
	   i=1;
           while(i<num)
	   {
	     scanf("%lld",&b[i]);
             if(b[i]<least)
	     {
	     least=b[i];
	     }
	     i++;
	   }
	   i=0;
	   while(i<num)
	   {
	     b[i]=b[i]-least;
	     if(high<b[i])
	     {
	     high=b[i];
	     }
	     i++;
	   }
	   i=0;
	   while(i<num)
	   {
		   j=b[i];
	       c[j]++;
	       i++;
	   }i=0;
	   while(i<=high)
	   {
		   h=(c[i]*(c[i]-1))/2;
	   ans=ans+h;
	   i++;
	   }
	   printf("%lld\n",ans);
	   t--;

   }
   return 0;
}
