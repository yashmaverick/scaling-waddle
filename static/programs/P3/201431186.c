#include<stdio.h>
int main()
{ int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{  long long int n,j,a,b,c,d,max,res,f,e;
		scanf("%lld",&n);
		long long int A[n];
		for(j=0;j<n;j++)
		  scanf("%lld",&A[j]);
		max=A[n-1];res=0;
		for(d=0;d<n;d++)
		{  if((A[n-1]-A[d])>res)
			{
			res=A[n-1]-A[d];
			e=d;
			}
			
		}
		   for(a=n-2;a>=0;a--)
		{     if(max<A[a]&&a>e)
			{ res=res+A[a]-max;
			   max=A[a];
			   continue;
			}
			if(max>A[a])
			   continue;
			if(max<A[a]&&a<e)
			 {  for(f=a-1;f>=0;f--)
				 { if((A[a]-A[f])>res)
					 { res=A[a]-A[f];
					      if(f<e)
						  e=f;
					 }

				 }max=A[a];
			 }
		}
		printf("%lld\n",res);  
	}
	return 0;
}
		
				 
				 
			 
					
			  

		
