#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
//void mininsert()
//mindelete
int min[1000010];
typedef struct node
{int vertex;
	struct node* next;
}node;
void mininsert(int a[],int x,int index)
{int t;

	a[index]=x;
	while(1)
	{if(x>=a[(index)/2])
		{a[(index)]=x;
			break;
		}
		if(x<a[(index)/2])
		{
			t=a[(index)];
			a[(index)]=a[(index)/2];
			a[(index)/2]=t;
			index=(index)/2;
		}
	}
}
void mindelete(int a[],int in,int n)
{int t;
	t=a[in];
	a[in]=a[n];
	a[n]=t;
	a[n]=1000010;
	while(in<=(n-1)/2)
	{if(a[in]<=a[2*in]&&a[in]<=a[(2*in)+1])
		break;
		else
		{
			if(a[2*in]<=a[(2*in)+1])
			{ //swap(a[2in a[in]])
				t=a[2*in];
				a[2*in]=a[in];
				a[in]=t;
				in=2*in;
			}
                        else
			if(a[2*in+1]<a[2*in])
			{   //swap(a[2in+1]a[in])
				t=a[(2*in)+1];
				a[(2*in)+1]=a[in];
				a[in]=t;
				in=(2*in)+1;
			}

		}
	}
}

int main()
{
	int topa=1;
	int n,m,i,a,b;
	int state[1000010];
	    node* graph[1000010];
	min[0]=-1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=1000010;i++)
		state[i]=0;
	for(i=1;i<=n;i++)
	{  
	   graph[i]=(node*)malloc(sizeof(node));
	   graph[i]->vertex=i;
	   graph[i]->next=NULL;
	}
	for(i=1;i<=m;i++)
	{    scanf("%d%d",&a,&b);
	     
	node* tmp=(node*)malloc(sizeof(node));
			tmp->vertex=b;
			tmp->next=NULL;
			if(graph[a]->next==NULL)
			{  graph[a]->next=(node*)malloc(sizeof(node));
				graph[a]->next=tmp;
			}
			else
			{node *tmp1=(node*)malloc(sizeof(node));
				tmp1=graph[a]->next;
				graph[a]->next=tmp;
				tmp->next=(node*)malloc(sizeof(node));
				tmp->next=tmp1;
			}

		
		
		state[b]++;

	}
	for(i=1;i<=n;i++)
	{   if(state[i]==0)
		{mininsert(min,i,topa);
		topa++;
		}
	}
	int h=0;
	int final[1000010],x;
	while(topa!=1)
	{
	x=min[1];
	final[h++]=x;
	mindelete(min,1,topa-1);
	topa--;
	node* tmp12=(node*)malloc(sizeof(node));
	tmp12=graph[x];
	while(tmp12->next!=NULL)
	{    
		state[tmp12->next->vertex]--;
		if(state[tmp12->next->vertex]==0)
		{		mininsert(min,tmp12->next->vertex,topa);
		         topa++;
	}
		tmp12=tmp12->next;

	
	}
	}
	for(i=0;i<h-1;i++)
	{printf("%d ",final[i]);
	
	}
	if(h!=0)
	printf("%d\n",final[h-1]);
        return 0;
}
