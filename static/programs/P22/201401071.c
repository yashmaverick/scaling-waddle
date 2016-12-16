/*
 * Compare(i, parent(i)) returns true if in violation, else false
 * for max i>parent of i is violation
 * for min i<parent of i is violation
 *
 *
 *
 */
#include <stdio.h>
#include <assert.h>

#define MAX ((int)1e6)
#define P   ((int)1e9+7)


//Buhahaha, XOR swapping algorithm
void swap(int *x, int *y){
	(*x) = (*x)^(*y);
	(*y) = (*x)^(*y);
	(*x) = (*y)^(*x);
}
typedef struct{
    int A[MAX];
    int n;
}heap;
void heap_init(heap *h){
    h->n = 0;
}
void heap_insert(heap *h, int x, int (*compare)(const int *, const int *)){
	int i;
    h->n += 1;
    h->A[h->n] = x;
    for(i=h->n; i>1; i/=2){
        if(compare(&h->A[i], &h->A[i/2]))
            swap(&h->A[i], &h->A[i/2]);
        else
            break;
    }
}
int heap_extract(heap *h, int (*compare)(const int *a, const int *b)){
	int i=1, min=1;
	swap(&(h->A[i]), &(h->A[h->n]));
	while(2*i+1<=h->n){
		if(compare(&(h->A[2*i]), &(h->A[min])))
			min = 2*i;
		if(compare(&(h->A[2*i+1]), &(h->A[min])) && 2*i+1<(h->n))
			min = 2*i+1;
		if(i!=min)
			swap(&(h->A[i]), &(h->A[min]));
		else
			break;
		i = min;
	}
	h->n -= 1;
	return h->A[h->n+1];
}
void heap_debug(heap *h){
	int i;
	fprintf(stderr, "Heap: ");
	for(i=1; i<=h->n; i++)
		fprintf(stderr, "%d ", h->A[i]);
	fprintf(stderr, "\n");
}
int heap_top(heap *h){
	assert(h->n > 0);
	return h->A[1];
}
void heap_clear(heap *h){
	h->n =  0;
}
int cmax(const int (*a), const int (*b)){
	return (*a)>(*b);
}	
int cmin(const int (*a), const int (*b)){
	return (*a)<(*b);
}	

heap min_heap, max_heap;
int M[MAX];

int median(){
	if(max_heap.n < min_heap.n)
		return heap_top(&min_heap);
	else
		return heap_top(&max_heap);
}

int f(long long int a, long long int b, long int c, int i){
	if(i==1) return 1;
	long long x = a*median()+b*i+c;
	return x%P;
}

long long g(int a, int b, int c, int n){
	int i, tmp;
	long long sum = 1;
	heap_insert(&min_heap, 1, cmin);
	for(i=2; i<=n; i++){
		tmp = f(a, b, c, i);
		if(tmp > median()){
			heap_insert(&min_heap, tmp, cmin);
			if(min_heap.n - max_heap.n > 1){
				heap_insert(&max_heap, heap_extract(&min_heap, cmin), cmax);
			}
		}
		else{
			heap_insert(&max_heap, tmp, cmax);
			if(max_heap.n - min_heap.n > 1){
				heap_insert(&min_heap, heap_extract(&max_heap, cmax), cmin);
			}
		}

#ifdef DEBUG
		fprintf(stderr, "Max:");
		heap_debug(&max_heap);
		fprintf(stderr, "Min:");
		heap_debug(&min_heap);
		fprintf(stderr, "\n");
#endif
		sum += tmp;
	}
	return sum;
}

int main(int argc, char *argv[]){
	int n,a, b, c, T;
	scanf("%d", &T);
	while(T--){
		heap_clear(&min_heap);
		heap_clear(&max_heap);
		scanf("%d %d %d %d", &a, &b, &c, &n);
		printf("%lld\n", g(a, b, c, n));
	}
	return 0;
}
