#include<stdio.h>
long long int a[100000],b[100000];
int j=0,n,flag=0;
int func(const void *a,const void *b)
{
	return (*(long long int*)a- *(long long int*)b);
}
void f(long long int k2)
{
	int i=0,l=0;
	long long int k;
	k=k2/10;
	//	printf("%lld\n",k);
	if(k>=1)
	{
		b[j]=k;
		j++;
		if(k>=1 && flag==0)
		{
			f(k);
		}
	}
}
int main()
{
	int i,m=0,a1,a2;
	scanf("%d",&a1);
	for(a2=0;a2<a1;a2++)
	{	
		j=0;
		flag=0;
		long long int k1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		qsort(a,n,sizeof(long long int),func);
		for(i=0;i<n;i++)
		{
			if(a[i]==a[i+1])
			{
				flag=2;
				break;
			}

			k1=a[i];
			f(k1);
		}
		int fl=0;
		if(flag!=2)
		{
			qsort(b,j,sizeof(long long int),func);
			long long int first,last,mid;
			int i1;
	//		for(i=0;i<n;i++)
	//		{
	//			printf("%lld ",a[i]);
	//		}
	//		printf("\n");
	//		for(i=0;i<j;i++)
	//		{
	//			printf("%lld ",b[i]);
	//		}
	//		printf("\n");
			for(i=0;i<n;i++)
			{
				first=0;
				last=j-1;
				mid=(first+last)/2;
//				printf("%lld\n",a[i]);
				while(first<=last)
				{
					if(b[mid]>a[i])
					{
						last=mid-1;
						//	printf("%lld\n",a[i]);
					}
					if(b[mid]==a[i])
					{
						fl=1;
						//	printf("%lld\n",a[i]);
						break;
					}
					if(b[mid]<a[i])
					{
						first=mid+1;
						//	printf("%lld\n",a[i]);
					}
					mid=(first+last)/2;
//					if(first>last)
//						break;
				}
				if(fl==1)
					break;
			}
		}
		if(fl==1 || flag==2)
		{
			printf("NO\n");
		}
		else
		{
			if(n!=0)
				printf("YES\n");
		}
	}
	return 0;
}
