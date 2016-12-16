#include<stdio.h>
#define s(n) scanf("%llu",&n)
typedef unsigned long long int ulli;

void merge(ulli *value, int start, int mid, int end){
	int i=0,ll=mid-start+1, lr=end-mid, lmax=ll+lr, j=0,k=0, left[ll], right[lr];
	for(i=0;i<ll;i++)
		left[i]=value[i+start];//copy the values indexed from start - mid ->to left
	for(i=0;i<lr;i++)
		right[i]=value[i+mid+1];//copy the values indexed from mid - end ->to right
	i=start;  //reinitialising
	while(j<ll && k<lr){
		if(left[j]<=right[k])
			value[i++]=left[j++];
		else
			value[i++]=right[k++];
	}
	//to copy the remnants,if existing, to array value:
	while(j<ll)
		value[i++]=left[j++];
	while(k<lr)
		value[i++]=right[k++];
}
void mergesort(ulli value[], int start, int end){
	int mid;
	if(start<end)
	{
		mid=start + (end-start)/2;//to avoid overflow 
		mergesort(value,start,mid);//left
		mergesort(value,mid+1,end);//right
		merge(value,start,mid,end);//left+right
	}
}

int main()
{

	ulli t,n,answer,value[1001],i;
	int c;
	s(t);
	while(t--)
	{
		s(n);
		s(answer);
		for(i=0;i<n;i++)
		{
			while((c=getchar())!=' ');
			s(value[i]);
		}
		if(n>2)
		{
		mergesort(value,0,n-1);
//		for(i=0;i<n;i++)
//			printf("%llu ",value[i]);
//		printf("\n");
		ulli low, high;
		int f=0;
		for(i=0;i<=n-3;i++)
		{
			low=i+1;
			high=n-1;///always last
			while(low<high)
			{
				if(value[i]+value[low]+value[high] == answer)
				{
					printf("YES\n");
					f=112;
					break;
				}
				else if(value[i]+value[low]+value[high] > answer)
					high--;
				else
					low++;
			}
			if(f==112)
				break;
		}
		if(f==0)
			printf("NO\n");
		}
		else
			printf("NO\n");

	}
	return 0;
}


