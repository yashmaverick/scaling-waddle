#include<stdio.h>
#include<stdlib.h>

int point=1;
int last=0;


typedef struct list
{
	int x;
	struct list *next;
	/* data */
}list;

typedef struct list *link;

typedef struct heap
{
	int x;
	int weight; //from the root
}heap;

heap h[100045];
int flag[100045];

void su(heap a[],int temp)
{
	int x=temp/2;

	if(x==0) return;

	int ya=a[x].weight;

	if(ya<=a[temp].weight) return;

		int y=a[x].x;
		int y1=a[x].weight;

		a[x].x=a[temp].x;
		a[x].weight=a[temp].weight;

		a[temp].x=y;
		a[temp].weight=y1;
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

		a[x].x=a[temp].x;
		a[x].weight=a[temp].weight;

		a[temp].x=y;
		a[temp].weight=y1;

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

			a[x].x=a[temp].x;
			a[x].weight=a[temp].weight;

			a[temp].x=y;
			a[temp].weight=y1;
	
			sd(a,x);
		}
		else
		{
			int y=a[x+1].x;
			int y1=a[x+1].weight;

			a[x+1].x=a[temp].x;
			a[x+1].weight=a[temp].weight;

			a[temp].x=y;
			a[temp].weight=y1;
	
			sd(a,x+1);
		}
	}

}

void ins(heap a[],int x,int weight) 
{
	last++;
	a[last].x=x;
	a[last].weight=weight;
	su(a,last);
}

void del(heap a[])
{
	a[1].x=a[last].x;
	a[1].weight=a[last].weight;

	last--;
	sd(a,1);
}

void merge(int x,link tree[],int ans[],int count[])
{
	link temp=tree[x];

	while(temp!=NULL)
	{
		count[temp->x]--;

		if(count[temp->x]==0)
		{
			ins(h,temp->x,temp->x);
		}
		temp=temp->next;
	}


/*
	while(last>0)
	{
		int t;
		t=h[1].x;
		del(h);

		if(flag[t]==0)
		{	
			ans[point]=t;
			point++;
			flag[t]=1;
			merge(t,tree,ans,count);
		}
	}	*/
}

int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);

	int count[100045],ans[100045];
	link tree[100045];

	for(i=0;i<=100044;i++) {ans[i]=0; count[i]=0; tree[i]=NULL; flag[i]=0; }

	for(i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
	
//		if(x>y)
//		{	
			count[y]++;

			link temp;
			temp=malloc(sizeof(list));
			temp->x=y;
			temp->next=tree[x];
			tree[x]=temp;
//		}

	}


	for(i=1;i<=n;i++)
	{
		if(count[i]==0) ins(h,i,i);
	}

	while(last>0)
	{	
		int t=h[1].x;

			ans[point]=t;
			point++;
			del(h);
			merge(t,tree,ans,count);
	}


	for(i=1;i<=n;i++)
	{
		printf("%d",ans[i]);
		if(i!=n) printf(" ");
	}
	printf("\n");	

	return 0;
}