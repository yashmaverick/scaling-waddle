#include<stdio.h>
long long int k,a[1000005];
long long int split(long long int start,long long int end)
{
	long long int temp;
	long long int p=start;
	long long int i=start;
	while(i<end)
	{
		if(a[i]<=a[end])
		{
			temp=a[i];
			a[i]=a[p];
			a[p]=temp;
			p++;
		}
		i++;
	}
	temp=a[end];
	a[end]=a[p];
	a[p]=temp;
	return p;
}
void quicksort(long long int start,long long int end)
{
	if(start<end)
	{
		long long int pivot=split(start,end);
//		if(pivot>(k-1))
			quicksort(start,pivot-1);
//		else if(pivot<(k-1))
			quicksort(pivot+1,end);
	//	else return ;
	}
}
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld %lld",&n,&k);
		long long int i;
		char b[100005];
//		scanf("%s",b);
		for( i=0;i<n;i++)
		{

			scanf("%s",b);
			scanf("%lld",&a[i]);
		}
		quicksort(0,n-1);
		i=0;
		for(;i<n;i++)
		{
			int l=n-1,j=i+1;
			while(j<l)
			{
				if(a[j]+a[l]<k-a[i])
				{
					j++;
				}
				else if(a[j]+a[l]>k-a[i])
				{
					l--;
				}
				else
				{
					printf("YES\n");
					goto end;
					
				}
			}
		}

		printf("NO\n");
		end:;
//		return 0;
	}
	return 0;
}
		

		



	


			

