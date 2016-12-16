#include<stdio.h>
long long int a[1000000];
char z[100000];

void swap(long long int c,long long int b)
{
	long long int temp=a[c];
	a[c]=a[b];
	a[b]=temp;
}
long long int partition(long long int start,long long int end)
{
	long long int pivot=a[end];
	long long int pindex=start;
	long long int i;
	for(i=start;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			swap(i,pindex);
			pindex++;
		}
	}
	swap(pindex,end);
	return pindex;
}


void quicksort(long long int start,long long int end)
{
	if(start<end)
	{
		long long int pindex=partition(start,end);
		quicksort(start,pindex-1);
		quicksort(pindex+1,end);
	}
return;
}



int main()
{
	long long int sum,total;
	long long int N,n,fl,fr;
	scanf("%lld",&N);
	long long int i,j,k;
	int flag=0;
	for(total=0;total<N;total++)
	{
		scanf("%lld",&n);
		scanf("%lld",&k);
		flag=0;
	
		for(i=0;i<n;i++)
		{
			scanf("%s",z);
			scanf("%lld",&a[i]);

		}
		int m;

		quicksort(0,n-1);
	//	for(m=0;m<n;m++)
	//	printf("%lld",a[m]);

		for(j=0;j<n;j++)
		{
			fl=j+1;
			fr=n-1;
			while(fl<fr)
			{
				if(a[j]+a[fl]+a[fr]==k)
				{
					sum=k;
					 flag=1;
					break;
				}

				else if(a[j]+a[fl]+a[fr]<k)
					fl++;
				else 
					fr--;



			}
			if(flag==1)
				break;



		}

		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");


	}

	


return 0;
}

