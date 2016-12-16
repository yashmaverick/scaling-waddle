#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node* next;
};
typedef struct node node;
node* insert(node* head,int val)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->val=val;
	temp->next=head;
	return temp;
}
int nemin=0;
int heapmin[100005];
void insertmin(int val)
{
	nemin++;
	heapmin[nemin]=val;
	int ind=nemin;
	while(ind>1)
	{
		if(heapmin[ind]<heapmin[ind/2])
		{
			int temp=heapmin[ind];
			heapmin[ind]=heapmin[ind/2];
			heapmin[ind/2]=temp;
		}
		ind=ind/2;
	}
}
void popmin()
{

	heapmin[1]=heapmin[nemin];
	nemin--;
	int ind=1;
	if(ind>nemin)
		return;
	while(1)
	{

		int maxind=2*ind;
		if(maxind>nemin)
			return;
		if(heapmin[maxind]>heapmin[maxind+1]&&maxind+1<=nemin)
		{
			maxind++;
		}
		if(heapmin[ind]>heapmin[maxind])
		{
			int temp=heapmin[ind];
			heapmin[ind]=heapmin[maxind];
			heapmin[maxind]=temp;
		}
		ind=maxind;
		if(ind>nemin)
			break;

	}
}
int min()
{
	return heapmin[1];
}



//node* adju[100005]={NULL};
node* adjd[100005]={NULL};
int arr[100005]={0};
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int i;
	for(i=0;i<m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		u--;
		v--;
		adjd[u]=insert(adjd[u],v);
		//adju[v]=insert(adju[v],u);
		arr[v]++;
	}
	for(i=0;i<n;i++)
		if(arr[i]==0)
			insertmin(i);
	int ans[100005];
	int ct=0;
	while(nemin!=0)
	{
		int root=min();
		ans[ct]=root;
		ct++;
		popmin();
		node* temp=adjd[root];
		while(temp!=NULL)
		{
			int u=temp->val;
			arr[u]--;
			if(arr[u]==0)
				insertmin(u);
			temp=temp->next;
		}
	}
	printf("%d",ans[0]+1);
	for(i=1;i<n;i++)
		printf(" %d",ans[i]+1);
	printf("\n");
	return 0;
}
