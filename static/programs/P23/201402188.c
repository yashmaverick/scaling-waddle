#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node
{
	int val;
	node *next;
};

node* a[100100];
node* arr[100100];

void insert(v1,v2)
{
	node* root=a[v1];
	while(root->next!=NULL)
	{
		root=root->next;
	}
	node* tmp=(node*)malloc(sizeof(node));
	tmp->val=v2;
	tmp->next=NULL;
	root->next=tmp;
}

void intra(v1,v2)
{
	node* root=arr[v1];
	while(root->next!=NULL)
	{
		root=root->next;
	}
	node* tmp=(node*)malloc(sizeof(node));
	tmp->val=v2;
	tmp->next=NULL;
	root->next=tmp;
}


int b[100100],countmin=0,flag[100100]={0};
int heapin(int n)
{
	countmin++;
	b[countmin]=n;
	flag[n]=1;
	int w=countmin;
	while(b[w]<b[w/2] && w>1)
	{
		int t=b[w];
		b[w]=b[w/2];
		b[w/2]=t;
		w=w/2;
	}
}

int min1(int re,int rt)
{
	if(re > rt)
		return rt;
	else
		return re;
}


void delete()
{
	b[1]=b[countmin];
	countmin--;
	int i=1,ind;
	while( min1(b[2*i],b[2*i+1]) < b[i])
	{
		if(b[2*i]< b[2*i+1])
		{
			ind=2*i;
		}
		else
			ind=2*i+1;
		if(ind>countmin)
			break;
		int t=b[ind];
		b[ind]=b[i];
		b[i]=t;
		i=ind;
	}
}
int count[100100]={0},var=0;
void dec_co(int w)
{
	node* root=a[w];
	root=root->next;
	var++;
	while(root!=NULL)
	{
		count[root->val]--;
		if(count[root->val]==0)
		{
			flag[root->val]=1;
			heapin(root->val);
		}
		root=root->next;
	}

}

/*void print(int n)
{
	int i;

	for(i=0;i<=n;i++)
	{
		node* root=arr[i];
		while(root!=NULL)
		{
			printf("%d ",root->val );
			root=root->next;
		}
		printf("\n");
	}
}*/

int main()
{
	int i,n,v,m;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a[i]=(node*)malloc(sizeof(node));
		a[i]->val=i;
		a[i]->next=NULL;
		arr[i]=(node*)malloc(sizeof(node));
		arr[i]->val=i;
		arr[i]->next=NULL;
	}
	int t;
	scanf("%d",&t);
	//printf("t: %d\n",t );
	for(i=1;i<=t;i++)
	{
		scanf("%d",&v);
		scanf("%d",&m);
		insert(v,m);
		//printf("amannnnn\n");
		intra(m,v);
		count[m]++;
	}
	//	printf("aman\n");
	//print(n);
	//for(i=1;i<=n;i++)
	//		printf("%d ",count[i] );
	//	printf("\n");
	int re;

	for(i=1;i<=n;i++)
	{
		if(count[i]==0 && flag[i]!=1)
		{
			//printf("heap: %d",i);
			heapin(i);
		}
	}
	while(1)
	{
		re=b[1];
		if(var<n-1)
			printf("%d ",re );
		else
			printf("%d\n",re );
		delete();
		dec_co(re);
		if(var==n)
			break;
	}
	//printf("\n");
	return 0;
}
