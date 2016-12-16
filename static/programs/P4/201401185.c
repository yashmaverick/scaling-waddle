#include<stdio.h>
#include<string.h>

void merge(long long int a[],long long int b[],long long int c[],long long int m,long long int g)
{
	long long int i,j,k;
	i=0;
	j=0;
	k=0;
	while(i<m&&j<g)
	{
		if(a[i]>b[j])
			c[k++]=b[j++];
		else
			c[k++]=a[i++];
	}
	while(i<m)
		c[k++]=a[i++];
	while(j<g)
		c[k++]=b[j++];
	return;
}
void msort(long long int a[],long long int n)
{
	long long int i,left[n],right[n];
	if(n<=1)
		return ;
	for(i=0;i<n/2;i++)
		left[i]=a[i];
	for( ; i<n;i++)
		right[i-n/2]=a[i];
	msort(left,n/2);
	msort(right,n-n/2);
	merge(left,right,a,n/2,n-n/2);
	return;
}

/*void bucket(int a[],int b[],int n,int min)
  {
  int i,j;
  for(i=0;i<n;i++){
  if(b[i]==0)
  zc++;
  j=b[i]-min;
  a[j]++;
  }
  }*/


int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		//zc=0;
		char c[100000];
		long long int i,n;
		scanf("%s",c);
		n=strlen(c);
		long long int a[n];
		for(i=0;i<n;i++){
			if(c[i] == 'J')
				a[i]=100000;
			else if(c[i] == 'M')
				a[i]=-99999;
			else if(c[i]=='R')
				a[i]=-1;
		}
		for(i=1;i<n;i++){
			a[i]=a[i-1]+a[i];
		}
		//		for(i=0;i<n;i++)
		//			printf("%Ld ",a[i]);
		//		printf("\n");
		msort(a,n);
		//		for(i=0;i<n;i++)
		//			printf("%Ld ",a[i]);
		//		printf("\n");
		
		long long int sum=0;
		long long int count=1;
		//int flag=0;
		for(i=1;i<n;i++)
		{
			if(a[i-1]==0)
				sum++;
			if(a[i] == a[i-1]){
				count++;
			}
			else if(a[i]!=a[i-1]){
				sum=sum+(count*(count-1))/2;
				count=1;
			}
		//	printf("%lld %lld\n",count,sum);
		}
		if(a[n-1]==0)
			sum++;
		sum=sum+(count*(count-1))/2;
	/*int count[1000];
	  for(i=0;i<1000;i++)
	  count[i]=0;
	  bucket(count,b,n,min);*/
	/*	int sum=0;
		for(i=0;i<k;i++)
		{
		sum=sum+((count[i]-1)*count[i])/2;
		}*/
	printf("%lld\n",sum);
}
return 0;
}
