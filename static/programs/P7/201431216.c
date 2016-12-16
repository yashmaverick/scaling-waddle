#include<stdio.h>
long long int a[1000010],temp[1000010];
void part(long long int a[],long long int start,long long int end);
void merge(long long int a[],long long int start,long long int mid,long long int end);
int main()
{
	long long int i,t,k,test,count,value,sum;
	long long int n;
	scanf("%lld",&test);
	for(t=0;t<test;t++)
	{
	//long long int zero;
		scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	  //      if(a[i]==0)
	//		++zero;
	}
	part(a,0,n-1);
	//for(i=0;i<n;i++)
	//{
	//	printf("%lld ",a[i]);
	//}
	//printf("\n");
	long long int count=1;
		sum=0;
		for(i=0;i<n-1;i++)
		{
		    if(a[i]==a[i+1])
		    {
		           count++;
		    }
		    else
		    {
			    sum=sum+(count*(count-1))/2;
	                   	count=1;	   
			
		    }
		}
 sum=sum+count*(count-1)/2;
		printf("%lld\n",sum);
	}
       return 0;
}       
void part(long long int a[],long long int start,long long int end)
{
	long long int mid;
	if(start<end)
	{
		mid=(start+end)/2;
		part(a,start,mid);
		part(a,mid+1,end);
		merge(a,start,mid,end);
        }
}	
void merge(long long int a[],long long int start,long long int mid,long long int end)
{
	long long int m=mid+1, k=start,t, j=start, size=end-start+1;
	while(k<=mid && m<=end)
	{
		if(a[k]<=a[m])
		{
			temp[j]=a[k];
		         k++;	
		}
		else
		{
			temp[j]=a[m];
			m++;
		}
	j++;
	}
       while(k<=mid)
       {
	       temp[j++]=a[k++];
       }
       while(m<=end)
       {
	       temp[j++]=a[m++];
       }
       for(t=start;t<=end;t++)
       {
	       a[t]=temp[t];
       }

}
	


       

