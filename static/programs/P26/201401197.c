#include<stdio.h>
#include<stdlib.h>

struct list{
	int val;
	struct list *next;
};

char near(int,int);
void pushin(int,int);
void bfs(int);
void enq(int);
char sieve[10004]={0};
struct list **adj,*VCC,*head,*tail;
int **dist,pcount,*nthprime,map[10004];
int main(){
	int i,j,k,l,m,t;
	VCC=(struct list *)malloc(sizeof(struct list));
	VCC->next=NULL;
	head=(struct list *)malloc(sizeof(struct list));
	head->next=NULL;
	tail=head;
	for(i=2;i<10000;i++){
		if(sieve[i]==0){
			for(j=i<<1;j<10000;j+=i){
				sieve[j]=1;
			}
		}
	}
	for(i=1000,pcount=0;i<10000;i++){
		if(sieve[i]==0){
			pcount++;
		}
	}
	nthprime=malloc(sizeof(int)*pcount);
	for(i=1000,j=0;i<10000&&j<pcount;i++){
		if(sieve[i]==0){
			map[i]=j;
			nthprime[j++]=i;
		}
	}
	dist=(int **)malloc(sizeof(int *)*pcount);
	adj=(struct list **)malloc(sizeof(struct list *)*pcount);
	for(i=0;i<pcount;i++){
		dist[i]=(int *)malloc(sizeof(int)*pcount);
		adj[i]=NULL;
		for(j=0;j<pcount;j++){
			dist[i][j]=-1;
		}
	}
	for(i=0;i<pcount;i++){
		for(j=i+1;j<pcount;j++){
			if(near(nthprime[i],nthprime[j])){
				pushin(i,j);pushin(j,i);
			}
		}
	}
	for(i=0;i<pcount;i++){
		bfs(i);
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&i,&j);
		i=map[i];j=map[j];
		if(dist[i][j]==-1){
			printf("Impossible");
		}
		else{
			printf("%d\n",dist[i][j]);
		}
	}
	return 0;
}

char near(int a,int b){
	int c,i;
	for(i=0,c=0;i<4;i++,a/=10,b/=10){
		if(a%10!=b%10){
			c++;
		}
	}
	if(c==1){
		return 1;
	}
	else{
		return 0;
	}
}

void pushin(int in,int val){
	struct list *temp;
	temp=(struct list *)malloc(sizeof(struct list));
	temp->next=adj[in];
	temp->val=val;
	adj[in]=temp;
}

void bfs(int from){
	int depth;
	struct list *todel;
	if(head->next!=NULL){
		printf("improper q\n");
		return ;
	}
	enq(from);
	tail->next=VCC;
	tail=VCC;
	tail->next=NULL;
	depth=0;
	while(12){
		if(head->next==VCC){
			if(VCC->next==NULL){
				head->next=NULL;
				tail=head;
				break;
			}
			else{
				depth++;
				tail->next=VCC;
				head->next=VCC->next;
				VCC->next=NULL;
				tail=VCC;
			}
		}
		if(dist[from][head->next->val]==-1){
			dist[from][head->next->val]=depth;
			todel=adj[head->next->val];
			while(todel!=NULL){
				enq(todel->val);
				todel=todel->next;
			}
		}
		todel=head->next;
		head->next=todel->next;
		free(todel);
	}
}

void enq(int val){
	tail->next=(struct list *)malloc(sizeof(struct list));
	tail=tail->next;
	tail->next=NULL;
	tail->val=val;
}
