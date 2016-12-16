#include<stdio.h>
#include<stdlib.h>
int max(int a, int b)
{
	return (a > b) ? a: b;
}
int min(int a, int b)
{
	return (a < b) ? a: b;
}
struct node
{
	int data;
	struct node* next;
};
struct list
{
	struct node* head;
};
void push(struct node** head,int d)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=(*head);
	(*head)=newnode;
}
void minheap(int a[], int n)
{
	if (n == 1)
		return;
	else if (a[n] <= a[n/2])
	{
		int t = a[n];
		a[n] = a[n/2];
		a[n/2] = t;
		n /= 2;
		minheap(a,n);
	}
	else
		return;
}
int deletemin(int a[], int *n1)
{
	int ans=a[1];
	int t = a[*n1];
	(*n1)--;
	int n = (*n1);
	int i = 1;
	while (2*i <= n)
	{
		int j = 2*i;
		if (j != n && a[j] >= t && a[j+1] >= t)
			break;
		else if (j == n && a[j] >= t)
			break;
		else
		{
			a[i] = min(a[j],a[j+1]);
			if (a[j] < a[j+1])
				i = j;
			else
				i = j+1;
		}
	}
	a[i] = t;
	return ans;
}
int main()
{
	int m,n;
	//while(1)
	//{
	scanf("%d%d",&n,&m);
	//if(m==0&&n==0)break;
	int a[100010];
	int i;
	int in[100010];
	for(i=1;i<=n;i++)
		in[i]=0;
	int visited[100010];
	int added[100010];
	for(i=1;i<=n;i++)
	{
		added[i]=0;
		visited[i]=0;
	}
	struct list* l[100010];
	int p,q;
	int size=0;
	int t;
	int ans[100010];
	struct node* head=(struct node*)malloc(sizeof(struct node));
	for(i=1;i<=n;i++)
	{
		l[i]=(struct list*)malloc(sizeof(struct list));
		l[i]->head=NULL;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&p,&q);
		//push(&(l[q]->head),p);
		push(&(l[p]->head),q);
		in[q]++;
	}
	for(i=1;i<=n;i++)
	{
		if(in[i]==0&&(!added[i]))
		{
			size++;
			a[size]=i;
			minheap(a,size);
			added[i]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		t=deletemin(a,&size);
		if(i==n)
			printf("%d\n",t);
		else
			printf("%d ",t);
		visited[t]=1;
		head=l[t]->head;
		while(head!=NULL)
		{
			if(!visited[head->data]&&!added[head->data])
			{
				(in[head->data])--;
				if(in[head->data]==0)
				{
					size++;
					a[size]=head->data;
					minheap(a,size);
					added[head->data]=1;
				}
			}
			head=head->next;
		}
	}
	//}
	return 0;
}
