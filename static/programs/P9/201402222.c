#include<stdio.h>
int Add[1003],S[1003],A[1000001];
typedef struct  node{
	int weight;
	int head;
	int tail;
}node;
void sort( int Add[],int A[],int S[],int t )
{
	int i,j;
	struct node T[1003],temp;
	for(i=0;i<t;i++)
	{
		T[i].weight=Add[i];
		T[i].head=S[i];
		T[i].tail=S[i+1]-1;
		//printf("-->%d\n",T[i].weight);
	}
	for(i=0;i<t;i++)
	{
		for(j=i;j<t;j++)
		{
			if(T[i].weight>T[j].weight)
			{
				temp=T[i];
				T[i]=T[j];
				T[j]=temp;
			}
		}
	}
	for(i=0;i<t;i++)
	{	printf("%d\n",T[i].weight);
	for(j=T[i].head;j<=T[i].tail;j++)
	{
		printf("%d\n",A[j]);
	}
	printf("\n");
	}
}
int main()
{
	int i,j,t,n,k=0,s=0,m,sum;
	scanf("%d %d",&t,&m);
	for(i=0;i<t;i++)
	{
		S[s]=k;
		s++;
		scanf("%d",&n);
		sum=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&A[k]);
			sum=(sum%m+A[k]%m)%m;
			k++; 
		}
		S[s]=k;
		Add[i]=sum%m;
	}
		sort( Add,A,S,t);
	
	return 0;
}
