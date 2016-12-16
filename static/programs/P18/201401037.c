#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct graph{
     int v;
     struct graph* next;
}gr;

gr a[1010][12];



int vs[1010][12],ct=0,fl=0,gc=1,in=0;

#define gc1 getchar_unlocked
#define pc putchar_unlocked

inline void si(int *p)
{    int x =0,neg=0;
     char c=gc1();
     //  if(c=='-'){ neg=-1; printf("bb") ;} 
     while((c<'0'|| c>'9') && c!='-')
          c=gc1();
     if(c=='-') {neg=1; c=gc1();}
     for(;c>='0' && c<='9';c=gc1())
     {
          x=x*10+c-48;
     }
     if(neg==1)
          x=-1*x;
     *p=x;
}

void dfs(int v)
{   int i;  gr* temp;
     if(vs[v][in]!=gc)
     { vs[v][in]=gc; // printf("v=%d\n",v) ;
          ct++;
     }
     temp=&a[v][in];
     temp=temp->next;
     while(temp!=NULL)
     {
          if(vs[temp->v][in]!=gc)
          {              //  printf("%d->%d\n ",v,temp->v);
               dfs(temp->v);
          }
          temp=temp->next;
     }
}                                         

void dfs2(int v,int s)
{   int i;  gr* temp;
     if(vs[v][in]!=gc)
          vs[v][in]=gc; // printf("v=%d\n",v) ;
     temp=&a[v][in];
     temp=temp->next;
     if(fl==1)
          return;
     while(temp!=NULL)
     {
          if(vs[temp->v][in]!=gc)
          { //   ct++;
               if(temp->v==s) 
                    fl=1;

               // printf("%d->%d\n ",v,temp->v);
               if(fl==0)
                    dfs2(temp->v,s);
          }
          temp=temp->next;
     }
}

int st[10001],ed1=0;
void dfsit(int v,int s,int bit)
{       gr* temp;
     int i,ed=0,p;
     st[ed++]=v;
     ct=1;
     while(ed!=0)
     {
          p=st[ed-1]; ed--;
          vs[p][in]=gc;
          temp=&a[p][in];
          temp=temp->next;

          while(temp!=NULL)
          {
               if(vs[temp->v][in]!=gc)
               {    ct++;
                    st[ed++]=temp->v;
                    if(temp->v==s && bit==1)
                    {    fl=1;
                         ed=0; break;
                    }
                    vs[temp->v][in]=gc;
               }
               temp=temp->next;
          }

     }

}

int main (){
     gr* temp,*head,*temp3;
     int i,j,n,m,u,v,test,i1;
     // scanf("%d",&test);
     si(&test);
     for(i1=0;i1<test;i1++)
     {    in=i1;
          //  memset(a,0,sizeof(a));
          si(&n);
          //scanf("%d",&n);
          ct=0; fl=0;

          for(i=1;i<=n;i++)
          {
               // scanf("%d",&m); 
               si(&m);
               for(j=0;j<m;j++)
               {
                    // scanf("%d",&v);
                    si(&v);
                    head=&a[v][in];
                    temp3=(gr*)malloc(sizeof(gr));
                    temp3->next=NULL;
                    if(head->next==NULL)
                    {
                         head->next=temp3;
                         head=head->next;
                         head->v=i;
                    }

                    else 
                    {
                         temp=head->next;
                         head->next=temp3;
                         head=head->next;
                         head->v=i;
                         head->next=temp;
                    }


               }
          }

          /*     for(i=1;i<=n;i++)
                 {
                 temp=&a[i];
                 temp=temp->next;
                 while(temp!=NULL)
                 {
                 printf("%d ",temp->v);
                 temp=temp->next;
                 }
                 printf("\n");
                 }*/
          int ans=0,i2,fl2=0,ee=0;
          gc=1;
          for(i=1;i<=n;i++)
          {
               ct=0; //memset(vs,0,sizeof(vs));
               //  for(i2=0;i2<=n;i2++)vs[i2]=0;
               if(fl2==0) 
                    dfsit(i,ee,0);

               if(fl2==1)
               {   fl=0;
                    dfsit(i,ee,1);
                    if(fl==1)
                    {  // printf("i=%d\n",i);
                         ans++;
                    }
               }

               if(ct==n && fl2==0)
               {  fl2=1; 
                    ee=i;
                    // printf("i=%d\n",i);
                    ans++;
               }
               gc++;
          }

          printf("%d\n",ans);

          //  for(i=1;i<=n;i++)
          //{
          //   temp=&a[i];
          // temp=temp->next;
          //       while(temp!=NULL)
          //     {
          //       // printf("%d ",temp->v);
          //   /      temp=temp->next;
          ///   }
          // }

     }

     return 0;
}
