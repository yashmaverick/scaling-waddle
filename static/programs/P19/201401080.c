#include<stdio.h>
long long int b[1000000],temp[1000000];
int binary(long long int b[],int l,int u,long long int m){

	int mid=(l+u)/2;
	if(l<=u){
		if(m==b[mid])
			return 1;
		else if(m<b[mid])
			return binary(b,l,mid-1,m);
		else
			return binary(b,mid+1,u,m);
	}
	else
		return 0;
}
void merge(long long int a[],int low,int mid,int high){

	int i,m,k,l;

	l=low;
	i=low;
	m=mid+1;

	while((l<=mid)&&(m<=high)){

		if(a[l]<=a[m]){
			temp[i]=a[l];
			l++;
		}
		else{
			temp[i]=a[m];
			m++;
		}
		i++;
	}

	if(l>mid){
		for(k=m;k<=high;k++){
			temp[i]=a[k];
			i++;
		}
	}
	else{
		for(k=l;k<=mid;k++){
			temp[i]=a[k];
			i++;
		}
	}

	for(k=low;k<=high;k++){
		a[k]=temp[k];
	}
}
void part(long long int a[],int low,int high){

	int mid;

	if(low<high){
		mid=(low+high)/2;
		part(a,low,mid);
		part(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
int main()
{
	int t,j,i,flag,k,n;
	long long int a[100000],p;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		k=0;
		flag=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[j]);
			p=a[j];
			while(p>=10)
			{
				p=p/10;
				b[k]=p;
				k++;
			}
		}
		part(a,0,n-1);
		part(b,0,k-1);	
 /*		for(j=0;j<n;j++)
 		{
 			printf("%d ",a[j]);
 		}
 	printf("\n");
 	for(j=0;j<k;j++)
		{
 
 			printf("%d ",b[j]);		}		
	printf("\n");*/
		for(j=0;j<n-1;j++)
			{
			if(a[j]==a[j+1])
			{
				flag=1;
				break;
			}
			}
		if(flag!=1)
		{
			for(j=0;j<n;j++)
			{
				flag=binary(b,0,k-1,a[j]);
				if(flag==1)
					break;
			}
		}
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}




