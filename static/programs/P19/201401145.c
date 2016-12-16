#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define rep(i,n) for(i=0;i<n;i++)
void intin(int *address){
	scanf("%d",address);
}
void strin(char *pointer){
	scanf("%s",pointer);
}
void no(){
	printf("NO\n");
}
void yes(){
	printf("YES\n");
}
bool state=0;
typedef struct trie{
	int passcount;
	int endcount;
	struct trie *a[10];
}trie;
trie *head;
trie *insert(trie *head,char *in,int index,int len){
	int i=in[index]-'0';
	if(head->a[i]==NULL) {
		head->a[i]=(trie *)malloc(sizeof(trie));
		head->a[i]->endcount=head->a[i]->passcount=0;
	}
	head->a[i]->passcount++;
	if(index<len-1) head->a[i]=insert(head->a[i],in,index+1,len);
	else head->a[i]->endcount++;
	return head;
}
void dfs(trie *head){
	int i;
	rep(i,10){
		if(!state && head->a[i]!=NULL){
			if(head->a[i]->endcount>0){
				if(head->a[i]->endcount>1 || head->a[i]->passcount>head->a[i]->endcount){
					state=1;
					return ;
				}
			}
			else dfs(head->a[i]);
		}
	}
}
int main()
{
	int t,j,n,i,len;
	intin(&t);
	rep(j,t){
		state=0;
		char s[10];
		head=(trie *)malloc(sizeof(trie));
		head->passcount=head->endcount=0;
		intin(&n);
		rep(i,n){
			strin(s);
			head->passcount++;
			head=insert(head,s,0,strlen(s));
		}
		dfs(head);
		if(state)no();
		else yes();
	}
	return 0;
}
