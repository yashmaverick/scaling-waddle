#include<stdio.h>
#include<string.h>
char s[10011][110];
int main()
{
	int n,N,i,j,k,read=0,end=0,l,check,p=0,t,total;
	char waste,c;
	scanf("%d",&N);
	scanf("%c",&waste);
	if(N==0)
	{
		scanf("%c",&c);
		while(c!='Q')
		{
			if(c=='A')
			{
				scanf("%c",&waste);
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					scanf("%s",s[0]);
				}
			}
			if(c=='R')
			{
				scanf("%c",&waste);
				scanf("%d",&n);
			}
			scanf("%c",&c);
		}
	}
	else
	{
		scanf("%c",&c);
		k=0;read=0;end=0;total=0;p=0;
		while(c!='Q')
		{
			if(c=='A')
			{
				scanf("%c",&waste);
				scanf("%d",&n);
				//total=total+n;
				//if(total>N)
				//	total=N;
				for(i=0;i<n;i++)
				{
					scanf("%s",s[k%N]);
					k++;
					//if(k>N)
					//{
					//	p=1;
					//}
					total++;
					if(total>N)
					{
						read++;
						read=read%N;
					}
				}
				if(total>N)
					total=N;
				if(N-read<total)
					end=total+read-N-1;
				else
					end=total+read-1;
				//printf("read:%d end:%d total:%d k:%d\n",read,end,total,k);
			}
			if(c=='L')
			{
				if(end>=read && total>0)
					for(i=read;i<=end;i++)
						printf("%s\n",s[i]);
				if(end<read)
				{
					for(i=read;i<N;i++)
						printf("%s\n",s[i]);
					for(i=0;i<=end;i++)
						printf("%s\n",s[i]);
				}
				//printf("read:%d end:%d total:%d\n",read,end,total);
			}
			if(c=='R')
			{
				scanf("%c",&waste);
				scanf("%d",&n);
				if(total>n)
				{
					read=read+n;
					if(read>=N)
						read=read%N;
					total=total-n;
					//if(N-read<total)
					//	end=total+read-N-1;
					//else
					//	end=total+read-1;
				}
				else
				{
					//printf("ASD");
					read=0;
					end=0;
					k=0;
					total=0;
				}
				//printf("read:%d end:%d total:%d\n",read,end,total);
			}
			scanf("%c",&c);
		}
	}
	return 0;
}
