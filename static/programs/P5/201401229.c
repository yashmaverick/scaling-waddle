#include<stdio.h>
int cmpfunc(const void * a, const void * b)
{
	return(*(int*)a - *(int *)b);
}
int main()
{
	int test;
	int n,sum,A[1000],i,j,k,temp;
	char str[1000];
	scanf("%d",&test);
	while(test--)
	{
		//count=0;
		scanf("%d%d",&n,&sum);
		for(i=0;i<n;i++)
			scanf("%s%d",str,&A[i]);
/*		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(A[i]>A[j])
				{
					temp=A[i];
					A[i]=A[j];
					A[j]=temp;
				}
			}
		}*/
	//	for(i=0;i<n;i++)
	//		printf("%d\t",A[i]);
		qsort(A,n,sizeof(int),cmpfunc);

		for(i=0;i<n-2;i++)
		{
			j=i+1;
			k=n-1;
			while(j<k)
			{
		//	j=i+1;
		//	k=n-1;
			if(A[i]+A[j]+A[k]>sum)
				k--;
			else if(A[i]+A[j]+A[k]==sum)
			{
			printf("YES\n");
			break;
			}
			else
				j++;
			}
			if(j<k)
				break;
		}
		if(i>n-3)
			printf("NO\n");
	}
	return 0;
}


		
		
