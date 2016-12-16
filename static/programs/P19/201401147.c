#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	char a;
	int end;
	struct node *alpha[10];
}node;
int flag=0;
void preorder(node *head){
	if(head==NULL)
		return ;
	printf("%c\t%d\n",head->a,head->end);
	int i=0;
	for(i=0;i<10;i++){
		preorder(head->alpha[i]);
	}//printf("\n");
	return ;
}
node * newnode(){
	node * p=malloc(sizeof(node));
	return p;
}
node * insert(node *head,char *temp,int start,int end){
	if(head==NULL){
		head=newnode();
		head->a=temp[start];
		if(start<end){
			head->alpha[temp[start+1]-'0']=insert(head->alpha[temp[start+1]-'0'],temp,start+1,end);
			head->end=0;
		}
		else
			head->end=1;
		return head;
	}
	if(start<end){
		head->alpha[temp[start+1]-'0']=insert(head->alpha[temp[start+1]-'0'],temp,start+1,end);
	}
	else
		head->end=1;
	if(head->end==1)
		flag=1;
	return head;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		flag=0;
		int N,i;
		node *head=NULL;
		head=malloc(sizeof(node));
		scanf("%d",&N);
		for(i=0;i<N;i++){
			char temp[10];
			scanf("%s",temp);
			//printf("%d\n",strlen(temp));
			head->alpha[temp[0]-'0']=insert(head->alpha[temp[0]-'0'],temp,0,strlen(temp)-1);
		}
		if(flag==0)
			printf("YES\n");
		else
			printf("NO\n");
		//preorder(head);
	}
	/*char temp1[10];
	  scanf("%s",temp1);
	  find(head->alpha[temp1[0]-'0'],temp1,0,strlen(temp1)-1);*/
	return ;
}
