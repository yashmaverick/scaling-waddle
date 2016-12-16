#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
  long long int weight;
  long long int source;
  long long int val;
  struct link *next;
}link;
link *head[500100];
long long int a[500100],h[500100],pos=0,f=0,found=0;

void shuffleup(long long int crow)
{
  if(crow/2>0 && head[a[crow/2]]->source>head[a[crow]]->source)
    {
      long long int temp=a[crow];
      a[crow]=a[crow/2];
      a[crow/2]=temp;
      h[a[crow]]=crow;
      h[a[crow/2]]=crow/2;
      shuffleup(crow/2);
    }
  //  else
  //  if(a[crow/2]<a[crow])
  //    f=1;
}  

void shuffledown(long long int crow)
{
  if(f==0 && crow<=pos)
    {
      long long int t,q,p;
      if(crow*2+1<=pos)
	{
	  t=head[a[crow*2]]->source < head[a[crow*2+1]]->source?crow*2:(crow*2+1);
	}
      else
	{
	  t=crow*2;
	}
      long long int temp=a[crow];
      q=h[a[t]];
      p=h[a[crow]];
      a[crow]=a[t];
      a[t]=temp;
      h[a[t]]=t;
      h[a[crow]]=crow;
      //      printf("exchange  a[%lld]=%lld and a[%lld]=%lld\n",crow,a[crow],t,a[t]);
      shuffledown(t);
      if(f!=1 || ((crow*2+1)<=pos && (head[a[crow]]->source>head[a[crow*2]]->source || head[a[crow]]->source>head[a[crow*2+1]]->source)))
	{
	  f--;
	  a[t]=a[crow];
	  a[crow]=temp;
	  h[a[t]]=q;
	  h[a[crow]]=p;
	  //	  printf("back to  a[%lld]=%lld and a[%lld]=%lld\n",crow,a[crow],t,a[t]);
	}
    }
  else
    if(crow>pos)
      f=2;
}

void hprint()
{
  long long int i;
  for(i=1;i<=pos;i++)
    printf("a[%lld]=%lld ",h[a[i]],a[i]);
  printf("\n");
}

void delete()
{
  if(pos>0)
    {
      //      printf("F O R   %lld :\n",val);
      long long int imp=-1;
      f=0;
      imp=1;
      h[a[imp]]=-1;
      free(head[a[imp]]);
      a[imp]=a[pos];
      h[a[imp]]=imp;
      pos=pos-1;
      shuffleup(imp);
      shuffledown(imp);
    }
}

void insert(long long int val)
{
  if(h[val]==-1)
    {
      a[++pos]=val;
      h[val]=pos;
      shuffleup(pos);
    }
  else
    if(h[val]>0 && h[val]<=pos)
      {
	shuffleup(h[val]);
      }
}

void gins(long long int i)
{
  link *new=(link*)malloc(sizeof(link));
  //link *hi=(link*)malloc(sizeof(link));
  //hi->next=NULL;
  new->next=NULL;
  scanf("%lld",&(new->val));
  scanf("%lld",&(new->weight));
  //  hi->val=i;
  //  hi->weight=new->weight;
  if(head[i]==NULL)
    {
      head[i]=(link*)malloc((sizeof(link)));
      head[i]->source=1000000000000100;
      head[i]->val=i;
    }
  if(head[new->val]==NULL)
    {
      head[new->val]=(link*)malloc((sizeof(link)));
      head[new->val]->source=1000000000000100;
      head[new->val]->val=new->val;
    }
  if(head[i]->next!=NULL)
      new->next=head[i]->next;
  //  if(head[new->val]->next!=NULL)
  //    hi->next=head[new->val]->next;  
  head[i]->next=new;
  //  head[new->val]->next=hi;
  insert(i);
  insert(new->val);
}

void neigh(long long int i,long long int dest)
{
  if(head[i]!=NULL && head[i]->val==dest)
    found=1;
  //    printf("a[1]=%lld , h[a[1]]=%lld\n",a[1],h[a[1]]);
  //    printf("%lld shadowed the event, pos=%lld\n",i,pos);
  if(head[i]!=NULL && found==0 && pos>0)
    {
      link *p=head[i];
      long long int w=p->source;
      //     visit[i]=1;
      delete();
      p=p->next;
      while(p!=NULL)
	{
	  if(h[p->val]>0 && h[p->val]<=pos)
	    {
	      //	      printf("p->val=%lld\n",p->val);
	      if((p->weight+w) < (head[p->val]->source))
		{
		  head[p->val]->source=p->weight+w;
		  //		  printf("Neigh %lld source=%lld update from %lld\n",p->val,head[p->val]->source,i);
		  insert(p->val);
		}
	    }
	  p=p->next;
	}
      neigh(a[1],dest);	
    }
}

int main()
{
  long long int t,n,m,v,i,st,dt;
  found=0;pos=0;f=0;
  scanf("%lld %lld",&n,&m); 
  for(i=0;i<=n;i++)
    {
      h[i]=-1;
      head[i]=NULL;
    }
  for(i=0;i<m;i++)
    {
      scanf("%lld",&v);
      gins(v);
    }
  scanf("%lld %lld",&st,&dt);
  if(h[st]>0 && h[dt]>0 && h[st]<=pos && h[dt]<=pos)
    {
      head[st]->source=0;
      insert(st);
      neigh(st,dt);
      if(found==1 || head[dt]->source < 1000000000000100)
	{
	  if(head[dt]->source != 1000000000000100 && found==1)
	    printf("%lld\n",head[dt]->source);
	  else
	    printf("NO\n");
	}
      else
	printf("NO\n");
    }
  else
    printf("NO\n");
  return 0;
}
