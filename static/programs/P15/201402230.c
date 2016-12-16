#include<stdio.h>
int main()
{ int t;
	scanf("%d",&t);
	long long int n,k,i;
	while(t--)
	{  scanf("%lld %lld",&n,&k);
           long long int a[n],minvalue,minindex,min[n-k+4],j=0,l;
		for(i=0;i<n;i++)
	   { scanf("%lld",&a[i]);
	   }
           if(k==1)
	   { for(i=0;i<n;i++)
		 if(i!=n-1)
		   printf("%lld ",a[i]);
	        else
			printf("%lld\n",a[i]);
	   }
	   else	  
	   {  minvalue=a[0];
	     minindex=0;
	     for(i=0;i<k;i++)
	     { if(minvalue>a[i])
	      {      minvalue=a[i];
		     minindex=i;
	     }
//	     printf("minvalue:%d minindex:%d\n",minvalue,minindex); 
	     }
	     min[j]=minvalue;
	     j++;
	     for(i=k;i<n;i++)
	     { if(minvalue<=a[i] && minindex<=i && minindex>i-k)
		     { min[j]=minvalue;
			     j++;
//		     printf("minvalue:%d minindex:%d\n",minvalue,minindex);
		     }
		else if(minvalue>=a[i] && minindex<=i && minindex>i-k)
		{ minvalue=a[i];
			min[j]=minvalue;
			minindex=i;
			j++;
//		printf("minvalue:%d minindex:%d\n",minvalue,minindex);
		}
		else if(minindex<=i-k && minindex>=0)
		{ l=i;
			minvalue=a[l];
			while(l>i-k)
			{ if(minvalue>a[l])
				{ minvalue=a[l];
					minindex=l;
				}
			l--;
			}
//			printf("minvalue:%d minindex:%d\n",minvalue,minindex);
			min[j]=minvalue;
			j++;
		}
//		for(i=0;i<n-k+1;i++)
//			printf("%d ",min[i]);
//	     printf("minvalue:%d minindex:%d\n",minvalue,minindex);
	     }
	     for(i=0;i<j;i++)
	     { if(i!=j-1)
		     printf("%lld ",min[i]);
	       else
		       printf("%lld",min[i]);
	     }
	     printf("\n");
	   }
	}
	return 0;
}


                
