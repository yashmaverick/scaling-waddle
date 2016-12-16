#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct l{
    struct l * next;
    int val;
}node;
node *arr1[10005],*arr2[10005];
int visited[10005];
int n,ans,count;
node*insert(node* root,int a){
    node * temp=(node*)malloc(sizeof(node));
    temp->val=a;
    temp->next=root;
    return temp;
}
void dfs1(int a){
    node *temp= arr2[a];
    while(temp!=NULL){
        if(visited[temp->val]==0){
            count++;
            visited[temp->val]=1;
            dfs1(temp->val);
        }
        temp=temp->next;
    }
}
void dfs2(int a){
    node *temp= arr1[a];
    while(temp!=NULL){
        if(visited[temp->val]==0){
            ans++;
            visited[temp->val]=1;
            dfs2(temp->val);
        }
        temp=temp->next;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int i;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            int m,u;
            scanf("%d",&m);
            while(m--){
                scanf("%d",&u);
                arr1[i]=insert(arr1[i],u);
                arr2[u]=insert(arr2[u],i);
            }
        }
        for(i=1;i<=n;i++){
            memset(visited,0,sizeof(visited));
            count=0;
            visited[i]=1;
            dfs1(i);
            if(count==n-1)break;
        }
        if(i>n)
            printf("0\n");
        else{
            ans=1;
            memset(visited,0,sizeof(visited));
            visited[i]=1;
            dfs2(i);
            printf("%d\n",ans);
        }
        for(i=1;i<=n;i++){
            arr1[i]=NULL;
            arr2[i]=NULL;
        }
    }
    return 0;
}
