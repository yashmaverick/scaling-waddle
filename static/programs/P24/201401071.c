#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_STACK_SIZE 100
#define ML 20

#define max(a,b) ((a)>(b)?(a):(b))

struct node_t{
    void *d;
    int h, n;
    struct node_t *c[2];
};
typedef struct node_t node;

struct avl_t{
    node *root;
};
typedef struct avl_t avl;


void avl_init(avl *T){
    T->root = NULL;
}
node *newnode(){
    node *t = (node*)(malloc(sizeof(node)));
    t->c[0] = t->c[1] = NULL;
    t->h = 0;
	t->n = 1;
    return t;
}

int height(node *t){
	if(t==NULL)
		return -1;
	return t->h;
}

int n_val(node *t){
	if(t==NULL)
		return 0;
	return t->n;
}

int del(node *t){
	if(t==NULL) return 0;
	return height(t->c[0])-height(t->c[1]);
}
int balanced(node **t){
    int bf = del(*t);
    return ((bf>-2 && bf<2));
}
void rotate(node **t, int q){
    node *y = *t;
    node *x, *l, *r, *z;
    x = y->c[q];
	z = y->c[!q];
    l = x->c[q];
    r = x->c[!q];
    x->c[!q] = y;
    y->c[q] = r;
	
	//Updating n
	y->n = n_val(z)+n_val(r)+1;
	x->n = n_val(l)+n_val(y)+1;
	
	//Updating Heights
	y->h = max(height(y->c[0]), height(y->c[1]))+1;
	x->h = max(height(x->c[0]), height(x->c[1]))+1;
	
    *t = x;
	
}
void balance(node **t){
    node *y = *t;
    //left left case
    if(del(y)==2 && del(y->c[0])==1){
        rotate(t, 0);
    }
    //Right Right case
    else if(del(y)==-2 && del(y->c[1])==-1){
        rotate(t, 1);
    }
    //Right Left case
    else if(del(y)==2 && del(y->c[0])==-1){
        rotate(&(y->c[0]), 1);
        rotate(t, 0);
    
    }

    //Left Right case
    else{
        rotate(&(y->c[1]), 0);
        rotate(t, 1);
    }
    
}
void avl_insert(avl *T, void *data, int (*compare)(const void*, const void *)){
    node **S[MAX_STACK_SIZE];
	node *x;
    int top=-1;
    node **ip = &(T->root);
    while(*ip!=NULL){
		(*ip)->n += 1;
        S[++top] = ip;
        ip = &((*ip)->c[compare((*ip)->d, data)<0]);
    }

    //*ip is null, create a new node there.
    *ip = newnode();
    (*ip)->d = data;

    //Fix avl tree
    while(top!=-1){
		x = *S[top];
		x->h = max(height(x->c[0]), height(x->c[1]))+1;
        if(!balanced(S[top])){
            balance(S[top]);
        }
        top--;
    }
}
int avl_find(avl *T, void *data, int (*compare)(const void*, const void*)){
    node *ip = T->root;
    while(ip!=NULL){
        if(compare(ip->d, data)){
            ip = ip->c[compare((ip)->d, data)<0];
        }
        else{
            return 1;
        }
    }
    return 0;
}

inline void *tc(const int x){
	return (void*)(long)(x);
}
inline int tc_inv(const void *x){
	return (long)(x);
}
int compare(const void *a, const void *b){
	return (tc_inv(a)-tc_inv(b));
}

int find_x(node *t, int x){
	if(t==NULL)
		return -1;
	if(x==0){
		return tc_inv(t->d);
	}
	if(n_val(t->c[0])==x-1)
		return tc_inv(t->d);
	if(n_val(t->c[0])>=x){
		return find_x(t->c[0], x);
	}
	else{
		return find_x(t->c[1], x-n_val(t->c[0])-1);
	}
}

int find_n(node *t, int x){
	if(t==NULL)
		return 0;
	//Data is greater than e
	if(compare(t->d, tc(x))<0)
		return 1+n_val(t->c[0])+find_n(t->c[1], x);
	if(compare(t->d, tc(x))>0)
		return find_n(t->c[0], x);
	return n_val(t->c[0]);
}

avl T;

int f(char c){
	if(c=='Q') return 0;
	int x;
	scanf("%d", &x);
	switch(c){
		case 'S':
			avl_insert(&T, tc(x), compare);
			break;
		case 'C':
			printf("%s\n",avl_find(&T, tc(x), compare)?"YES":"NO");
			break;
		case 'H':
			x = find_x(T.root, x);
			if(x==-1)
				printf("NONE\n");
			else
				printf("%d\n", x);
			break; 
		case 'R':
			printf("%d\n", find_n(T.root, x));
			break;
		default:
			return 0;
	}
	return 1;
}

void print_inorder(node *t, int l){
	if(t==NULL) return;
	int i;
	for(i=0; i<l; i++)
		fprintf(stderr, " ");
	fprintf(stderr, "%d\n", tc_inv(t->d));
	print_inorder(t->c[0], l+1);
	print_inorder(t->c[1], l+1);
}
void debug_tree(avl *T){
	fprintf(stderr, "Tree:\n ");
	print_inorder(T->root, 0);
	fprintf(stderr, "\n");
}

int main(int argc, char *argv[]){
	char c[ML];
	do{
#ifdef DEBUG
		debug_tree(&T);
#endif
		scanf("%s", c);
	}while(f(c[0]));
	return 0;
}
