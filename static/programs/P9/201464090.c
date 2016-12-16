#include<stdio.h>
#include<stdlib.h>
int a[1000000];
typedef struct node
{
	int val;
	int index;
	struct node *next;
}node;
node *head;
void makenode(int value,int ind)
{
	node *new=malloc(sizeof(node));
	new->val=value;
	new->index=ind;
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
		return;
	}
	else
	{
		node *q;
		q=head;
		while(q->next!=NULL)
			q=q->next;
		q->next=new;
	}
	return;
}
void sort()
{
	node *p;
	p=head;
	node *q;
	int g,d;
	while(p!=NULL)
	{
		q=p->next;
		while(q!=NULL)
		{
			if((p->val)>(q->val))
			{
				g=p->val;
                                d=p->index;
				p->val=q->val;
                                p->index=q->index;
				q->val=g;
                                q->index=d;
			}
			q=q->next;
		}
		p=p->next;
	}
}
int main()
{
	int mod;
	int n,i=0,j,g=0,w,d,ind,nd,s,h;
	scanf("%d%d",&n,&mod);
	for(ind=0;ind<n;ind++)
	{
		scanf("%d",&a[i]);
                s=i;
		g=0;
		i++;
		j=i;
		for(nd=0;nd<a[i-1];nd++)
		{
			scanf("%d",&a[j]);
                        h=a[j];
			g=(g+h)%mod;
			j++;
		}
	        i=j;
               // printf("g=%d,s=%d\n",g,s);	
		makenode(g,s);
	}
	    sort();
	    node *f;
	    f=head;
	    while(f!=NULL)
	    {
	    printf("%d\n",f->val);
	    w=f->index;
	    for(i=1;i<=a[w];i++)
	    {
            printf("%d\n",a[w+i]);
	    }
            printf("\n");
	    f=f->next;
	    }

	return 0;
}
