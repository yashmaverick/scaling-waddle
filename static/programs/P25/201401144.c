//
//  main.c
//  kruskal
//
//  Created by Mukul Hase on 10/04/15.
//  Copyright (c) 2015 Mukul Hase. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
int par[1000001];
struct edge
{
    int a,b;
    int weight;
};

int comp(const void * a, const void * b)
{
    //printf("sort %d/n",(*((struct edge **)a))->weight);
    return (*((struct edge **)a))->weight-(*((struct edge **)b))->weight;
}

int parent(int a){
    if(par[a]==a){return a;}
    par[a]=parent(par[a]);
    return par[a];
}
int main(){
    int n,i;
    scanf("%d %d",&i,&n);
    struct edge* edge[1000001];
    int count=i;
    for (i = 0; i < n; i++)
    {
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        struct edge *temp =(struct edge *) malloc(sizeof(struct edge));
        temp->a=a;
        temp->b=b;
        temp->weight=w;
        edge[i]=temp;
        /*if (par[a]!=1) {
            par[a]=1;
            count++;
        }
        if (par[b]!=1) {
            par[b]=1;
            count++;
        }*/
    }
    qsort(edge, n, sizeof(struct edge *), comp);
    int j=0;
    for (j=1; j<=count; j++) {
        par[j]=j;
    }
    int sum=0;
    i=0;
    j=0;
    while (j<count-1&&i<n) {
        if(parent(edge[i]->a)==parent(edge[i]->b))
            i++;
        else{
            sum+=edge[i]->weight;
            par[par[edge[i]->a]]=par[edge[i]->b];
            i++;
            j++;
        }
    }
    if (j<count-1) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n",sum);
    return 0;
}