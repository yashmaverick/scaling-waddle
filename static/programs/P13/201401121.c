#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	long long int data;
	long long int max;
	struct node* l;
	struct node* r;
}node;
node* insert(node *head,long long int  data)
{
	if(head==NULL)
	{
		head=malloc(sizeof(node));
		head->l=NULL;
		head->r=NULL;
		head->data=data;
		return head;
	}
	else
	{
		if(head->data>=data)
		{

			head->l=insert(head->l,data);
			return head;
		}
		else
		{

			head->r=insert(head->r,data);
			return head;
		}
	}

}
void print(node *head)
{
	if(head->l!=NULL)
		print(head->l);
	printf("%lld ",head->data);
	if(head->r!=NULL)
		print(head->r);
}
long long int max(long long int a,long long int b)
{
	if(a>b)
		return a;
	else
		return b;
}
long long int maxdepth(node *head)
{
	
	if(head==NULL)
	{
		return -1;
	}
	head->max=max(maxdepth(head->l),maxdepth(head->r))+1;
	return head->max;
}
long long int maxi;
long long int search(node *head)
{
	

	long long int find;
	if(head->l!=NULL && head->r!=NULL)
	{


		if(head->l->max>=head->r->max)
		{
			find=search(head->l);
			return find;
		}
		else
		{
			find=search(head->r);
			return find;
		}
	}
	else if (head->l==NULL&&head->r!=NULL)
	{
		find=search(head->r);
		return find;
	}
	else if(head->r==NULL&&head->l!=NULL)
	{
		find=search(head->l);
		return find;
	}
	else
	{
		maxi=head->max;
		
		return head->data;
	}
}
int main()
{
	long long int maxd,maxnode;
	int t;
	scanf("%d",&t);
	while(t--)
	{

		node *head=NULL;
		long long int n;
		scanf("%lld",&n);
		long long int a[n];
		node* b[n];
		long long int i=0;
		long long int top=-1;
		while(n--)
		{
			long long int d;
			scanf("%lld",&d);
			a[i]=d;
			i++;

		}
		int m=i-1;
		while(m>=0)
		{

			if(top==-1)
			{
				head=malloc(sizeof(node));
				head->l=NULL;
				head->r=NULL;
				head->max=0;
				head->data=a[m];
				maxnode=head->data;
				maxd=0;
				top++;
				b[top]=head;

			}
			else if(a[m]>=b[top]->data)
			{
				node *temp;
				temp=malloc(sizeof(node));
				temp->data=a[m];
				temp->r=NULL;
				temp->l=NULL;
				temp->max=b[top]->max+1;
				if(temp->max>=maxd)
				{
					maxd=temp->max;
					maxnode=temp->data;
				}
				b[top]->r=temp;

			//	printf("Max of %lld is %lld\n",b[top]->data,b[top]->max);
				top++;
				b[top]=temp;

			}
			else	
			{
				while(a[m]<b[top]->data)
				{
					top--;
					if(top==-1)
						break;

				}
				node *temp=malloc(sizeof(node));
				temp->data=a[m];
				temp->l=NULL;
				temp->r=NULL;

				temp->max=b[top+1]->max+1;
		//		b[top+1]->max++;
				if(temp->max>=maxd)
				{
					maxd=temp->max;
					maxnode=temp->data;

				}
			

		//		printf("Max of %lld is %lld\n",b[top+1]->data,b[top+1]->max);
				b[top+1]->l=temp;
				b[top+1]=temp;

				top++;

			}
			m--;
		}
//		long long int max=maxdepth(head);
		printf("%lld %lld\n",maxnode,maxd);
	}
	return 0;
}





