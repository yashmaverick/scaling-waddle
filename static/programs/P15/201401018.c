#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int A[10001],K,N,i,j,index;
		scanf("%d%d",&N,&K);
		for(i=0;i<N;i++)
			scanf("%d",&A[i]);
		int min=1000000001,idx;
		/*for(i=0;i<K;i++)
		{
			if(A[i]<=min)
			{
				min=A[i];
				idx=i;
				}
				}*/
		//printf("%d",min);
		//int flag=0;
		for(i=0;i<N-K;i++)
		{
			//if(i>0)
			//{
			if(i==0 || i>index)
			{
				min=A[i];
				for(j=i;j<i+K;j++)
				{
					if(A[j]<=min)
					{
						min=A[j];
						index=j;
						//idx=j;
						//flag=1;
					}
					//if(flag==1)
					//	printf(" %d",min);
				}
				//min=1000000001;
			}

			if(A[i+K-1] < min)
				min=A[i+K-1];

			printf("%d ",min);

		}

		min=A[N-K];
		for(i=N-K;i<N;i++)
			if(A[i] < min)
				min=A[i];

		printf("%d\n",min);
	}
	return 0;
}
