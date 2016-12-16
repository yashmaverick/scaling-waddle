#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	long long int *A;	/*A is pointer to dynamically allocated memory*/
	struct node* next;
}node;
node* head;
int main()
{
	long long int N,MOD,M,w,i,j;
	node* p;
	node* q;
	//while(1)
	//{
		scanf("%lld",&N);
		if(N==0)
			return 0;
		scanf("%lld",&MOD);
		head=NULL;
		for(i=0;i<N;i++)
		{
			scanf("%lld",&M);
			
			node *new = (node*)malloc(sizeof(node));	/*creation of new node*/
			new->A=(long long int*)malloc((M+2)*sizeof(long long int));	/*dynamically allocating array of size M+1*/
			new->A[0]=0;
			//printf("\n");
			for(j=1;j<=M;j++)
			{	
				scanf("%lld",&w);
				new->A[j]=w;
				//printf("for M=%lld element %lld\n",M,new->A[j]);
				new->A[0]+=w%MOD;
			}
			new->A[j]=-1;			/*storing -1 at end of array to mark end,useful while printing*/
			new->A[0]%=MOD;
			new->next=NULL;
			if(head==NULL)
			{	
				head=new;
				
			}
			else if(new->A[0]<head->A[0])
			{
				new->next=head;
				head=new;
			}
			else
			{
				q=head;
				while(q!=NULL && q->A[0]<=new->A[0])
				{	
					p=q;
					q=q->next;
				}
				new->next=q;
				p->next=new;
			}
		}
		p=head;
		while(p!=NULL)
		{
			//printf("%lld\n",p->A[0]);
			for(i=0;p->A[i]!=-1;i++)
				printf("%lld\n",p->A[i]);
			printf("\n");
			p=p->next;
		}
	//}
	return 0;
}
					
			
				
				
				
			
