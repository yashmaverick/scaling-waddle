#include<stdio.h>
int main()
{
	int n,l,k,j,i;
	int y=0;
	char a[10001][100];
	scanf("%d",&n);
	char c,x;
	scanf("%c",&x);
	int start=0,end=0;
	int flag=0;
	while(1)
	{
		scanf("%c%c",&c,&x);
		/*	if(c=='A')
			{
			int num;
			scanf("%d",&num);
			y=y+num;
			for(i=0;i<num;i++)
			{
			scanf("%s",a[end]);
			end++;
			if(end>n-1)
			{
			flag=1;
			end=0;
			}
			if(flag==1 && end-1==start || flag==1 && end==0 && start==n-1)
			{
			if(start<n-1)
			start++;
			else
			{
			start=0;
			}
			y--;
			}


			}
			scanf("%c",&x);
			}*/

		if(c=='A')
		{

			int num;
			scanf("%d",&num);

			for(i=0;i<num;i++)
			{
				scanf("%s",a[end]);
				end++;
				y++;
				if(end==n)
					end=0;
				
				if(end-1==start && end>0 && y==n+1)
				{
					y--;
					if(start<n-1)
						start++;
					else
						start=0;
				}
				if(end==0 && start==n-1 && y==n+1)
				{
					y--;
					start=0;
				}
			//	printf("start=%d, end=%d,y=%d\n",start,end,y);

			}
			scanf("%c",&x);
		}











		if(c=='R')
		{
			int num;
			scanf("%d",&num);
			y=y-num;
			start=start+num;
			if(start>=n)
				start=start%n;
			scanf("%c",&x);
		}
		if(c=='L')
		{
			//		printf("strings will be printed.\n");
			if(end>start)
			{
				for(i=start;i<end;i++)
					printf("%s\n",a[i]);
			}
			if(end<start)
			{
				for(i=start;i<n;i++)
					printf("%s\n",a[i]);
				for(i=0;i<end;i++)
					printf("%s\n",a[i]);
			}
			if(end==start && y>0)
			{
				for(i=start;i<n;i++)
					printf("%s\n",a[i]);
				for(i=0;i<end;i++)
					printf("%s\n",a[i]);
			}
		}
		if(c=='Q')
			break;
	}
	return 0;
}
