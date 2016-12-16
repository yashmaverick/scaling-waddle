#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct trie{
	int leaf;
	struct trie * children[10];
};

int one = 1;
int zero = 0;

long long int scan()
{
	long long int g;
	scanf("%lld",&g);
	return g;
}

int main(){
	long long int t,n;
	scanf("%lld",&t);
	while(t--){

		n = scan();
			//scanf("%lld",&n);

		struct trie * dummy = (struct trie *)malloc(sizeof(struct trie)* one);
		dummy -> leaf = zero;
		long long int num,rem,tem;
		struct trie * temp = dummy;
		int flag = zero;
		int i,j;
		char a[20];
		int len;
		for(i = zero; i < n;i++){
			scanf("%s",a);
			temp = dummy;
			len = strlen(a);
			if(flag == zero){
			for(j = zero;j < len;j++){
				rem = a[j]-'0';
				if(temp->children[rem]==NULL){
					temp->children[rem] = (struct trie *)malloc(sizeof(struct trie) * one);
					temp->children[rem]->leaf = zero;
					temp = temp->children[rem];
					if(j == len-one){
						temp->leaf = -one;
						break;
					}
				}else{
					temp = temp->children[rem];
					if(j == len-one){
						flag = one;
						temp->leaf = -one;
						break;
					}
					else if(temp->leaf == -one){
						flag = one;
						break;
					}
				}
			}
			}
		}
		if(flag == one){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	return 0;
}
