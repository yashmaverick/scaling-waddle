#include<stdio.h>
#include<stdlib.h>

int tmp,tmp1;
int minh[100005][2];
int mincount=0;
int vis[100005];
void shuffledown(int number);
int min(int a,int b);

typedef struct list
{
	int source;
	int dest;
	int weight;
	struct list *next;
}list;

list *insert(list *head,int src,int des,int wei)
{
	list *new=(list *)malloc(sizeof(list));
	new->source=src;
	new->dest=des;
	new->weight=wei;
	new->next=NULL;
	list *temp;
	temp=head;
	if(head==NULL)
	{
		head=new;
		return head;
	}
	else
	{
		new->next=temp;
		head=new;
		return head;
	}
}

void insertheap(int weight,int vertex)
{
//	printf("insert w=%d ver=%d\n",weight,vertex);
	int x;
	x=mincount+1;
	minh[x][0]=weight;
	minh[x][1]=vertex;
	int parent=x/2,temp,temp1;
	while(minh[parent][0]>=minh[x][0] && x!=1 && parent!=0)
	{
		temp=minh[x][0];
		minh[x][0]=minh[parent][0];
		minh[parent][0]=temp;

		temp1=minh[x][1];
		minh[x][1]=minh[parent][1];
		minh[parent][1]=temp1;

		x=x/2;
		parent=parent/2;
	}
	return;
}

void deletemin()
{	if(mincount==0)
	{
		tmp= 0;
		tmp1=0;
	}
	//	int tmp,tmp1;
	tmp=minh[1][0];
	minh[1][0]=minh[mincount][0];

	tmp1=minh[1][1];
	minh[1][1]=minh[mincount][1];

	mincount=mincount-1;
	shuffledown(minh[1][0]);
	//	return tmp;
	return;
}

int min(int a,int b)
{
	if(a<=b)
		return a;
	return b;
}
void print(){
	int i;
	for(i=1;i<=mincount;i++)
		printf("d:%d v:%d -> ",minh[i][0],minh[i][1]);
	printf("\n");
	return;
}
void shuffledown(int num)
{
	int i=1,mini,temp,j,mini1,temp1;
	while(i<=mincount/2 && (num >= minh[2*i][0] || num >= minh[2*i+1][0]) && (2*i+1)<=mincount)
	{
		if(2*i<mincount)
		{
			mini=min(minh[2*i][0],minh[2*i+1][0]);
			if(mini==minh[2*i][0])
			{
				mini1=minh[2*i][1];
				j=2*i;
			}

			else 
			{
				j=2*i+1;
				mini1=minh[2*i+1][1];
			}
		}
		else 
		{
			mini=minh[2*i][0];
			j=2*i;
			mini1=minh[2*i][1];
		}	

		temp=mini;
		minh[j][0]=minh[i][0];
		minh[i][0]=temp;

		temp1=mini1;
		minh[j][1]=minh[i][1];
		minh[i][1]=temp1;

		i=j;
	}
	if(2*i == mincount) 
		if(num>minh[2*i][0]) 
		{ 
			temp=minh[i][0]; 
			minh[i][0]=minh[2*i][0]; 
			minh[2*i][0]=temp;

			temp1=minh[i][1];
			minh[i][1]=minh[2*i][1]; 
			minh[2*i][1]=temp1;
		}
	return;
}

int main()
{
	list *head[100005];
	int i,m1,n,m,x,y,w;
	scanf("%d%d",&n,&m);
	m1=m;
	for(i=1;i<=n;i++)
	{	
		head[i]=NULL;
		vis[i]=0;
	}
	while(m1--)
	{
		scanf("%d%d%d",&x,&y,&w);
		head[x]=insert(head[x],x,y,w);
		head[y]=insert(head[y],y,x,w);
	}

/*	for(i=1;i<=n;i++)
	  {
	  list *temp=head[i];
	  printf("%d ->>",i);
	  while(temp!=NULL)
	  {
	  printf("%d %d %d ",temp->source,temp->dest,temp->weight);
	  temp=temp->next;
	  }
	  printf("\n");
	  }*/
	int count=1,d,s=1,flag=0;
	long long int ans=0;
	vis[1]=1;
	list *temp;
	while(mincount>=0 || flag==0)
	{
		flag=1;
		temp=head[s];
		while(temp!=NULL)
		{
			if(vis[temp->dest]==0)
			{
				insertheap(temp->weight,temp->dest);
				mincount++;
			}
			temp=temp->next;
		}
//		print();
		int finsrc;
		finsrc=s;
loop:		deletemin();
		d=tmp;
		s=tmp1;
	//	printf("delete w=%d v=%d\n",d,s);
		if(s==finsrc || vis[s]==1)
		{
			goto loop;
		}
		ans=ans+d;
	//	printf("%d added\n",d);
		if(s!=0)
		{	
			vis[s]=1;
			count++;
		}
		if(count==n)
		{
			printf("%lld\n",ans);
			return 0;
		}
	}
	if(count!=n)
	{	printf("-1\n");
		return 0;
	}
	return 0;
}
