#include<stdio.h>
long long int A1[100000];
long long int A2[100000];
long long int A3[100000];
//long long int A1n[100000]= { [0 ... 99999] = -1 };
//long long int A2n[100000]={0};


int main()
{
    int test,q;
    scanf("%d",&test);
    for(q=0;q<test;q++)
    {
	long long int A1n[100000]= { [0 ... 99999] = -1};
	long long int A2n[100000]= { 0 } ;
	long long int p,q,r;

	scanf("%lld",&p);

	int i,j;
	for(i=0;i<p;i++)
	{
	    scanf("%lld",&A1[i]);
	}
	scanf("%lld",&q);
	for(i=0;i<q;i++)
	{
	    scanf("%lld",&A2[i]);
	}
	scanf("%lld",&r);
	for(i=0;i<r;i++)
	{
	    scanf("%lld",&A3[i]);
	}

	for(i=0;i<q;i++)
	{   
		long long int low=i;
		long long  int high= r-1;
		long long int mid;
		int f1=0;
			 mid=(low+high)/2;
	    while(low<=high)
	    {
	        mid=(low+high)/2; 
	        if(A3[mid]==A2[i])
	        {   
	        	
	        	if(A3[mid-1]==A2[i] && mid>i )
	        	high=mid-1;
	        	else
	        	{
	        		f1=1;
	        		break;
	        	}
	        	
	        }
	        else if(A3[mid]<A2[i] )
	        {
	        	if(A3[mid+1]>A2[i] && mid>i)
	        	{
	        		mid=mid+1;
                    f1=1;
                    break;
                }
	            else 
	            {
	            	low=mid+1;
	            }
	        }
	        else if(A3[mid] > A2[i]  )
            {
            	if(A3[mid-1]<A2[i] && mid>i || mid>i &&mid==(r-1) || mid==i)
            	{
            		f1=1;
            		break;
            	}
            	else
            	{
            		high=mid-1;
            	}
            }          
	   }
	   if(f1==1)
	   {
	   	A2n[i]=r-mid;
	   }
	}
	
	/*	for(i=0;i<q;i++)
		printf("%lld ",A2n[i]);
		printf("\n");*/

	long long int sum=0;
	for(i=(q-1);i>=0;i--)
	{
	    sum=sum+A2n[i];
	    A2n[i]=sum;
	}
	//	     for(i=0;i<q;i++)
	//	        printf("%lld",A2n[i]);

	for(i=0;i<p;i++)
	{
	    
			long long int low=i;
			long long high= q-1;
			long long int mid;
		     int f1=0;
			 mid=(low+high)/2;
	    while(low<=high)
	    {
	        mid=(low+high)/2; 
	        if(A2[mid]==A1[i])
	        {
	        	if(A2[mid-1]==A1[i] && mid>i)
	        	high=mid-1;
	        	else
	        	{
	        		f1=1;
	        		break;
	        	}
	        	
	        }
	        else if(A2[mid]<A1[i])
	        {
	        	if(A2[mid+1]>A1[i] && mid>i)
	        	{
	        		mid=mid+1;
                    f1=1;
                    break;
                }
	            else 
	            {
	            	low=mid+1;
	            }
	        }
	        else if(A2[mid] > A1[i])
            {
            	if(A2[mid-1]<A1[i] && mid>i || mid==(q-1) && mid>i|| mid==i )
            	{
            		f1=1;
            		break;
            	}
            	else
            	{
            		high=mid-1;
            	}
            }          
	   }
	   if(f1==1)
	   {
	   	A1n[i]=mid;
	   }
	}
	    
	
	//         for(i=0;i<p;i++)
	//	     printf("%lld",A1n[i]);
	long long int count=0;
	for(i=0;i<p;i++)
	{
	    long long int k=A1n[i];
	    if(k==-1)
		break;
	    else
		count=count+A2n[k];
	}


	printf("%lld\n",count); 
    }
    return 0;
}