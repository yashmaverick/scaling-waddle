#include<stdio.h>
void qsort(long long int *arr,long long int first,long long int last)
{
	long long int i,pivot,pindex,temp;
	if(first<=last)
	{
		pivot=*(arr+last);
		pindex=first;
		for(i=first;i<last;i++)
		{
			if(*(arr+i)<=pivot)
			{
				temp=*(arr+i);
				*(arr+i)=*(arr+pindex);
				*(arr+pindex)=temp;
				pindex++;
			}
		}
		temp=*(arr+pindex);
		*(arr+pindex)=*(arr+last);
		*(arr+last)=temp;
		qsort(arr,first,pindex-1);
		qsort(arr,pindex+1,last);
	}
	return ;
}

long long int bsearch(long long int *a,long long int x,long long int n,long long int cost)
{
	long long int end=n,mid;
	long long int start=x,temp=0;
	while(start<=end)
	{
		temp=0;
		mid=(start+end)/2;
		if(*(a+mid)==cost)
		{
			temp=1;
			break;
		}
		else if(*(a+mid)>cost)
			end=mid-1;

		else
			start=mid+1;
		if(temp==1)
			break;
	}
	if(temp==1)
		return 1;
	return 0;
}

int main()
{
	char str[100];
	long long int t,A[1001],j,i,state=0;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n,x,c,k,l;
		scanf("%lld %lld",&n,&x);
		for(j=1;j<n+1;j++)
		{
			scanf("%s %lld",str,&A[j]);
		}
		qsort(A,1,n);
	//	for(i=1;i<n+1;i++)
	//		printf("%lld ",A[i]);
	//	printf("\n");	
		for(k=1;k<n+1;k++)
		{
			state=0;
			for(l=k+1;l<n+1;l++)
			{
				i=x-A[k]-A[l];
				state=bsearch(A,l+1,n,i);
	//			printf("%lld\n",state);
				if(state==1)
					break;
			}
			if(state==1)
				break;
		}
		if(state==1)
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
}			
