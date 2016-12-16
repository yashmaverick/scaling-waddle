#include<stdio.h>
#include<stdlib.h>
#define inf 1000000007

typedef struct t
{
		int d;
		int w;
		struct t* next;
}t;

typedef struct h
{
		int val;
		int nod;
}h;

int v;
int flag=0;
int dist[500005];
int vs[500005];
int un[500005];
int ind[500005];
h a[500005];
int p=1;

int min(int i,int j)
{
		if( a[i].val>a[j].val )
				return j;
		return i;
}

void shuffleup(int pos)
{
		if(a[pos/2].val>a[pos].val && pos!=1)
		{
				h temp;
				temp=a[pos/2];
				a[pos/2]=a[pos];
				a[pos]=temp;

				int tmp;
				tmp=ind[a[pos/2].nod];
				ind[a[pos/2].nod]=ind[a[pos].nod];
				ind[a[pos].nod]=tmp;


				shuffleup(pos/2);
		}
}

void shuffledown(int pos)
{
		if(a[pos*2].val!=0)
		{
				int posd=pos*2;
				if(a[pos*2+1].val!=0)
						posd=min(2*pos,2*pos+1);
				if(a[posd].val<a[pos].val)
				{
						h temp;
						temp=a[pos];
						a[pos]=a[posd];
						a[posd]=temp;

						int tmp;
						tmp=ind[a[pos].nod];
						ind[a[pos].nod]=ind[a[posd].nod];
						ind[a[posd].nod]=tmp;

						shuffledown(posd);
				}
		}

}

void insert(h x)
{
		ind[x.nod]=p;
		a[p].val=x.val;
		a[p].nod=x.nod;
		shuffleup(p);
		p++;
}

void update(int x,int new)
{
		a[ind[x]].val=new;
		//printf("update  %d	%d	%d\n",ind[x],a[ind[x]].val,a[ind[x]].nod);
		shuffledown(ind[x]);
		shuffleup(ind[x]);
}

h pop()
{
		h temp=a[1];
		ind[a[p-1].nod]=1;
		ind[a[1].nod]=0;
		a[1]=a[p-1];
		a[p-1].val=0;
		a[p-1].nod=0;
		p--;
		shuffledown(1);
		return temp;
}

void dijk(t* ar[],int source)
{
		int i;
		h tmpd;
		tmpd.val=0;
		tmpd.nod=source;
		insert(tmpd);
		for(i=1;i<=v;i++)
		{
				if(i==source)
				{
						dist[i]=0;
				}
				else
				{
						dist[i]=inf;
						h tmpd;
						tmpd.val=inf;
						tmpd.nod=i;
						insert(tmpd);
				}
		}
		//for(i=1;i<=v;i++)
		//printf("intial	%d	%d\n",a[i].nod,a[i].val);
		vs[source]=1;
		h yo;
		yo = pop();
		//for(i=1;i<=v;i++)
		//printf("pop	%d	%d\n",a[i].nod,a[i].val);
		int count = 0;
		int countvs = 1;
		while(1)
		{
				if(count>=v)
				{
						flag=1;
						break;
				}
				if(countvs>=v)
						break;

				/*int j;
				for(j=1;j<=v;j++)
						if(vs[j]!=1)
						{   
								break;
						}
				if(j==v+1)
						break;*/
				t* tmp;
				tmp=ar[source]->next;
				while(tmp!=NULL)
				{
						int x;
						x=dist[source]+tmp->w;
						//		printf("x %d	%d	%d\n",x,dist[tmp->d],tmp->d);
						if( x < dist[tmp->d])
						{
								//				printf("going to update %d	%d\n",tmp->d,x);
								dist[tmp->d]=x;
								update(tmp->d,x);
								//for(i=1;i<=v;i++)
								//						printf("updated values %d	%d\n",a[i].nod,a[i].val);

						}
						tmp=tmp->next;
				}
				int min;
				/*	for(j=1;j<=v;j++)
					{
					if(dist[j]<min && vs[j]!=1)
					{
					min=dist[j];
					source=j;
					}
					}*/
				h e;
				//printf("top min %d %d\n",a[1].nod,a[1].val);
				e=pop();
				//printf("new top %d %d\n",a[1].nod,a[1].val);
				min=e.val;
				source=e.nod;
				//printf("s=%d\n",source);
				vs[source]=1;
				countvs+=1;
				count++;
		}
}



int main()
{
		int k;
		scanf("%d%d",&v,&k);
		t* ar[500005];
		int i;
		for(i=1;i<=v;i++)
		{
				ar[i]=(t*)malloc(sizeof(t));
				ar[i]->next=NULL;
		}
		while(k--)
		{
				int a,b,c;
				scanf("%d%d%d",&a,&b,&c);

				t* temp;
				temp=(t*)malloc(sizeof(t));
				temp->d=b;
				temp->w=c;
				temp->next=ar[a]->next;
				ar[a]->next=temp;

		}
		/* t* q;
		   for(i=1;i<=v;i++)
		   {
		   printf("%d: ",i);
		   q=ar[i]->next;
		   while(q!=NULL)
		   {
		   printf("%d ",q->d);
		   q=q->next;
		   }
		   printf("\n");
		   }*/

		int source,dest;
		scanf("%d%d",&source,&dest);
		/*for(i=1;i<=v;i++)
		  {
		  dist[i]=0;
		  vs[i]=0;
		  }*/

		dijk(ar,source);
		if(flag==1 || dist[dest]==inf)
				printf("NO\n");
		else
				printf("%d\n",dist[dest]);
		return 0;
}

