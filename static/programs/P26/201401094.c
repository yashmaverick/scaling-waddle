#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 1000000000009
typedef long long int ll; 
typedef struct adj{
  int val;
  int dist;
  struct adj *next;
}node;
node* insert(node *head,int val)
{
  node *temp=malloc(sizeof(node));
  temp->val=val;
  temp->next=head;
  return temp;
}
typedef struct queue{
  int val;int dist;
}que;
que a[10004];
int vis[10004];
void prp( node *head)
{
    if(head==NULL)
        {printf("\n");    return ;}
      printf("%d ",head->val);
        prp(head->next);

}
void pr(int *hs,int n)
{
    int i;
      for(i=1;i<n;i++)
          {
            if(hs[i]!=0)
                  printf("pos:%d :%d ",i,hs[i]);
                    }
        printf("\n");
}
int bfs(int st,node **hd,int ch)
{
  int flag=0,j,i;
  for(i=0;i<10004;i++)
    vis[i]=0;
  a[1].val=st;
  a[1].dist=0;
  vis[st]=1;
  int end=1;
  int srt=1;
  node *head;  
  while(srt<=end)
  {
    head=hd[a[srt].val];
    while(head!=NULL)
    {
      if(vis[head->val]!=1)
      {
        vis[head->val]=1;
//      printf("end:%d ::  %d head->val:%d\n",end,a[srt].val,head->val);
        end++;
        a[end].val=head->val;
        a[end].dist=(a[srt].dist)+1;
      }
      if((head->val)==ch)
       {
         flag=1;
         break;
       }
      head=head->next;
    }
    if(flag==1)
      break;
    srt++;
//    printf("srt:%d\n",srt);
  //pr(vis,10004);
  }
  if(flag==1)
    return (a[end].dist);
  else
    return (-1);
}
int main()
{
  int i,a[10004],j,k,val;
  node *head[10004];
  for(i=0;i<10004;i++)
  {
    a[i]=0;
    head[i]=NULL;
  }
  a[0]=-1;
  a[1]=-1;
  for(i=2;i*i<10002;i++)
  {
    if(a[i]==0)
    {
      for(j=i;j<10000;j+=i)
        a[j]=-1;
    }
  }
  int next;
  int l=1;
  for(i=1000;i<10000;i++)
  {
    if(a[i]!=-1)
    {
  //    printf("prime:%d\n",i);
      l=1;
      for(k=0;k<4;k++)
      {
        val=((i/(l*10))*(l*10))+(i%l);
        for(j=0;j<10;j++)
        {
          next=val+j*l;
          if(a[next]!=-1 && i!=next && next >1000 && next<10000)
           {
//            printf("next:%d\n",next);
             head[i]=insert(head[i],next);
           }
        }
        l*=10;
      }
    }
  }
/*  for(i=1000;i<10000;i++)
 {
   prp(head[i]);
 }*/
  int t,st,en,ans;
  scanf("%d",&t);
  while(t--)
  {
    ans=0;
    scanf("%d %d",&st,&en);
    if(st!=en)
    ans=bfs(st,head,en);
    printf("%d\n",ans);
  }
  return 0;
}
