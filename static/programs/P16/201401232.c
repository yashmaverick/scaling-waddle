#include<stdio.h>
int main()
{
	int testcases,quiery,index,ans;
	scanf("%d",&testcases);
	while(testcases--)
	{
		index=1;
		ans=0;
		scanf("%d",&quiery);
//		if(quiery==1)
//			printf("0\n");
//		else
//		{
			while(2*index<=quiery)
			{
				index=index<<1;
				ans++;
			}
			index=index>>1;
//			printf("index:%d  ans:%d\n",index,ans);
			if((2*index+index)>quiery)
				printf("%d\n",((2*ans)-(1)));
			else
				printf("%d\n",(2*ans));
//		}
	}
	return 0;
}

