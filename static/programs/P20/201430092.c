#include<stdio.h>
#include<stdlib.h>
#define s(n) scanf("%d",&n)
#define l(i,n) for(i=0;i<=n;i++)
struct node{
	int data;
	struct node* next;
};
typedef struct node node;
node *head[1000001],*end[1000001];
int visited[1000001];
int ans,found=-1;
void fun(int cu,int hei){
	visited[cu]=1;
	node* t=head[cu];
	if(hei>ans){
		ans=hei;
		found=cu;
	}
	while(t!=NULL){
		if(visited[t->data]==0){
			fun(t->data,hei+1);
		}
		t=t->next;
	}
}
int main(){
	int test,te,n,i,j,k,l,a,b,x,y;
	s(test);
	while(test--){
		ans=0;
		s(n);
		l(i,n){
			head[i]=NULL;
			end[i]=NULL;
			visited[i]=0;
		}
		l(i,n-2){
			s(x);
			s(y);
			node* t;
			t=malloc(sizeof(node));
			t->data=y;
			t->next=NULL;
			if(end[x]==NULL){
				head[x]=t;
				end[x]=t;
			}
			else{
				end[x]->next=t;
				end[x]=t;
			}
			t=NULL;
			t=malloc(sizeof(node));
			t->data=x;
			t->next=NULL;
			if(end[y]==NULL){
				head[y]=t;
				end[y]=t;
			}
			else{
				end[y]->next=t;
				end[y]=t;
			}
		}
		fun(1,1);
		ans=0;
		l(i,n){
			visited[i]=0;
		}
		fun(found,1);
		printf("%d\n",ans);
	}
	return 0;
}
