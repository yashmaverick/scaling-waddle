#include<stdio.h>
#include<stdlib.h>
typedef struct adj{
	int val;
	struct adj *link;
}adj;
int heap[100006],a[100006],front=0;
adj *list[100006];
int deleteheap()
{
	int temp,delel;
	int newcrap;
	//printf("deled el is %d\n",heap[1]);
	delel=heap[1];
	temp=heap[front];
	front--;
	int crap=1;
	for(crap=1;2*crap<=front;crap=newcrap)
	{
		newcrap=crap*2;
		if(newcrap!=front&&heap[newcrap+1]<heap[newcrap])
			newcrap++;
		if(temp> heap[newcrap])
			heap[crap]=heap[newcrap];
		else
			break;
	}
	heap[crap]=temp;
	//printf("about to return\n");
	return delel;
}
void heapinsert(int x)
{
	front++;
	heap[front]=x;
	int t=front;
	while(heap[t/2]>heap[t]&&(t/2)!=0)
	{
		int temp;
		temp=heap[t/2];
		heap[t/2]=heap[t];
		heap[t]=temp;
		t=t/2;
	}
}
int main()
{
	int n,m,v1,el,v2,i;
	scanf("%d %d",&n,&m);
	for(i=1;i<=100006;i++)
	{
		list[i]=NULL;
		a[i]=0;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&v1,&v2);
		adj *temp=(adj*)malloc(sizeof(adj));
		temp->val=v2;
		temp->link=list[v1];
		list[v1]=temp;
		a[v2]++;
	}
	//printf("akjdnaj\n");
	for(i=1;i<=n;i++)
	{
		if(a[i]==0)
			heapinsert(i);
	}
	//printf("cameout\n");
	int count=0;
	while(front!=0)
	{
		//printf("camein\n");
		el=deleteheap();
		//printf("%d\n",el);
		//printf("returned\n");
		if(count!=n-1)
		{
			printf("%d ",el);
			count++;
		}
		else
			printf("%d\n",el);
		adj* temp1;
		temp1=list[el];
		while(temp1!=NULL)
		{
			a[temp1->val]--;
			if(a[temp1->val]==0)
				heapinsert(temp1->val);
			temp1=temp1->link;
		}
	}
	return 0;
}
