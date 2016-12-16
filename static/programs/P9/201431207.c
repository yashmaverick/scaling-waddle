#include<stdio.h>
int main()
{
	long long int n,mod,i,j,count,count1,num,a[1000000],sum,numb,temp,temp1,val,tmp; 
	scanf("%lld%lld",&n,&mod);
	long long int b[n+1][2];
	count=0;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&num);
		a[count]=num;
		b[i][1]=count;
		count+=1;
		sum=0;
		for(j=0;j<num;j++)
		{
			scanf("%lld",&numb);
			a[count]=numb;
			count++;
			sum=((sum+numb)%mod);
		}
		b[i][0]=sum;
	}
	b[n][1]=count;
//	for(i=0;i<n;i++)
//		printf("%lld\n",b[i][1]);
	for(i=n-2;i>=0;i--)
	{
		for(j=0;j<=i;j++)
		{
			if(b[j][0]>b[j+1][0])
			{
				temp=b[j][0];
				b[j][0]=b[j+1][0];
				b[j+1][0]=temp;

				temp1=b[j][1];
				b[j][1]=b[j+1][1];
				b[j+1][1]=temp1;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%lld\n",b[i][0]);
		val=b[i][1];

		for(j=0;j<a[b[i][1]];j++)
		{
			val++;
			printf("%lld\n",a[val]);
		}
		printf("\n");
	}
	return 0;
}
