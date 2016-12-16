#include<stdio.h>
#include<stdlib.h>
typedef struct node{
        int data;
        struct node *next;
}node;
typedef struct adj{
        node *head;
}adj;

adj *arr,*arr1;
int n;

void newedge(adj *ar,int s,int d){
        node* temp=(node *)malloc(sizeof(node));
        temp->data=d;
        temp->next=ar[s].head;
        ar[s].head=temp;
        return ;
}

/*void print(adj *ar){
        int i;
        for(i=1;i<=n;i++){
                node* temp=ar[i].head;
                printf("%d--->",i);
                while(temp){
                        printf("%d ",temp->data);
                        temp=temp->next;
                }
                printf("\n");
        }
}*/

/*int isadj(adj *ar,int s,int d){
        node* temp=ar[s].head;
        while(temp){
                if(temp->data==d)
                        return 1;
                temp=temp->next;
        }
        return 0;
}*/

int count=0;
int *visit,*counted;

void tocount(adj *ar1,int counted[],int s){
        int i;
        counted[s]=1;
//        printf("%d-",s);
        node* temp=ar1[s].head;
        while(temp){
                if(counted[temp->data]==0){
                        tocount(ar1,counted,temp->data);
                        temp=temp->next;
                }
                else{
                        return ;
                }
        }
}

void dfs1(adj *ar,int visit[],int s){
        int i;
        visit[s]=1;
//                printf("%d-",s);
//        node* temp=ar[s].head;
        /*for(i=0;i<n;i++){
                if(visit[i]==0 && isadj(ar,s,i)){
                        dfs1(ar,visit,i);
                   //     temp=temp->next;
                }
        }*/
        node* temp=ar[s].head;
        while(temp){
                if(visit[temp->data]==0){
                        dfs1(ar,visit,temp->data);
                        temp=temp->next;
                }
                else{
                        return ;
                }
        }
}

void dfs(adj *ar){
        int i,state=0;
        for(i=1;i<=n;i++){
//                printf("--%d--\n",i);
                int j,flag=0;
                for(j=1;j<=n;j++){
                        visit[j]=0;
                }
                dfs1(ar,visit,i);
  //            printf("\n%d--",i);
                for(j=1;j<=n;j++){
                        //                        printf("%d ",visit[j]);
                        if(visit[j]!=1){
                                flag=1;
                                break;
                        }
                }
                //                printf("\n");
                if(!flag){
                        counted[i]=1;
                        state=1;
                        break;
                }
        }
  //      printf("--%d-%d--\n",i,counted[1]);
        if(state){
                tocount(arr1,counted,i);
//                printf("\n");
                for(i=1;i<=n;i++){
                        if(counted[i]==1){
//                                printf("%d\n",i);
                                count++;
                        }
                }
        }
        return ;
}

int main(){
        int test;
        scanf("%d",&test);
        while(test--){
                int i;
                count=0;
                scanf("%d",&n);
                arr=(adj *)malloc((n+1)*sizeof(adj));
                arr1=(adj *)malloc((n+1)*sizeof(adj));
                visit=(int *)malloc((n+1)*sizeof(int));
                counted=(int *)malloc((n+1)*sizeof(int));
                for(i=1;i<=n;i++){
                        arr[i].head=NULL;
                        arr1[i].head=NULL;
                        counted[i]=0;
                }
                for(i=1;i<=n;i++){
                        int b,j;
                        scanf("%d",&b);
                        for(j=0;j<b;j++){
                                int c;
                                scanf("%d",&c);
                                newedge(arr,c,i);
                                newedge(arr1,i,c);
                        }
                }
//               print(arr);
//               print(arr1);
                dfs(arr);
                printf("%d\n",count);
                free(arr);
                free(visit);
                free(arr1);
        }
        return 0;
}
