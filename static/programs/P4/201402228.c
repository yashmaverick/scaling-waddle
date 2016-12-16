#include<stdio.h>
#include<string.h>
int b[100010],temp[100010];
void merge(int arr[],int low,int mid,int high);
void split(int arr[],int low,int high);
int main()
{
	int t,i,l,p,q,r,j,k,sum,y;
	char a[100010];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int flag=0,z=0;
		sum=0;
		int f=1;
		int g=0;
		scanf("%s",a);
		l=strlen(a);
		p=100000+1;
		q=1;
		r=-(100000+2);
		for(j=0;j<l;j++)
		{
			if(a[j]=='J')
			{
				b[j]=sum+p;
				sum=b[j];
			}
			else if(a[j]=='M')
			{
				b[j]=sum+q;
				sum=b[j];
			}
			else if(a[j]=='R')
			{
				b[j]=sum+r;
				sum=b[j];
			}
		}
		split(b,0,l-1);
		for(k=0;k<l-1;k++)
		{
			if(b[k]==b[k+1] && b[k]!=0 )
			{
				f++;
				flag=1;
			}
			else if(b[k]!=b[k+1] && flag==1)
			{
				z=(f*(f-1))/2+z;
				flag=0;
				f=1;
			}
			else if(b[k]==0)
				g++;
			if(k==(l-2) && b[k]==b[k+1])
			{
				z=(f*(f-1))/2+z;
			}
		}
		y=(g*(g-1))/2;
		printf("%d\n",g+z+y);
	}
	return 0;
}
void split(int arr[],int low,int high){

	int mid;

	if(low<high){
		mid=(low+high)/2;
		split(arr,low,mid);
		split(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
void merge(int arr[],int low,int mid,int high){

	int i,m,k,l;
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
