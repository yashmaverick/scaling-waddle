#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node{
	long long int d;
	long long int wt;
	struct node*next;
};

typedef struct node node;

node*head[100005]={NULL};	// graph
long long int heap[100005][2]={0};	// contains node number and its corresponding weight. heap[][0] contains weight and heap[][1] contains node number.
long long int dist[100005];		// min distance from source currently
long long int where[100005]={0};	// 0 if node is not present in heap else tells where the node is located in heap
long long int t=1;
long long int n;
void swap(long long int e,long long int f){
	long long int g;
	g=heap[e][0];
	heap[e][0]=heap[f][0];
	heap[f][0]=g;
	g=heap[e][1];
	heap[e][1]=heap[f][1];
	heap[f][1]=g;
	g=where[heap[e][1]];
	where[heap[e][1]]=where[heap[f][1]];
	where[heap[f][1]]=g;
	return;
}

void insertheap(long long int distance,long long int num){
	long long int l=t;
	long long int c=l;
	heap[l][0]=distance;
	heap[l][1]=num;
	where[num]=l;
	while(heap[l][0]<heap[l/2][0]){
		swap(l,l/2);
		l=l/2;
	}
	t++;
	return;
}

void del(){
	//printf("to be deleted heap[1][1] = %lld\n",heap[1][1]);
	t--;
	where[heap[t][1]]=1;
	where[heap[1][1]]=0;
	heap[1][0]=heap[t][0];
	heap[1][1]=heap[t][1];
	long long int c=1,fl;
	while(2*c+1<=t&&(heap[c][0]>heap[2*c][0]||heap[c][0]>heap[2*c+1][0])){
		fl=0;
		if(heap[2*c][0]<=heap[2*c+1][0])
			fl=1;
		if(fl==1){
			swap(c,2*c);
			c=2*c;
		}
		else{
			swap(c,2*c+1);
			c=2*c+1;
		}
	}
	return;
}

void updateheap(long long int whereinheap,long long int distance){
	long long int loc=whereinheap;
	heap[loc][0]=distance;
	while(heap[loc][0]<heap[loc/2][0]){
		swap(loc,loc/2);
		loc=loc/2;
	}
	return;
}
void insert(long long int x,long long int y,long long int w){ 
	node*temp=(node*)malloc(sizeof(node));
	temp->d=y;
	temp->wt=w;
	temp->next=head[x];
	head[x]=temp;
	return; 
}

void print(long long int x){ 
	printf("%lld -> ",x);
	node*temp=head[x];
	while(temp!=NULL){
		printf(" n=%lld w=%lld",temp->d,temp->wt);
		temp=temp->next;
	}
	printf("\n");
	return;
}
void show(){
	long long int i;
	printf("start\n");
	for(i=1;i<t;i++)
		printf("i = %lld dist = %lld node = %lld @=%lld\n",i,heap[i][0],heap[i][1],where[heap[i][1]]);
	printf("t = %lld\n",t);
	printf("end\n");
}
long long int main(){
	long long int m,e,x,y,u,v,w,i,p,r,s;
	scanf("%lld%lld",&n,&m);
	e=m;
	while(e--){
		scanf("%lld%lld%lld",&x,&y,&w);
		insert(x,y,w);
	}
	scanf("%lld%lld",&u,&v);
	for(i=0;i<100005;i++){
		dist[i]=INT_MAX;
	}
	dist[u]=0;
	for(i=1;i<=n;i++){

	//	print(i);
		if(i!=u)
			insertheap(INT_MAX,i);
	}
	insertheap(0,u);
	p=t;
	p--;
//	show();
	node*temp=NULL;
	while(p!=0){
		temp=head[heap[1][1]];
		r=heap[1][1];
		s=heap[1][0];
		//printf("heap[1][1] = %lld\n",heap[1][1]);
		while(temp){
			if(where[temp->d]!=0 && dist[temp->d] > dist[r]+temp->wt ){	// it is in minheap
				dist[temp->d]=dist[r]+temp->wt;
				updateheap(where[temp->d],dist[temp->d]);
			//	printf("going on %lld with %lld at %lld heap %lld\n",temp->d,dist[temp->d],where[temp->d],heap[temp->d][0]);
			}

			temp=temp->next;
		}
		del();
		//show();
		p=t;
		p--;
		//for(i=1;i<100005;i++)
		//	if(dist[i]<INT_MAX)
		//		printf("i=%lld d=%lld\n",i,dist[i]);
		//	printf("pre - %lld\n",dist[v]);
	}
		if(dist[v]<INT_MAX)
			printf("%lld\n",dist[v]);
		else
			printf("NO\n");
	return 0;
}
