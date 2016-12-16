#include <stdio.h>
#include <stdlib.h>

typedef struct bag{
	int weight;
	int *weight_array;
	int len;
}bag;

int compare (const void *a, const void *b){
	return ( ((bag *)a)->weight - ((bag *)b)->weight );
}


int main(){
	int n,m,mod;
	scanf("%d%d",&n,&mod);
	bag bags[n];
	int w;
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&m);
		bags[i].weight=0;
		bags[i].weight_array = (int *)(malloc(sizeof(int)*m));
		bags[i].len = 0;
		for(j=0;j<m;j++){
			scanf("%d",&w);
			bags[i].weight = (bags[i].weight + w)%mod;
			bags[i].weight_array[j] = w;
			bags[i].len++;
		}
	}
	qsort(bags,n,sizeof(bag),compare);
	for(i=0;i<n;i++){
		printf("%d\n",bags[i].weight);
		for(j=0;j<bags[i].len;j++)
			printf("%d\n",bags[i].weight_array[j]);
		printf("\n");
	}
	return 0;
}
