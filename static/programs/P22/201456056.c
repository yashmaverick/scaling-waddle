#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 1000006
#define MOD 1000000007

#define MIN_D 0
#define MAX_D 1
//Heap
typedef struct{
    int A[MAX];
    int n;
}heap;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int priority(int a, int b, int q){
    if(q)
		return (a>b);
    else
		return (a<b);
}
void heap_init(heap *h){
    h->n = 1;
}
void shuffle_up(heap *h, int n, int q){
    int i;
    for(i=n; i>1; i=(i>>1)){
	if(priority(h->A[i], h->A[i/2], q)){
	    swap(&(h->A[i]), &(h->A[i/2]));
	}
	else
	    return;
    }
}
void shuffle_down(heap *h, int i, int q){
    int p;
    while(2*i+1<= h->n){
		p = i;
		if(priority(h->A[2*i], h->A[p], q))
			p = 2*i;
		if(2*i+1< h->n && priority(h->A[2*i+1], h->A[p], q))
			p = 2*i + 1;
		if(p==i) return;
		swap(&(h->A[p]), &(h->A[i]));
		i = p;
    }

}
int heap_empty(heap *h){
    return (h->n<=1);
}
void heap_insert(heap *h, int x, int q){
    h->A[h->n] = x;
    h->n += 1;
    shuffle_up(h, (h->n)-1, q);
}
int heap_extract(heap *h, int q){
    int tmp = h->A[1];
    h->A[1] = h->A[h->n-1];
    h->n -= 1;
    shuffle_down(h, 1, q);
    return tmp;
}
int heap_prior(heap *h){
	return h->A[1];
}
int heap_size(heap *h){
	return h->n - 1;
}
void print_heap(heap *h){
    int i;
    fprintf(stderr, "Heap: ");
    for(i=1; i<h->n; i++)
	fprintf(stderr, "%d ", h->A[i]);
    fprintf(stderr, "\n");
}

int main()
{
    int t;
	unsigned long long a,b,c,n, median, i;
	int del, x;
	unsigned long long f, s;
	heap mnh_t, mxh_t, *mn_h=&mnh_t, *mx_h=&mxh_t;
    scanf("%d", &t);
    while(t--)
    {
		s = 0;
		heap_init(mx_h);
		heap_init(mn_h);
		scanf("%llu %llu %llu %llu", &a, &b, &c, &n);
		heap_insert(mx_h, 1, MAX_D);
		median = 1;
		s += 1;
		for(i=2; i<=n; i++){
			f = (a*median+b*i+c)%MOD;
			assert(f<MOD);
			s += f;
			if(f>median)
				heap_insert(mn_h, f, MIN_D);
			else
				heap_insert(mx_h, f, MAX_D);
			del = heap_size(mx_h)-heap_size(mn_h);
			if(del>1){
				x = heap_extract(mx_h, MAX_D);
				heap_insert(mn_h, x, MIN_D);
			}
			else if(del<-1){
				x = heap_extract(mn_h, MIN_D);
				heap_insert(mx_h, x, MAX_D);
			}
			del = heap_size(mx_h)-heap_size(mn_h);
			assert(del>=-1 && del<=1);
			if(del>=0)
				median = heap_prior(mx_h);
			else
				median = heap_prior(mn_h);

		}
		printf("%llu\n", s);
    }
	return 0;
}
