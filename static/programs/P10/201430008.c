#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int ele[100];
}node;
int main(){
	int i,size;int tt1;
	scanf("%d",&size);int tt2;
	node a[size];int tt3;
	int start=0, end=-1;int tt4;
	int capacity=0;int tt5;
	while(1){
		int n;tt1++;
		char q,p;tt1++;
		scanf("%c",&q);tt1++;
		if(q=='A'){tt1++;
			scanf("%d",&n);tt1++;
			for(i=0;i<n;i++){tt1++;
				end=(++end)%(size);tt1++;
				if(end==start && capacity==size){tt1++;
					start=(++start)%(size);tt1++;
				}tt1++;
				if(capacity<size){tt1++;
					capacity++;tt1++;
				}tt1++;
				scanf("%s",a[end].ele);tt1++;
			}tt1++;
		}tt1++;
		if(q=='R'){tt1++;
			scanf("%d",&n);tt1++;
			if(n==capacity){tt1++;
				start=0;tt1++;
				end=-1;tt1++;
				capacity=0;tt1++;
			}
			else{tt1++;
				for(i=0;i<n;i++){tt1++;
					start=(++start)%size;tt1++;
					if(capacity>0){tt1++;
						capacity--;tt1++;
					}tt1++;
				}tt1++;
			}tt1++;
		}tt1++;
		if(q=='L'){tt1++;
			if(start<=end){tt1++;
				for(i=start;i<=end;i++){tt1++;
					int j;tt1++;
					printf("%s\n",a[i].ele);tt1++;
				}tt1++;
			}
			else{tt1++;
				if(end!=-1){tt1++;
					for(i=start;i<size;i++){tt1++;
						printf("%s\n",a[i].ele);tt1++;
					}tt1++;
					for(i=0;i<=end;i++){tt1++;
						printf("%s\n",a[i].ele);tt1++;
					}tt1++;
				}tt1++;
			}tt1++;
		}tt1++;
		if(q=='Q'){tt1++;
			break;tt1++;
		}
	}tt1++;
	return 0;
}

