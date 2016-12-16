#include<stdio.h>
#include<stdlib.h>
int A[100005];
void swap(int i,int j)
{
    int c=A[i];
    A[i]=A[j];
    A[j]=c;
}
int min(int a,int b)
{
    if(a<b)
    {
	return a;
    }
    else
    {
	return b;
    }
}
typedef struct bogi{
    int nu;
    struct bogi* next;
}name;
typedef name* ptr;
ptr graph[100005];
int count=1;
void insertheap(int d)
{
    int jugad=count;
    A[jugad]=d;
    int parent=jugad/2;
    while(A[parent]>A[jugad])
    {
	swap(parent,jugad);
	jugad=jugad/2;
	parent=jugad/2;
    }
    count++;
}
int heapmin()
{
    return A[1];
}
void deletemin()
{
    A[1]=A[count-1];
    A[count-1]=0;
    count--;
    int parent=1;
    int child1=2;
    int child2=3;
    while(1)
    {
	if(child1<count&&child2<count)
	{
	    if(A[parent]>min(A[child1],A[child2]))
	    {
		if(A[child1]<A[child2])
		{
		    swap(parent,child1);
		    parent=child1;
		    child1=2*parent;
		    child2=2*parent+1;

		}
		else
		{
		    swap(parent,child2);
		    parent=child2;
		    child1=2*parent;
		    child2=2*parent+1;
		}
	    }
	    else
	    {
		break;
	    }
	}
	else if(child1<count&&child2>=count)
	{
	    if(A[parent]>A[child1])
	    {
		swap(parent,child1);
		parent=child1;
		child1=2*parent;
		child2=2*parent+1;
	    }
	    else
	    {
		break;
	    }
	}
	else if (child1>=count&&child2>=count)
	{
	    break;
	}
    }

}
ptr insert(int n,ptr root)
{
    ptr tmp=(ptr)malloc(sizeof(name));
    tmp->nu=n;
    tmp->next=root;
    return tmp;
}
void print(ptr root)
{
    ptr tmp=root;
    while(tmp!=NULL)
    {
	printf("%d ",tmp->nu);
	tmp=tmp->next;
    }
    printf("\n");
}
int nod[1000005];
int main()
{
    int print=0;
    int n,m,i,x,y;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
	nod[i]=0;
	graph[i]=NULL;
    }
    for(i=0;i<m;i++)
    {
	scanf("%d %d",&x,&y);
	nod[y]++;
	graph[x]=insert(y,graph[x]);
    }
    for(i=1;i<=n;i++)
    {
	if(nod[i]==0)
	{
	    insertheap(i);
	}
    }
    while(count!=1)
    {
	if(print==(n-1))
	{
	    printf("%d",A[1]);
	}
	else
	{
	    printf("%d ",A[1]);
	}
	print++;
	ptr tmp=graph[A[1]];
	deletemin();
	while(tmp!=NULL)
	{
	    nod[tmp->nu]--;
	    if(nod[tmp->nu]==0)
	    {
		insertheap(tmp->nu);
	    }
	    tmp=tmp->next;
	}
    }
    printf("\n");
    return 0;
}


