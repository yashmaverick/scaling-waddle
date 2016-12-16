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
void dfs(int i,node *arr[]){
	if(arr[i]==NULL)
		return;
	node *tmp = arr[i]->down;
	pop(stack);
	while(tmp!=NULL){
		if(visited[tmp->val]!=1){
			push(tmp->val,stack);
			//level[tmp->val]=level[i] + 1;
			visited[tmp->val]=1;
		}
		tmp = tmp->down;
	}
	if(top>=0)
		dfs(stack[top],arr);
}
node *list[1000000];
node *list2[1000000];
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,a,b,i,j;
		scanf("%d",&n);
		top = -1;
		for(p=1;p<=n;p++){
			visited[p]=0;
			list[p] = NULL;
			list2[p] = NULL;
		}
		for(i=1;i<=n;i++){
			int m;
			scanf("%d",&m);
			for(j=0;j<m;j++){
				int a;
				scanf("%d",&a);
				node *x = (node *)malloc(sizeof(node));
				node *y = (node *)malloc(sizeof(node));
				if(list[a]==NULL){
					list[a]=(node *)malloc(sizeof(node));
				}
				if(list[a]->down==NULL){
					x->val=i;
					list[a]->down=x;
					list[a]->val = 1;
				}
				else{
					x->val=i;
					x->down=list[a]->down;
					list[a]->down=x;
					list[a]->val += 1;
				}
				if(list2[i]==NULL){
					list2[i]=(node *)malloc(sizeof(node));
				}
				if(list2[i]->down==NULL){
					y->val=a;
					list2[i]->down=y;
					list2[i]->val = 1;
				}
				else{
					y->val=a;
					y->down=list2[i]->down;
					list2[i]->down=y;
					list2[i]->val += 1;
				}
			}
		}
		int po;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				visited[j]=0;
			}
			visited[i]=1;
			top = -1;
			push(i,stack);
			dfs(i,list);
			int flag = 0;
			for(j=1;j<=n;j++){
				if(visited[j]!=1){
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				po = i;
				break;
			}
		}
		int ans=0;
		//printf("Po is %d\n",po);
		for(j=1;j<=n;j++){
			visited[j]=0;
		}
		visited[po]=1;
		top = -1;
		push(po,stack);
		dfs(po,list2);
		for(p=1;p<=n;p++){
			if(visited[p]==1){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}