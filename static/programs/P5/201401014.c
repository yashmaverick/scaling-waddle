#include<stdio.h>
long long int A[100001],n;
//void sort(long long int start,long long int end,long long int no_elements);
void swap(long long int a,long long int b);
int main()
{
	long long int i,test_cases,k,k1,j,sum,start,end,flag;
	char S[1000];
	scanf("%lld",&test_cases);
	while(test_cases--)
	{
		scanf("%lld%lld",&n,&k);
		for(i=0;i<n;i++)
		{
		//	while((c=getchar())!=' ');
			scanf("%s",S);
			scanf("%lld",&A[i]);
		}
		//sort(A);
//		for(i=0;i<n;i++)
//			printf("%lld ",A[i]);
//		printf("\n");
		for(i=n-1;i>=0;i--)
		{
			for(j=0;j<i;j++)
			{
				if(A[j]>A[j+1])
				{
					A[j]=A[j]+A[j+1];
					A[j+1]=A[j]-A[j+1];
					A[j]=A[j]-A[j+1];
				}
			}
		}


		flag=0;
		for(i=0;i<n;i++)
		{
			start=i+1;
			end=n-1;
			k1=k-A[i];
			//if(k1<=0)
			//	continue;
			//else
		//	{
				while(start<end)
				{
					sum=A[start]+A[end];
					if(sum<k1)
						start++;
					else if(sum>k1)
						end--;
					else
					{
						flag=1;
						break;
					}
				}
				if(flag==1)
					break;
		//	}
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
/*void sort(long long int start,long long int end,long long int no_elements)
{			
	long long int pivot_value,pivot_index,temp,i,flag,start1,end1,ifflag;
	start1=start;
	end1=end;
	pivot_index=start+((no_elements-1)/2);
	pivot_value=A[pivot_index];
	if(start>=end)
		return;
	else
	{
		while(start<end)
		{
			flag=0;
			while(A[start]<pivot_value)
				start++;
			while(A[end]>pivot_value)
			{
				end--;
			}
			if(start<end)
			{
				flag=0;
				if(A[start]==pivot_value && start==pivot_index)
					flag=1;
				else if(A[end]==pivot_value && end==pivot_index)
					flag=2;
				ifflag=0;
				if(A[start]>=A[end])
				{
					ifflag=1;
					A[start]=A[start]+A[end];
					A[end]=A[start]-A[end];
					A[start]=A[start]-A[end];
				}
				if(flag==1)
					pivot_index=end;
				if(flag==2)
					pivot_index=start;
				if(ifflag==1)
				{
					start++;
					end--;
				}
				pivot_value=A[pivot_index];
			}
		}
		if(start==end)
		{
			if(start<pivot_index && A[start]>pivot_value)
			{
				temp=start;
				A[start]=A[start]+A[pivot_index];
				A[pivot_index]=A[start]-A[pivot_index];
				A[start]=A[start]-A[pivot_index];
				pivot_index=temp;
			}
		}
	}
	if(pivot_index>0)
		sort(start1,(pivot_index-1),pivot_index-start1);
	if(pivot_index<n-1)
		sort(pivot_index+1,end1,end1-pivot_index);
	return;
} */


