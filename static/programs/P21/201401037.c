#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define inf 10000000000000000

long long int heap[100011][2];
long long int ind[100010];
long long int hs=0;
void insert(long long int a,long long int v)
{    
     long long int i,tmp;
     hs++;
     heap[hs][1]=a;
     heap[hs][2]=v;
     i=hs;
     ind[v]=hs;
     if(hs==1)
          return;
     while(heap[i/2][1] > heap[i][1] && i>1)
     {
          ind[heap[i/2][2]]=i;
          ind[heap[i][2]]=i/2;
          tmp=heap[i/2][1];heap[i/2][1]=heap[i][1];
          heap[i][1]=tmp;
          tmp=heap[i/2][2];heap[i/2][2]=heap[i][2];
          heap[i][2]=tmp;
          i=i/2;
     }

}


void heapify(long long int in)  // suffle down
{
     long long int i=in,tmp;

     while(heap[i][1] > heap[2*i][1] || heap[i][1] > heap[2*i+1][1] && i<hs)
     {
          if(heap[2*i][1] <= heap[2*i+1][1])
          {
               ind[heap[i][2]]=2*i;
               ind[heap[2*i][2]]=i;
               tmp=heap[i][1];heap[i][1]=heap[2*i][1];
               heap[2*i][1]=tmp;
               tmp=heap[i][2];heap[i][2]=heap[2*i][2];
               heap[2*i][2]=tmp;
               i=2*i;
          }

          else
          {
               ind[heap[i][2]]=2*i+1;
               ind[heap[2*i+1][2]]=i;
               tmp=heap[i][1];heap[i][1]=heap[2*i+1][1];
               heap[2*i+1][1]=tmp;
               tmp=heap[i][2];heap[i][2]=heap[2*i+1][2];
               heap[2*i+1][2]=tmp;
               i=2*i+1;
          }
     }

}

void deletemin()
{    long long int tmp;
     if(hs==0)
          return;
     ind[heap[hs][2]]=1;
     ind[heap[1][2]]=0;
     tmp=heap[hs][1];heap[hs][1]=heap[1][1];
     heap[1][1]=tmp;
     tmp=heap[hs][2];heap[hs][2]=heap[1][2];
     heap[1][2]=tmp;

     heap[hs][1]=inf;
     heap[hs][2]=0;
     hs--;

     heapify(1);
}


long long int findmin()
{
     return heap[1][2];
}

void deckey(long long int key,long long int nw,long long int v)
{
     long long int i,tmp;
     i=ind[v];
   //  ind[key]=0;
     heap[i][1]=nw;
     if(i==1)
          return ;
     while(heap[i/2][1] > heap[i][1] && i>1)
     {
          ind[heap[i/2][2]]=i;
          ind[heap[i][2]]=i/2;
          tmp=heap[i/2][1];heap[i/2][1]=heap[i][1];
          heap[i][1]=tmp;
          tmp=heap[i/2][2];heap[i/2][2]=heap[i][2];
          heap[i][2]=tmp;
          i=i/2;
     }
}


typedef struct graph{
     long long int v;
     long long int val;
     struct graph* next;
}gr;

gr a[100010];

long long int vs[100010];
long long int dt[100010];

void dsp(long long int v,long long int n)
{  
     gr *temp1,*temp; long long int i,j=0,min,ct=2,u;
     hs=0;
     temp=&a[v]; temp=temp->next;
     while(temp!=NULL)
     {
          dt[temp->v]=temp->val;
         //pr[temp->v]=v;
          insert(temp->val,temp->v);
          temp=temp->next;

     }

     dt[v]=0; vs[v]=1;

     while(ct<=n)
     {     
          u=v;

          u=findmin();
          if(u==inf)
               break;
          deletemin();
          temp=&a[u]; vs[u]=1;
          temp=temp->next;

          while(temp!=NULL)
          {
               if(dt[temp->v] > dt[u]+temp->val && vs[temp->v]!=1)
               { 
                    if(dt[temp->v]==inf)
                         insert(dt[u]+temp->val,temp->v);

                    else
                         deckey(dt[temp->v],dt[u]+temp->val,temp->v);
                    dt[temp->v]=dt[u]+temp->val;
             //     pr[temp->v]=u;
               }
               temp=temp->next;
          }
          ct++;
     }
}


int main (){     
     gr* temp,*head,*temp3;

     long long int i,j,i1,n,m,u,v,w,test,i2,v1,v2;
    // scanf("%d",&test);
   //  for(i2=0;i2<test;i2++)
    // {
          for(i=0;i<=100010;i++)
          {
               heap[i][1]=inf;
               heap[i][2]=0;
          }
          hs=0;
          scanf("%lld%lld",&n,&m);
          for(i=0;i<=n+1;i++)dt[i]=inf;
          memset(ind,0,sizeof(ind));
          memset(vs,0,sizeof(vs));
          //memset(a,0,sizeof(a));

          for(i=0;i<m;i++) 
          {
               scanf("%lld%lld",&u,&v); scanf("%lld",&w); 
               head=&a[u];
               temp3=(gr*)malloc(sizeof(gr));
               temp3->next=NULL;
               if(head->next==NULL)
               {
                    head->next=temp3;
                    head=head->next;
                    head->v=v;
                    head->val=w;
               }

               else 
               {
                    temp=head->next;
                    head->next=temp3;
                    head=head->next;
                    head->v=v;
                    head->val=w;
                    head->next=temp;

               }

            /*  temp3=(gr*)malloc(sizeof(gr));
               temp3->next=NULL;
               head=&a[v];

               if(head->next==NULL)
               {
                    head->next=temp3;
                    head=head->next;
                    head->v=u;
                    head->val=w;
               }

               else
               {
                    temp=head->next;
                    head->next=temp3;
                    head=head->next;
                    head->v=u;
                    head->val=w;
                    head->next=temp;
               }   */

          }
          scanf("%lld%lld",&v1,&v2);
                  dsp(v1,n);
          if(dt[v2]!=inf)
          {
               printf("%lld\n",dt[v2]);
          }
          else
              printf("NO\n");

     return 0;
}
