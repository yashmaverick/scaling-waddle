#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node *a[500000],*b[500000];
void insertparent(int x,int y)
{
	node *i=(node*)malloc(sizeof(node));
	i->next=NULL;
	i->data=y;
	node *temp;
	if(a[x]==NULL)
		a[x]=i;
	else if(a[x]!=NULL)
	{
		temp=a[x]->next;
		a[x]->next=i;
		i->next=temp;
	}
}
void insertchild(int x,int y)
{
	node *i=(node*)malloc(sizeof(node));
	i->next=NULL;
	i->data=y;
	node *temp;
	if(b[x]==NULL)
		b[x]=i;
	else if(b[x]!=NULL)
	{
		temp=b[x]->next;
		b[x]->next=i;
		i->next=temp;
	}
}
int heap[500000],c=0;
//heap[0]=100000;
void insertinheapi(int val)
{
	if(c==0)
	{
		c=c+1;
		heap[c]=val;
		//		c=c+1;
		return;
	}
	else
	{
		c=c+1;
		heap[c]=val;
		int p=c,temp;
		//		c=c+1;
		while(p>0)
		{
			if(heap[p]<heap[p/2])
			{
				temp=heap[p];
				heap[p]=heap[p/2];
				heap[p/2]=temp;
		//		break;
				p=p/2;
			}
			else
				p=p/2;
		}
	}
	return;
}
void insertinheap(int val)
{
	heap[0]=-1000000;
        c++;
        int i;
	i=c;
	heap[c]=val;
        for(;heap[i/2]>val;) 
        {
                heap[i]=heap[i/2];
                i=i/2;
        }
        heap[i]=val;
	return;
}
int deletemin()
{
	int ret,h;
	ret=heap[1];
	int s;
	s=heap[c];
	c--;
	int i;
	i=1;
	while(2*i<=c)
	{
		h=2*i;
		if(h!=c )
		{
			if(heap[h+1]<heap[h])
			h++;
		}
		if(s>heap[h])
		{
			heap[i]=heap[h];
		}
		else
			break;
		i=h;
	}

	heap[i]=s;
	return ret;
}
int deletemini()
{
	int i=0,temp,ret=heap[0];
	heap[0]=heap[c-1];
	c--;
	while(i<c)
	{
		if(2*i<c)
			if(heap[i]>heap[2*i])
			{
				temp=heap[i];
				heap[i]=heap[2*i];
				heap[2*i]=heap[i];
			}
		i=2*i;
	}
	return ret;
}
int main()
{
	int n,m,l,flag=0;
	scanf("%d%d",&n,&m);
	int i,x,y,indegree[n];
	for(i=0;i<n;i++)
		indegree[i]=0;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		insertparent(y-1,x-1);
		insertchild(x-1,y-1);
	}
	for(i=0;i<n;i++)
	{
		node *p=a[i];
		while(p!=NULL)
		{
			indegree[i]++;
			p=p->next;
		}
	}
	int count=0;
	for(i=0;i<n;i++)
                {
                        if(indegree[i]==0)
                        {
                                indegree[i]=-1;
                                count++;
                                insertinheap(i);
                        }
                }
int co=0;
	while(1)
	{
	/*	for(i=0;i<n;i++)
		{
			if(indegree[i]==0)
			{
				indegree[i]=-1;
				count++;
				insertinheap(i);
			}
		}*/
/*		if(c==0)
		{
			printf("\n");
			break;
		}*/
		l=deletemin();
		if(flag==1)
			printf(" ");
		printf("%d",l+1);
//		co++;
		flag=1;
		node *u=b[l];
		while(u!=NULL)
		{
//			u=u->next;
//			printf("%d----",u->data);
			indegree[u->data]--;
			 if(indegree[u->data]==0)
                        {
                                indegree[u->data]=-1;
                                count++;
                                insertinheap(u->data);
                        }

//			indegree[u->data]--;
			u=u->next;
		}
		      if(c==0)
                {
                        printf("\n");
                        break;
                }
		count=0;
	}	
	return 0;
}		
