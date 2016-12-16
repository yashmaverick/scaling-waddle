#include<stdio.h>
int main()
{
	int n,start,end,x,y,s,z,t,i,temp,bsize=0,ch=0;
	char op;
	scanf("%d",&n);
	char A[n][100];
	start=0,end=0,bsize=0;
	while(1)
	{
		scanf("%c",&op);
		if(op=='A')
		{
			scanf("%d",&t);
			for(i=0;i<t;i++)
			{
				scanf("%s",A[end++]);
				bsize++;
				if(bsize>n)
				{
					bsize=n;
					start=(start+1)%n;
				}
				if(end==n)
				{
					end=end%n;
				}
			}
		}
		else if(op=='R')
		{
			scanf("%d",&t);
			if(t==n)
			{
				start=0,end=0,bsize=0;
			}
			else
			{
				bsize-=t;
				start=(start+t)%n;
			}
		}
		else if(op=='L')
		{
		//	printf("%d\n",start);
			y=0;
			x=start;
			while(y<n)
			{
				if(bsize!=n && x==end)
					break;
				printf("%s\n",A[x]);
				x=(x+1)%n;
				y++;		
			}
		}
		else if(op=='Q')
			break;
	}
	return 0;
}
