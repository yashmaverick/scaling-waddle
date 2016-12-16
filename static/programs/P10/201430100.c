#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	getchar();

	char buffer[n][104];
	int start=-1,end=0,count=0;

	//printf("start:%d count: %d end: %d\n",start,count,end);

	char c;
	while((c=getchar())!='\n')
	{

		if(c=='Q') break;

		else if(c=='A')
		{

			int a;
			scanf("%d",&a);
			getchar();

			int i;
			for(i=0;i<a;i++)
			{
				count++;
				if(count>n) count=n;

				char d;
				int j=0;
				while((d=getchar())!='\n')
				{
					buffer[end][j]=d;
					j++;
				}
				buffer[end][j]='\0';
				if(end==start && count>=n) start=(start+1)%n;
				end++;
				end=end%n;
			}
			if(start==-1) start=0;
		}
		else if(c=='R')
		{
			getchar();
			int r;
			scanf("%d",&r);
			getchar();
			count-=r;
			start=(start+r)%n;

			if(count==0) { start=-1; end=0; }
		}
		else if(c=='L')
		{
			getchar();

			int i;
			if(start!=-1)
			for(i=0;i<count;i++)
			{
				printf("%s\n",buffer[(start+i)%n]);
			}
		}	
	//	printf("start:%d count: %d end: %d\n",start,count,end);

	}
	return 0;
}