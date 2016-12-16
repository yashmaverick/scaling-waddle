#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
  int val;
  struct link *next;
}link;
link *head[500100];
int h[500100]={0};
int a[500100],st[500100],pos=0,f=0,top=-1;

void hprint()
{
  if(pos>0)
    {
      int i;
      for(i=1;i<=pos;i++)
	printf("%d ",a[i]);
      printf("\n");
    }
}

void shuffleup(int crow)
{
  if(crow/2>0&&a[crow/2]>a[crow])
    {
      int temp=a[crow];
      a[crow]=a[crow/2];
      a[crow/2]=temp;
      shuffleup(crow/2);
    }
  //  else
  //  if(a[crow/2]<a[crow])
  //    f=1;
}  

void shuffledown(int crow)
{
  if(f==0 && crow<=pos)
    {
       int t;
      if(crow*2+1<=pos)
	{
	  t=a[crow*2]<a[crow*2+1]?crow*2:(crow*2+1);
	}
      else
	{
	  t=crow*2;
	}
      if(t<=pos && a[t]<a[crow])
	{
	  int temp=a[crow];
	  a[crow]=a[t];
	  a[t]=temp;
	  //      printf("exchange( %c )  a[%d]=%d and a[%d]=%d\n",c,crow,a[crow],t,a[t]);
	  shuffledown(t);
	}
      else
	if(t<=pos)
	  f=1;
    }
}

void sprint()
{
  int i;
  for(i=0;i<=top;i++)
    {
      if(i<top)
	printf("%d ",st[i]);
      else
	printf("%d",st[i]);
    }
}

void delete()
{
  if(pos>0)
    {
      //      printf("F O R   %d :\n",val);
      int imp=1;
      f=0;
      //      free(head[a[imp]]);
      st[++top]=a[imp];
      h[a[imp]]=-1;
      a[imp]=a[pos];
      pos=pos-1;
      shuffledown(imp);
    }
  if(pos==2 && a[2]<a[1])
    {
      int temp=a[1];
      a[1]=a[2];
      a[2]=temp;
    }
}

void insert(int val)
{
  a[++pos]=val;
  shuffleup(pos);
}

void gins(int i)
{
  link *new=(link*)malloc(sizeof(link));
  new->next=NULL;
  scanf("%d",&(new->val));
  h[new->val]+=1;
  if(head[i]==NULL)
    {
      head[i]=(link*)malloc((sizeof(link)));
      head[i]->val=i;
    }
  if(head[new->val]==NULL)
    {
      head[new->val]=(link*)malloc((sizeof(link)));
      head[new->val]->val=new->val;
    }
  if(head[i]->next!=NULL)
      new->next=head[i]->next;
  head[i]->next=new;
}

void saber()
{
  if(pos>0 && head[a[1]]==NULL)
    {
      delete();
      saber();
    }
  else
    if(pos>0 && head[a[1]]!=NULL)
      {
	link *p=head[a[1]];
	delete();
	p=p->next;
	while(p!=NULL)
	  {
	    h[p->val]-=1;
	    if(h[p->val]==0)
	      insert(p->val);
	    p=p->next;
	  }
	saber();
      }
}

int main()
{
  int n,m,k,i;
  scanf("%d %d",&n,&m);
  for(k=1;k<=n;k++)
    head[k]=NULL;
  for(k=0;k<m;k++)
    {
      scanf("%d",&i);
      gins(i);
    }
  for(k=1;k<=n;k++)
    if(h[k]==0)
      {
	insert(k);
      }
  saber();
  if(top>-1)
    sprint();
  printf("\n");
  return 0;
}
