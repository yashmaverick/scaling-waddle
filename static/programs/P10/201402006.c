#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N,num=0,n,end,start,diff;
	scanf("%d",&N);
	char arr[N][100],func;
	end = 0;
	num = 0;
//	diff = end - num;
	while(1)
	{
		scanf("%c",&func);
		if(func == 'Q')
			break;
		else if(func == 'A')
		{
			scanf("%d",&n);
			num = (num+n);
			if(num > N)
				num = N;
			while(n--)
			{
				if(end==N)
					end=0;
				scanf("%s",arr[end]);
				end++;
			}
//			printf("num is %d, end is %d\n",num ,end);
		}
		else if(func == 'R')
		{
			scanf("%d",&n);
			num = num - n;
		}
		else if(func=='L')
		{
			start = end - num;
		//	if(diff == N)
		//		diff = 0;
			if(start < 0)
				start = start + N;
			
			int limit=num;
			while(limit--)
			{
				if(start == N)
					start = 0;
				printf("%s\n",arr[start]);
				start++;
			}	
//			printf("start is %d\n",start);
		}
	}
	return 0;
}
