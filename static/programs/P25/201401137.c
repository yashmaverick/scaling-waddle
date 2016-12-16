#include<stdio.h>
#include<stdlib.h>

typedef struct data
{
	int val;
	int dist;
}data;

int poi=0;
data b[1000001];
typedef struct node
{
	int val;
	int di;
	struct node *next;
}node;

node* insert(node *head,int ver,int distance) 
{
	node *temp=(node*)malloc(sizeof(node));
	temp->val=ver;
	temp->di=distance;
	temp->next=head;
	return temp;
}

void insert1(int poi)
{
	if(b[(poi-1)/2].dist<=b[poi].dist || poi==0)
	{
		return;
	}
	else
	{
		data temp;
		temp=b[poi];
		b[poi]=b[(poi-1)/2];
		b[(poi-1)/2]=temp;
		insert1((poi-1)/2);
	}
}

void delete(int index)
{
	data temp;
	if(((2*index)+1)>poi)
		return;
	if(((2*index)+2)<=poi)
	{
		int n,m;
		n=b[(2*index)+1].dist;
		m=b[(2*index)+2].dist;
		if(n<=m)
		{
			if(b[index].dist>n)
			{
				temp=b[index];
				b[index]=b[(2*index)+1];
				b[(2*index)+1]=temp;
				delete((2*index)+1);
				return;
			}
		}
		if(m<n)
		{
			if(b[index].dist>m)
			{
				temp=b[index];
				b[index]=b[(2*index)+2];
				b[(2*index)+2]=temp;
				delete((2*index)+2);
				return;
			}
		}
		return;
	}
	if(((2*index)+1)==poi)
	{
		if(b[(2*index)+1].dist<b[index].dist)
		{
			temp=b[index];
			b[index]=b[(2*index)+1];
			b[(2*index)+1]=temp;
			delete((2*index)+1);
			return;
		}
		return;
	}
}



int main()
{
	int v,e,i,fi,se,dis,stop=0,ans=0;
	poi=0;
	scanf("%d%d",&v,&e);
	node *a[100001];
	int c[1000001]={0};
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&fi,&se,&dis);
		if(fi==se)
			continue;
		fi=fi-1;
		se=se-1;
		a[fi]=insert(a[fi],se,dis);
		a[se]=insert(a[se],fi,dis);
	}
	b[0].dist=0;
	b[0].val=0;
	//	c[0]=1;
	poi++;
	int o;
	while(poi!=0)
	{
		node *head=a[b[0].val];
		//		c[b[0].val]=1;
		if(c[b[0].val]==0)
		{
			if(c[b[0].val]==0)
			{
				ans=ans+b[0].dist;
				stop++;
				c[b[0].val]=1;
			}
			b[0]=b[poi-1];
			poi=poi-2;
			delete(0);
			poi++;
			while(head!=NULL)
			{
				if(c[head->val]==0)
				{
//					printf("YES\n");
					b[poi].val=head->val;
					b[poi].dist=head->di;
					insert1(poi);
					poi++;
				}
				head=head->next;
			}
//			for(o=0;o<poi;o++)
//				printf("%d ",b[o].val+1);
//			printf("\n");
//			for(o=0;o<poi;o++)
//				printf("%d ",b[o].dist);
//			printf("\n");
//			printf("%d\n",poi);
/*			if(c[b[0].val]==0)
			{
				ans=ans+b[0].dist;
				stop++;
				c[b[0].val]=1;
			}
*/		//	for(o=0;o<poi;o++)
//				printf("%d ",b[o].val+1);
//			printf("\n");
//			for(o=0;o<poi;o++)
//				printf("%d ",b[o].dist);
//			printf("\n");
		}
		else
		{
			b[0]=b[poi-1];
			poi=poi-2;
			delete(0);
			poi++;
		}
	}
	if(stop==v)
		printf("%d\n",ans);
	else
		printf("-1\n");
	return 0;
}
