#include<stdio.h>
#include<stdlib.h>
int S[1000];
int p=0;
int temp23[1000000];
static int hk=0;
void push(int x,int *C,int i)
{
	temp23[hk]=x;
	int sum1=0;
	if(hk==C[i])
	S[p]=&temp23[hk];
	hk++;
}

int main()
{
	int N,i,j,k,m,l;
	scanf("%d %d",&N,&m);
	int sum[N];
	int M[N];
	int C[N+1];
	int sum3=0;
	C[0]=0;
	for(i=0;i<N;i++)
	{
		sum[i]=0;
		scanf("%d",&M[i]);
		sum3=sum3+M[i];
		for(j=0;j<M[i];j++)
		{
			int x;
			scanf("%d",&x);
			push(x,C,i);
			sum[i]=(((sum[i])%m+(x)%m)%m);
		}
		C[i+1]=sum3;
	p++;
	}
	for(k=0;k<N;k++)
	{
		for(l=k+1;l<N;l++)
		{
			if(sum[k]>sum[l])
			{
				int temp=sum[k];
				sum[k]=sum[l];
				sum[l]=temp;
				temp=M[k];
				M[k]=M[l];
				M[l]=temp;
				temp=S[k];
				S[k]=S[l];
				S[l]=temp;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		printf("%d\n",sum[i]);
			int *tmp;
			tmp=(int)S[i];
		for(j=0;j<M[i];j++)
		{
			printf("%d\n",*tmp);
			tmp++;
		}
		//free(tmp);
		printf("\n");
	}

	return 0;
}
