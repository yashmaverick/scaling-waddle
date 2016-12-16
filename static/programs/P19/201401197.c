#include<stdio.h>
#include<stdlib.h>

struct node{
	char end;
	struct node *ar[10];
};

struct node *initnode();
char insert(struct node *,char *);
void clean(struct node *);
int main(){
	struct node *head;
	int t,n,i,j,k;
	char s[11],ans;
	scanf("%d",&t);
	while(t--){
		head=initnode();
		scanf("%d",&n);
		for(i=0,ans=1;i<n;i++){
			scanf("%s",s);
			if(ans&&insert(head,s)){
				ans=0;
			}
		}
		clean(head);
		if(ans){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}

struct node *initnode(){
	int i;
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->end=0;
	for(i=0;i<10;i++){
		(temp->ar)[i]=NULL;
	}
	return temp;
}

char insert(struct node *head,char *s){
	char c;
	if(*s=='\0'){
		if(head->end){
			return 1;
		}
		else{
			head->end=2;
			return 0;
		}
	}
	else{
		if(head->end==2){
			return 1;
		}
		c=s[0]-'0';
		head->end=1;
		if((head->ar)[c]==NULL){
			(head->ar)[c]=initnode();
		}
		return insert((head->ar)[c],s+1);
	}
}

void clean(struct node *head){
	if(head==NULL){
		return ;
	}
	int i;
	for(i=0;i<10;i++){
		clean((head->ar)[i]);
	}
	free(head);
}
