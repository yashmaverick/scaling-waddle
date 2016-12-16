#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node* next;
	long long int val;
	long long int w;
}node;
typedef struct heap
{
	long long int node;
	long long int weight;
}heap;
void swap(long long int *a,long long int *b)
{
	long long int temp=*a;
	*a=*b;
	*b=temp;
}
heap h[100000];
long long int hp[100000];
long long int hi=1;
void shuffleup(long long int x)
{
	while(x!=1 && h[x].weight<h[x/2].weight)
	{
		swap(&h[x].weight,&h[x/2].weight);
		swap(&h[x].node,&h[x/2].node);
		swap(&hp[h[x].node],&hp[h[x/2].node]);
		x/=2;
	}
}
long long int insertheap(long long int n,long long int w)
{
	heap temp;
	temp.node=n;
	temp.weight=w;
	h[hi++]=temp;
	hp[n]=hi-1;
	shuffleup(hi-1);
}
node* insert(node* a,long long int n2,long long int weight)
{
	node* temp=malloc(sizeof(node));
	temp->val=n2;
	temp->w=weight;
	temp->next=a;
	a=temp;
	return a;
}
void shuffledown(long long int x)
{
	long long int ul=hi-1;
	while(1)
	{
		if(2*x>ul && 2*x+1>ul) return;
		else if(2*x<=ul && 2*x+1>ul)
		{
			if(h[x].weight>h[2*x].weight)
			{
				swap(&hp[h[x].node],&hp[h[2*x].node]); 
				swap(&h[x].node,&h[2*x].node); swap(&h[x].weight,&h[2*x].weight);     x*=2;    
			}
			else break;
		}
		else if(2*x<=ul && x*2+1<=ul)
		{
			if(h[2*x].weight<=h[2*x+1].weight)
			{
				if(h[x].weight>h[2*x].weight) 
				{
					swap(&hp[h[x].node],&hp[h[2*x].node]);
					swap(&h[x].node,&h[2*x].node); swap(&h[x].weight,&h[2*x].weight); x*=2;
				}
				else break;
			}
                        else if(h[2*x+1].weight<=h[2*x].weight)
			{
				if(h[x].weight>h[2*x+1].weight) 
				{
					swap(&hp[h[x].node],&hp[h[2*x+1].node]); 
					swap(&h[x].node,&h[2*x+1].node); swap(&h[x].weight,&h[2*x+1].weight); x=2*x+1;  
				}
				else break;
			}
		}
	}
}
void deleteheap()
{
	swap(&h[1].node,&h[hi-1].node);
	swap(&h[1].weight,&h[hi-1].weight);
	swap(&hp[h[1].node],&hp[h[hi-1].node]);
	hi--;
	shuffledown(1);
}
int main()
{
        {
                h[0].weight=-2;
		long long int nodes,edges,i,j,k;
		scanf("%lld %lld",&nodes,&edges);
		node* a[nodes+1];
		for(i=0;i<nodes+1;i++) a[i]=NULL;
		for(i=0;i<edges;i++)
		{
			long long int n1,n2,weight;
			scanf("%lld %lld %lld",&n1,&n2,&weight);
			a[n1]=insert(a[n1],n2,weight);
		}
/*		for(i=1;i<nodes+1;i++)
		{
			node* head=a[i];
			while(head!=NULL)  { printf("%lld ",head->val); head=head->next;  } 
			printf("\n");
		}*/

		long long int n1,n2;
		scanf("%lld %lld",&n1,&n2);
		long long int coverednodes[nodes+1];
		for(i=0;i<nodes+1;i++) coverednodes[i]=0;
		long long int distance[nodes+1];
		for(i=0;i<nodes+1;i++) distance[i]=9223372036854775807;
		coverednodes[n1]=1;
		distance[n1]=0;
		for(i=1;i<nodes+1;i++)
		{
			if(coverednodes[i]==1) insertheap(i,0);
			else insertheap(i,9223372036854775807);
		}
//		printf("heap ->");
//		for(i=1;i<hi;i++) printf("%lld %lld\n",h[i].node,h[i].weight);
		while(hi!=1)
		{
			node* head=a[h[1].node];
			while(head!=NULL)
			{
//				printf("heap-> ");
//				for(i=1;i<hi;i++) printf("%lld %lld\n",h[i].node,h[i].weight);
				long long int neighbour=head->val;
//				printf("%lld %lld \n",distance[neighbour],distance[h[1].node]+head->w);
				if(distance[neighbour]>distance[h[1].node]+head->w) 
				{
					distance[neighbour]=distance[h[1].node]+head->w;
					long long int position=hp[neighbour];
					h[position].weight=distance[h[1].node]+head->w;
					shuffleup(position);
				}
				head=head->next;
			}
			deleteheap();
		}
		if(distance[n2]==9223372036854775807) printf("NO\n");
		else printf("%lld\n",distance[n2]);
//		for(i=1;i<nodes+1;i++) printf("%lld ",distance[i]);
	}
	return 0;
}
