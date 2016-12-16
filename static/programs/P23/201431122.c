#include<stdio.h>
#include<stdlib.h>


typedef struct ll{
	int ind;
		struct ll* next;
}ll;

ll *arr[500005];

void add(int x,long long int y)
{

	ll *temp;
	temp=(ll *)malloc(sizeof(ll));
	temp->ind=y;
	temp->next=arr[x];
	arr[x]=temp;
}


int h[500005];
int head;
int vis[500005];
int in[500005];

void insert(int in)
{
	head++;
	h[head]=in;
	int i=head,p;
	while(i>1)
	{
		p=i/2;
		if(h[p]>h[i])
		{
			int temp=h[p];
			h[p]=h[i];
			h[i]=temp;
			i=p;

		}
		else
			break;

	}
	
}


int min()
{
	int res=h[1];
	h[1]=h[head];
	head--;
	int i=1,p;
	while(2*i<=head)
	{
		p=2*i;
		if(2*i+1<=head)
		{if(h[2*i+1]<h[2*i])
			p=2*i+1;
		}
		if(h[p]<h[i])
		{
			int tmp=h[p];
			h[p]=h[i];
			h[i]=tmp;
			i=p;
		}
		else if(h[p]>=h[i])
		{
			break;
		}
		}
	

return res;
}


int main()
{

	int v,x,y,n,m,i,j,k;
	scanf("%d%d",&n,&m);
	for(k=1;k<=n;k++)
	{
		in[k]=0;
		vis[k]=0;
	}
	head=0;
	for(k=1;k<=m;k++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		in[y]++;
	}
	for(i=1;i<=n;i++)
		if(in[i]==0)
			insert(i);
	while(head!=0)
	{
		/*for(j=1;j<=head;j++)
			printf("h-%d ",h[j]);
		printf("\n");
	*/	v=min();
		if(vis[v]==0)
		{
			vis[v]=1;
			ll * temp=arr[v];
			while(temp!=NULL)
			{
				in[temp->ind]--;
				if(in[temp->ind]==0)
				{
					insert(temp->ind);
				}
			temp=temp->next;
			}
		}
//		ans[ai++]=v;
		if(head==0)
			printf("%d\n",v);
		else
			printf("%d ",v);

	}
/*	for(j=0;j<ai-1;j++)
		printf("%d ",ans[j]);
	printf("%d\n",ans[ai-1]);*/

return 0;
}
