#include<stdio.h>
#include<stdlib.h>
int last=0;

typedef struct list
{
	int x;
	int weight;
	struct list *next;
}list;

typedef struct list *link;

typedef struct heap
{
	int x;
	int parent;
	int weight; //from the root
}heap;


void su(heap a[],int temp)
{
	int x=temp/2;

	if(x==0) return;

	int ya=a[x].weight;

	if(ya<=a[temp].weight) return;

		int y=a[x].x;
		int y1=a[x].weight;
		int y3=a[x].parent;

		a[x].x=a[temp].x;
		a[x].weight=a[temp].weight;
		a[x].parent=a[temp].parent;

		a[temp].x=y;
		a[temp].weight=y1;
		a[temp].parent=y3;
	su(a,x);
}

void sd(heap a[],int temp)
{
	int x=2*temp;

	if(x>last) return;
	else if(x==last)
	{
		if((a[temp].weight)<=(a[x].weight)) return;
		
		int y=a[x].x;
		int y1=a[x].weight;
		int y3=a[x].parent;

		a[x].x=a[temp].x;
		a[x].weight=a[temp].weight;
		a[x].parent=a[temp].parent;

		a[temp].x=y;
		a[temp].weight=y1;
		a[temp].parent=y3;

		return;
	}
	else
	{
		int p,q;
		p=a[x].weight;
		q=a[x+1].weight;

		if(a[temp].weight<=p && a[temp].weight<=q) return;

		if(p<=q)
		{
			int y=a[x].x;
			int y1=a[x].weight;
			int y3=a[x].parent;

			a[x].x=a[temp].x;
			a[x].weight=a[temp].weight;
			a[x].parent=a[temp].parent;

			a[temp].x=y;
			a[temp].weight=y1;
			a[temp].parent=y3;
	
			sd(a,x);
		}
		else
		{
			int y=a[x+1].x;
			int y1=a[x+1].weight;
			int y3=a[x+1].parent;

			a[x+1].x=a[temp].x;
			a[x+1].weight=a[temp].weight;
			a[x+1].parent=a[temp].parent;

			a[temp].x=y;
			a[temp].weight=y1;
			a[temp].parent=y3;
	
			sd(a,x+1);
		}
	}

}

void ins(heap a[],int x,int weight,int parent) 
{
	last++;
	a[last].x=x;
	a[last].weight=weight;
	a[last].parent=parent;
	su(a,last);
}

void del(heap a[])
{
	a[1].x=a[last].x;
	a[1].weight=a[last].weight;
	a[1].parent=a[last].parent;

	last--;
	sd(a,1);
}

int main()
{

		long long int span=0;
		int count=0;
		last=0;
		int n,m,i; //number of nodes and edges
		scanf("%d %d",&n,&m);

		link tree[n];

		for(i=0;i<n;i++) tree[i]=NULL;

		for(i=0;i<m;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			a--;
			b--;

			link temp;
			temp=malloc(sizeof(list));
			temp->x=b;
			temp->weight=c;
			temp->next=tree[a];
			tree[a]=temp;
		
			link temp1;
			temp1=malloc(sizeof(list));
			temp1->x=a;
			temp1->weight=c;
			temp1->next=tree[b];
			tree[b]=temp1;


		}


		heap a[m+2];
		ins(a,0,0,-1);


		int ans[n],parent[n];
		for(i=0;i<n;i++) { ans[i]=-1; parent[i]=0; }
		

		while(last!=0 && count<n)
		{

			//printf("last:%d\n",last);
			//printf("==>heap top and status:%d %d\n",temp+1,ans[temp]);

			int temp=a[1].x;
			if(ans[temp]!=-1)
			{
				del(a);
			//	printf("last:%d\n",last);

			}
			else
			{
				span+=a[1].weight;
				ans[temp]=a[1].weight;
				parent[temp]=a[1].parent;
				del(a);
				count++;

				link t;
				t=tree[temp];

				while(t!=NULL)
				{

					if(ans[t->x]==-1)
					{
						ins(a,t->x,(t->weight),temp); //heap, node, distance from parent,parent

					}

					t=t->next;
				}


			}
		}

		if(count==n) printf("%lld\n",span);
		else printf("-1\n");
		
	return 0;
}
