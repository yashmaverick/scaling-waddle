#include<stdio.h>

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
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--){
		char s[100000];
		long long int n,k,i,x,y,z,c;
		scanf("%lld%lld",&n,&k);
		long long int a[n];
		for(i=0;i<n;i++){
			scanf("%s",s);
			scanf("%lld",&a[i]);
		}
		msort(a,n);
		int flag=0;
		c=0;
		for(x=0;x<n-1;x++){
			for(y=x+1,z=n-1;y<z;){
				i=a[x]+a[y]+a[z];
				if(i==k){
					flag=1;
					break;
				}
				if(i<k)
					y++;
				if(i>k)
					z--;
			}

			if(flag == 1)
				break;
		}

		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
