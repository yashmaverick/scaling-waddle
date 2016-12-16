#include<stdio.h>
int main()
{	int N,n,count=0,start=0,end=0,i;
	scanf("%d",&N);
	char a[N+20][110],ch;
	while(1)
	{
		scanf("%c",&ch);
		if(ch=='Q')
			break;
		if(ch=='A')
		{
			scanf("%d",&n);
			while(n--)
			{
				if(count<N)
				{
					scanf("%s",a[end]);
					count++;
					end++;
					end=end%N;
				}
				else
				{
					start++;
					start=start%N;
					end=end%N;
					scanf("%s",a[end]);
					count=N;
					end++;
				}
			}		
		}
		else if(ch=='R')
		{
			scanf("%d",&n);
			while(n--)
			{
				if(count!=0)
				{
					if(start==N-1)
						start=0;
					else
						start++;
					count--;
					if(count==0)
					{
						start=0;
						end=0;
						break;
					}
				}
			}

		}
		else if(ch=='L')
		{
			if(count!=0)
			{
				if(end>start)
				{
					for(i=start;i<end;i++)
						printf("%s\n",a[i]);

				}
				else
				{
					for(i=start;i<N;i++)
						printf("%s\n",a[i]);
					for(i=0;i<end;i++)
						printf("%s\n",a[i]);
				}
			}
		}
	}
	return 0;
}
