
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct mktrie {
    int count;
    struct mktrie* child[10];
};
//struct stack {
    //int a[10];
  //  int top;
//}s;
int addtotrie(struct mktrie* root, char x[]){
    struct mktrie* temp= root;
    int i=0;
    while (x[i]!='\0') {
        if (temp->child[x[i]-'0']==NULL){
            if(temp->count>0){
                return 1;
            }
            temp->child[x[i]-'0']=(struct mktrie*)malloc(sizeof(struct mktrie));
            temp->child[x[i]-'0']->count=0;
            int j;
            for (j=0; j<10; j++) {
                temp->child[x[i]-'0']->child[j]=NULL;
            }
        }
        temp=temp->child[x[i]-'0'];
        i++;
    }
    
    if(temp->count==1)return 1;
    temp->count=1;
    return 0;
}
int checktrie(struct mktrie* root, char x[]){
    struct mktrie* temp= root;
    int i=0;
    while (x[i]!='\0') {
        temp=temp->child[x[i]-'0'];
        i++;
    }
    int state=0;
    for (i=0; i<10; i++) {
        if(temp->child[i]!=NULL){
            state=1;
            break;
        }
    }
    if (state==1) {
        return 1;
    }
    return 0;
}
/*int comp(const void *a, const void *b){
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
}*/
void run(){
    int n,i;
    
    scanf("%d",&n);
    char* a[n];
    int state=0;
    for (i=0; i<n; i++) {
        a[i]=malloc(11*sizeof(char));
        scanf("%s",a[i]);
    }
    //qsort (a,n,sizeof(char*), comp);
    struct mktrie* root=(struct mktrie*)malloc(sizeof(struct mktrie));
    for (i=0; i<10; i++) {
        root->child[i]=NULL;
    }
    for (i=0; i<n; i++) {
        if (1){
            if (1==addtotrie(root,a[i])){
                state=1;
            }
        }
    }
    if (state==1){
        printf("NO\n");
    }else{ //printf("YES\n");
        for (i=0; i<n; i++) {
            if (1==checktrie(root,a[i])){
                state=1;
                break;
            }
        }
        if (state==1){
            printf("NO\n");
        }else
            printf("YES\n");
    }
}
int main() {
    int n,i;
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        run();
    }
    return 0;
}
