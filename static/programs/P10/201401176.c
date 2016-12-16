#include<stdio.h>
int main()
{
	int i,k=0,n,end=0,req,c,re,sz=0;
	char a[10001][101];
	char ch;
	scanf("%d",&n);
	c=getchar();
	while(1)
	{
		scanf("%c",&ch);
		//printf("p ");
		if(ch=='A'||ch=='R')
			scanf("%d",&req);
		if(ch=='A')
		{
			c=getchar();
			//	if(k==n)
			//		k=0;
			while(req)
			{			
				scanf("%s",a[end]);
				sz++;
				if(sz>n)
				{
					sz=n;
					k=(k+1)%n;
				}
				end=(end+1)%n;
				req--;
			}
		}
		if(ch=='R')
		{
			c=getchar();
			while(req)
			{
				if(sz)
				{
					sz--;
					k=(k+1)%n;
				}
				req--;
			}
		}
		if(ch=='L')

		{
			c=getchar();
			if(sz)
			{
				i=k;
				if(k>=end)
				{
					while(i<n)
					{
						printf("%s\n",a[i]);
						i++;
					}
					i=0;
					while(i<end)
						printf("%s\n",a[i++]);
				}
				else
				{
					while(i<end)
						printf("%s\n",a[i++]);
				}
			}
		}
		if(ch=='Q')
			break;
	}
	return 0;
}
