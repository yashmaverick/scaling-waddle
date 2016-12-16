#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct l{
    struct l *next[11];
    int pass;
}try;
try *head;
try *prev;
int flag;
void insert(char a,int check){
    if(a=='\0'){
        prev->pass=1;
        return;
    }
    if(check==1 && prev->next[a-'0']!=NULL)flag=1;
    if(prev->next[a-'0']==NULL){
        try *temp=(try*)malloc(sizeof(try));
        int i;
        for(i=0;i<=10;i++)
            temp->next[i]=NULL;
        prev->next[a-'0']=temp;
        prev=temp;
    }
    else {
        prev=prev->next[a-'0'];
        if(prev->pass==1)
            flag=1;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        head=(try*)malloc(sizeof(try));
        head->pass=0;
        int i;
        for(i=0;i<10;i++)
            head->next[i]=NULL;
        flag=0;
        for(i=0;i<n;i++){
            int i;
            char s[12];
            prev=head;
            scanf("%s",s);
            for(i=0;;i++)
            {
                if(s[i+1]=='\0')
                    insert(s[i],1);
                else
                    insert(s[i],0);
                if(s[i]=='\0')break;
            }
        }
        if(flag==1)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
