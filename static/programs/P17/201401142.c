#include <stdio.h>
#include <stdlib.h>
#define SIZE 100001
#define INTS(X) scanf("%d",&X);
//GLobals and typedefs
int in[SIZE],num,pre[SIZE];
int times[2][SIZE];
typedef struct xnode{
   struct xnode *l,*r;
   int tin,tout,d;
}ANODE;
typedef ANODE* NODE;
NODE make_t(NODE head,int pst,int pend,int ist,int iend)
{
   if(pst>pend || ist>iend)
      return NULL;
   if(head==NULL)head = (NODE)malloc(sizeof(ANODE));
   head->d = pre[pst];
   int i;
   for(i=ist;i<=iend;i++)
      if(pre[pst]==in[i])
         break;
   head->l = make_t(head->l,pst+1,pst + i-ist,ist,i-1);
   head->r = make_t(head->r,pst + i - ist + 1,pend,i+1,iend);
   return head;
}
int time = 0;
void dfst(NODE w)
{
   if(w==NULL)
      return;
   w->tin = ++time;
   times[0][w->d]  = time;
   dfst(w->l);
   dfst(w->r);
   times[1][w->d] = time;
   w->tout = time;
}
int t1,t2,t1i,t1o,t2i,t2o;
int find(NODE head)
{
   if(head->l!=NULL)
   {
      int nod = head->l->d;
      if(times[0][nod]<=t1i && times[0][nod]<=t2i && times[1][nod]>=t1o && times[1][nod]>=t2o)
         return find(head->l);
   }
   if(head->r!=NULL)
   {
      int nod = head->r->d;
      if(times[0][nod]<=t1i && times[0][nod]<=t2i && times[1][nod]>=t1o && times[1][nod]>=t2o)
         return find(head->r);
   }
   return head->d;
}
int main()
{
   INTS(num);
   int i;
   for(i=0;i<num;i++)INTS(pre[i]);
   for(i=0;i<num;i++)INTS(in[i]);getchar();
   NODE root = NULL;
   root = make_t(root,0,num-1,0,num-1);
   dfst(root);
   int q;
   INTS(q);
   while(q--)
   {
      INTS(t1);INTS(t2);
      t1i = times[0][t1];
      t1o = times[1][t1];
      t2i = times[0][t2];
      t2o = times[1][t2];
      printf("%d\n",find(root)); 
   }
   return 0;
}
