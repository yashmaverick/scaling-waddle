#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	struct node* arr[10];
	int flag;
}node;
int i,set;
node* insert(char s[],int size,node* head){
	if(set==1)
		return head;
	i++;
	int k;
	if(head->arr[s[i]-'0']==NULL){
		node* temp;
		temp=malloc(sizeof(node));
		for(k=0;k<size;k++)
			temp->arr[k]=NULL;
		head->arr[s[i]-'0']=temp;
		if(i==size-1){
			temp->flag=1;
			return head;
		}
		else{
			temp->flag=0;
			head=head->arr[s[i]-'0'];
			insert(s,size,head);
		}
	}
	else{
		if(i==size-1){
			set=1;
			return head;
		}
		else{
			head=head->arr[s[i]-'0'];
			if(head->flag==1){
				set=1;
				return head;
			}
			insert(s,size,head);
		}
	}
	return head;
}
int main(){
	int test,z;
	scanf("%d",&test);
	for(z=0;z<test;z++){
		int total,b;
		scanf("%d",&total);
		node* head=NULL;
		head=(node*)malloc(sizeof(node));
		/*for(b=0;b<10;b++)
		  {
		  head->s[b]=NULL;
		  }*/
		node* add;
		add=head;
		//int set;
		set=0;
		for(b=0;b<total;b++){
			char s[10];
			scanf("%s",s);
			int size;
			size=strlen(s);
			i=-1;
			insert(s,size,head);
			head=add;
			/*if(set==0){
				continue;
			}
			else{
				break;
			}*/
		}
		if(set==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
