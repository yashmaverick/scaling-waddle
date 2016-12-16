#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX ((int)1e6)

struct vector_t{
    void **A;
    int size, capacity;
};
//Function Prototyps
typedef struct vector_t vector;
void vector_init(vector *v);
void vector_push_back(vector *v, void *data);
void vector_pop(vector *v);
void vector_reserve(vector *v, int size);
void *vector_data(vector *v, int i);
void vector_clear(vector *v);

//Vector Libraries
void vector_init(vector *v){
    v->capacity = 1;
    v->size = 0;
    v->A = (void**)malloc(sizeof(void*)*v->capacity);
}
void vector_push_back(vector *v, void *data){
    if(v->size>=v->capacity){
        v->capacity *= 2; 
        v->A = (void**)realloc(v->A, sizeof(void*)*v->capacity);
    }
    v->A[v->size] = data;
    v->size += 1;
}
void vector_pop(vector *v){
    assert(v->size>0);
    v->size -= 1;
    if(v->size < v->capacity/2){
        v->capacity = v->capacity/2;
        v->A = (void**)realloc(v->A, sizeof(void*)*v->capacity);
    }
    
}
void vector_reserve(vector *v, int size){
    v->capacity = size;
    v->A = (void**)realloc(v->A, sizeof(void*)*(v->capacity));
}
void* vector_data(vector *v, int i){
    assert(i>=0 && i<v->size);
    return v->A[i];
}
void vector_clear(vector *v){
    free(v->A);
}

vector adj[MAX];
int vis[MAX];

void init_vector(int N){
    int i;
    for(i=0; i<N; i++){
        vector_init(&adj[i]);
    }
}
void reset_vector(int N){
    int i;
    for(i=0; i<N; i++){
        vector_clear(&adj[i]);
    }
}
void reset_visited(int N){
    int i;
    for(i=0; i<N; i++)
        vis[i] = 0;
}

//typecasting function
void *t(int u){
    return (void*)(long)(u);
}
int tinv(void *t){
    return (int)(long)(long*)t;
}

//Running dfs to find max depth node
int mv, maxl=0;

void dfs(int v, int l){
    vis[v] = 1;
    if(l>maxl){
        maxl = l;
        mv = v;
    }
    int i, u;
    for(i=0; i<adj[v].size; i++){
        u = tinv(vector_data(&adj[v], i));
        if(!vis[u]){
            dfs(u, l+1);
        }
    }
}

int main(int argc, char *argv[]){
    int T, N, i, u, v;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        init_vector(N+1);
        for(i=0; i<N-1; i++){
            scanf("%d %d", &u, &v);
            vector_push_back(&adj[u], t(v));
            vector_push_back(&adj[v], t(u));
        }
        maxl = 0;
        mv = u;
        reset_visited(N+1);
        dfs(u, 0);
        reset_visited(N+1);
        maxl = 0;
        dfs(mv, 0);
        printf("%d\n", maxl+1);
        reset_vector(N+1);
    }
    return 0;
}
