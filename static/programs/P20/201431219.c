#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
	struct node *next;
	int val;
}node;

int max_global;
// int count;
int final;

void insert(node *head, int data){
	node *temp=(node *)malloc(sizeof(node));
	temp->next=head->next;
	temp->val=data;
	head->next=temp;
}

void print(node *head){
	node *root;
	root=head;
	while(head!=NULL){
		printf("%d ",head->val );
		head=head->next;
	}
	puts("");
	head=root;
}

void dfs(node *root, int *ho_gaya, node *start, int count){
	count++;
	// printf("Here count incremented to %d\n",count );
	if(count >max_global){
				// printf("Max global updated as %d and value at this time was %d\n",count, root->val );
		final=root->val;
		max_global=count;
	}

	// printf("Here it is %d\n",root->val );
	// int a;
	while(root!=NULL){
		if(ho_gaya[root->val]==0){
		// final=root->next->v`al;
			
			ho_gaya[root->val]=1;
				// printf("root->val=%d and count=%d, going to do dfs\n",root->val, count );
				// scanf("%d", &a);
			dfs(start+(root->val), ho_gaya, start,count);
		}
		/*else{
			printf("Entered else condition with root->val=%d\n", root->val);
		}*/
			// if(root->next!=NULL)
			// printf("Going to make root as root->next, with root = %d and root->next = %d\n",root->val, root->next->val );
			// scanf("%d", &a);
			root=root->next;
		}
		// printf("Returning from the function dfs\n");
		return ;
	}
	int main()	{
		int test;
		scanf("%d",&test);
		while(test--) {
			max_global=0;
			final=0;
			int i,max,temp;
			int count=0;
			max=-1;
// new_1=ho_gaya;
			int a,b,n;
// printf("Enter the number of nodes\n");
			scanf("%d", &n);
			node *A=(node*)malloc(sizeof(node)*(n+1));
			int *ho_gaya=(int *)malloc(sizeof(int)*(n+1));
			int *ho_gaya2=(int *)malloc(sizeof(int)*(n+1));
			node *B=A;
			for (i = 0; i <=n; i++) {
				A[i].val=i;
				A[i].next=NULL;
				ho_gaya[i]=0;
				ho_gaya2[i]=0;
			}

			for (i = 0; i < n-1; i++) {
				B=A;
				scanf("%d%d", &a,&b);
				temp= ((a>b)*a | (b>a)*b);
				if(temp>max){
					max=temp;
				}
// printf("max is %d\n", max);
				insert(B+a,b);
				insert(B+b,a);
	 // print(B+a);
	 // print(B+b);
// printf("Original value is %d\n",A[a].val );
// printf("Original value was %d\n",A[a].val );
			}
// ho_gaya=new_1;
// printf("Max is %d\n",max);
			// printf("Adjancency list\n");
		/*	for (i = 0; i <= max; i++) {
				if(A[i].next!=NULL)
					print(A+i);
			}*/
			// printf("List ended\n");
			B=A;
// max=1;
			ho_gaya[B[max].val]=1;
			dfs(B+max,ho_gaya,B,count);
			// puts("After first dfs");
			// printf("Final->%d max was ->%d, max_global->%d\n",final,max,max_global );
	/*for (i = 0; i < max; i++) {
		ho_gaya[i]=0;
	}*/
		B=A;
		count=0;
		ho_gaya2[B[final].val]=1;
		max_global=0;
		
		dfs(B+final,ho_gaya2,B,count);
		// printf("After second dfs\n");
		// printf("Final->%d max was ->%d, max_global->%d\n",final,max,max_global );
		printf("%d\n",max_global);
		free(A);
		free(ho_gaya);
		free(ho_gaya2);
	}
	return 0;
}



/*16
15 14
14 13
13 12
12 5
5 4
5 6
4 3
3 2
2 1
6 7
8 7
9 8
10 9
10 11
9 16
*/