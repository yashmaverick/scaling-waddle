//
//  main.c
//  p23oj
//
//  Created by Mukul Hase on 14/04/15.
//  Copyright (c) 2015 Mukul Hase. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
struct list{
    int a;
    struct list* n;
};
struct store{
    int arr[1000001];
    int curr;
}s;
int vis[1000001];
struct list* adj[1000001];
void topo(int i){
    vis[i]=1;
    struct list* temp=adj[i];
    if (temp==NULL) {
        s.arr[++s.curr]=i;
        return;
    }
    while (temp->n!=NULL) {
        if (vis[temp->a]==0) {
            topo(temp->a);
        }
        temp=temp->n;
    }
    if (vis[temp->a]==0) {
        topo(temp->a);
    }
    s.arr[++s.curr]=i;
}
int main(){
    int i,n,m;
    scanf("%d %d",&n,&m);
    struct list* temp;
    for (i = 0; i < m; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        temp=adj[a];
        if(adj[a]==NULL){
            adj[a]=(struct list*)malloc(sizeof(struct list));
            adj[a]->a=b;
            adj[a]->n=NULL;
        }else{
            while (temp->n!=NULL) {
                temp=temp->n;
            }
            temp->n=(struct list*)malloc(sizeof(struct list));
            temp=temp->n;
            temp->a=b;
            temp->n=NULL;
        }
    }
    for (i=n; i>=1; i--) {
        if (vis[i]==0) {
            topo(i);
        }
    }
    while (s.curr>1) {
        printf("%d ",s.arr[s.curr--]);
    }
    printf("%d\n",s.arr[s.curr]);
    return 0;
}