#include<stdio.h>
#include<string.h>
/*typedef struct node
  {
  char b[101];
  }node;*/
int main()
{
	int n;
	scanf("%d ",&n);
	char a[n][101];
	char c;
	int head,tail,i,j,x;
	head=0;
	tail=0;
	while(1)
	{
		c=getchar();
		if(c=='Q')
			break;
		else if(c=='A')
		{
			scanf("%d ",&x);
			if(head==tail)
			{
				head=0;
				tail=0;
			}
			for(i=0;i<x;i++)
			{
				scanf("%s",a[tail%n]);
				if(tail>=n&&tail%n==head%n)			
					head++;	
				tail++;
			}
		}
		else if(c=='R')
		{
			scanf("%d ",&x);
			head=head+x;
		}
		else if(c=='L')
		{
			for(i=head;i<tail;i++)
				printf("%s\n",a[i%n]);
		}
	}
	return 0;
}
