#include<stdio.h>
int main()
{
	int i,t,j,n,k,l,min_ind,end,start;
	long long int arr[10005];
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<10005;i++)
			arr[i]=0;
		scanf("%d",&n);
		scanf("%d",&k);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		min_ind=0;
		for(i=1;i<k;i++)
		{
			if(arr[i]<arr[min_ind])
				min_ind=i;
		}
		if(k==n)
			{
				
		printf("%lld\n",arr[min_ind]);
		continue;
			}
			printf("%lld ",arr[min_ind]);
		start=1;
		end=k;
		while(end<=(n-1))
		{
			if(min_ind>=start && min_ind<=end)
			{
				if(arr[min_ind]<arr[end])
				{
					if(end==(n-1))
						printf("%lld\n",arr[min_ind]);
					else
						printf("%lld ",arr[min_ind]);
				}
				else
				{
					if(end==(n-1))
						printf("%lld\n",arr[end]);
					else
						printf("%lld ",arr[end]);
					min_ind=end;
				}


			}
			else
			{
				min_ind=start;
				for(i=start+1;i<=end;i++)
				{
					if(arr[i]<arr[min_ind])
						min_ind = i;
				}
				if(end==(n-1))
					printf("%lld\n",arr[min_ind]);
				else
					printf("%lld ",arr[min_ind]);
			}
			start++;
			end++;
		}

		

		
	}
	return 0;
}