#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{

	int vis[10];
	struct node *ar[10];

}node;
int main()
{
	node *head;
	char a[13];
	int number;
	scanf("%d",&number);
	while(number--)
	{
		head=malloc(sizeof(node));
		int o;
		for(o=0;o<=9;o++)
			head->vis[o]=0;
		int flag=0;
		int t;
		scanf("%d",&t);
		scanf("%s",a);
		int l=strlen(a);
		o=0;
		node *temp=head;
		while(o<l)
		{	
			int c=a[o]-'0';
			temp->ar[c]=malloc(sizeof(node));
			temp->vis[c]=1;
			int h=0;
			for(;h<=9;h++)
				temp->ar[c]->vis[h]=0;
			temp=temp->ar[c];
			o++;
		}
		t--;
		while(t--)
		{

			int i=0;
			scanf("%s",a);
			if(flag==0)
			{
				int l=strlen(a);
				node *temp=head;
				int c;
				int x=0;
				while(i<l)
				{
					c=a[i]-'0';
					if(i==l-1)
					{
						if(temp->vis[c])
						{
							flag=1;
							break;
						}
					}
					if(!temp->vis[c])
					{
						int tf=0;
						int j=0;
						for(j=0;j<=9;j++)
						{
							if(temp->vis[j]==1)
							{	
								tf=1;
								break;
							}
						}
						if(tf==1 )
						{
							flag=0;
							x=1;
						}
						if(tf==0 && x==0)
							flag=1;
						temp->ar[c]=malloc(sizeof(node));
						temp->vis[c]=1;
						int h=0;
						for(;h<=9;h++)
							temp->ar[c]->vis[h]=0;
					}

					temp=temp->ar[c];
					i++;

				}
			}
		}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}












