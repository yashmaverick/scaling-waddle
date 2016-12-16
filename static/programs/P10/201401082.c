#include<stdio.h>
int main()
{
	int i,n,tail=-1,head=0,p,c;
	scanf("%d",&n);
	getchar();
	char a[n][101],q;
	while(1)
	{
		scanf("%c",&q);
		if(q=='A')
		{
			scanf("%d",&p);
			for(i=0;i<p;i++)
			{
				c=tail;
				tail=(tail+1)%n;
				if(tail==head && c!=-1)
					head=(head+1)%n;
				scanf("%s",a[tail]);
			}
		}	
		if(q=='R')
		{
			scanf("%d",&p);
			for(i=1;i<=p;i++)
			{
				head=(head+1)%n;
				if(head==(tail+1)%n)
				{
					head=0;
					tail=-1;
					break;
				}
			}
		}
		if(q=='L')
		{
			if(head<=tail)
			{
				for(i=head;i<=tail;i++)
					printf("%s\n",a[i]);
			}
			else if(tail!=-1)
			{
				for(i=head;i<n;i++)
					printf("%s\n",a[i]);
				for(i=0;i<=tail;i++)
					printf("%s\n",a[i]);
			}
		}
		if(q=='Q')
			break;
	}
	return 0;
}
