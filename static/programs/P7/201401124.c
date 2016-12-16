#include<stdio.h>
/*void merges(long long int a, long long int b ,long long int c,long long int d,long long int A[])
{
	long long int n,m;
	n=b-a;

	m=d-c;
	
	long long int w[n],x[m];
	long long int i,k=0,g=0;
	for(i=a;i<b;i++)
	{
		w[k++]=A[i];
	}
	for(i=c;i<d;i++)
	{
		x[g++]=A[i];
	}
	long long int j=0,C[m+n];
	i=0;
	k=0;
	while((j<m)&&(i<n))
	{
		if(w[i]<x[j])
		{
			C[k++]=w[i];
			i++;
		}
		else 
		{
			C[k++]=x[j];
			j++;
		}
	}
	while(j<m)
	{
		C[k++]=x[j++];
		//	printf("sdad\n");
	}
	while(i<n)
	{
		C[k++]=w[i++];
		//	printf("asdasda\n");
	}
	k=0;
	for(i=a;i<d;i++)
	{
		A[i]=C[k++];
	}
//	A[a]=C[0];
//	A[b]=C[1];

}
void mergeso(long long int l,long long int r,long long int A[])
{
	if(r==l+1)
	{
		return;
	}
	else
	{
		long long int mid;
		mid=l+((r-l)/2);
		mergeso(l,mid,A);
		mergeso(mid,r,A);
		merges(l,mid,mid,r,A);
	}
}
*/
long long int comp(const void*a ,const void* b)
{
	return(*(long long int*)a - *(long long int*)b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t)
	{
		long long int n,i,sum=0;
		scanf("%lld",&n);
		long long int A[n];
		for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
	//	mergeso(0,n,A);
		qsort(A,n,sizeof(long long int),comp);
	//	for(i=0;i<n;i++)
	//		printf("%lld ",A[i]);
	//	printf("\n");
		long long int count=0;
		for(i=0;i<n;i++)
		{
			if(A[i]!=A[i+1])
			{
				count++;
				sum=sum+((count*(count-1))/2);
				count=0;
			}

			else
				count++;
		}		
		printf("%lld\n",sum);


		t--;
	}
	return 0;
}
