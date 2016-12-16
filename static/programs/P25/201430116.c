#include<stdio.h>
#include<stdlib.h>
struct list
{
	int vtx1,vtx2;
	int weight;
	//struct list *nxt;
};
typedef struct list element;
typedef element *link;
void qcksrt(link a[],int first,int last)
{
	if(first<=last){
        int wall=first,pivot=first,i,t1,t2,w;

        for(i=first;i<=last;i++){
            if((a[i]->weight)<(a[pivot]->weight)){
            	wall++;
            	t1=a[wall]->vtx1;
            	t2=a[wall]->vtx2;
            	w=a[wall]->weight;
            //	printf("i=%d wall=%d 1\n",i,wall);
         //   	if(a[i]!=NULL&&a[wall]!=NULL){
            	a[wall]->vtx1=a[i]->vtx1;
            	a[wall]->vtx2=a[i]->vtx2;
            	a[wall]->weight=a[i]->weight;
            	a[i]->vtx1=t1;
            	a[i]->vtx2=t2;
            	a[i]->weight=w;
           //     }
            }
        }
        t1=a[wall]->vtx1;
        t2=a[wall]->vtx2;
        w=a[wall]->weight;
        //a[wall]=a[pivot];
      //  if(a[i]!=NULL&&a[wall]!=NULL)
       // {
      // 	printf("i=%d wall=%d 2\n",i,wall);
        	a[wall]->vtx1=a[pivot]->vtx1;
        	a[wall]->vtx2=a[pivot]->vtx2;
        	a[wall]->weight=a[pivot]->weight;
       // }
      //  a[pivot]=temp;
        a[pivot]->vtx1=t1;
        a[pivot]->vtx2=t2;
        a[pivot]->weight=w;
        qcksrt(a,first,wall-1);
        qcksrt(a,wall+1,last);
    }
}
int temp;
void findsup(int value,int parent[])
{
	if(parent[value]==value)
	{
		temp=value;
		return;
	}
	findsup(parent[value],parent);
	parent[value]=temp;
}  
int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);
	int *parent,*rank;
	parent=malloc((n+1)*sizeof(int));
	rank=malloc((n+1)*sizeof(int));
	link *a;
	a=malloc((m)*sizeof(link));
	int v1,v2,wt;
	for(i=1;i<=n;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
	for(i=0;i<m;i++)
	{
		a[i]=malloc(sizeof(element));
		scanf("%d %d %d",&v1,&v2,&wt);
		a[i]->vtx1=v1;
		a[i]->vtx2=v2;
		a[i]->weight=wt;
	}
	qcksrt(a,0,m-1);
/*	for(i=0;i<m;i++)
	{
		printf("%d %d %d\n",a[i]->vtx1,a[i]->vtx2,a[i]->weight);
	} */
	int x,y,sx,sy,count=0;
	long long int ans=0;
	for(i=0;i<m;i++)
	{
		x=a[i]->vtx1;
		y=a[i]->vtx2;
		findsup(x,parent);
		sx=temp;
		findsup(y,parent);
		sy=temp;
		if(sx!=sy)
		{
			count++;
			ans=ans+a[i]->weight;
			if(rank[sx]>rank[sy])
			{
				parent[sy]=parent[sx];
				//children[sx]=children[sx]+children[sy];
			}
			else if(rank[sx]<rank[sy])
			{
				parent[sx]=parent[sy];
				//children[sy]=children[sy]+children[sx];
			}
			else
			{
				parent[sy]=parent[sx];
				rank[sx]=rank[sy]+1;
				//children[sx]=children[sx]+children[sy];
			}
		}
	}
	//printf("count=%d\n",count);
	if(count==n-1)
	{
		printf("%d\n",ans);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}