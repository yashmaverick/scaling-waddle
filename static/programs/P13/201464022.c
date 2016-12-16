#include<stdio.h>
#include<stdlib.h>
typedef struct result
{
        long long int value;
	long long int index;
}result;
long long int search(long long int a[],long long int val,long long int low,long long int high)
{
//	if(low>=high)
//		return -1;
	//if(high<0)
	//	return -1;
	if(low>high)
		return -1;
	if(low==high)
		return low;
	long long mid=(low+high)/2;
	if(a[mid]<val)
	{
		if(a[mid+1]>val)
			return mid+1;
		else return search(a,val,mid+1,high);
	}
	else if(a[mid]>val)
	{
		if(a[mid-1]<val)
			return mid;
		else return search(a,val,low,mid);
	}

}
result findmin(long long int a[],long long int low,long long int high,long long int level)
{
//	printf("high=%lld\n",high);
	result r;
	if(low==high)
	{
		r.value=a[low];
		r.index=level;
		return r;
	}
//	if(high-low==2)
//	{
//		r.value=a[low];
//		r.index=level+1;
//		return r;
//	}
	if(high-low==1)
	{
		r.value=a[low];
		r.index=level;
		return r;
	}
		
	long long int root=a[high-1],i;
	result r1,r2;
	/*for(i=low;i<high-1;i++)
	{
		if(a[i]>root)
			break;
	}*/
	i=search(a,root,0,high-1);
//	printf("searchvalue for root=%lld is=%lld\n",root,i);
	r1=findmin(a,low,i,level+1);
	r2=findmin(a,i,high-1,level+1);
//	if(i>=high-1-i)
//		return findmin(a,low,i-1,level+1);
//	else return findmin(a,i,high-1,level+1);
//	if(high-i-1-i>=2)
//		return r2;
//	else if(i-(high-i-1)>=2)
//		return r1;
//	else if(high-i-i-1==0)
//		return r1;
//	else
//	{
	//r1=findmin(a,low,i,level+1);
	//r2=findmin(a,i,high-1,level+1);
	if(r1.index>=r2.index)
		return r1;
	else return r2;
//	}
}
	
	


int main()
{
	long long int n,t,i;
	result res;
	scanf("%lld",&t);
	while(t--)
	{
		long long int *a;
		scanf("%lld",&n);
		a=malloc(sizeof(long long int)*n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		res=findmin(a,0,n,0);
		printf("%lld %lld\n",res.value,res.index);
		free(a);
	}
	return 0;
}


