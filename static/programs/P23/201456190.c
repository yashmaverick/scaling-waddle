#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int L[100005];
int a[100005];
int minind=0;
struct linked{
	int d;
	struct linked * next;
};

typedef struct linked ELEMENT;

ELEMENT *node[100005];
ELEMENT *node1[100005];

void graph(int u,int v)
{
	ELEMENT *head;
	head=(ELEMENT *)(malloc(sizeof(ELEMENT)));
	head->d=v;
	head->next=node[u];
	node[u]=head;
	return;
}


void graphy(int u,int v)
{
	ELEMENT *head;
	head=(ELEMENT *)(malloc(sizeof(ELEMENT)));
	head->d=v;
	head->next=node1[u];
	node1[u]=head;
	return;
}

void minheapinsert(int d)
{
	minind++;
	if(minind==1)
	{
		a[1]=d;
	}
	else
	{
		a[minind]=d;
		int j=minind;
		while(1)
		{
			int k;
			k=j;
			j=j/2;
			if(a[j]>a[k]&&j>0)
			{
				int temp;
				temp=a[k];
				a[k]=a[j];
				a[j]=temp;

			}
			else
			{
				a[k]=d;
				break;
			}
		}
	}

//	int q;
//	for(q=1;q<=minind;q++)
//		printf("a[%d]=%d ",q,a[q]);
//	printf("\n");
	return;

}



int minheapdelete()
{
	if(minind==0)
		return -1;
	int t=a[minind];
	int y=a[1];
	a[minind]=INT_MAX;
	a[1]=t;
//	printf("%d\n",a[1]);
	int k=1;
	int j=1;
	int g=1;
	while(1)
	{
		j=2*k;
		g=(2*k)+1;

		if((j<=minind-1) && a[k]>a[j] && a[j]<=a[g])
		{
		//	printf("if\n");
			int temp=a[k];
			a[k]=a[j];
			a[j]=temp;
			k=j;
		}
		else if((g<=minind-1) && a[k]>a[g] && a[g]<=a[j])
		{
		
			int tem=a[k];
			a[k]=a[g];
			a[g]=tem;
			k=g;
		}
		else
		{
			minind=minind-1;
			break;
		}
	}
	return y;
}
		
int main()
{ 
	int ver,edges;
	int i,j;
	int u,v;
	scanf("%d %d",&ver,&edges);
	for(i=1;i<=ver;i++)
	{ 
		node[i]=NULL;
		node1[i]=NULL;
		a[i]=INT_MAX;
	}

	for(j=1;j<=edges;j++)
	{
		scanf("%d %d",&u,&v);
		graph(u,v);
		graphy(v,u);
	}

	for(j=1;j<=ver;j++)
	{
		int count=0;
		ELEMENT *tail;
		tail=node1[j];
		while(tail!=NULL)
		{

			count=count+1; 
			tail=tail->next;
		}
		if(count==0)
			minheapinsert(j);
		L[j]=count;
	}
        
//	for(j=1;j<=ver;j++)
//		printf("%d ",L[j]);
//	int y=minheapdelete();
//	printf("y=%d",y);
        int flag=0;
	while(1)
	{
        	int y=minheapdelete();
		if(y==-1)
	        {
                        printf("\n");
			break;
		}
		else if(y!=-1 && flag==1)
		{
			printf(" ");
		}
		printf("%d",y);
		ELEMENT *tail;
		tail=node[y];
		flag=1;
		while(tail!=NULL)
		{
		      L[tail->d]=L[tail->d]-1;
		      if(L[tail->d]==0)
                         minheapinsert(tail->d);
		      tail=tail->next;
		}     
	 }          
        
	return 0;
}
