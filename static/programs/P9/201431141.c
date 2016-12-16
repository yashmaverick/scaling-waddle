#include<stdio.h>
#include<stdlib.h>
typedef struct bag
{
	int weight;
	int start;
	int end;
	int position;
}bag;
int N;
int main()
{
	int i,M,W,mod,a,j,B[1000000],s=0,e;
	bag A[1000],temp;
	scanf("%d%d",&N,&mod);
	for(i=0;i<N;i++)
	{
		scanf("%d",&M);
		A[i].position=i;
		A[i].weight=0;
		A[i].start=s;
		W=0;
		for(j=0;j<M;j++)
		{
			scanf("%d",&a);
			B[s]=a;
			s++;
			A[i].weight=a;
			W=(W+A[i].weight)%mod;
		}
		A[i].weight=W;
		A[i].end=s;
	}
	for(i=0;i<N;i++)
		for(j=i+1;j<N;j++)
			if(A[i].weight>A[j].weight)
			{
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
			else if(A[i].weight==A[j].weight && A[i].position>A[j].position)
			{
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
	for(i=0;i<N;i++)
	{
		printf("%d\n",A[i].weight);
		for(j=A[i].start;j<A[i].end;j++)
			printf("%d\n",B[j]);
		printf("\n");
	}
	return 0;
}
