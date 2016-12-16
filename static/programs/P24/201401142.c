#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *l,*r;
	int h;
   int unme;
};
typedef struct node N;
typedef N* NODE;
NODE root=NULL;
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int absi(int a)
{
	return a>0?a:(-1*a);
}
int chkbal(NODE w)
{
      if(w==NULL)
         printf("Erro\n");
		int h1,h2;
		if(w->r==NULL)h1 = 0;
		else
			h1 = w->r->h;
		if(w->l==NULL)h2 = 0;
		else
			h2 = w->l->h;
		return h1 - h2;
}
void inord(NODE head)
{
	if(head==NULL)
		return;
	inord(head->l);
	printf("N %d H %d U %d\n",head->data,head->h,head->unme);
	inord(head->r);
	return;
}
int underme(NODE x)
{
   if(x!=NULL)
      return x->unme;
   else
      return 0;
}
NODE avlbalance(NODE x)
{
	if(chkbal(x)==2) //Right Unbalanced.
	{
		if(chkbal(x->r)==1)
		{
			NODE y = x->r;
			NODE t2 = y->l;
			x->r = t2;
			y->l = x;
			x->h -= 2;
         //Height Updatations
         x->unme = underme(x-> l) + underme(x->r) + 1;
         y->unme = underme(y-> l) + underme(y->r) + 1;
			return y;
		}
		else if(chkbal(x->r)==-1)
		{
			NODE y = x->r;
			NODE z = y->l;
			NODE t2 = z->l;
			NODE t3 = z->r;
			x->r = t2;
			z->l = x;
         z->r = y;
			y->l = t3;
         z->h += 1;
         x->h -= 2;
         y->h -= 1;
         x->unme = underme(x-> l) + underme(x->r) + 1;
         y->unme = underme(y-> l) + underme(y->r) + 1;
         z->unme = underme(z-> l) + underme(z->r) + 1;
			return z;
		}
		else
			printf("Error\n");
	}
	else if(chkbal(x)==-2)
	{
		if(chkbal(x->l)==-1)
		{
			NODE y = x->l;
			NODE t3 = y->r;
			x->l = t3;
			y->r = x;
			x->h -= 2;
         x->unme = underme(x-> l) + underme(x->r) + 1;
         y->unme = underme(y-> l) + underme(y->r) + 1;
			return y;
		}
		else if(chkbal(x->l)==1)
		{	
			NODE y = x->l;
			NODE z = y->r;
			NODE t2 = z->l;
			NODE t3 = z->r;
			y->r = t2;
			x->l = t3;
			z->l = y;
			z->r = x;
         z->h += 1;
         y->h -= 1;
         x->h -= 2;
         x->unme = underme(x-> l) + underme(x->r) + 1;
         y->unme = underme(y-> l) + underme(y->r) + 1;
         z->unme = underme(z-> l) + underme(z->r) + 1;
			return z;
		}
		else
			printf("L? Error\n");
	}
	else
		printf("Error.....\n");	
   return NULL;
}
NODE insert(NODE w,int data)
{
	if(w==NULL)
	{
		w = (NODE)malloc(sizeof(N));
		w -> data = data;
		w -> l = NULL;
		w -> r = NULL;
		w -> h = 1;
      w -> unme = 1;
	}
	else if(data > (w -> data))
	{
		w->r = insert(w->r,data);
      w->unme += 1;
	}
	else
	{
		w->l = insert(w->l,data);
      w->unme += 1;
	}
	//Find height.
		int h1,h2; //h1 is r, h2 is l;
		if(w->r==NULL)h1 = 0;
		else
			h1 = w->r->h;
		if(w->l==NULL)h2 = 0;
		else
			h2 = w->l->h;
		w -> h = max(h1,h2) + 1;
	//Height End. => Height will be set for this node after this step.
	if(absi(chkbal(w))>1)
	    w = avlbalance(w);
	return w;
}
int search(NODE where,int what)
{
   if(where==NULL)
      return 0;
   else
   {
      if(where->data==what)
         return 1;
      else if( (where->data) >what)
         return search(where->l,what);
      else
         return search(where->r,what);
   }
}
int numbefore(NODE head,int x)
{
   if(head==NULL)
      return 0;
   if(x>head->data)
   {
      if(head->r!=NULL)
         return head->unme - head->r->unme + numbefore(head->r,x);
      else
         return head->unme;
   }
   else if(x==head->data)
      return underme(head->l);
   else 
      return numbefore(head->l,x);
}
int healthy(NODE head,int x)
{
   if(head==NULL)
      return -1;
   int unhl = underme(head->l);
   if(unhl==x-1)
      return head->data;
   else if((x-1)<unhl)
      return healthy(head->l,x);
   else
      return healthy(head->r,x-(unhl+1));
}
int main()
{
	int temp;
   char com[40];
   scanf("%s",com);
	while(com[0]!='Q')
	{
		scanf("%d",&temp);
      if(com[0]=='S')
		   root = insert(root,temp);
      else if(com[0]=='C')
      {
         if(search(root,temp)==1)
            printf("YES\n");
         else
            printf("NO\n");
      }
      else if(com[0]=='H')
      {
         int ans = healthy(root,temp);
         if(ans==-1)
            printf("NONE\n");
         else
            printf("%d\n",ans);
      }
      else if(com[0]=='R')
      {
         printf("%d\n",numbefore(root,temp));
      }
      else
      {
         printf("The tree is\n");
         inord(root);
      }
      scanf("%s",com);
	}
	return 0;
}
