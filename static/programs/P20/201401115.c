#include<stdio.h>
#include<stdlib.h>
typedef struct vertex{
	int val;
	struct vertex *down;
}node;

int p,top=-1,visited[1000010],stack[1000010],level[1000010];
void push(int a, int arr[]){
	top++;
	arr[top]=a;
}
void pop(int arr[]){
	top--;
}
int max,global;
node *last;
void dfs(int i,node *list[]){
	//printf("Visited %d with level %d\n",i,level[i]);
	node *tmp = list[i]->down;
	//global = i;
	pop(stack);
	while(tmp!=NULL){
		if(visited[tmp->val]!=1){
			push(tmp->val,stack);
			level[tmp->val]=level[i] + 1;
			if(level[tmp->val] > max){
				max = level[tmp->val];
				global = tmp->val;
			}
			visited[tmp->val]=1;
		}
		tmp = tmp->down;
	}
	if(top>=0)
		dfs(stack[top],list);
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		node *list[1000010];
		int n,a,b,i,j;
		scanf("%d",&n);
		top = -1;
		for(p=1;p<=n;p++){
			visited[p]=0;
			list[p] = NULL;
			//level[p] = 0;
		}
		for(i=0;i<n-1;i++){
			scanf("%d%d",&a,&b);
			node *x = (node *)malloc(sizeof(node));
			node *y = (node *)malloc(sizeof(node));
			if(list[a]==NULL){
				list[a]=(node *)malloc(sizeof(node));
			}
			if(list[b]==NULL){
				list[b]=(node *)malloc(sizeof(node));
			}
			if(list[a]->down==NULL){
				x->val=b;
				list[a]->down=x;
				list[a]->val = 1;
			}
			else{
				x->val=b;
				x->down=list[a]->down;
				list[a]->down=x;
				list[a]->val += 1;
			}
			if(list[b]->down==NULL){
				list[b]->down=y;
				y->val=a;
				list[b]->val = 1;
			}
			else{
				y->val=a;
				y->down=list[b]->down;
				list[b]->down=y;
				list[b]->val += 1;
			}
		}
		visited[1]=1;
		level[1]=0;
		push(1,stack);
		max = -1;
		dfs(1,list);

		for(p=1;p<=n;p++){
			visited[p]=0;
			//level[p]=0;
		}
		//printf("global %d\n",global);
		visited[global]=1;
		level[global]=0;
		push(global,stack);
		max = -1;
		dfs(global,list);
		printf("%d\n",max+1);
	}
	return 0;
}