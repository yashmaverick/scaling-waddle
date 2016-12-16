#include<stdio.h>
int bs(long long int ary[],int start,int end,long long int e)
{
	int mid;
	while(start<end)
	{
		mid=(start+end)/2;
		if(ary[mid]>=e)
		{
			end=mid;
		}
		else
		{
			start=mid+1;
		}
	}
	return start;
}
int main()
{
	int sa,sb,sc;
	long long int a[100010],b[100010],c[100010],ans;
	int i,t,min,ind1,ind2;
	scanf("%d",&t);
	while(t>0)
	{
		long long int bstore[100010]={0};
		long long int newstore[100010]={0};
		scanf("%d",&sa);
		for(i=0;i<sa;i++)
		{
			scanf("%lld",&a[i]);
		}
		scanf("%d",&sb);
		min=sb;
		for(i=0;i<sb;i++)
		{
			scanf("%lld",&b[i]);
		}
		scanf("%d",&sc);
		if(sc<min)
		{
			min=sc;
		}
		for(i=0;i<sc;i++)
		{
			scanf("%lld",&c[i]);
		}
		for(i=0;i<min;i++)
		{
			ind1=bs(c,i,sc-1,b[i]);
			//printf("%d\n",ind1);
			if(c[ind1]>=b[i])
			{
				bstore[i]=sc-ind1;
			}
			else
			{
				bstore[i]=0;
			}
		}
		/*for(i=0;i<min;i++)
		{
			printf("%d ",bstore[i]);
		}
		printf("\n");
		if(sa<min)
		{
			min=sa;
		}*/
		newstore[min-1]=0;
		ans=0;
		for(i=min-1;i>=0;i--)
		{
			newstore[i]=newstore[i+1]+bstore[i];
		//	printf("%d ",newstore[i]);
		}
		if(sa<min)
		{
			min=sa;
		}
		for(i=0;i<min;i++)
		{
			ind2=bs(b,i,sb-1,a[i]);
			if(b[ind2]>=a[i])
			{
				ans=ans+newstore[ind2];
			}
		}
		printf("%lld\n",ans);
		t--;
	}
	return 0;
}


	

