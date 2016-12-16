#include<stdio.h>
#include<stdlib.h>
struct type_edge
{
    //int count;
    int vertex1;
    int vertex2;
    int wt;
};
typedef struct type_edge edge;
//edge *e[1000000];
int  delete_min(edge *h);
int child(edge *h , int i ,int flag);
void insert_min(edge* h ,int data,int , int);
void heapify_min(edge *h , int i); 
int n,m;
int parent[10001];
int rank[100001];
void make(int vertex);
int find(int vertex);
int kruskal(edge* e);
void un(int root1 , int root2);
int count;
int ed;
int main()
{
    int i,x,y,z;
    scanf("%d%d",&n,&m);
    edge* e;
    e=(edge*)malloc(sizeof(edge)*(m+1));
    for(i=1 ; i<=m ;i++)
    {
	scanf("%d%d%d",&x,&y,&z);
	insert_min(e,x,y,z);
    }

    //qsort(e,m,sizeof(e[0]),mycomp);
   
    int ans=kruskal(e);
    int flag=0;
//printf("i am edi %d\n",ed);
    if(n==1)
	printf("0\n");
    else if(ed==n-1)
	printf("%d\n",ans);
    else
	printf("-1\n");
    return 0;
}
int find(int vertex)
{
  //  printf("i am in find parent[%d] %d \n",vertex-1,parent[vertex-1]);
    if(parent[vertex]==vertex)
    {
	return parent[vertex];
    }
    else
    {
	return find(parent[vertex]);
    }

}
void un(int root1 , int root2)
{
    //printf("i am in un rank[%d]=%d rank[%d]=%d \n",root1,rank[root1],root2,rank[root2]);

    if(rank[root1]>rank[root2])
    {
	parent[root2]=root1;
    }
    else if(rank[root2]>rank[root1])
    {
	parent[root1]=root2;

    }
    else
    {
	parent[root1]=root2;
	rank[root2]++;
    }
}
void make(int vertex)
{

    parent[vertex-1]=vertex-1;
    rank[vertex-1]=0;
}
int kruskal(edge* e)
{
    //printf("hii\n");
    int i,sum=0;
    for(i=1 ; i<=n ; i++)
	make(i);
    i=1;
 //   printf("%d   \n",count);
    //for(i=0;i<m ;i++)
   // printf("--%d--\n",delete_min(e));
	for(ed=0 ; ed<n-1&&count>0;)
	{
  //  	printf("%d   \n",count);
	    //if(count>0)
	    //{
	    
	    int root1=find(e[0].vertex1-1);
	    int root2=find(e[0].vertex2-1);
//	    printf("==%d==%d==\n",root1,root2);
            int wt=delete_min(e);
	    if(root1!=root2)
	    {
//	    printf(" ed==%d",ed);
		sum+=wt;
//		printf("%d---\n",sum);
		un(root1,root2);
		ed=ed+1;
	    }
	//}
	}
    return sum;
}
int child(edge *h , int i , int flag)
{
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
    //printf("i am in min  heapify\n");
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
		    hl[0]=hl[count-1];
		        count--;
			    heapify_min(hl,0);
			        return data;
}

void insert_min(edge* hl ,int vertex1,int vertex2,int data)
{
    int i;
    count++;
    i=(count)-1;
    while(i>0 && data<hl[(i-1)/2].wt)
    {
	hl[i]=hl[(i-1)/2];
	i=(i-1)/2;
    }
    hl[i].wt=data;
    hl[i].vertex1=vertex1;
    hl[i].vertex2=vertex2;
}

