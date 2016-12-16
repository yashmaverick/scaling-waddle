#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

#define true 1
#define false 0

int count[1000001];
int vis[1000001];
int inh[1000001];

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *a[1000001];

NODE *insert(NODE *root,int data)      
{
	NODE *temp=malloc(sizeof(NODE));
	temp->data=data;
	temp->next=root;
	return temp;
}

void print(NODE *root)
{
	NODE *temp=root;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	return ;
}
typedef struct heap
{
	int data;
}HEAP;

HEAP aa[1000001];

int size=0; 

void inserth(int data)     //insert  for the heap
{
	size++;
	int r=size,temp;
	aa[r].data=data;
	while(r>1 && aa[r].data < aa[r/2].data)
	{
		temp=aa[r].data;
		aa[r].data=aa[r/2].data;
		aa[r/2].data=temp;
		r=r/2;
	}
	return ;
}

int deleteh()      //delete for the heap
{
	int ret=aa[1].data,t;
	aa[1].data=aa[size].data;
	size--;
	int i=1,j;
	while(2*i<=size)
	{
		j=2*i;
		if(2*i+1<=size)
		{
			if(aa[2*i].data<aa[2*i+1].data)
			{
				j=2*i;
			}
			else
			{
				j=2*i+1;
			}
		}
		if(aa[j].data<aa[i].data)
		{	
			t=aa[i].data;
			aa[i].data=aa[j].data;
			aa[j].data=t;
			i=j;
		}
		else
			break;
	}
	return ret;
}

void dos()
{
	int source;
	NODE *temp;
	while(size!=0)
	{
		source=deleteh();
		while(a[source]!=NULL)
		{
			count[a[source]->data]--;
			if(count[a[source]->data]==0)
			{
				inserth(a[source]->data);
			}
			temp=a[source];
			a[source]=a[source]->next;
			free(temp);
		}
		if(size==0)
			printf("%d",source);
		else
			printf("%d ",source);
	}
	printf("\n");
	return ;
}
int main()
{
	int t=1,i,j,k,cities,index,ed,l,m,n,il,val,edge,o;
	int test1,test2;
	while(t--)
	{
		scanf("%d %d",&n,&ed);
		for(i=1;i<=n;i++)
			a[i]=NULL;
		for(i=1;i<=ed;i++)
		{
			scanf("%d %d",&il,&val);
			a[il]=insert(a[il],val);
			count[val]++;
		}
		/*for(o=1;o<=n;o++)
			print(a[o]);*/
		for(o=1;o<=n;o++)
		{
			if(count[o]==0)
			{
				inserth(o);
			}
		}
		dos();
		for(o=1;o<=n;o++)
		{
			a[o]=NULL;
			inh[o]=0;
		}
	}
	return 0;
}
