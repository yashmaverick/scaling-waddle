#include<stdio.h>
int main(){
	long long int a[500000];
	long long int n,i,j,sum;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			break;
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		i=n;
		/*while(i--){
			scanf("%lld",&a[n-i]);
		}*/
		sum=0;
		for(i=0;i<n-1;i++)
		{
			long long int k=0;
			for(j=i+1;j<n;j++)
			{
				if(a[j]>a[i])
				{
					sum+=n-j-1;
					break;
				}
				else if(a[j]>=k && a[j]<=a[i])
					k=a[j];
				else
					sum++;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}