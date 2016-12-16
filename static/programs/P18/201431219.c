#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int completed[1001];
int todo[1001];
int counter=0;
int count=0;
int global_sum=0;
typedef struct node {
	struct node *next;
	int val;
}node;

void insert(node *head, int data){
	node *temp=(node *)malloc(sizeof(node));
	temp->next=head->next;
	temp->val=data;
	head->next=temp;
}

void print(node *head){
	node *root;
	root=head;
	printf("%d ",head->val);
	head=head->next;
	while(head!=NULL){
		printf("%d ",head->val);
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
	if (counter>0) {
		// printf("Returning from pop function the value %d\n", todo[counter]);
		counter--;
		return todo[counter];
	}
	else{
		counter--;
		return -1;
	}
}

void my_algo(node *head){
	if(completed[head->val]==0){
		node *temp=head;
		completed[head->val]=1;
		// printf("Incrementing count for %d\n",head->val );
		count++;
		// printf("Incrementing global_sum for %d\n", head->val);
		global_sum++;
		while(head!=NULL){
			push(head->val);
			head=head->next;
		}
		head=temp;
		return ;
	}
	return ;
}

int main() {
	int test;
	scanf("%d", &test);
	while(test--){
		int n,i,a,l,j;
		global_sum=0;
		counter=0;
		count=0;
		scanf("%d",&n);
		for (j=0;j <=n; j++) {
			completed[j]=0;
			todo[j]=0;
		}
		
		node *A=(node*)malloc(sizeof(node)*(n+1));
		node *B=(node*)malloc(sizeof(node)*(n+1));
		
		for (i = 1; i <=n; i++) {
			A[i].next=NULL;
			A[i].val=i;
			B[i].next=NULL;
			B[i].val=i;
		}

		for(i = 1; i <= n; i++) {
			scanf("%d", &l);
			for(j = 0; j < l; j++) {
				scanf("%d", &a);
				insert(A+a,i);
				insert(B+i,a);
			}
		}

		int i_want_it=-1;

		for (i = 1; i <= n; i++) {
			counter=0;
			count=0;
			my_algo(A+i);
			while(1){
				a=pop();
				if(a<=0 || counter<0) {
					// printf("Breaking\n");
					break;
				}
				my_algo(A+a);
			}
			if(count >= n){
				i_want_it=i;
				break;	
			}
			for (j=0;j <=n; j++) {
				completed[j]=0;
				todo[j]=0;
			}
		}

		if(i_want_it==-1){
			printf("0\n");
		}

		else{

			for (j=0;j<=n; j++) {
				completed[j]=0;
				todo[j]=0;
			}

			counter=0;
			global_sum=0;
			my_algo(B+i_want_it);
			while(1){
				a=pop();
				if(a<=0 || counter <0){
					// printf("Breaking from here\n");
					break;
				}
				my_algo(B+a);
			}
			printf("%d\n",global_sum);
		}
		free(A);
		free(B);
	}
	return 0;
}