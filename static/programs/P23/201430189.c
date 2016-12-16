#include<stdio.h>
#include<stdlib.h>

long long *heap,toput=1;

void push(long long k){
		if(toput==1){
				heap[1]=k;
				toput++;
				return;
		}
		heap[toput]=k;
		long long pt=toput;
		while(heap[pt]<heap[pt/2]){
				long long temp=heap[pt];
				heap[pt]=heap[pt/2];
				heap[pt/2]=temp;
				pt=pt/2;
				if(pt==1){
						break;
				}
		}
		toput++;
		return;
}

void pop(){
		toput--;
		long long pt=1,npt=2;
		while(npt<toput){
				if(heap[npt]>heap[npt+1]){
						npt++;
				}
				if(heap[npt]>=heap[toput]){
						npt=toput;
						heap[pt]=heap[toput];
						return;
				}
				heap[pt]=heap[npt];
				pt=npt;
				npt=pt*2;
		}
		heap[pt]=heap[toput];
		return;
}

long long top(){
		return heap[1];
}

typedef struct linknode{
		long long num;
		struct linknode *next;
}linknode;

typedef struct node{
		long long beforecount;
		linknode *after;
}node;

node *map;

int main(){
		long long N,M,u,v,i;
		scanf("%lld %lld" ,&N,&M);
		map=malloc((N+1)*sizeof(node));
		for(i=1;i<N+1;i++){
				map[i].beforecount=0;
				map[i].after=NULL;
		}
		heap=malloc((N+1)*sizeof(long long));
		while(M--){
				scanf("%lld %lld" ,&u,&v);
				linknode *temp;
				temp=malloc(sizeof(linknode));
				temp->num=v;
				temp->next=map[u].after;
				map[u].after=temp;
				map[v].beforecount++;
		}
		for(i=1;i<N+1;i++){
				if(map[i].beforecount==0){
						push(i);
				}
		}
		int flag=0;
		while(toput!=1){
				linknode *pt=map[top()].after;
				if(flag==0){
						printf("%lld" ,top());
						flag=1;
				}
				else
						printf(" %lld" ,top());
				pop();
				while(pt!=NULL){
						map[pt->num].beforecount--;
						if(map[pt->num].beforecount==0){
								push(pt->num);
						}
						pt=pt->next;
				}
		}
		printf("\n");
		return 0;
}
