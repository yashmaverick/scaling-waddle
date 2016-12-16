#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct trie{
	char data;
	struct trie *child[11];
};

typedef struct trie trie;
trie *root;
void insert(char *str);
int fl;
int main(){
	char inp[15];
	int n,i,j,l,t;
	scanf("%d",&t);
	while(t--){
		root=malloc(sizeof(trie));
		root->data='\0';
		for(i=0;i<11;i++)
			(root->child[i])==NULL;
		fl=0;
		scanf("%d",&n);
		while(n--){
			scanf("%s",inp);
			if(fl==0)
			insert(inp);
		}
		if(fl==0)
			printf("YES\n");
		else
			printf("NO\n");
	} 
	return 0;
}

void insert(char *str){
	int i,l,x,j;
	trie *node,*tmp;
	tmp = root;
	l=strlen(str);
//	printf("%c\n",str[l]);
	i=0;
	while(i<=l){
		if(fl==1)
			break;
		if(str[i]!='\0')
			x=((int)str[i]-48);
		else
			x=10;
//		printf("x:%d\n",x);
		while((tmp->child[x])!=NULL){
//			printf("%c\n",str[i]);
			if(i<l)
				i++;
			else{
				fl=1;
				break;
			}
			tmp=(tmp->child[x]);
//			printf("%c\n",str[i]);
			if(str[i]!='\0')
				x=((int)str[i]-48);
			else
				x=10;
		}
		
		if(fl!=1&&(tmp->child[x])==NULL){
			if(str[i]=='\0'){
				for(j=0;j<11;j++){
					if((tmp->child[j])!=NULL){
						fl=1;
						break;
					}
				}	
			}
			else if(str[i]!='\0'){
				for(j=0;j<11;j++){
					if((tmp->child[j])!=NULL){
						if(((tmp->child[j])->data)=='\0'){
							fl=1;
							break;
						}
					}
				}	
			}
			if(fl==0){
				node = malloc(sizeof(trie));
				node->data=str[i];
				tmp->child[x] = node;
				tmp = node;
				i++;
			}
		}
		if(fl==1){
			break;
		}
	}
}


