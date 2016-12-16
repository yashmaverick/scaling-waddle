#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
	int value;
	struct node *a[11];
}node;

int main()
{
	int t,h;
	scanf("%d",&t);
	for(h=0;h<t;h++)
	{
		int n,i,l,ans=0;
		char b[10];
		scanf("%d",&n);
		node *head=(node*)malloc(sizeof(node));
		for(i=0;i<n;i++)
		{
			int j;
			node *temp=head;
			scanf("%s",b);
			if(ans==1)
				continue;
			l=strlen(b);
			for(j=0;j<l;j++)
			{
				node *temp1;
				if(temp->a[b[j]-'0']==NULL)
				{
					temp1=(node*)malloc(sizeof(node));
					temp->a[b[j]-'0']=temp1;
					temp=temp->a[b[j]-'0'];
					temp->value=0;
					if(j==l-1)
						temp->value=1;
//					printf("1\n");
				}
				else
				{
					int ha;
//					printf("0\n");	
					if(temp->a[b[j]-'0']->value==1)
					{
						ans=1;
						break;
					}
					for(ha=0;ha<10 && j==l-1;ha++)
					{
						if(temp->a[b[j]-'0']->a[ha]!=NULL)
						{
							ans=1;
							break;
						}
					}
					if(ans==1)
						break;
					temp=temp->a[b[j]-'0'];
				}
			}
		}
		if(ans==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
