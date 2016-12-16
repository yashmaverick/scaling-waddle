#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
typedef long long int ll;
struct node{
	int ind;
	int val;
	struct node* next;
};
ll size;
void push(node** head,ll i,ll data)
{
	node* tmp=(node*)malloc(sizeof(node));
	tmp->ind=i;
	tmp->val=data;
	tmp->next=*head;
	*head=tmp;
	size++;
}
void pop(node** head)
{
	if(*head==NULL)
	{
		return;
	}
	node* tmp=*head;
	*head=(*head)->next;
	free(tmp);
	size--;
}
ll top(node* head)
{
	if(head!=NULL)
	{
		return head->ind;
	}
}
int main()
{
	while(1)
	{
		ll a[500100],n,i,j,count,stu,ans=0;
		ll b[500100]={0};
		count=0;
		node* head=NULL;
		size=0;
		scanf("%lld",&n);
		if(n==0)
		{
			break;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<=n-1;)
		{
			if(head==NULL || a[i]<=a[top(head)])
			{
				count=0;
				if(size>1)
				{
					if(a[i]==a[top(head)])
					{
			//			ll jj=top(head);
			//			while(a[i]==a[jj])
			//			{
			//				count++;
			//				jj--;
			//			}
						node* tmp=head;
						while(tmp!=NULL&&a[i]==tmp->val)
						{
							count++;
							tmp=tmp->next;
						}
					}
				/*	else
					{
						count=0;
					} */
					if(size-1-count>0)
						ans+=(size-1)-count;
			//		printf("%Ld\t%Ld\t%Ld\n",count,size-1-count,a[i]);
				} 
				push(&head,i,a[i]);
				i++;
			}
			else
			{
				stu=top(head);
				pop(&head);
				b[stu]=i;
				ans+=(n-b[stu]-1);
			}
		}
		head=NULL;
//		while(head!=NULL)
//		{
//			stu=top(head);
//			pop(&head);
//			b[stu]=-1;
			
//		} 
/*		for(i=0;i<n;i++)
		{
			if(b[i]>0)
				c[i]=n-b[i]-1;
			else
			ans+=c[i];
			//	printf("%Ld ",b[i]);
		} */
		/*		printf("\nIndex -\n");
				} */
		//		printf("\nNormal count\n");
		printf("%Ld\n",ans);
		/*		printf("\nBarrier Count\n");
				for(i=0;i<n;i++)
				{
				printf("%Ld ",d[i]);
				} */
		/*		for(i=n-1;i>=0;)
				} */
	} 
	return 0;
}
