#include <stdio.h>
#define s(n) scanf("%d",&n)
#define cQ struct cQ
#define MAX 10001
int deleted=0;
cQ
{
	int A[MAX],I[MAX];
	int front,back;
};

void Qinit(cQ *D)
{
	D->front=-1;
	D->back=-1;
}

int empty(cQ *D)
{
	if(D->back==-1)
		return 1;
	return 0;
}
void cQinsert(cQ *D,int k,int i)
{
	if(D->back==-1)
		D->front=D->back=0;
	else if(k<=D->A[D->front])
		{D->front=D->back=0;deleted=1;}
	else if(k<=D->A[D->back])
	{
		//deleted=1;
		while(k<=D->A[D->back])
			D->back--;
		D->back++;
	}
	else if(D->back==MAX-1)
		D->back=0;
	else
		D->back++;
	D->A[D->back]=k;
	D->I[D->back]=i;
}

void cQdelete(cQ *D)
{
	if(D->front==D->back)
		D->front=D->back=-1;
	else if(D->front==MAX-1)
		D->front=0;
	else
		D->front++;
}

int cQfro(cQ *D)
{
	return D->A[D->front];
}

int fIndex(cQ *D)
{
	return D->I[D->front];
}

void display(cQ* D)
{
	int i,l=(D->front<=D->back) ? D->back:D->back+MAX;
	for(i=D->front;i<=l;i++)
	{
		int t=D->A[i%MAX],index=D->I[i%MAX];
		printf("%d ; %d\n",t,index);
	}
}

int main()
{
	int T,i,N,K,j,in;
	cQ Q;
	Qinit(&Q);
	s(T);
	for(i=0;i<T;i++)
	{
		s(N);s(K);Qinit(&Q);
		deleted=0;
		for(j=0;j<K;j++)
		{
			s(in);
			cQinsert(&Q,in,j);
		}
		//display(&Q);
			printf("%d",cQfro(&Q));
			if(deleted==0)
				cQdelete(&Q);
		for(j=K;j<N;j++)
		{
			s(in);
			cQinsert(&Q,in,j);
			//display(&Q);
			if(!empty(&Q))// && j!=N-1)
				printf(" %d",cQfro(&Q));
			/*if (!empty(&Q) && j==N-1)
			{
				printf("%d",cQfro(&Q));
			}*/
			if(!empty(&Q) && (j-fIndex(&Q))==K-1)
				cQdelete(&Q);
		}
		printf("\n");
	}

	return 0;
}