#include <stdio.h>
#include <stdlib.h>
int maxh;
int far;
struct edge {
    int n;
    struct edge* next;
};
struct edge *a[1000001];
void dfs(int i,int h,int p){
    struct edge* temp=a[i];
    if(h>maxh){
        maxh=h;
        far=i;
    }
    if (temp==NULL) {
        return;
    }
    while (temp->next!=NULL) {
        if (temp->n!=p) {
            dfs(temp->n,h+1,i);
        }
        temp=temp->next;
     }
    if (temp->n!=p)
        dfs(temp->n,h+1,i);
}
void run(){
    int i,n;
    for (i=0; i<1000001; i++) {
        a[i]=NULL;
    }
    scanf("%d",&n);
    for (i=1; i<n; i++) {
        int X,Y;
        scanf("%d %d",&X,&Y);
        if (a[X]==NULL){
            a[X]=(struct edge*) malloc (sizeof(struct edge));
            a[X]->n=Y;
        }
        else{
            struct edge* temp=a[X];
            while (temp->next!=NULL) {
                temp=temp->next;
            }
            temp->next=(struct edge*)malloc(sizeof(struct edge));
            temp->next->n=Y;
            temp->next->next=NULL;
        }
        if (a[Y]==NULL){
            a[Y]=(struct edge*) malloc (sizeof(struct edge));
            a[Y]->n=X;
        }
        else{
            struct edge* temp=a[Y];
            while (temp->next!=NULL) {
                temp=temp->next;
            }
            temp->next=(struct edge*)malloc(sizeof(struct edge));
            temp->next->n=X;
            temp->next->next=NULL;
        }
    }
    maxh=0;
    far=1;
    dfs(1, 1, 0);
    maxh=0;
    dfs(far, 1, 0);
    printf("%d\n", maxh);
    return;
}

int main() {
    int test,i;
    scanf("%d",&test);
    for (i=0; i<test; i++) {
        run();
    }
    return 0;
}
