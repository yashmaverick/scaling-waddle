#include<stdio.h>
#include<stdlib.h>

#define LL int
#define SL(x) scanf("%d",&x)

struct node{
	LL Sum;
	LL N;
	LL *a;
};

typedef struct node node;
int cmp(const void* a, const void* b)
{
	return (((struct node *)a)->Sum -  ((struct node *)b)->Sum);
}

int main(){
	LL T;
	SL(T);
	LL M;
	SL(M);
	LL t;
	node In[T+2];
	for(t=0;t<T;++t){
		LL N,n;
		SL(N);
		LL Ans=0;
		In[t].N=N;
		In[t].a=malloc((N+2)*(sizeof(int)));
		for(n=0;n<N;++n){
			SL(In[t].a[n]);
			Ans+=In[t].a[n];
			Ans%=M;
		}
		In[t].Sum=Ans%M;
	}
	qsort(In, T, sizeof(node), cmp);
	for(t=0;t<T;++t){
		LL n;
		LL N=In[t].N;
		printf("%d\n", In[t].Sum);
		for(n=0;n<N;++n){
			printf("%d\n",In[t].a[n]);
		}
		printf("\n");
	}
	return 0;
}
