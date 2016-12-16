#include<stdio.h>
#include<stdlib.h>
#define size 1000006
typedef long long int lli;

struct node
{
    lli index,len,total;
    struct node* next;
};
typedef struct node node;
typedef node* link;

void one(link itemp)
{
    printf("itemp->total=%lld\n",itemp->total);
    return;
}
void swap(link a,link b)
{
    lli tin,tl,tt;

    tin=a->index;
    tl=a->len;
    tt=a->total;

    a->index=b->index;
    a->len=b->len;
    a->total=b->total;

    b->index=tin;
    b->len=tl;
    b->total=tt;
    return;
}

link insert(link head,lli index,lli M,lli total)
{
    if(head==NULL)
    {    
	link temp=(link)malloc(sizeof(node));
	temp->index=index;
	temp->len=M;
	temp->total=total;
	temp->next=head;

	temp->next=NULL;
	return temp;
    }   
    else
    {   
	head->next=insert(head->next,index,M,total);
	return head;
    }   
}

void show(link head)
{
    link temp=head;
    while(temp!=NULL)
    {
	printf("Index = %lli\n",temp->index);
	printf("Len = %lli\n",temp->len);
	printf("Total = %lli\n",temp->total);
	printf("\n");
	temp=temp->next;
    }
    return;
}

void bbsort(link head)
{
    if(head==NULL)
	return;
    int c=-1;
    link itemp;
    link end=NULL;
    while(c!=0)
    {
	c=0;
	itemp=head;
	while(itemp->next!=end)
	{
	    //	    one(itemp);
	    //	    one(itemp->next);
	    if(itemp->total > itemp->next->total)
	    {
		c++;
		//		printf("c=%d\n",c);
		swap(itemp,itemp->next);
	    }
	    itemp=itemp->next;
	}
	end=itemp;
    }
    return;
}

void output(link head,lli a[])
{
    if(head==NULL)
	return;
    link temp=head;
    lli i,start,n;

    while(temp!=NULL)
    {
	start=temp->index;
	n=temp->len;
	n+=start;
	//	printf("start = %lld\n",start);
	//	printf("n = %lld\n",n);
	printf("%lld\n",temp->total);
	for(i=start;i<n;i++)
	    printf("%lld\n",a[i]);
	printf("\n");
	temp=temp->next;
    }
    return;
}

int main()
{
    link head=NULL;
    lli a[size],N,mod,M,W,index,total;
    lli i,j,pa=0;
    scanf("%lld",&N);
    scanf("%lld",&mod);
    for(i=0;i<N;i++)
    {
	total=0;
	scanf("%lld",&M);
	index=pa;
	for(j=0;j<M;j++)
	{
	    scanf("%lld",&W);
	    a[pa++]=W;
	    total=((total%mod)+(W%mod))%mod;
	}
	head=insert(head,index,M,total);
    }
    //  show(head);
    //  one(head);

    bbsort(head);
    //  printf("over\n");
    //  show(head);
    /*
       printf("--a--\n");
       for(i=0;i<pa;i++)
       printf("%lld ",a[i]);
       printf("\n");
     */
    output(head,a);
    return 0;
}

