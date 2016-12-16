#include <stdio.h>
#include <stdlib.h>
struct list{
	int val;
	struct list * next;
};
struct node{
	int t;
	struct list * children;
};
struct node * tree;
int * a;
int max;
int find(int i){
	int highest =0;
	int second_highest = 0;
	int temp;
	a[i] = 1;
	struct list * consider = tree[i].children;
	while(consider!=NULL){
		if(a[consider->val]==0){
			temp = find(consider->val);
			if(temp > highest){
				second_highest = highest;
				highest = temp;
			}
			else if(temp > second_highest){
				second_highest = temp;
			}
		}
		consider = consider->next;
	}
	if(highest + second_highest + 1> max)
		max = highest + second_highest + 1;
	return highest + 1;
}
int main(){
	int t,n,i,l1,l2;
	struct list * temp;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		i = 0;
		max = 0;
		tree = (struct node *)calloc(sizeof(struct node),(n+1));
		a = (int *)calloc(sizeof(int),(n+1));		
		for(i = 0; i < n-1;i++){
			scanf("%d %d",&l1,&l2);
			if(tree[l1].children == NULL){
				tree[l1].children = (struct list *)malloc(sizeof(struct list));
				tree[l1].children->val = l2;
				tree[l1].children->next = NULL;
			}else{
				temp = (struct list *)malloc(sizeof(struct list));
				temp->val = l2;
				temp->next = tree[l1].children;
				tree[l1].children = temp;
			}
			if(tree[l2].children == NULL){
				tree[l2].children = (struct list *)malloc(sizeof(struct list));
				tree[l2].children->val = l1;
				tree[l2].children->next = NULL;
			}else{
				temp = (struct list *)malloc(sizeof(struct list));
				temp->val = l1;
				temp->next = tree[l2].children;
				tree[l2].children = temp;
			}
		}
		//tree construction done
		find(1);
		printf("%d\n",max);
	}
	return 0;
}
