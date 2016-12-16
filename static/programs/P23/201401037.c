// arrival time dep time and topological sorting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct graph{
     int v;
     struct graph* next;
}gr;

gr a[100010];
#define gc getchar_unlocked
#define pc putchar_unlocked

inline void si(int *p)
{    int x =0,neg=0;
     char c=gc();
     //  if(c=='-'){ neg=-1; printf("bb") ;} 
     while((c<'0'|| c>'9') && c!='-')
          c=gc();
     if(c=='-') {neg=1; c=gc();} 
     for(;c>='0' && c<='9';c=gc())
     {
          x=x*10+c-48;
     }
     if(neg==1)         
          x=-1*x;

     *p=x;
}
inline void pi(int n)
{
    int i=0;
    char ch[20];
    if(n<0)
        if(n==0) pc('0');
        else
            pc('-'),n=n*(-1);

    while(n>0)
    {  ch[i]=n%10 +'0';
        n=n/10;
        i++;
    }

    while(i>0)
    { 
        pc(ch[i-1]);
        i--;
    }
    //pc(' ');
}
int vs[100110]={0},ts[100110],ig=0,fl=0;
int tt=0,deg[100101]={0};

void dfs(int v)
{   // printf("dfs calld\n");
     int i;  gr* temp;
    if(vs[v]==0)
         vs[v]=1; //as[v]=2;
     temp=&a[v];
     temp=temp->next;
     while(temp!=NULL)
     {
          if(vs[temp->v]==1)
               fl=1;

          if(vs[temp->v]!=1 && vs[temp->v]!=2)
          {    //  printf("%d->%d\n ",v,temp->v);
               dfs(temp->v);
          }
          temp=temp->next;
     }
     ts[ig++]=v;// printf("ts[i]=%d\n",ts[ig-1]);
     vs[v]=2;
     //dp[v]=tt++;                             
}                                         

int main (){
     gr* temp,*head,*temp3;
     int i,j,i1,n,m,u,v;
     //scanf("%d%d",&n,&m); 
 	si(&n),si(&m);
     for(i=0;i<m;i++) // creating an adjacency for a directed graph
     {     si(&u),si(&v);	
          //scanf("%d%d",&u,&v); 
          head=&a[u];
          deg[v]++;
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

          /*     temp3=(gr*)malloc(sizeof(gr));
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
                 }   */

     }

     // for(i=1;i<=n;i++)
     //  {
     //      temp=&a[i];
     //     temp=temp->next;
     //    while(temp!=NULL)
     // / /   {
     //       // printf("%d ",temp->v);
     // temp=temp->next;
     //     }
     //    printf("\n");
     // }

     //  dfs(1);
     //printf("\n");
     //for(i=1;i<=n;i++)printf("%d %d\n",ar[i],dp[i]); printf("\n");
     int fl2=0;
     for(i=n;i>=1;i--)
     {
          if(deg[i]==0 && fl2==0)
          {  if(vs[i]!=1 && vs[i]!=2)
               { 
                    dfs(i);
                    fl2=1;
               }
          }
          else if(vs[i]!=1 && vs[i]!=2)
                    dfs(i);
     }
     
     //if(fl==1)
     //     printf("Sandro fails.\n");
    // else
     //{
          for(i=ig-1;i>0;i--){
               pi(ts[i]); 
          pc(' ');
          }
          printf("%d",ts[0]);
          printf("\n");
    // }
     return 0;
}
