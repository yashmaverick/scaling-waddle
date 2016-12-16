#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,i;
		scanf("%d",&a);
		long long int A[a];
		for(i=0;i<a;i++)
			scanf("%lld",&A[i]);
		scanf("%d",&b);
		long long int B[b];
		for(i=0;i<b;i++)
			scanf("%lld",&B[i]);
		scanf("%d",&c);
		long long int C[c];
		for(i=0;i<c;i++)
			scanf("%lld",&C[i]);

		int j,k;
		long long int new1[b];
		long long int new2[c];
		for(i=0;i<b;i++)
			new1[i]=0;
		for(i=0;i<c;i++)
			new2[i]=0;
		for(i=0,j=0; i<a &&j<b;)
		{
			if(A[i]<=B[j])
			{
				new1[j]++;
				i++;
				j++;
			}
			else{
				j++;
			}
		}
		for(i=1;i<b;i++)
			new1[i]=new1[i]+new1[i-1];

		for(i=0,j=0; i<b &&j<c;)
		{
			if(B[i]<=C[j])
			{
				new2[j]=new2[j]+new1[i];
				i++;
				j++;
			}
			else{
				j++;
			}
		}

		for(i=1;i<c;i++)
			new2[i]=new2[i]+new2[i-1];

		long long int sum=0;
		for(i=0;i<c;i++){
			sum=sum+new2[i];
		}
		printf("%lld\n",sum);
	
	}
	return 0;
}
