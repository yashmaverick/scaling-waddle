#include<stdio.h>
//#include<limits.h>
#include<stdlib.h>

typedef struct data
{
	long long int val;
	long long int dist;
}data;

long long int poi=0;
data b[1000001];
typedef struct node
{
	long long int val;
	long long int di;
	struct node *next;
}node;

node* insert(node *head,long long int ver,long long int distance) 
{
	node *temp=(node*)malloc(sizeof(node));
	temp->val=ver;
	temp->di=distance;
	temp->next=head;
	return temp;
}

void insert1(long long int poi)
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

void delete(long long int index)
{
	data temp;
	if(((2*index)+1)>poi)
		return;
	if(((2*index)+2)<=poi)
	{
		long long int n,m;
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
	long long int v,e,i,fi,se,dis,stop=0,ans=0;
	poi=0;
	scanf("%lld%lld",&v,&e);
	node *a[1000001];
	long long int c[1000001];//={0};
	long long int l[v];
	for(i=0;i<v;i++)
	{
		//		l[i]=INT_MAX;
		l[i]=100000000;
	}
	l[0]=0;
	for(i=0;i<e;i++)
	{
		scanf("%lld%lld%lld",&fi,&se,&dis);
		if(fi==se)
			continue;
		fi=fi-1;
		se=se-1;
		a[fi]=insert(a[fi],se,dis);
		//		a[se]=insert(a[se],fi,dis);
	}
	long long int first,second;
	scanf("%lld%lld",&first,&second);
	second--;
	b[0].dist=0;
	b[0].val=first-1;
	//	c[0]=1;
	poi++;
	long long int o;
	long long int flag=0;
	stop=0;
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
			if(b[0].val==second)
			{
				flag=1;
				//				break;
			}
			long long int temp1=l[b[0].val];
			b[0]=b[poi-1];
			poi=poi-2;
			delete(0);
			poi++;
			while(head!=NULL)
			{
				if(c[head->val]==0)
				{
					b[poi].val=head->val;
					b[poi].dist=head->di;
					if(l[head->val]>(head->di+temp1))
					{
						l[head->val]=head->di+temp1;
					}
					insert1(poi);
					poi++;
				}
				head=head->next;
			}
		}
		else
		{
			b[0]=b[poi-1];
			poi=poi-2;
			delete(0);
			poi++;
		}
	}
	if(flag==1)
		printf("%lld\n",l[second]);
	if(flag==0)
		printf("NO\n");
	//	}
		return 0;
}


