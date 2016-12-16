#include<stdio.h>
#define s(n) scanf("%lld",&n)
typedef long long int LL;

void merge(LL *a, LL start, LL mid, LL end){
	LL i=0,ll=mid-start+1, lr=end-mid, lmax=ll+lr, j=0,k=0, left[ll], right[lr];
	for(i=0;i<ll;i++)
		left[i]=a[i+start];//copy the values indexed from start to mid to left
	for(i=0;i<lr;i++)
		right[i]=a[i+mid+1];//copy the values indexed from mid to end to right
	i=start;  //reinitialising
	while(j<ll && k<lr){
		if(left[j]<=right[k])
			a[i++]=left[j++];
		else
			a[i++]=right[k++];
	}
	//to copy the remnants to array a:
	while(j<ll)
		a[i++]=left[j++];
	while(k<lr)
		a[i++]=right[k++];
}
void mergesort(LL *a, LL start, LL end){
	LL mid;
	if(start<end)
	{
		mid=start + (end-start)/2;//to avoid overflow 
		mergesort(a,start,mid);//left
		mergesort(a,mid+1,end);//right
		merge(a,start,mid,end);//left+right
	}
}
int main()
{
	LL t,n,i;
	s(t);
	while(t--)
	{
		s(n);
		LL a[n],repeat_count=1;
		for(i=0;i<n;i++)
			s(a[i]);
		mergesort(a,0,n-1);
	//	for(i=0;i<n;i++)
	//		printf("%lld ",a[i]);
		
		LL ans = 0;
		a[n]=0;
		for(i=0;i<n;i++)
		{
			if(a[i+1]==a[i])
				repeat_count++;
			if(repeat_count>1 && a[i+1]!=a[i])
			{
				ans = ans + ( repeat_count*(repeat_count-1) )/2;
				repeat_count=1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
