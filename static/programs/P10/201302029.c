#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LL int
#define SL(x) scanf("%d",&x)

typedef struct node {
	char a[105];
	struct node *next;
	char flag;
}node;

node* root=NULL;
void init(LL N){
	node *p,*q;
	LL n;
	for(n=0;n<N;++n){
		if(n==0){
			root=(node*)malloc(sizeof(node));
			root->next=NULL;
			root->flag='-';
			p=root;
		}
		else{
			q=p;
			p=p->next;
			p=(node*)malloc(sizeof(node));
			p->next=NULL;
			p->flag='-';
			q->next=p;
		}
	}
	p->next=root;
	return;
}
int main(){
	LL N;
	SL(N);
	init(N);
	LL n;
	int X;
	node* pos=root;
	while(1){
		char a[3]={'\0'};
		scanf("%s",a);
		if(a[0]=='A'){
			scanf("%d", &X);
			for(n=0;n<X;++n){
				char S[105]={'\0'};
				scanf("%s",S);
				strcpy(root->a, S);
				root->flag='+';
				root=root->next;
			}
		}
		else if(a[0]=='R'){
			scanf("%d", &X);
			for(n=0;n<X;++n){
				pos->flag='-';
				pos=pos->next;
			}
		}
		else if(a[0]=='L'){
			for(n=0;n<N;++n){
				if(pos->flag=='+'){
					printf("%s\n",pos->a);
				}
				pos=pos->next;
			}
		}
		else{
			break;
		}

	}
	return 0;
}
