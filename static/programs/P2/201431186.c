#include<stdio.h>
int main()
{
	long long int t,i;
	scanf("%lld",&t);int flag;
	long long int A[100100],B[100100],C[100100],BB[100100],AB[100100];
	for(i=0;i<t;i++)
	{  long long int p,q,r,j,a,b,c,d,e,f,l,m;l=0;m=0;f=0;flag=0;
		scanf("%lld",&p);
		
            for(j=0;j<p;j++)
	        scanf("%lld",&A[j]);

	    scanf("%lld",&q);
	    
	    for(j=0;j<q;j++)
                scanf("%lld",&B[j]);

	    scanf("%lld",&r);
	    
	    for(j=0;j<r;j++)
		    scanf("%lld",&C[j]);
	    for(a=0;a<q;a++)
	    { f=0; if(a>=p)
		      f=1; 
		    for(b=((p-1)*f+a*(1-f));b>=0;b--)
		   {
                     
		    if(A[b]<=B[a])
		    {
		         BB[a]=b+1;			 
		         break;
		    }
		   }
		    if(b<0)
		      BB[a]=0;
	      if(a>=r)
		    { AB[a]=0;
		    continue;
		    }
	      if(l>=a)
	         m=l;
		    for((d=m*(flag)+(1-flag)*a);d<r;d++)
		    {  
		      if(B[a]<=C[d])
		      {
			    AB[a]=r-d;
			    flag=1;
			    l=d;m=l+1;
			    //printf("%d\n",AB[a]);
			   break;
		      }
		    }
		    if(d==r)
		     AB[a]=0;		    
	    } 
	  long long int sum;sum=0;
	for(e=0;e<q;e++)
             sum=sum+(BB[e]*AB[e]);
		     
		     printf("%lld\n",sum);
	}
	return 0;
}
	    
