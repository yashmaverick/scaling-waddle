#include<stdio.h>
#include<stdlib.h>
/*int cmpfunc (const void * a, const void * b)
{
   return ( *(long long int*)a - *(long long int*)b );
}
long long int bs(long long int arr[],long long int low,long long int high,long long int num)
{
	if(high<low)
	{
		return -1;
	}
	long long int mid=(low+high)/2;
	if(num==arr[mid])
	{
		return arr[mid];
	}
	if(num > arr[mid])
	{
		return bs(arr,mid+1,high,num);
	}
	else
		return bs(arr,low,mid-1,num);
}*/
int main()
{
	long long int te;
	scanf("%lld",&te);
	long long int i;
	long long int in[te];
	long long int pre[te];
	for(i=0;i<te;i++)
	{
		scanf("%lld",&pre[i]);
	}
	for(i=0;i<te;i++)
	{
		scanf("%lld",&in[i]);
	}
	long long int test,a,b,g,e;
	scanf("%lld",&test);
	for(g=0;g<test;g++)
	{
		scanf("%lld %lld",&a,&b);
		if(a==b)
		printf("%lld\n",a);
		else{
		long long int arr[te];
		for(i=0;i<te;i++)
			arr[i]=0;
		long long int flag=0,temp=0,g=0;
		while(flag<2)
		{
			if(in[g]==a||in[g]==b)
				flag++;
			if(flag>0 && flag<2)
			{	
				arr[temp++]=in[g];
			}
			if(flag==2)
				arr[temp++]=in[g];
			g++;
		}
		long long int j=0,risk=0;
		for(i=0;i<te;i++)
		{
			for(j=0;j<temp;j++)
			{
				if(pre[i]==arr[j])
				{
					flag=8;
					risk=pre[i];
					break;
				}
			}
			if(flag==8)
			break;
		}
		printf("%lld\n",risk);
	    }
	}
	return 0;
}
