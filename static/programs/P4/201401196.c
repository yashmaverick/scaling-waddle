#include <stdio.h>
#include<string.h>
void merge(int arr[],int low,int mid,int high)
{
	int i,m,k,l,temp[100001];
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
void mergesort(int a[],int lo,int hi)
{
	if(lo>=hi)
		return;
	int mid=(lo+hi)/2;
	mergesort(a,lo,mid);
	mergesort(a,mid+1,hi);
	merge(a,lo,mid,hi);
}
int main()
{
	//int t,i,j,k,l,n,m,a[100000],x;
	//char c[100000];
	int t,l;
	scanf("%d",&t);
	//a[0]=0;
	for(l=0;l<t;l++)
	{
		int t,i,j,k,l,n,m,a[100000],x;
		char c[100000];
		a[0]=0;
		scanf("%s",c);
		x=strlen(c);
		a[0]=0;
		for(i=1;i<=x;i++)
		{
			if(c[i-1]=='M')
			{
				a[i]=a[i-1]+1;
			}
			else if(c[i-1]=='R')
			{
				a[i]=a[i-1]+100000;
			}
			else
			{
				a[i]=a[i-1]-100001;
			}
		}
		mergesort(a,1,x);
		int good;
//		for(i=1;i<=x;i++)
//			printf("%d ",a[i]);
//		printf("\n");
		good=1;
		long long int ans=0;
		for(i=1;i<=x;i++){
//			printf("%d ",i);
			if(a[i]==a[i+1]){
				good++;
				if(i==x){
					if(a[x]==a[x+1])
					ans=ans+((good-1)*(good-2))/2;
					else
						ans=ans+((good)*good-1)/2;
				}
			}
			else{
				ans=ans+((good)*(good-1))/2;
				good=1;
			}
			if(a[i]==0)
				ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
