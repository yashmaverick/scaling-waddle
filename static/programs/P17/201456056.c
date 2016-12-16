#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int pre[MAX], in[MAX];
int vis[MAX];

int main(){
	int N, i, t, u, v, val, l, r;
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d", &pre[i]);
	}
	for(i=0; i<N; i++){
		scanf("%d", &in[i]);
	}

	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &u, &v);
		val = -1;
		if(u==v){
			printf("%d\n", u);
			continue;
		}
		for(i=0; i<N; i++){
			vis[in[i]] = val;
			if(in[i] == u || in[i] == v){
				val += 1;
				if(val==0)
					vis[in[i]] = 0;
			}
		}
		/*
		for(i=0; i<N; i++)
			fprintf(stderr, "%d ", vis[in[i]]);
		fprintf(stderr, "\n");
		*/
		for(i=0; i<N; i++){
			if(vis[pre[i]]==0){
				printf("%d\n", pre[i]);
				break;
			}
		}
	}
	
	return 0;
}
