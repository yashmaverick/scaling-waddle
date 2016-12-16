#include<stdio.h>
int main()
{
	int size,total=0;
	scanf("%d\n",&size);
	char s[size][100],c;
	int k,cu=0,start=0,i;
	c=getchar();
	while(c!='Q')
	{
		if(c=='A')
		{
			scanf("%d",&k);
			if(total+k>size)
				start+=total+k-size;
			for(i=0;i<k;i++)
			{

				scanf(" %s",s[cu]);
				cu++;
				cu%=size;
			}
			start%=size;
			total+=k;
			if(total>size)
				total=size;
		}
		else if(c=='R')
		{
			scanf("%d",&k);
			start+=k;
			start%=size;
			total-=k;
		}
		else if(c=='L')
			for(i=0;i<total;i++)
				printf("%s\n",s[(i+start)%size]);
//		printf("total= %d start=%d cu=%d\n",total,start,cu);
		c=getchar();
		c=getchar();
	}
	return 0;
}
