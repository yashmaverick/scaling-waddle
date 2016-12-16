#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i,bingo=0,path;

typedef struct trie{
    int ha;
    struct trie *a[10];
}node;

node *init(node *p){
    if(p==NULL){
        p=(node*)malloc(sizeof(node));
    }
    int i;
    for(i=0;i<10;i++){
        p->a[i]=NULL;
    }
    p->ha=0;
    return p;
}

void insert(node *head,char str[]){
    //printf("--%d %c--\n",i,str[i]);
    if(str[i]=='\0'){
        //printf("done\n");
        return;
    }
    int digit=str[i++]-'0';
   //printf("digit=%d, head-ha=%d\n",digit,head->ha);
    if(head->ha==0 && path==1){
        //printf("----------------------------------------------->\n");
        bingo=1;
    }
    if(i==strlen(str) && head->a[digit]!=NULL){
        bingo=1;      
    }
    if(head->a[digit]==NULL){
        path=0;
        head->ha=1;
        //printf("not initialised\n");
        head->a[digit]=init(head->a[digit]);
    }
    else{
        path=1;
    }
    insert(head->a[digit],str);
}

int main(){
    node *head=NULL;
    int n,j,t;
    char str[11];
    scanf("%d",&t);
    while(t--){
        head=init(head);
        scanf("%d",&n);
        for(j=0;j<n;j++){
            i=0;
            scanf("%s",str);
            //printf("%d\n",strlen(str));
            insert(head,str);
            if(!j){
                bingo=0;
            }
        }
        if(bingo){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}


