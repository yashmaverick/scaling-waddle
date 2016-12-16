#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
	int w;
	struct node_t *c[10];
}node;

node *STACK[100000];
int top;

void insert(node *root, char S[]){
	int i, j, val;
	node *t = root;
	for(i=0; S[i]!='\0'; i++){
		val = S[i]-'0';
		if(t->c[val] == NULL){
			t->c[val] = malloc(sizeof(node));
			t->c[val]->w = 0;
			for(j=0; j<10; j++){
				t->c[val]->c[j] = NULL;
			}
		}
		t = t->c[val];
		t->w += 1;
	}
	top = top + 1;
	STACK[top] = t;
}


int main(){
	int T, N, i, flag;
	char S[100];
	node root_t, *root=&root_t;
	scanf("%d", &T);
	while(T--){
		root->w = 0;
		for(i=0; i<10; i++){
			root->c[i] = NULL;
		}
		scanf("%d", &N);
		flag = 1;
		top = -1;
		for(i=0; i<N; i++){
			scanf("%s", S);
			insert(root, S);
		}
		while(top!=-1){
			if(STACK[top]->w > 1){
				flag = 0;
				break;
			}
			top = top - 1;
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
