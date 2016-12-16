#include<stdio.h>
#include<string.h>
long long int a[1000000];
char str[1000000];
void mergeSort(long long int a[],long long int low,long long int mid,long long  int high);
void partition(long long int a[], long long int low,long long int high);
int main()
{
	long long int p,q,t,k,i,j,n,l;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%s",str);
		long long int len=strlen(str);
		if(str[0]=='J')
			a[0]=100001;
		else if(str[0]=='M')
			a[0]=1;
		else if(str[0]=='R')
			a[0]=-100002;
		for(i=1;i<len;i++)
		{
			a[i]=a[i-1];
			if(str[i]=='J')
				a[i]=a[i]+100001;
			else if(str[i]=='M')
				a[i]=a[i]+1;
			else if(str[i]=='R')
				a[i]=a[i]-100002;
		}
		//for(q=0;q<len;q++)
		//{
		//	printf("%lld\n",a[q]);
		//}
		partition(a,0,len-1);
		//for(p=0;p<len;p++)
		//{
		//	printf("%lld\n",a[p]);
		//}
		long long int temp=a[0];
		long long int count=1,cnt=1,sum=0,m;
		for(l=1;l<len;l++)
		{
			if(a[l]==a[l-1])
				cnt++;
		}
		if(cnt==len)
			printf("%lld\n",((cnt)*(cnt-1))/2);
		else
		{
			for(i=1;i<len;i++)
			{
				if(a[i]==temp)
				{
					count++;
					if(i==len-1)
						sum+=((count)*(count-1))/2;
				}

				else
				{
					temp=a[i];
					sum+=((count)*(count-1))/2;
					count=1;
				}
			}
			//printf("nn! %lld\n",sum);
			for(m=0;m<len;m++)
			{
		//	printf("%lld\n",a[m]);
				if(a[m]==0)			
					sum++;
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}

void partition(long long int a[],long long int low,long long int high){

	long long int mid;

	if(low<high){
		mid=(low+high)/2;
		partition(a,low,mid);
		partition(a,mid+1,high);
		mergeSort(a,low,mid,high);
	}
}

void mergeSort(long long int a[],long long int low,long long int mid,long long int high){

	long long int i,m,k,l,temp[1000000];

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

