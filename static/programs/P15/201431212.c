#include<stdio.h>
int main()
{
	int t,m;
//	long long int a[10001],min;
	scanf("%d",&t);
	for(m=0;m<t;m++)
	{	
		int n,k,i,pos=0,j,index,start=0;;
		long long int a[10001],min;
	
		long long int b[10001]={};
		pos=0;
		start=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		min=a[0];
		index=0;
		for(i=0;i<k;i++)
		{
		//	min=a[0];     
		//	index=0;
			if(a[i]<min)
			{
				min=a[i];
				index=i;
			}
		}
		b[pos]=min;
		start++;
		int h=i;
		while(h<n)
		{
			if(index!=start-1)
			{
				if(a[h]<min)
				{
					min=a[h];
					index=h;
				}
				start++;
				pos++;
				b[pos]=min;
				h++;
			}
			else if(index==start-1)
			{
				min=a[start];
				index=start;
				for(j=start;j<=start+k-1;j++)
				{
					if(a[j]<min)
					{
						min=a[j];
						index=j;
					}
				}
				start++;
				pos++;
				b[pos]=min;
				h++;
			}
		}
		for(pos=0;pos<n-k;pos++)
			printf("%lld ",b[pos]);
		printf("%lld\n",b[pos]);
	}
	return 0;
}
