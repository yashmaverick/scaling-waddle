#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct trie{
	int leaf;
	struct trie * children[10];
};
int main(){
	long long int t,n;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		struct trie * dummy = (struct trie *)malloc(sizeof(struct trie)* 1);
		dummy -> leaf = 0;
		long long int num,rem,tem;
		struct trie * temp = dummy;
		int flag = 0;
		int i,j;
		char a[20];
		int len;
		for(i = 0; i < n;i++){
			scanf("%s",a);
			temp = dummy;
			len = strlen(a);
			if(flag == 0){
			for(j = 0;j < len;j++){
				rem = a[j]-'0';
				if(temp->children[rem]==NULL){
					temp->children[rem] = (struct trie *)malloc(sizeof(struct trie) * 1);
					temp->children[rem]->leaf = 0;
					temp = temp->children[rem];
					if(j == len-1){
						temp->leaf = -1;
						break;
					}
				}else{
					temp = temp->children[rem];
					if(j == len-1){
						flag = 1;
						temp->leaf = -1;
						break;
					}
					else if(temp->leaf == -1){
						flag = 1;
						break;
					}
				}
			}
			}
		}
		if(flag == 1){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	return 0;
}
