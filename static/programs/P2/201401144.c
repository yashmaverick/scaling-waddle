#include <stdio.h>
int find();
int main(){
	int tt,tb;
	scanf("%d",&tb);
	for(tt=0;tt<tb;tt++){
		find();
	}
	return 0;
}
int find()
{
	long long int i,j,k,l,m,n;
	long long int count=0;
	
	scanf("%lld",&l);
	long long int a[1000000]={0};
	for(i=0;i<l;i++)	
		scanf("%lld",&a[i]);
	
	scanf("%lld",&m);
	long long int b[1000000]={0};
	for(i=0;i<m;i++)	
		scanf("%lld",&b[i]);
	
	scanf("%lld",&n);
	long long int c[1000000]={0};
	long long int d[1000000]={0};
	long long int e[1000000]={0};
	for(i=0;i<n;i++)	
		scanf("%lld",&c[i]);
	//printf("%d",findex(b,0,m,5));
	count=0;
	long long int nex=0;
	long long int opt;
	for(i=n-1;i>=0;i--)
	{	
		if(i>m-1){
			opt=m-1;
		}else{
			opt=i;
		}	
		d[binary(b,0,opt,c[i])]++;
	}
	long long int sum=0;
	for(i=m-1;i>=0;i--){
		sum+=d[i];
		d[i]=sum;
	}
	for(i=m-1;i>=0;i--){
		if(i>l-1){nex=l-1;}
		else{nex=i;}
	
		/*j=nex;
		j=findex(b,j,m-1,a[i]);
		count+=j;*/
		e[binary(a,0,nex,b[i])]+=d[i];
		//printf("%d \n",j);
		/*int next=j;
		for(j;j<m;j++){
		
	if(next<j){next=j;}
			next=findex(c,next,n-1,b[next]);
			count+=n-next;
		//	
		//	printf("__%d__%d\n",next,findex(c,j,n-1,b[next]));
		}*/
		
	}
	sum=0;
	for(i=l-1;i>=0;i--)
	{	
		sum+=e[i];
		e[i]=sum;
	}
	count=0;
	for(i=l-1;i>=0;i--)
		count+=e[i];
	printf("%lld\n",count);
	return 0;
}/*
int findex(long long int arr[],int low,int high,long long int val)
{
	//printf("low %d high %d val %lld", low, high , val);
	if(low>high){
		return low;
	}
	int mid;
	mid = (low + high)/2;
	//printf(" %d %lld",mid,arr[mid]);
	if(val<arr[mid]){
		return findex(arr, low, mid-1, val);
	}else if(val>arr[mid]){
		return findex(arr, mid+ 1, high, val);
	}else if(val == arr[mid]){
		while(arr[mid]==arr[mid-1]&&mid>low){mid--;}
		return mid;
	}
}
int findex1(long long int arr[],int low,int high,long long int val)
{
        //printf("low %d high %d val %lld", low, high , val);
        if(low>=high){
                if(arr[high]<=val)return high;
                else return high-1;

        }
        int mid;
        mid = (low + high)/2;
        //printf(" %d %lld",mid,arr[mid]);
        if(val<arr[mid]){
                return findex(arr, low, mid-1, val);
        }else if(val>arr[mid]){
                return findex(arr, mid+ 1, high, val);
        }else if(val == arr[mid]){
                while(arr[mid]==arr[mid-1]&&mid>low){mid--;}
                return mid;
        }
}
*/
int binary(long long arr[],long long int low,long long int high,long long int k)
{
  if(low<high)
    {
      int mid=(low+high)/2;
      if(arr[mid]<=k)
	binary(arr,mid+1,high,k);
      else 
	binary(arr,low,mid-1,k);
    }
  else
    {
      if(arr[high]<=k)
	return high;
      else
	return high-1;
    }
}


