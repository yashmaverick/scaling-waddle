#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
	int visited;
}node;
static int preIndex,max,count2;
int search(int arr[], int strt, int end, int value)
{
	int i;
	for(i = strt; i <= end; i++)
	{
		if(arr[i] == value)
			return i;
	}
}
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
node* buildTree(int in[], int pre[], int first, int last)
{
	if(first>last)
	{
		return NULL;
	}
	node *p;
	p=(node*)malloc(sizeof(node));
	p->data=pre[preIndex];
	p->left=NULL;
	p->right=NULL;
	preIndex++;
	//	printf("%d %d\n", count, p->data);
	if(first==last)
	{
		return p;
	}
	//int index = binarysearch(in,p->data, first, last);
	int index = search(in, first, last, p->data);
	//	printf("%d\n", index);
	p->left = buildTree(in, pre, first, index-1);
	p->right = buildTree(in, pre, index+1, last);

	return p;
}
int flag=0,flag2=0;
int pos1;
int pos2;
int c[100003];
int got1,got2;
int d[100005];
node *dfs(node *root,int point)
{
	if(root==NULL)
	{
		return ;
	}
	node *q;
	q=root;
	if(flag!=1)
	{
		c[point]=q->data;
//		printf("%d %d\n", point,c[point]);
	}
	//	printf("%d ", q->data);
	if(q->data==pos1)
	{
		//		printf("-1");
		got1=point;
		//		printf("%d ", got1);
		flag=1;
	}
	dfs(q->left,point+1);
	dfs(q->right,point+1);

}	
node *dfs2(node *root,int point2)
{
	if(root==NULL)
	{
		return;
	}
	node *q;
	q=root;
	if(flag2!=1)
	{
		d[point2]=q->data;
//		printf("%d %d\n", point2,d[point2]);
	}
	//	printf("%d ", q->data);
	if(q->data==pos2)
	{
		//		printf("-1");
		got2=point2;
		//		printf("%d ", got1);
		flag2=1;
	}
	dfs2(q->left,point2+1);
	dfs2(q->right,point2+1);

}	
int main() 
{
	int n,x,t,test,pre[500005],in[500005],point=0,point2=0;
	int numbers;
	preIndex=0;
	scanf("%d", &numbers);
	for(x=0;x<numbers;x++) 
	{
		//	printf("Enter new node: ");
		scanf("%d",&pre[x]);
	}
	for(x=0;x<numbers;x++)
	{
		scanf("%d", &in[x]);
	}
	node *root=buildTree(in, pre, 0, numbers - 1);
//	postOrderTrav(root);
	scanf("%d", &n);
	int i,j;
	for(i=0;i<n;i++)
	{
		flag=0,flag2=0;
		point=0;
		point2=0;
		scanf("%d %d", &pos1,&pos2);
//		printf("root%d\n",root->data);
		dfs(root,point);
		dfs2(root,point2);
	/*	for(x=0;x<=got1;x++)
		{
			printf("%d ", c[x]);
		}
		printf("\n");
		for(x=0;x<=got2;x++)
		{
			printf("%d ", d[x]);
		}*/
		if(got1>=got2)
		{
			for(j=got2;j>=0;j--)
			{
				if(c[j]==d[j])
				{
					printf("%d\n", c[j]);
					break;
				}
			}
		}
		else
		{
			for(j=got1;j>=0;j--)
			{
				if(c[j]==d[j])
				{
					printf("%d\n", c[j]);
					break;
				}
			}
		}
	}
	return 0;
}
