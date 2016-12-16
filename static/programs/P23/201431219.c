#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct node {
	struct node *next;
	int val;
}node;

void insert_heap(int A[],int val,int count){
	A[count]=val;
	int temp;
	while(A[count] < A[count/2] && count>1){
		temp=A[count];
		A[count]=A[count/2];
		A[count/2]=temp;
		count=count/2;
	}
}

int delete(int A[],int count){
	if(count<=1){
		if(count==1)
			return A[1];
		else
			return 922337203; 
	}
	int max=count;
	int final=A[1];
	A[1]=A[count];
	A[count]=922337203;
	count=1;
	int temp;
	while( (A[count] > A[2*count] || A[count] > A[2*count+1]) && ( (2*count+1)<max || 2*count<max) ){
		if(A[2*count] < A[2*count+1]){
			// printf("If Swapping %d and %d\n",A[count],A[2*count] );
			temp=A[count];
			A[count]=A[2*count];
			A[2*count]=temp;
			count=2*count;
		}
		else{
			// printf("Else Swapping %d and %d\n",A[count],A[2*count+1] );
			temp=A[2*count+1];
			A[2*count+1]=A[count];
			A[count]=temp;
			count=(2*count+1);	
		}
	}
	return final;
}

void insert(node *head, int data){
	node *temp = (node *)malloc(sizeof(node));
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

int traverse(node *head, int *count, int *heap, int count_heap){	//returns count_heap value
	node *root;
	root=head;
	head=head->next;
	while(head!=NULL){
		count[head->val]--;
		if(count[head->val]==0){
			insert_heap(heap,head->val, count_heap);
			count_heap++;
		}
		head=head->next;
	}
	head=root;
	return count_heap;
}

void print_count(int *a, node *A, int n){
	int i;
	for (i = 1; i <= n; i++) {
		printf("count for %d is %d\n",i,a[i] );
		print(A+i);
	}
}

int main() {
	int i,n,m,a,b,count_heap=1;
	scanf("%d%d", &n, &m);
	
	if(m==0){
		for (i = 1; i <= n-1; i++) {
			printf("%d ",i);
		}
		printf("%d\n",n);
		return 0;
	}

	int *heap=(int *)malloc(sizeof(int)*(n+1));
	node *A=(node*)malloc(sizeof(node)*(n+1));
	int *count=(int *)malloc(sizeof(int)*(n+1));

	for (i = 1; i <=n; i++) {
		A[i].next=NULL;
		A[i].val=i;
		count[i]=0;
		heap[i]=922337203;
	}

	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		insert(A+a,b);
		count[b]++;
	}

	for (i = 1; i <= n; i++) {
		if(count[i]==0){
			insert_heap(heap,i,count_heap);
			count_heap++;
		}
	}

	int storing_array[100001];
	int store_count=0;

	while(count_heap>0){
		a=delete(heap,count_heap-1);
		count_heap--;
		if(a == 922337203)
			break;
		storing_array[store_count++]=a;
		count_heap=traverse(A+a,count, heap, count_heap);
	}

	for (i = 0; i < store_count-1; i++) {
		printf("%d ",storing_array[i] );
	}
	printf("%d\n",storing_array[i] );

	free(A);
	free(heap);
	free(count);
	return 0;
}