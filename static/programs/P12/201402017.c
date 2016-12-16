#include<stdio.h>
#include<stdio.h>
#include<string.h>
int main()
{
	long long int max,j,n,a[1000004],i,sum;
	//scanf("%lld",&n);
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			break;
		else
		{
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	sum=0;
	for(i=0;i<n;i++){
	
		max=0;
		for(j=i+1;j<n;j++){
		if(a[j]>a[i]){
		sum=sum+n-1-j;
		break;}
		else if(a[j]>max)max=a[j];
		if(a[j]<max)sum++;}
	}
		printf("%lld\n",sum);
	
	//scanf("%lld",&n);
	}
	}
	return 0;
}

