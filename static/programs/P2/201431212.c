#include<stdio.h>
long long int binarytop(long long int a[],long long int first,long long int last,long long int value,long long int size)
{
	long long int mid;
	if(a[0]>value)
		return 0;
	if(value>=a[size-1])
		return size;
	mid=(first+last)/2;
	//	if(first>=last)
	//		return mid;
	while(first<=last)
	{
		if(a[mid]<=value && a[mid+1]>value)
			return mid+1;
		else if(a[mid]>value)
			return binarytop(a,first,mid-1,value,size);
		else
			return binarytop(a,mid+1,last,value,size);
	}
}
long long int binarybottom(long long int c[],long long int first,long long int last,long long int value,long long int size)
{
	long long int mid;
	if(value>c[size-1])
		return 0;
	if(value<=c[0])
		return size;
	mid=(first+last)/2;
	//	if(first>=last)
	//		return mid;
	while(first<=last)
	{
		if(c[mid]<value && c[mid+1]>=value)
			return size-(mid+1);
		else if(c[mid]>=value)
			return binarybottom(c,first,mid-1,value,size);
		else
			return binarybottom(c,mid+1,last,value,size);
	}
}
int main()
{
	int m,t;
	long long int count1,count2,result=0;
	long long int a[100003],b[100003],c[100003];
	scanf("%d",&t);
	for(m=0;m<t;m++)
	{result=0;
		long long int i,j,k,p,q,r;
		scanf("%lld",&p);
		for(i=0;i<p;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&q);
		for(j=0;j<q;j++)
			scanf("%lld",&b[j]);
		scanf("%lld",&r);
		for(k=0;k<r;k++)
			scanf("%lld",&c[k]);
		if(q<r)
		{
			for(i=0;i<q;++i)
			{
				count1=binarytop(a,0,p-1,b[i],p);
				count2=binarybottom(c,0,r-1,b[i],r);
				if(count1<i+1 && count2<(r-i))
					result=result+(count1*count2);
				else if(count1<i+1 && count2>=(r-i))
					result=result+(count1*(r-i));
				else if(count1>=i+1 && count2<(r-i))
					result=result+((i+1)*count2);
				else if(count1>=i+1 && count2>=(r-i))
					result=result+((i+1)*(r-i));
			}
		}
		else
		{
			for(i=0;i<r;++i)
			{
				count1=binarytop(a,0,p-1,b[i],p);
				count2=binarybottom(c,0,r-1,b[i],r);
				if(count1<i+1 && count2<(r-i))
					result+=(count1*count2);
				else if(count1<i+1 && count2>=(r-i))
					result+=(count1*(r-i));
				else if(count1>=i+1 && count2<(r-i))
					result+=((i+1)*count2);
				else if(count1>=(i+1) && count2>=(r-i))
					result+=((i+1)*(r-i));
			}
		}
		printf("%lld\n",result);
	}
	return 0;
}
