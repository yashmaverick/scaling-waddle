#include<stdio.h>
#include<stdlib.h>

typedef struct LaTree
{
	int n;
	struct LaTree *next;
}LaTree;

int Depend[500004];
LaTree *head[500004];
int Heap[500004],end=-1,front=0;

void heapinsert(int i)
{
	int c,Root,temp;
	c=i;
		while(c!=front)
		{
			Root=(c-1)/2;
			if(Heap[Root]>Heap[c])
			{
				temp=Heap[Root];
				Heap[Root]=Heap[c];
				Heap[c]=temp;
					
			}
			c=Root;
			
		}
}
void deletemin()
{
	int b,temp,child,temp1;
	int tempo;
	//printf("Heap[%d]=%d  Heap[%d]=%d \n",front,Heap[front],end,Heap[end]);
	tempo=Heap[front];
	Heap[front]=Heap[end];
	Heap[end]=tempo;
	end--;
	b=front;
	while(b!=end && end!=-1)
	{
		child=2*b+1;
		if(child>end)
			break;
		//printf("Heap[%d]=%d  Heap[%d]=%d   Heap[%d]=%d\n",b,Heap[b],child,Heap[child],child+1,Heap[child+1]);
		if(Heap[b]<Heap[child] )
			if(Heap[b]<Heap[child+1] )
				break;
		if(Heap[b]>Heap[child])
		{	
			if(child+1>end)
			{
				temp1=Heap[b];
				Heap[b]=Heap[child];
				Heap[child]=temp1;
				b=child;
			}
			else if(Heap[child]<Heap[child+1] && child+1<=end)
			{
				temp1=Heap[b];
				Heap[b]=Heap[child];
				Heap[child]=temp1;
				b=child;
			}
			else if(Heap[child]>Heap[child+1] && child+1<=end)
			{
				temp1=Heap[b];
				Heap[b]=Heap[child+1];
				Heap[child+1]=temp1;
				b=child+1;
			}
			else
				break;
			
		}
		else if(Heap[b] >Heap[child+1] )
		{
			if(Heap[child+1] < Heap[child] && child+1<=end)
			{
				temp1=Heap[b];
				Heap[b]=Heap[child+1];
				Heap[child+1]=temp1;
				b=child+1;
			}
			else if(Heap[child]<Heap[child+1] && child+1<=end)
			{
				temp1=Heap[b];
				Heap[b]=Heap[child];
				Heap[child]=temp1;
				b=child;
			}
			else
				break;
		}
		else break;	
	}
}

int main()
{
	int Tasks,N;
	scanf("%d%d",&Tasks,&N);
	LaTree *temp;
	int a,i,val,root;
/*	if(N==0)
	{
		for(i=1;i<Tasks;i++)
			printf("%d ",i);
		printf("%d\n",i);
		return 0;
	}*/

	for(i=0;i<=Tasks;i++)
	{
		head[i]=NULL;
		Depend[i]=0;
	}	
	int node1,node2;
	for(i=0;i<N;i++)
	{
		scanf("%d%d",&node1,&node2);
		Depend[node2]=Depend[node2]+1;

		if(head[node1]!=NULL)
		{
			temp=head[node1];
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=(LaTree*)malloc(sizeof(LaTree));
			temp->next->n=node2;
		}
		else if(head[node1]==NULL)
		{
			head[node1]=(LaTree*)malloc(sizeof(LaTree));
			head[node1]->n=node2;
		}

	}
	end=-1;


	for(i=1;i<=Tasks;i++)
	{	
		if(Depend[i]==0)
		{
			end++;
			Heap[end]=i;
			heapinsert(end);
		}

	}
	int Vikas;

	while(1)
	{
		printf("%d",Heap[front]);
		Vikas=Heap[front];
		if(end!=-1)
			deletemin();

		LaTree *temp;
		temp=head[Vikas];
		while(temp!=NULL)
		{
			Depend[temp->n]=Depend[temp->n]-1;
				
			if(Depend[temp->n]==0)
			{
				end++;
				Heap[end]=temp->n;	
//				printf("Heap[%d]=%d\n",end,Heap[end] );
				heapinsert(end);
			}	
			temp=temp->next;
		}
		if(end==-1)
			break;
		else
			printf(" ");
	}	
	printf("\n");
	return 0;
}
