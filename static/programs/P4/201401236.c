#include<stdio.h>
#include<string.h>
#define  MAX 100000
/*long long int   quick( long long int a[],long long int low,long long int high)
  {
  if(low<high)
  {
  long long int i,x=0,c;
  long long int pivot=low;
  for(i=low+1;i<=high;i++)
  {
  if(a[i]<a[pivot])
  {
  c=a[i];
  a[i]=a[pivot];
  a[pivot]=c;
  pivot=i;
  while(x--)
  {
  c=a[pivot-1];
  a[pivot-1]=a[pivot];
  a[pivot]=c;
  pivot--;
  }
  x=0;

  }
  else
  x++;

  }
//		if(k<pivot)
quick(a,low,pivot-1);
//		else if(k>pivot)
quick(a,pivot+1,high);
//		else if(k==pivot)
//			return a[k];
}


}*/

void mergeSort(long long int arr[],long long int low,long long int mid,long long int high);
void partition(long long int arr[],long long int low,long long int high){

	long long int mid;

	if(low<high){
		mid=(low+high)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		mergeSort(arr,low,mid,high);
	}
}
void mergeSort(long long int arr[],long long int low,long long int mid,long long int high){

	long long int i,m,k,l,temp[MAX];

	l=low;
	i=low;
	m=mid+1;

	while((l<=mid)&&(m<=high)){

		if(arr[l]<=arr[m]){
			temp[i]=arr[l];
			l++;
		}
		else{
			temp[i]=arr[m];
			m++;
		}
		i++;
	}

	if(l>mid){
		for(k=m;k<=high;k++){
			temp[i]=arr[k];
			i++;
		}
	}
	else{
		for(k=l;k<=mid;k++){
			temp[i]=arr[k];
			i++;
		}
	}

	for(k=low;k<=high;k++){
		arr[k]=temp[k];
	}
}
int main()
{
	long long int d,i,a[100001],g,count=0,st=0 ,gy=1,gr=0,test         ;
	char s[100001];		
	scanf("%lld",&test);
	while(test--)
	{
		gy=1;
		gr=0;
		st=0;
		count=0;
		scanf("%s",s);
		d=strlen(s);
		for(i=0;i<d;i++)
		{
			if(s[i]=='J')
				a[i]=(-1);
			else if(s[i]=='M')
				a[i]=(-999);
			else if(s[i]=='R')
				a[i]=1000;
		}
		for(i=1;i<d;i++)
			a[i]=a[i-1]+a[i];
		partition(a,0,d-1);
		//	for(i=0;i<d;i++)
		//	printf("%lld\n",a[i]);
		for(i=0;i<d;i++)
		{

			if(a[i]==0)
				gr++;
			if(st==0) 
			{
				g=a[i];
				st=1;

			} 


			else
			{
				if(a[i]==g)
					gy++;
				else 
				{
					g=a[i];
					count=count+(gy*(gy-1))/2;
					//        printf("%lld %lld\t",count,i);
					gy=1;				
					//      printf("%lld\n",count);
				}

			} 
		}
		if(gy!=1)
			count=count+gy*(gy-1)/2;
		printf("%lld\n",count+gr);	
	}
	return 0;
}














