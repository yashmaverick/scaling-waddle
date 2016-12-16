#include<stdio.h>
long long int bin(long long int a[],long long int m,long long int low,long long int high)
{	
	if(low>high)
		return -1;
        if(a[high]<m){
                return -1; 
        }
        else if(a[low]>=m)
                return low;
        if(low+1==high){
                if(a[low]==m)
                        return low;
                else return high;
        }
        long long int mid;
        mid=(low+high)/2;
        if(a[mid]<m)
                return bin(a,m,mid,high);
        else if(a[mid]>m)
                return bin(a,m,low,mid);
        else
                return mid;
}

int main()
{
	long long int test,jaa;
	scanf("%lld",&test);
	for(jaa=0;jaa<test;jaa++)
	{
		long long int k1,k2,k3,a1[100000],b[100000],c[100000],a_dup[100000]={0},b_dup[100000]={0};
		long long int i,temp=0;
		scanf("%lld",&k1);
		for(i=0;i<k1;i++)
			scanf("%lld",&a1[i]);

		scanf("%lld",&k2);
		for(i=0;i<k2;i++)
			scanf("%lld",&b[i]);

		scanf("%lld",&k3);
		for(i=0;i<k3;i++)
			scanf("%lld",&c[i]);
		b_dup[k2]=0;
		for(i=k2-1;i>=0;i--)
		{
			temp=bin(c,b[i],i,k3-1);
			if(temp>=0)
				b_dup[i]=k3-temp+b_dup[i+1];
		}

		for(i=0;i<k1;i++)
		{
			temp=bin(b,a1[i],i,k2-1);
			if(temp>=0)
				a_dup[i]=b_dup[temp];
		}
	/*	for(i=0;i<k2;i++)
			printf("%d ",b_dup[i]);
		printf("\n");
		printf("A aarar\n");*/
	/*	for(i=0;i<k1;i++)
			printf("%d ",a_dup[i]);
		printf("\n");*/
		long long int aman=0;
		for(i=0;i<k3;i++)
			aman=aman+a_dup[i];
		printf("%lld\n",aman);
	}
	return 0;
}
