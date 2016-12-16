#include<stdio.h>
#include<stdlib.h>
typedef struct node
{   struct node* next;
    int vertex;
    int weight;
}node;
node* N[100001];
struct type_edge
{
    int vertex;
    int wt; 
};
typedef struct type_edge edge;
void insert(int u , int v,int w); 
void adj_list(int no_nodes,int no_edges);
int visited[100001];
void shift_up_min(edge *h , int i,int dis);
int  delete_min(edge *h);
int child(edge *h , int i ,int flag);
void insert_min(edge* h ,int data,int , int);
void heapify_min(edge *h , int i);
int max=1000000005;
int t,s,n,count=0;
long long int m;
int position[100001];
int main()
{
    int i;
    scanf("%d %lld",&n,&m);
    adj_list(n,m); 
    scanf("%d%d",&t,&s);
    if(m==0 && t!=s)
	printf("NO\n");
    else if(t==s)
	printf("0\n");
    else
    {
	edge *e;
	e=(edge*)malloc(sizeof(edge)*(n+1));
	for(i=0 ; i<n ; i++)
	{
	    e[i].vertex=i;
	    e[i].wt=max;
	   count++;
	}
    	t=t-1;
	e[t].wt=0;
	shift_up_min(e,t,0);
	visited[t]=1;
	int w;
	while(count!=0)
	{
	    int u= e[0].vertex;
	    int q=e[position[u]].wt;
//    	    printf("q is %d=%d\n",u,q);
	     w=delete_min(e);
//	  printf("w is %d\n",w);
	    visited[u]=1;
	    node *p;
	    p=N[u];
	    
	    if(s-1==u)
		break;
	    while(p!=NULL)
	    {
		int te=position[p->vertex];
		int y=w;
//		printf("imp=%d\n",te);
//		printf("e[te].wt=%d w=%d \n",e[te].wt,w);
		if(e[te].wt>w+p->weight&&visited[p->vertex]==0)
		{
//		    printf("p->vertex=%d\n",p->vertex);
		    e[te].wt=w+p->weight;
//	     printf("e[te].wt=%d wt.root=%d p->weigth=%d\n",e[te].wt,w,p->weight);
		    shift_up_min(e,p->vertex,w+p->weight);
		}	
		p=p->next;
	    }
	}
	//printf("%d==",q);
	if(w!=max)
	{
	printf("%d\n",w);
	}
	else
	{
	printf("NO\n");
	}
    }
    return 0;
}
void adj_list(int no_nodes,int no_edges)
{
//    printf("adj");
    int i,j,ui,vi, w;
    for(i=0; i< no_nodes ; i++)
    {
	N[i]=NULL;
	visited[i]=0;
	position[i]=i;
    }
    for(j=0 ; j<no_edges ; j++)
    {

	scanf("%d %d %d",&ui,&vi,&w);
	insert(ui,vi,w);
    }
}
void insert(int u,int v, int w)
{
  //  printf("insert");
    node *p,*q,*r;
    u=u-1;
    v=v-1;
    q=(node*)malloc(sizeof(node));
    q->vertex=v;
    q->weight=w;
    q->next=NULL;
    //printf("%d==%d\n",q->vertex,q->weight);
    if(N[u]==NULL)
	N[u]=q;
    else
    {
	p=N[u];
	r=p->next;
	p->next=q;
	q->next=r;
	
    //printf(" hii %d==%d\n",p->vertex,p->weight);
    }
}
void shift_up_min(edge *e , int j,int dis)
{     
    //printf("sum ");
    int i=position[j];
    e[i].wt=dis;
    while(i>0 && e[i].wt < e[(i-1)/2].wt)
    {  
	int parent = (i-1)/2;
	int tempo=position[e[parent].vertex];
	position[e[parent].vertex]=position[e[i].vertex];
	position[e[i].vertex]=tempo;
	edge temp;
	temp=e[parent];
	e[parent]=e[i];
	e[i]=temp;
	i=(i-1)/2;
    }
   // for(i=0;i<n ;i++)
    //printf("@ %d @",position[i]);
} 
int child(edge *h , int i , int flag)
{
    //printf("child");
    int left=2*i+1;
    int right=2*i+2;
    if(flag==0)
    {
	//printf("i am in min  child\n");
	if(left>=count)
	    return -1;
	return left;

    }
    //if(flag==1)
    else
    {
	//printf("i am in max child\n");
	if(right>=count)
	    return -1;
	return right;
    }
}
void heapify_min(edge *hl , int i)
{
    int l,r,min;
    edge temp;
    l=child(hl,i,0);
    r=child(hl,i,1);
    if(l!=-1&& hl[l].wt<hl[i].wt)
	min=l;
    else
	min=i;
    if(r!=-1 && hl[r].wt<hl[min].wt)
	min=r;
    if(min!=i)
    {
	int tempo=position[hl[min].vertex];
	position[hl[min].vertex]=position[hl[i].vertex];
	position[hl[i].vertex]=tempo;
	temp=hl[i];
	hl[i]=hl[min];
	hl[min]=temp;
	heapify_min(hl,min);
    }
}
int delete_min(edge* hl)
{
    
    //printf("i am in min delete\n");
    int data;
    if(count==0)
	return -1;
    data=hl[0].wt;
    //printf("%d",)
    //printf("%d\n",data);
    int temp=position[hl[0].vertex];
    position[hl[0].vertex]=position[hl[count-1].vertex];
    position[hl[count-1].vertex]=temp;
    hl[0]=hl[count-1];
    count--;
    heapify_min(hl,0);
    return data;
}
