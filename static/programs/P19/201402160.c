#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define cout(n) printf("%c", n)
#define cin(n) scanf("%c", &n)

typedef struct trie node;

struct trie{
	char c;
	node *child[11];
};
int flag;
node* add(char a[15], node* head){
	int i = 0, j;
	node* temp = head;
	while(i<strlen(a) && temp->child[a[i]-'0'] != NULL)temp = temp->child[a[i]-'0'], i++;
	for(j=0; j<11; j++)if(temp->child[j]!=NULL){
		//printf("%d %d\n", i, j); 
		break;
	}
	if(j==11 && i==strlen(a))flag=1;
	while(i<strlen(a)){
		//cout(a[i]);
		node* n = (node*)malloc(sizeof(node));
		n->c = a[i];
		for(j=0; j<11; j++)n->child[j]=NULL;
		temp->child[a[i]-'0'] = n;
		temp = n;
		i++;
	}
	return head;
}

int check_prefix(char a[15], node* head){
	int i = 0, j;
	node* temp = head;
	while(i<strlen(a) && temp->child[a[i]-'0'] != NULL)temp = temp->child[a[i]-'0'], i++;
	for(j=0; j<11; j++)if(temp->child[j]!=NULL){
		//printf("%d %d\n", i, j); 
		return 1;
	}
	return 0; //Not prefix
}
	
void debug_show(node* temp){
	int i;
	printf("Current: %c\n", temp->c);
	for(i=0; i<11; i++)if(temp->child[i]!=NULL)debug_show(temp->child[i]);
}
char a[1000034][11];
int main(){
	int t, n;
	scanf("%d", &t);
	while(t--){
		flag=0;
		node* head = (node*)malloc(sizeof(node));
		head->c = 'a';
		int i;
		for(i=0; i<11; i++)head->child[i]=NULL;
		scanf("%d", &n);
		for(i=0; i<n; i++)scanf("%s", &a[i]), add(a[i], head);
		for(i=0; i<n; i++)if(check_prefix(a[i], head)){flag=1; break;}
		//debug_show(head);
		if(flag==1)printf("NO\n");
		else printf("YES\n");
	}
		
	
	return 0;
}
	
