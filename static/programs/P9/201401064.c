#include<stdio.h>
#include<stdlib.h>
int *arr;
typedef struct node{
	int n;
	int sum;
	int start;
	int end;
}node;
int main()
{
	int i,j,s;
	int mod,num;
	scanf("%d%d",&num,&mod);
	struct node *B;
	struct node *temp,pu;
	B=malloc(sizeof(node)*num);
	arr=malloc(1000001*sizeof(int));
	//	temp=malloc(sizeof(node)*100000);
	for(i=0;i<num;i++)
	{
		scanf("%d",&B[i].n);
		B[i].sum=0;
		B[0].start=0;
		B[0].end=(B[0].n)-1;
		if(i!=0)
		{

			B[i].start=B[i-1].start+B[i-1].n;
			B[i].end=(B[i].start)+((B[i].n)-1);


		}
		for(j=B[i].start;j<=B[i].end;j++)
		{
			scanf("%d",&arr[j]);
			B[i].sum=(B[i].sum%mod +arr[j]%mod)%mod;
		}
		//B[i].sum=(B[i].sum)%mod;

		// temp[i]=B[i];
	}
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(B[i].sum>B[j].sum)
			{
				//swap
				pu=B[i];
				B[i]=B[j];
				B[j]=pu;
			}

		}
		//    printf("%d\n",B[test-1].sum);
		//  for(s=0;s<B[test-1].n;s++)
		//{
		//      printf("%d\n",B[i].arr[s]);
		//}
	}
	for(i=0;i<num;i++)
	{
		printf("%d\n",B[i].sum);
		for(j=B[i].start;j<=B[i].end;j++)
		{
			printf("%d\n",arr[j]);
		}
		printf("\n");
	}

	return 0;
}
