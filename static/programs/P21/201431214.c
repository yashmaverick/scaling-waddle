#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    long long  int weight;
    struct node* next;
}node;
typedef struct heap{
    int src;
    long long  int we;
}heap;
heap* q[500006];
int top=0,flag=0,b;
int visited2[500006],hash[500006],visited[500006],search=0,heapvi[500006];
node* head[500006];
void insertheap(int n1,long long int n3){
    int j,te;
    heap* temp;
    heap* temp1;
    temp=(heap*)malloc(sizeof(heap));
    temp->src=n1;
    temp->we=n3;
    if(top==0){
        top++;
        q[top]=temp;
        hash[n1]=top;
    }
    else{
        top++;
        q[top]=temp;
        hash[n1]=top;
        j=top;
        while(j/2!=0 && ((q[j]->we)<(q[j/2]->we))){
            te=hash[q[j]->src];
            hash[q[j]->src]=hash[q[j/2]->src];
            hash[q[j/2]->src]=te;
            temp1=q[j];
            q[j]=q[j/2];
            q[j/2]=temp1;
            j=j/2;
        }
    }
}
void insert(int num1,int num2,int we){
    node* p;
    node* temp;
    temp=(node*)malloc(sizeof(node));
    temp->value=num2;
    temp->next=NULL;
    temp->weight=we;
    if(head[num1]==NULL)
        head[num1]=temp;
    else{
        p=head[num1];
        head[num1]=temp;
        temp->next=p;
    }
}
void deletemin(){
    int i,te;
    heap* temp;
    q[1]=q[top];
    hash[q[top]->src]=1;
    top--;
    i=1;
    while((2*i<=top && q[i]->we > q[2*i]->we ) || (2*i+1<=top && q[i]->we > q[2*i+1]->we)){
        if(q[2*i+1]->we < q[2*i]->we && 2*i+1<=top){
            te=hash[q[i]->src];
            hash[q[i]->src]=hash[q[2*i+1]->src];
            hash[q[2*i+1]->src]=te;
            temp=q[(2*i)+1];
            q[(2*i)+1]=q[i];
            q[i]=temp;
            i=(2*i)+1;
        }
        else{
            te=hash[q[i]->src];
            hash[q[i]->src]=hash[q[2*i]->src];
            hash[q[2*i]->src]=te;
            temp=q[(2*i)];
            q[(2*i)]=q[i];
            q[i]=temp;
            i=(2*i);
        }
    }
    return ;
}
void dfs(int num){
    if(num==b){
        search=1;
        return;
    }
    visited[num]=1;
    node* temp;
    temp=head[num];
    while(temp!=NULL){
        if(visited[temp->value]!=1)
            dfs(temp->value);
        temp=temp->next;
    }
}
void shuffle(int index)
{
    heap* temp;
    int te,i;
    i=index;
    if(i!=1 && q[i]->we<q[i/2]->we)
    {
        while(i!=1 && q[i]->we<q[i/2]->we)
        {
            te=hash[q[i]->src];
            hash[q[i]->src]=hash[q[i/2]->src];
            hash[q[i/2]->src]=te;
            temp=q[i];
            q[i]=q[i/2];
            q[i/2]=temp;
            i=i/2;
        }
    }
    else
    {
        while((2*i<=top && q[i]->we > q[2*i]->we ) || (2*i+1<=top && q[i]->we > q[2*i+1]->we)){
            if(q[2*i+1]->we < q[2*i]->we && 2*i+1<=top){
                te=hash[q[i]->src];
                hash[q[i]->src]=hash[q[2*i+1]->src];
                hash[q[2*i+1]->src]=te;
                temp=q[(2*i)+1];
                q[(2*i)+1]=q[i];
                q[i]=temp;
                i=(2*i)+1;
            }
            else{
                te=hash[q[i]->src];
                hash[q[i]->src]=hash[q[2*i]->src];
                hash[q[2*i]->src]=te;
                temp=q[(2*i)];
                q[(2*i)]=q[i];
                q[i]=temp;
                i=(2*i);
            }
        }
    }
}
void print(){
    int i;
    for(i=1;i<=top;i++)
        printf("we=%lld src= %d\n",q[i]->we,q[i]->src);
 //   printf("\n");
}
int main(){
    int n,m,x,y,i,a,f=0;
    long long int distance[500006],w,c;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %lld",&x,&y,&w);
        insert(x,y,w);
       // insert(y,x,w);
    }
    scanf("%d %d",&a,&b);
    dfs(a);
    if(m!=0){
        for(i=1;i<=n;i++){
            visited2[i]=0;
            heapvi[i]=0;
            if(i==a){
                distance[i]=0;
                hash[i]=0;
            }
            else{
                hash[i]=0;
                distance[i]=200000000000000001;
            }
        }
        node *temp=head[a];
        visited2[a]=1;
        while(temp!=NULL){
            if(visited2[temp->value]==0 && (temp->weight)+distance[a]<distance[temp->value])
            {
                distance[temp->value]=temp->weight+distance[a];
            }
            insertheap(temp->value,distance[temp->value]);
            heapvi[temp->value]=1;
            temp=temp->next;
        }
       // print();
        while(top!=0)
        {
            visited2[q[1]->src]=1;
            c=distance[q[1]->src];
            temp=head[q[1]->src];
            deletemin();
            while(temp!=NULL)
            {
               // printf("tv=%d\n",temp->value);
               // printf("tw=%lld d[1]=%lld d[tv]=%lld\n",temp->weight,distance[q[1]->src],distance[temp->value]);
                if(visited2[temp->value]==0 && heapvi[temp->value]==1 && (temp->weight)+c<distance[temp->value] )
                {
                   // printf("if\n");
                    distance[temp->value]=temp->weight+c;
                    q[hash[temp->value]]->we=distance[temp->value];
                    shuffle(hash[temp->value]);
                }
                else if(visited2[temp->value]==0 && heapvi[temp->value]==0 && (temp->weight)+c<distance[temp->value])
                    {
                        distance[temp->value]=temp->weight+c;
                        insertheap(temp->value,distance[temp->value]);
                        heapvi[temp->value]=1;
                    }
                temp=temp->next;
            }
        //    print();
        }
    }
    if( m==0||visited2[b]==0)
        printf("NO");
    else
        printf("%lld",distance[b]);
    printf("\n");
    return 0;
}
