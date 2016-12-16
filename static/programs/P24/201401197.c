#include<stdio.h>
#include<stdlib.h>

struct node{
	int val,h,family;
	struct node *left,*right;
};

void insert(struct node **,int);
void update(struct node **);
int geth(struct node *);
int getf(struct node *);
void fixit(struct node **);
void rotl(struct node **);
void rotr(struct node **);
void lookforpotato(struct node *,int);
void nth(struct node *,int);
int lessthan(struct node *,int);
int main(){
	int qval;
	char qs[102];
	struct node *head;
	head=NULL;
	while(1){
		scanf("%s",qs);
		switch(qs[0]){
			case 'S':
				scanf("%d",&qval);
				insert(&head,qval);
				break;
			case 'C':
				scanf("%d",&qval);
				lookforpotato(head,qval);
				break;
			case 'H':
				scanf("%d",&qval);
				nth(head,qval);
				break;
			case 'R':
				scanf("%d",&qval);
				printf("%d\n",lessthan(head,qval));
				break;
			default:
				return 0;
		}
	}
	return 0;
}

void insert(struct node **tarp,int val){
	struct node *tar;
	tar=*tarp;
	if(tar==NULL){
		*tarp=(struct node *)malloc(sizeof(struct node));
		tar=*tarp;
		tar->val=val;
		tar->left=NULL;
		tar->right=NULL;
		tar->h=0;
		tar->family=1;
		return ;
	}
	if(tar->val>val){
		insert(&(tar->left),val);
	}
	else if(tar->val<val){
		insert(&(tar->right),val);
	}
	else{
		return ;
	}
	tar->family++;
	update(tarp);
}

void update(struct node **tarp){
	struct node *tar;
	int lh,rh,lf,rf;
	tar=*tarp;
	if(tar==NULL){
		return ;
	}
	lh=geth(tar->left);rh=geth(tar->right);
	lf=getf(tar->left);rf=getf(tar->right);
	tar->family=lf+rf+1;
	if(lh<rh){
		tar->h=rh+1;
	}
	else{
		tar->h=lh+1;
	}
	lh-=rh;
	if(lh<-1||lh>1){
		fixit(tarp);
	}
}

int geth(struct node *tar){
	if(tar==NULL){
		return -1;
	}
	return tar->h;
}

int getf(struct node *tar){
	if(tar==NULL){
		return 0;
	}
	return tar->family;
}

void fixit(struct node **tarp){
	struct node *tar;
	tar=*tarp;
	if(geth(tar->left)>geth(tar->right)){
		tar=tar->left;
		if(geth(tar->left)>=geth(tar->right)){
			rotr(tarp);
		}
		else{
			rotl(&((*tarp)->left));
			rotr(tarp);
			update(&((*tarp)->left));
		}
		update(&((*tarp)->right));
		update(tarp);
	}
	else{
		tar=tar->right;
		if(geth(tar->right)>=geth(tar->left)){
			rotl(tarp);
		}
		else{
			rotr(&((*tarp)->right));
			rotl(tarp);
			update(&((*tarp)->right));
		}
		update(&((*tarp)->left));
		update(tarp);
	}
}

void rotl(struct node **tarp){
	struct node *temp;
	temp=(*tarp)->right;
	(*tarp)->right=temp->left;
	temp->left=*tarp;
	*tarp=temp;
}

void rotr(struct node **tarp){
	struct node *temp;
	temp=(*tarp)->left;
	(*tarp)->left=temp->right;
	temp->right=*tarp;
	*tarp=temp;
}

void lookforpotato(struct node *tar,int val){
	if(tar==NULL){
		printf("NO\n");
		return ;
	}
	if(tar->val>val){
		lookforpotato(tar->left,val);
	}
	else if(tar->val<val){
		lookforpotato(tar->right,val);
	}
	else{
		printf("YES\n");
	}
}

void nth(struct node *tar,int c){
	if(tar==NULL){
		printf("NONE\n");
		return ;
	}
	if(c<=getf(tar->left)){
		nth(tar->left,c);
	}
	else if(c==getf(tar->left)+1){
		printf("%d\n",tar->val);
	}
	else{
		nth(tar->right,c-getf(tar->left)-1);
	}
}

int lessthan(struct node *tar,int val){
	if(tar==NULL){
		return 0;
	}
	if(tar->val<val){
		return lessthan(tar->right,val)+getf(tar->left)+1;
	}
	else{
		return lessthan(tar->left,val);
	}
}
