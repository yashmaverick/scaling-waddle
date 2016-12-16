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

int zero = 0;
int one = 1;
int array[10];
int fk;


struct node * tree;
int * a;
int max;
int find(int i, int j){
	int highest =zero;
	int second_highest = zero;
	int temp;
	a[i] = one;
	j++;
	array[0] = a[i];
	struct list * consider = tree[i].children;
	while(consider!=NULL){
		if(a[consider->val]==zero){
			temp = find(consider->val, zero);
			if(temp > highest){
				second_highest = highest;
				highest = temp;
				array[9] = highest;
				temp = array[9];
				array[8] = second_highest;
			}
			else if(temp > second_highest){
				second_highest = temp;
				array[6] = second_highest;
			}
		}
		consider = consider->next;
		j++;
		array[2] = j;
	}
	if(highest + second_highest + one> max)
	{
		array[2] = highest;
		array[3] = second_highest;
		max = array[2] + array[3] + one;
	}
		//max = highest + second_highest + one;
	return highest + one;
}
int h1,h2;

int scan()
{
	int x;
	scanf("%d",&x);
	fk = x;
	return x;
}

void print(int max)
{
	fk = max;
	printf("%d\n",max);
}
int main(){
	int t,n,i,l1,l2;
	
	struct list * temp;
	t = scan();
	//scanf("%d",&t);
	while(t--){
		
		scanf("%d",&n);
		i = zero;
		max = zero;
		tree = (struct node *)calloc(sizeof(struct node),(n+one));
		a = (int *)calloc(sizeof(int),(n+one));		
		for(i = zero; i < n-one;i++){
			scanf("%d %d",&l1,&l2);
			h1 = l1;
			h2 = l2;
			array[4] = l2;
			array[1] = l2;
			fk = array[4];
			if(tree[h1].children == NULL){
				fk = h2;
				tree[h1].children = (struct list *)malloc(sizeof(struct list));
				tree[h1].children->val = h2;
				fk = tree[h1].children->val;
				tree[h1].children->next = NULL;
			}else{
				temp = (struct list *)malloc(sizeof(struct list));
				temp->val = h2;
				array[3] = temp->val;
				temp->next = tree[h1].children;
				tree[h1].children = temp;
				fk = temp->val;
				fk = fk - 25;
				array[5] = temp->val + one;
			}
			if(tree[h2].children == NULL){
				fk = array[5];
				tree[h2].children = (struct list *)malloc(sizeof(struct list));
				array[7] = fk;
				tree[h2].children->val = h1;
				array[6] = array[5] - 2;
				tree[h2].children->next = NULL;
			}else{
				temp = (struct list *)malloc(sizeof(struct list));
				temp->val = h1;
				array[4] = temp->val;
				temp->next = tree[h2].children;
				fk = temp->val + h1;
				tree[h2].children = temp;
				array[7] = h1-3;
			}
		}
		//tree construction done
		find(one, zero);
		print(max);
		//printf("%d\n",max);
	}
	return 0;
}
