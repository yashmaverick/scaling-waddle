#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int c=0;
typedef struct node
{
	int data;
	struct node* b[10];
}node;
struct node* head;
int flag=0;
void insert();
struct node* null();
int main()
{
	char c[10000];
	int a[10000];
	int n,i,j,l,t;
	scanf("%d",&t);
	while(t--)
        {scanf("%d",&n);
	head=null();
	flag=0;
	while(n--)
	{
		scanf("%s",c);
		l=strlen(c);
		for(i=0;i<l;i++)
			a[i]=c[i]-'a'+'1';
/*		for(i=0;i<l;i++)
			printf("%d ",a[i]);*/
		if(flag==0)
			insert(a,l);
	}
//	printf("flag=%d\n",flag);
	if(flag==0)
		printf("YES\n");
	else
		printf("NO\n");
	}
	return 0;
}
struct node* null()
{
	int i;
	node* q=(node*)malloc(sizeof(node));
	for(i=0;i<10;i++)
		q->b[i]=NULL;
	q->data=-1;
	return q;
}
void insert(int a[],int length)
{
	int i;
	node* p;
	p=head;
	i=0;
//	c++;
	//if(c>1)
	//printf("blah=%d\n",head->b[a[i]]->data);
	while(i<length)
	{
//		printf("a[i]=%d\n",a[i]);
		//p=p->b[a[i]];
		if(p->b[a[i]]==NULL)
		{
			p->b[a[i]]=null();	
//			printf("teja\n");
		}
		//else
		//	printf("p->data=%d at head[%d]\n",p->data,a[i]);
		if(p->b[a[i]]->data==-1) 
		{
//			printf("haha\n");
				//printf("-1=visiting first time\n");
				if(i==length-1)
					p->b[a[i]]->data=length;
				else
					p->b[a[i]]->data=0;
		}
		else if(p->b[a[i]]->data==0) // 0 means already present
		{
//			printf("lala\n");
			//printf("0=already visited\n");
			if(i==length-1)
			{
				flag=1;
				return;
			}
		}
		else 
		{
//			printf("baba\n");
			flag=1;
			return;
		}
		p=p->b[a[i]];
//		printf("%d\n",p->b[a[i]]->data);
			//if(p==NULL)
				//p=null();
		i++;
	}
	return;
}
