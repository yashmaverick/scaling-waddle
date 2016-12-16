#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct graph{
     int v;
     struct graph* next;
}gr;


gr a[1001010];

int vs[1001100]={0};
long long int ed=0,ct=0,mx=0;

void dfs(int v)
{   int i;  gr* temp;
     vs[v]=1;
     temp=&a[v];
     temp=temp->next;
     while(temp!=NULL)
     {
          if(vs[temp->v]!=1)
          {    ct++; ///         printf("%d->%d\n ",v,temp->v);
               dfs(temp->v);
          }
          temp=temp->next;
     }

     if(ct>mx)
     {
          mx=ct;
          ed=v;
     }
     ct--;
}                   

int main (){
     gr* temp,*head,*temp3;
     int i,j,i1,n,m,u,v,q,d,e,mx2=0,test,i2;
     int x1,fl=0;
     scanf("%d",&test);
     for(i2=0;i2<test;i2++)
     {    memset(vs,0,sizeof(vs));
          memset(a,0,sizeof(a));
          mx=0; ct=0;ed=0; fl=0;
          scanf("%d",&n);
          for(i=0;i<n-1;i++) 
          {    
               scanf("%d%d",&u,&v); 
               if(fl==0)
               {
                    fl=1;
                    x1=u;
               }
               head=&a[u];

               temp3=(gr*)malloc(sizeof(gr));
               temp3->next=NULL;
               if(head->next==NULL)
               {
                    head->next=temp3;
                    head=head->next;
                    head->v=v;
               }

               else 
               {
                    temp=head->next;
                    head->next=temp3;
                    head=head->next;
                    head->v=v;
                    head->next=temp;
               }

               temp3=(gr*)malloc(sizeof(gr));
               temp3->next=NULL;

               head=&a[v];
               if(head->next==NULL)
               {
                    head->next=temp3;
                    head=head->next;
                    head->v=u;
               }

               else
               {
                    temp=head->next;
                    head->next=temp3;
                    head=head->next;
                    head->v=u;
                    head->next=temp;
               }    

          }
          dfs(x1);
         // printf("x1=%d ed=%d\n",x1,ed);
          mx=0; ct=0;
          memset(vs,0,sizeof(vs));
          dfs(ed);

          printf("%lld\n",mx+1);
     }

     return 0;
}
