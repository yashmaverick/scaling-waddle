#include<stdio.h>
#include<stdlib.h>
int r=0;

int main()
{
	int n,a,b,ii,i,A[100000],B[100000],l,m,s,p,q,g,d,t;
	   	scanf("%d",&n);
		for(l=0;l<n;l++)
	{
			scanf("%d",&A[l]);
	}
		for(l=0;l<n;l++)
	{
			scanf("%d",&B[l]);}
scanf("%d",&t);
for(ii=0;ii<t;ii++)
{
			scanf("%d %d",&m,&r);	
// printf("mvklfvlkdfnvkdnfv");
				   g=d=-1;
for(l=0;l<n;l++)
{
   if(g!=-1 && d!=-1)
        break;
   else		
         if(B[l]==m)
		g=l;
	if(B[l]==r)
		d=l;		
}
r=0;
/*if order varies*/
if(d<g)
{
	g=g^d;
	d=g^d;
	g=d^g;			
}
				for(p=0;p<n;p++)	
{
				for(s=g;s<d+1;s++)
	{
							if(A[p]==B[s])
                          {
				printf("%d\n",B[s]);
                    			            r=1;
				break;		
                        	  }
       }
if(r==1)
		   break;
	}
			}
return 0;
}
