#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int n,pi[100000],d[100000];

void init(int preorder[],int inorder[],int l,int r,int a,int b,int parent,int level){
    //printf("\n-----(l %d)-----(r %d)-----(a %d)-----(b %d)-----\n\n",l,r,a,b);
    int head=preorder[l];
    pi[head-1]=parent;
    d[head-1]=level;    
    int x=-1,i;
    for(i=a;i<=b;i++){
        if(inorder[i]==preorder[l]){
            x=i-a;
            break;
        }
    }
    //printf("number %d found in index %d\n",head,x+a);
    if(x!=-1 && l!=r){
        if(x==0){
            //printf("going to right subtree\n");
            init(preorder,inorder,l+x+1,r,x+a+1,b,head,level+1);
        }
        else if(x==b-a){
            //printf("going to left subtree\n");
            init(preorder,inorder,l+1,l+x,a,x+a-1,head,level+1);
        }
        else{
            //printf("going to both subtrees\n");
            init(preorder,inorder,l+1,l+x,a,x+a-1,head,level+1);
            init(preorder,inorder,l+x+1,r,x+a+1,b,head,level+1);
        }
    }
    return;
}

void solve(int a,int b){
    int x=d[a-1],y=d[b-1];
    while(1){
        if(x>y){
            a=pi[a-1];
            x--;
        }
        else if(x<y){
            b=pi[b-1];
            y--;
        }
        else{
            if(a==b){
                printf("%d\n",a);
                return;
            }
            a=pi[a-1];
            b=pi[b-1];
            x--;
            y--;
        }
    }
}

int main(){
    int i,preorder[100000],inorder[100000],t,a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&preorder[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&inorder[i]);
    }
    init(preorder,inorder,0,n-1,0,n-1,0,0);
    //for(i=0;i<n;i++){
        //printf("vertex %d has parent %d is in level %d\n",i+1,pi[i],d[i]);
    //}
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        solve(a,b);
    }
    return 0;
}
