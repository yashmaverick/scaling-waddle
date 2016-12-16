#include<stdio.h>
long long int b_search(long long int a[],long long int start,long long int last,long long int k)
  {
  if(start>last) return -1;         
  if(a[start]>k)
  return start;
  else if(a[last]<k)
  return last+1;                    
  int mid=(start+last)/2;
  if(a[mid]>k)
  b_search(a,start,mid,k);
  else
  b_search(a,mid+1,last,k);
  }
/*int l_search(int a[],int start,int last,int k)
{
	int i,f=0;
	for(i=start;i<=last;i++)
		if(a[i]<k);
		else
		{
			f=1;
			break;
		}
	if(f==1)
		return i;
	else
		return -1;
}*/

//int count=0
void b_count(long long int a[],long long int c[],long long int start,long long int end,long long int x,long long int count)
{
	if(start>end)
	return;
	count++;
	long long int b=b_search(a,start,end,x);
	if(b==-1) return;                               
	c[end]=count;                                   
	if(b>0)
	{
		c[b-1]=count;
	}
	if(b>1)
		b_count(a,c,start,b-2,a[b-1],count);
	if(end>0&&b>=0)
		b_count(a,c,b,end-1,a[end],count);

}


int main()
{
	long long int t,d;
	scanf("%lld",&d);
	for(t=0;t<d;t++)
	{
		long long int n;
		scanf("%lld",&n);
		if(n==0)
		continue;
		long long int i,max=0,minval;
		long long int a[n],c[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		c[n-1]=0;
		if(n>=1)
			b_count(a,c,0,n-2,a[n-1],0);
//		for(i=0;i<n;i++)
//			printf("%d ",c[i]);
//		if(n==1)
//		{
//			printf("%lld 0\n",a[0]);
//			continue;
//		}
		for(i=0;i<n;i++)
		{
			if(max<c[i])
			{
				max=c[i];
				minval=a[i];
			}
		}
		for(i=0;i<n;i++)
		{
			if(c[i]==max)
			{
				if(a[i]<minval)                     
				{
					minval=a[i];
				}
			}
		}
		//		for(i=0;i<n;i++)
		//	printf("%d ",c[i]);
	printf("%lld %lld\n",minval,max);                  

	}
	return 0;
}

