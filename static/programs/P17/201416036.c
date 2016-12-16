#include <stdio.h>
#include <stdlib.h>
struct node{
	long long int a;
	long long int left;
	long long int right;
	long long int parent;
};


int main(){
	long long int n;
	scanf("%lld",&n);
	long long int * a = (long long int *)malloc(sizeof(long long int)*n);
	long long int * b = (long long int *)malloc(sizeof(long long int)*n);
	
	long long int * pos = (long long int *)malloc(sizeof(long long int)*(n+1));
	long long int i = 0;
	for(i = 0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(i = 0; i < n;i++){
		scanf("%lld",&b[i]);
		pos[b[i]] = i; 
	}
	long long int k;
	scanf("%lld",&k);
	struct node * tree = (struct node *)malloc(sizeof(struct node)*(n+1));
	for(i = 0;i <= n;i++){
		tree[i].a = i;
		tree[i].left = -1;
		tree[i].right = -1;
		tree[i].parent = -1;
	}

	tree[a[0]].parent = a[0];
	long long int check = a[0];
	long long int temp;
	for(i = 1; i < n;i++){
		check = a[0];
		while(1){
			if(pos[a[i]] < pos[check]){
				if(tree[check].left == -1){
					tree[check].left = a[i];
					break;
				}else{
					check = tree[check].left;
				}
			}
			else if(pos[a[i]] > pos[check]){
				if(tree[check].right == -1){
					tree[check].right = a[i];
					break;
				}else{
					check = tree[check].right;
				}
			}
		}
	}
	long long int ans;
	long long int p1,p2,temp1,temp2;
	for(i = 0; i < k;i++){
		scanf("%lld %lld",&p1,&p2);
		check = a[0];
		while(1){
			if((pos[p1] < pos[check]) && (pos[p2] < pos[check])){
				check = tree[check].left;
			}
			else if((pos[p1] > pos[check]) && (pos[p2] > pos[check])){
				check = tree[check].right;
			}
			else{
				ans = check;
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
