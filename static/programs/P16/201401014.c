#include<stdio.h>
int main()
{
	unsigned int n,q,i,height,flag;
	scanf("%u",&n);
	for(i=0;i<n;i++)
	{
		height=0;
		flag=0;
		scanf("%u",&q);
//		printf("%u\n",q);
		while(q>0)
		{
//			printf("%u ---q\n",q);
			if(q==2)
			{
				flag=1;
//				printf("%u --flag\n",flag);
			}
			height++;
//			printf("%u--height\n",height);
			q=q>>1;
		}
		height=height-1;
//		printf("%u --height\n",height);
		if(flag==1)
			printf("%u\n",(2*(height))-1);
		else
			printf("%u\n",(2*(height)));
	}
	return 0;
}
		

