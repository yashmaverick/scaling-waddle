#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct linkedlist
{
	int data;
	struct linkedlist *next[12];
}node;
int main()
{	
	node *head[100];
	int test,t,n,p,d,i,j,len,flag=0;
	char s[100];
	scanf("%d", &test);
	for(t=0;t<test;t++)
	{
	int f;
	for(f=0;f<10;f++)
		{
			head[f]=(node *)malloc(sizeof(node));
			int g;
				for(g=0;g<10;g++)
					head[f]->next[g]=NULL;
			head[f]->next[10]=NULL;
		}
		flag=0;
		scanf("%d", &n);
		for(i=0;i<n;i++)
		{
			int k;
			scanf("%s",s);
			len=strlen(s);
			/*head[s[0]-'0']->data=s[0]-'0';
			for(k=0;k<10;k++)
				head[s[0]-'0']->next[k]=NULL;*/
			node *q;
			q=malloc(sizeof(node));
			int pop=1;
			q=head[s[0]-'0'];
			if((q->next[10]!=NULL&&q->next[10]->data==-1))
				flag=1;
			if(len==1)
			{
				int l;
				for(l=0;l<10;l++)
					if(q->next[l]!=NULL)
						flag=1;
			}
			for(j=1;j<len;j++)
			{
				d=s[j]-'0';
				if(q->next[d]==NULL)
				{
					pop=0;
				//printf("Here for %d\n",d);
					node *q1;
					q1=(node *)malloc(sizeof(node));
					q1->data=d;
					for(k=0;k<12;k++)
						q1->next[k]=NULL;
					q->next[d]=q1;
					/*if(j==len-1)
					  {
					  printf("Making\n");
					  node *p;
					  p=(node *)malloc(sizeof(node));
					  p->data=-1;
					  q->next[10]=p;
					  }*/
					q=q->next[d];
				}
				else
				{
					q=q->next[d];
					//printf("Already and data:%d\n",q->data);
					if(q->next[10]!=NULL&&q->next[10]->data==-1)
					{
						flag=1;
					}
					else if(j==len-1&&pop==1)
					{
						flag=1;
					}
				}
			}
			//printf("Data:%d\n",q->data);
			node *p;
			p=(node *)malloc(sizeof(node));
			p->data=-1;
			for(k=0;k<12;k++)
				p->next[k]=NULL;
			q->next[10]=p;

		}
		if(flag==1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
