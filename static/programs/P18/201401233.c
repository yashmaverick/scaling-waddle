#include<stdio.h>
#include<stdlib.h>
typedef struct pig
{
	int value;
	struct pig *pointer;
}pig;
int marked[1000001];
int answer,l,top,nn;
pig *store[1000001];
pig *store1[1000001];
void visit()
{
int i;
for(i=1;i<=nn;i++)
marked[i]=0;
return ;
}
void create(int i,int j)
{
	pig *tmp = (pig *)malloc(sizeof(pig));
	tmp->value = j;
	if(store[i]!=NULL){
		tmp->pointer = store[i];
		store[i] = tmp;
		return ;}
		store[i] = tmp;
		return ;
}
void create1(int i,int j)
{
	pig *tmp = (pig *)malloc(sizeof(pig));
	tmp->value = j;
	if(store1[i]!=NULL){
		tmp->pointer = store1[i];
		store1[i] = tmp;
		return ;}
		store1[i] = tmp;
		return ;
}

void dfs(int i)
{
	if(store==NULL || marked[i]==1)
		return ;
	marked[i] = 1;
	pig *tmp = store[i];
	while(tmp!=NULL){
		if(marked[tmp->value]!=1){
			answer++;
			dfs(tmp->value);
		}
		tmp = tmp->pointer;
	}
}
void dfs1(int i)
{
	if(store1==NULL || marked[i]==1)
		return ;
	marked[i]=1;
	pig *tmp=store1[i];
	while(tmp!=NULL){
		if(marked[tmp->value]!=1){
			answer++;
			dfs1(tmp->value);
		}
		tmp=tmp->pointer;
	}
}

int main()
{
	int i,p,j,test,pnts,y;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&nn);
		for(i=1;i<=nn;i++){
			store[i]=NULL;
			store1[i]=NULL;
		}
		for(i=1;i<=nn;i++){
			scanf("%d",&j);
			while(j>0){
				j=j-1;
				scanf("%d",&p);
				create(p,i);
				create1(i,p);}}
		top=0;
		for(y=1;y<=nn;y++){
			visit();
			answer = 1;
			dfs(y);
			if(answer==nn){top=1;
				break;}}
		if(top!=1){
			printf("0");}
		else{
		visit();	
		answer=0;
		dfs1(y);
		printf("%d",answer+1);}
		printf("\n");}
	return 0;}
