#include<stdio.h>
int main()
{
	int n,no,i,j,k;
	char com;
	int start,end;
	scanf("%d",&n);
	n++;
	char ar[10001][101];
	scanf("%c",&com);
	start=0;
	end=0;
	while(com!='Q')
	{
		if(com=='A')
		{
			scanf("%d",&no);
			for(i=0;i<no;i++)
			{
				scanf("%s",ar[end]);
				if(end+1!=n)
				{
					if(end+1!=start)
						end++;
					else
					{
						end++;
						if(start+1!=n)
							start++;
						else
							start=0;
					}
				}
				else
				{
					if(start!=0)
						end=0;
					else
					{
						end=0;
						start++;
					}
				}
//				printf("%d%d\n",start,end);
			}
		}
		if(com=='R')
		{
			scanf("%d",&no);
			if(start+no<n)
				start=start+no;
			else
				start=start+no-n;
//			printf("%d%d\n",start,end);
		}
		if(com=='L')
		{
			i=start;
			while(i != end)
			{
				printf("%s\n",ar[i]);
				if(i+1!=n)
					i++;
				else
					i=0;
			}
		}
		scanf("%c",&com);
	}
	return 0;
}

