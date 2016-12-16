#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define TMAX 11
#define MAX 100 
#define MAXN (((int)1e6))

int h(char c){
    if(c>='0' && c<='9')
        return c-'0';
    return TMAX-1;
}

char hinv(int c){
    if(c==TMAX-1)
        return '\0';
    return '0'+c;
}

struct trie_node_t{
    int words;
    struct trie_node_t *c[TMAX];
};

typedef struct trie_node_t trie_node;

trie_node *get_trie_node(){
    //No segfaults here.
    int i;
    trie_node *t = (trie_node*)malloc(sizeof(trie_node));
    t->words = 0;
    for(i=0; i<TMAX; i++){
        t->c[i] = NULL;
    }
    return t;
}

trie_node *root, *end_node;
trie_node *V[MAXN];
int size;

void trie_insert(char *S){
    trie_node *t = root;
    while(*S!='\0'){
        if(t->c[h(*S)] == NULL)
            t->c[h(*S)] = get_trie_node();
        t = t->c[h(*S)];
        t->words += 1;
        S++;
    }
    t->c[h(*S)] = end_node;
    assert(size<MAXN);
    V[size++] = t;
}

int check_prefixes(){
    int i;
    for(i=0; i<size; i++){
        assert(V[i]!=NULL);
        if(V[i]->words > 1)
            return 0;
    }
    return 1;
}

char S[MAX];
int top=-1;


void print(trie_node *r){
    int i;
    if(r==end_node){
        printf("%s\n", S);
        return;
    }
    for(i=0; i<TMAX; i++){
        if(r->c[i]!=NULL){
            S[++top] = hinv(i);
            print(r->c[i]);
            top--;
        }
    }
}

void destroy_trie(trie_node *t){
    int i;
    assert(t!=NULL);
    for(i=0; i<TMAX-1; i++){
        if((t->c[i])!=NULL){
            destroy_trie(t->c[i]);
            free(t->c[i]);
            t->c[i] = NULL;
        }
    }
    t->c[TMAX-1] = NULL;

}

int main(int argc, char *argv[]){
    int T, N, i;
    char x[100];
    end_node = get_trie_node();
    root = get_trie_node();
    scanf("%d", &T);
    while(T--){
        size = 0;
        scanf("%d", &N);
        assert(N<MAXN);
        for(i=0; i<N; i++){
            V[i] = NULL;
        }
        for(i=0; i<N; i++){
            scanf("%s", x);
            assert(strlen(x)<=10);
            trie_insert(x);
        }
        //fprintf(stderr, "size %d N %d\n", size, N);
        assert(size==N);
        //print(root);
        printf("%s\n", check_prefixes()?"YES":"NO");
        destroy_trie(root);
    }
    free(root);
    free(end_node);
    return 0;
}
