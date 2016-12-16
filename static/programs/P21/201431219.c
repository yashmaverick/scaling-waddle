#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define large_number 18446744073709551

int completed[100001];
int todo[100001];
long long int weighted_array[100001];
int counter=0;
int rear=0;

typedef struct node {
	struct node *next;
	int val;
	long long int weight;
}node;

void insert(node *head, int data,long long int wt){
	node *temp=(node *)malloc(sizeof(node));
	temp->next=head->next;
	temp->val=data;
	temp->weight=wt;
	head->next=temp;
}

void print(node *head){
	node *root;
	root=head;
	printf("%d ",head->val);
	head=head->next;
	while(head!=NULL){
		printf("%d->%lld ",head->val, head->weight );
		head=head->next;
	}
	puts("");
	head=root;
}

void push(int a){
	if(completed[a]==0){
		// printf("Really pushed\n");
		todo[counter]=a;
		counter++;
	}
}

int pop(){
	if(rear<counter)
		return todo[rear++];
	else
		return -1;
}

void my_algo(node *head,long long int base_score){
	if(completed[head->val]==1)
		return ;
	else{
		long long int score;
		node *temp=head;
		while(head!=NULL){
			// printf("Pushing head->val as %d\n",head->val );
			push(head->val);
			score=head->weight;
			if(score+base_score < weighted_array[head->val]){
				weighted_array[head->val]=(score+base_score);
				// printf("Score changed for weighted_array[%d] as %lld\n",head->val,score+base_score);
			}
			head=head->next;
		}
		head=temp;
		// printf("Head->val for which completed is going to be unity is %d\n", head->val); 
		completed[head->val]=1;
		return ;
	}
}

int main() {
	int n,m,i,a,b;
	long long int w;
	scanf("%d%d",&n,&m );
	node *A=(node*)malloc(sizeof(node)*(n+1));
	
	for (i = 0; i <=n; i++) {
		A[i].next=NULL;
		A[i].val=i;
		A[i].weight=(long long int)large_number;
		weighted_array[i]=(long long int)large_number;
	}

	for (i = 0; i < m; i++) {
		scanf("%d%d%lld", &a, &b, &w);
		insert(A+a,b,w);
		// print(A+a);
	}
	scanf("%d%d", &a, &b);
	weighted_array[a]=0;
	A[a].weight=0;
	my_algo(A+a,weighted_array[a]);
	while(1){
		a=pop();
		// printf("a is %d\n",a);
		if(a==-1)
			break;
		my_algo(A+a,weighted_array[a]);
	}
	if(weighted_array[b]< ((long long int )large_number))
		printf("%lld\n",weighted_array[b]);
	else
		printf("NO\n");
	free(A);
	return 0;
}