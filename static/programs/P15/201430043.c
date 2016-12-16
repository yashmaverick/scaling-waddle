#include<stdio.h>

//void fun(int A[],int x)
//{
//}

int main()
{
	int i,j,test,A[10007],n,k,last,ele,first;
	scanf("%d",&test);
	for(j=0;j<test;j++)
	{
		scanf("%d",&n);
		scanf("%d",&k);
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		for(i=0;i<=n-k;i++)
		{
			first=0;ele=0;last=i+k-1;
			if(i==0)
			{
				first=i;
				ele=first;
//				fun(A,i);
				while(first<=last)	
				{
					if(A[ele]>A[last])
						ele=last;
					last--;
				}
				
			}
			else 
			{
				if(ele>=i)
				{
					if(A[last]<=A[ele])
						ele=last;
				}
				else
				{ 
					first=i;ele=first;
//					fun(A,i);
					while(first<=last)	
					{
						if(A[ele]>A[last])
							ele=last;
						last--;
					}
				}
			}
			if(i!=n-k)
			        printf("%d ",A[ele]);
			else
				printf("%d\n",A[ele]);
		}
	}
	return 0;
}
