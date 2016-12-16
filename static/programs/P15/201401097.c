#include<stdio.h>
int main ()
{
	long long int i,a[100005],t,mini,min,z,l,j,k,n;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		
		scanf("%lld%lld",&n,&k);
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[j]);

		}
		min=a[0];
	
		for(j=0;j<k;j++)
		{
		

			if(a[j]<=min)
			{
				mini=j;
				min=a[j];
			}
		
		}
l=0;
                  printf("%lld",min);
		  while(j!=n)
		  {
			  l++;
			  if(a[j]<=min)
			  {
				  mini=j;
				  min=a[j];
				  printf(" %lld",min);
  			  }
			  else if(a[l-1]==min)
			  {
				  min=a[l];
				  for(z=l;z<=j;z++)
				  {
					  if(a[z]<min)
					  {
						  min=a[z];
						  mini=z;
					  }
				  }
                               printf(" %lld",min);

			  }
			  else
				  printf(" %lld",min);
                       
			  j++;

		  }
		  printf("\n");

	}
	return 0;

}
