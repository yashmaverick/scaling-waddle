#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,n,k,*A,*S,min,ind,q,i,j,l;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		A=(int*)malloc(n*sizeof(int));
		S=(int*)malloc(n*sizeof(int));
		scanf("%d",&A[0]);
		S[0]=0;
		q=1;
		min=0;ind=0;
		for(i=1;i<k;i++)
		{
			scanf("%d",&A[i]);
		 	if(A[i]<=A[S[q-1]])
			{
				j=q-1;
				while(j>=0 && A[S[j]]>=A[i])
					j--;
				q=j+1;
		//		if(q==0)
		//			ind=i;
			//	ind=i;
			}
			S[q++]=i;
		}
//		for(i=min;i<q;i++)
//			printf("%d ",A[S[i]]);
//			printf("  --stack\n");
		if(n==k)
			printf("%d\n",A[S[min]]);
		else
		{
			printf("%d ",A[S[min]]);
			for(i=k;i<n;i++)
			{
				scanf("%d",&A[i]);
				//printf
				if(S[min]<i-k+1)
					min++;
	//				printf("%d --ind\n",ind);
				if(A[i]<=A[S[q-1]])
				{
					j=q-1;
					while(j>=min && A[S[j]]>=A[i])
						j--;
					q=j+1;
				//	if(q==min)
						
						
				}
			//	else
			//		in++;
				S[q++]=i;
		//		for(l=min;l<q;l++)
		//			printf("%d ",A[S[l]]);
		//			printf("  ----stack\n");
				if(i<n-1)
					 printf("%d ",A[S[min]]);
				else if(i==n-1)
					printf("%d",A[S[min]]);
			}
			printf("\n");
		}
	}
	return 0;
}	
