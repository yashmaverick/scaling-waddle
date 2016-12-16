#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct node {
	int * a;
	int total;
	struct node * next;
};
int main()
{
	int i,j,mod,n,m;
	scanf("%d %d",&n,&mod);
	struct node *p,*temp,*head=NULL,*start=NULL,*q;
        for(i=0;i<n;i++)
	{
                p=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&m);
		p->a=(int *)malloc((m+1)*sizeof(int));
		p->a[0]=m;
		p->total=0;
		p->next=NULL;
		/*if(i==0)
		{
			start=p;
		}*/
		for(j=1;j<=m;j++)
		{
			scanf("%d",&p->a[j]);
			p->total=(p->total+p->a[j])%mod;
		}
		if(start==NULL)
		{
			head=p;
			start=head;
		}
		else
		{
			head=start;
			/*while(head->total<=p->total && head!=NULL)
			{
				printf("1\n");
		                q=head;
				head=head->next;
			}
			if(head==start)
			{
				printf("2\n");
				p->next=start;
				start=p;
			}
			else if(head==NULL)
			{
				printf("3\n");
				q->next=p;
			}
			else
			{
				printf("4\n");
				temp=q->next;
				q->next=p;
				p->next=temp;
			}*/
			while(head->total<=p->total && head->next!=NULL)
			{
				q=head;
				head=head->next;
			}
			if(head==start)
			{
				if(head->total<=p->total)
					start->next=p;
				else
				{
					p->next=start;
					start=p;
				}
			}
			else if(head->next==NULL && head->total<=p->total)
					head->next=p;
			else if(head->total>p->total)
			{
				temp=q->next;
				q->next=p;
				p->next=temp;
			}
			else
			{
				temp=head->next;
				head->next=p;
				p->next=temp;
			}
		}

			        	
	}
	//p=NULL;
	//m=0;
        /*for(i=0;i<n-1;i++)
	{
		p=start;
	        for(j=0;j<n-i-1;j++)	
		{
			if(p->total>p->next->total)
			{
				if(start==p)
					m++;
				
				temp=p;
				p=p->next;
				p->next=temp;
				if(m==1)
				{
					start=p;
					m=0;
				}
			}
			p=p->next;
		}
	}*/
	p=start;
	while(p!=NULL)
	{
		printf("%d\n",p->total);
		for(i=1;i<=p->a[0];i++)
		{
			printf("%d\n",p->a[i]);
		}
		p=p->next;
		printf("\n");
	}

	return 0;
}
