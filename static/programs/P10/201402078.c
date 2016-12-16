#include<stdio.h>
#include<string.h>
int main()
{
	int i,n;
	char c,a[1000][100],s[100];
	int start=-1,end=-1,t,count,flag;
	scanf("%d",&n);
	getchar();
	scanf("%c",&c);
	count=0;
	while(c!='Q')
	{
		if(c=='A')
		{
			scanf("%d",&t);
			for(i=0;i<t;i++)
			{
				//	printf("%d %d \n",start,end);
				if (start==-1)
				{
					start=end=0;
					scanf("%s",a[end]);
					//	printf("scanned\n");
				}
				else
				{
					if(start==end+1)
						start++;
					start=start%n;
					if (end==n-1)
					{	
						end=0;
						if(start==0)
							start=1;
					}
					else
						end++;
					scanf("%s",a[end]);
				}
			}
			//		printf("%d %d\n",start,end);
		}
		//printf("ended\n");
		if (c=='R')
		{
			scanf("%d",&t);
			for(i=0;i<t;i++)
			{
				if(start==end)
				{
					start=end=-1;
					break;
				}
				else
				{
					count--;
					if(start==n)
						start=0;
					else
						start++;
				}
				start=start%n;
			}
		}
		else if(c=='L')
		{
			//printf("%d %d\n",start,end);
			if(start!=-1&&end!=-1)
			{
			for(i=start;i!=end;i=(i+1)%n)
				printf("%s\n",a[i]);
			printf("%s\n",a[end]);
			}
		}
		getchar();
		scanf("%c",&c);
	}
	return 0;
}

