#include<stdio.h>
#include<stdlib.h>

typedef struct linknode{
		int num;
		struct linknode *next;
}linknode;

typedef struct node{
		int visited;
		int present;
		struct linknode *adj;
}node;


node *ele;
int length=1,maxlength=0,maxlnum;

void dfs(int k){
		int i;
		ele[k].visited=1;
		linknode *temp=ele[k].adj;
		while(temp!=NULL){
				if(ele[temp->num].visited==0){
						length++;
						if(length>maxlength){
								maxlength=length;
								maxlnum=temp->num;
						}
						dfs(temp->num);
				}
				temp=temp->next;
		}
		length--;
		return;
}


int main(){
		int t,N,u,v,i;
		scanf("%d" ,&t);
		while(t--){
				scanf("%d" ,&N);
				ele=malloc((N+1)*sizeof(node));
				for(i=1;i<=N;i++){
						ele[i].visited=0;
						ele[i].adj=NULL;
				}
				length=1;
				maxlength=0;
				for(i=0;i<N-1;i++){
						scanf("%d %d" ,&u,&v);
						linknode *temp1,*temp2;
						temp1=malloc(sizeof(linknode));
						temp2=malloc(sizeof(linknode));
						temp1->num=u;
						temp2->num=v;
						temp1->next=ele[v].adj;
						temp2->next=ele[u].adj;
						ele[v].adj=temp1;
						ele[u].adj=temp2;
				}
				dfs(1);
				maxlength=length=1;
				for(i=1;i<=N;i++)
						ele[i].visited=0;
				dfs(maxlnum);
				printf("%d\n" ,maxlength);
		}
		return 0;
}
