#include<stdio.h>
#include<stdlib.h>

struct node
{
	int*a;
	int sum;
	struct node*next;
};
struct node *head=NULL;
int main()
{
	int i,j,n,m,mod;
	scanf("%d %d",&n,&mod);
	struct node*temp;
	for(i=0;i<n;i++)
	{

		//		struct node*temp[n];
		temp=(struct node*)malloc(sizeof(struct node*));
		temp->sum=0;
		scanf("%d",&m);
		//		for(j=0;j<m;j++)
		//		{
		temp->a=(int*)malloc((m+1)*sizeof(int));
		//			temp[i]->a[0]=m;
		//			printf("\nm=%d",temp->a[0]);
		temp->a[0]=m;
		temp->next=NULL;
		for(j=1;j<=m;j++)
		{
			scanf("%d",&temp->a[j]);
			//				printf("\n%d",temp->a[i]);
			temp->sum=((temp->sum)+(temp->a[j]))%mod;
		}
		/*			for(j=1;j<=m;j++)
					printf("%d",temp->a[j]);
					printf("\n");
					temp->next=NULL;
		 */
		if(head==NULL)
		{
			head=temp;
			//				head->next=NULL;
		}
		else
		{
			struct node*p;
			p=head;
			while(p->next!=NULL)
			{
				//				int k;
				//				printf("%d ",p->a[0]);
				//				printf("%d\n",p->sum);
				//				for(k=1;k<=p->a[0];k++)
				//				{
				//					printf("%d ",p->a[k]);
				//				}
				p=p->next;
				//				printf("%d\n",p->sum);
			}
			//			p=p->next;	
			p->next=temp;
		}
	}
/*	struct node*t=head;
	while(t!=NULL)
	{
		printf("%d\n",t->sum);
		for(i=1;i<=t->a[0];i++)
		{
			printf("%d\n",t->a[i]);
		}
		t=t->next;
		printf("\n");
	}
*/	//	int s;
	//	struct node*temp1;
	//	struct node*temp2=NULL;

	//	if(head==NULL||head->next==NULL)
	//	{
	//	}

	/*else
	  do
	  {
	  s=0;
	  temp1=head;
	  while(temp1->next!=temp2)
	  {
	  printf("\n check1");
	  if(temp1->sum>temp1->next->sum)
	  {
	  struct node*temp3;
	  temp3=temp1;
	  temp1=temp1->next;
	  temp1->next=temp3;
	  s=1;
	  }
	  temp1=temp1->next;
	  }
	  temp2=temp1;
	  }while(s==1);*/

/*	int count=0;
	struct node*temp1=head;
	while(temp1!=NULL)
	{
		temp1=temp1->next;
		count++;
	}

	printf("\n%d\n",i);
*/	/*	int done=0;
		while (!done) {
		struct node *pv = head;            // "source" of the pointer to the
	// current node in the list struct
	struct node *nd = head;            // local iterator pointer
	struct node *nx = head->next;  // local next pointer

	done = 1;

	while (nx) {
	//			int cmp = strcmp(nd->m_last_name, nx->m_last_name);

	if (nd->sum>nd->next->sum) {
	nd->next = nx->next;
	nx->next = nd;
	pv = nx;

	done = 0;
	}
	pv = nd->next;
	printf("%d pv",pv->sum);
	nd = nx;
	printf("%d nd", nd->sum);
	nx = nx->next;
	printf("%d nx", nx->sum);
	}
	}*/
	//int i,j;
	struct node *a = NULL;
	struct node *b = NULL; 
	struct node *c = NULL;
	struct node *e = NULL; 
	struct node *tmp = NULL; 

	/* 
	// the `c' node precedes the `a' and `e' node 
	// pointing up the node to which the comparisons
	// are being made. 
	 */
	while(e!=head->next) 
	{
		c=a;
	       	a=head;
		b=a->next;
		while(a!=e) 
		{
			if(a->sum>b->sum) 
			{
				if(a==head) 
				{
					tmp=b->next;
					b->next=a;
					a->next=tmp;
					head=b;
					c=b;
				} 
				else 
				{
					tmp=b->next;
					b->next=a;
					a->next=tmp;
					c->next=b;
					c=b;
				}
			} 
			else 
			{
				c=a;
				a=a->next;
			}
			b=a->next;
			if(b==e)
				e=a;
		}
	}
//	printf("\n");
	struct node*p=head;
	while(p!=NULL)
	{
		printf("%d\n",p->sum);
		for(i=1;i<=p->a[0];i++)
		{
			printf("%d\n",p->a[i]);
		}
		p=p->next;
		printf("\n");
	}

	return 0;
	}

