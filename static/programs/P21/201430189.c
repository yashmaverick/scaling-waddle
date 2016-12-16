#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct linknode{
		long long int num;
		long long int wt;
		struct linknode *next;
}linknode;

typedef struct node{
		long long int dist;
		long long int heappos;
		struct linknode *adj;
}node;

long long int *heap,toput;
node *map;
long long int N;

void heapex(long long int po1 ,long long int po2){
		long long int temp=heap[po1];
		heap[po1]=heap[po2];
		heap[po2]=temp;
		map[heap[po1]].heappos=po1;
		map[heap[po2]].heappos=po2;
		return;
}

void push(long long int num){
		if(map[num].heappos==-1){
				heap[toput]=num;
				map[num].heappos=toput;
				long long int pt=toput;
				while((map[heap[pt/2]].dist)>map[heap[pt]].dist){
						heapex(pt/2,pt);
						pt=pt/2;
				}
				toput++;
		}
		else{
				long long int pt=map[num].heappos;
				while((map[heap[pt/2]].dist)>(map[heap[pt]].dist)){
						heapex(pt/2,pt);
						pt=pt/2;
				}
		}
		return;
}

long long heapmin(long long int i, long long int j){
		if(j>toput)
				return i;
		if(map[heap[i]].dist>map[heap[j]].dist)
				return j;
		return i;
}

void pop(){
		toput--;
		long long int pt=1,npt=2;
		while(1){
				if(pt*2>toput){
						heap[pt]=heap[toput];
						map[heap[pt]].heappos=pt;
						break;
				}
				npt=heapmin(pt*2,pt*2+1);
				npt=heapmin(npt,toput);
				heap[pt]=heap[npt];
				map[heap[pt]].heappos=pt;
				pt=npt;
				if(npt==toput){
						break;
				}
		}
		return;
}

long long int top(){
		return heap[1];
}

int main(){
		long long M,u,v,w,i,S,T;
		scanf("%lld %lld" ,&N,&M);
		//initialising map nodes
		map=malloc((N+1)*sizeof(node));
		for(i=1;i<N+1;i++){
				map[i].dist=-1;
				map[i].heappos=-1;
				map[i].adj=NULL;
		}
		//making edges
		while(M--){
				scanf("%lld %lld %lld" ,&u,&v,&w);
				linknode *temp1,*temp2; 
				temp1=malloc(sizeof(linknode));
				temp1->num=u;
				temp1->wt=w;
				temp1->next=map[v].adj;
				map[v].adj=temp1;
				temp2=malloc(sizeof(linknode));
				temp2->num=v;
				temp2->wt=w;
				temp2->next=map[u].adj;
				map[u].adj=temp2;
		}
		scanf("%lld %lld" ,&S,&T);
		//initialising heap
		heap=malloc((N+1)*sizeof(long long int));
		map[S].dist=0;
		map[S].heappos=1;
		heap[1]=S;
		toput=2;
		
		//actual processing
		while(top()!=T && toput!=1){
				linknode *pt = map[top()].adj;
				int t=top();
				pop();
				while(pt!=NULL){
						if(map[pt->num].dist==-1 || (map[pt->num].dist)>((map[t].dist)+(pt->wt))){
								(map[pt->num].dist)=((map[t].dist)+(pt->wt));
								push(pt->num);
						}
						pt=pt->next;
				}
		}
		if(top()==T)
				printf("%lld\n" ,map[T].dist);
		else
				printf("NO\n");
		return 0;
}
