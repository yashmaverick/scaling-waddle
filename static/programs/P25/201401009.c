#include<stdio.h>
#include<stdlib.h>

typedef struct edge{
        int s;
        int d;
        int w;
}edge;

edge* arr;
int *parent,*r,n,m,count=0;

int fipar(int *parent,int e){
        if(parent[e]!=e){
                parent[e]=fipar(parent,parent[e]);
        }
        return parent[e];
}

void dsu(int *parent,int *r,int a,int b){
        int apar=fipar(parent,a),bpar=fipar(parent,b);
        if(r[apar]<r[bpar])
                parent[apar]=bpar;
        else if(r[apar]>r[bpar])
                parent[bpar]=apar;
        else{
                parent[bpar]=apar;
                r[apar]++;
        }
}

int cmpfunc(const void* i,const void* j){
        edge* a=(edge*)i;
        edge* b=(edge*)j;
        return (a->w > b->w);
}

void krus(){
        long long int sum=0;
        int i,e=0;
        qsort(arr,m,sizeof(edge),cmpfunc);
        /*for(i=0;i<m;i++){
                printf("%d %d %d\n",arr[i].s,arr[i].d,arr[i].w);
        }*/
        parent=(int *)malloc((n+1)*sizeof(int));
        r=(int *)malloc((n+1)*sizeof(int));
        for(i=0;i<=n;i++){
                parent[i]=i;
                r[i]=0;
        }
        while(count<n-1){
                edge newedge=arr[e++];
                if(newedge.s>n || newedge.d>n){
                        printf("-1\n");
                        return ;
                }

                int q=fipar(parent,newedge.s),w=fipar(parent,newedge.d);
//                printf("--%d %d-- ",q,w);
                if(q!=w){
                        sum=sum+newedge.w;
//                        printf("%d %d\n",newedge.s,newedge.d);
                        count++;
                        dsu(parent,r,q,w);
                }
        }
  //      for(i=0;i<n;i++){
    //            printf("%d  ",parent[i]);
      //  }
      //  printf("\n");
      //  printf("%d\n",count);
        if(count==n-1)
                printf("%lld\n",sum);
        else
                printf("-1\n");
}

int main(){
        int i;
        scanf("%d %d",&n,&m);
        arr=(edge *)malloc(m*sizeof(edge));
        for(i=0;i<m;i++){
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                arr[i].s=a;
                arr[i].d=b;
                arr[i].w=c;
        }
        /*for(i=0;i<m;i++){
                printf("%d %d %d\n",arr[i].s,arr[i].d,arr[i].w);
        }*/
        krus();
/*        for(i=0;i<n;i++){
                printf("%d %d\n",parent[i],r[i]);
        }*/
//        free(arr);
//        free(parent);
//        free(r);
        return 0;
}

