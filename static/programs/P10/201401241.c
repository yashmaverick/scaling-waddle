#include<stdio.h>
#include<string.h>
int main()
{
	char c;
	int i,j,n,no=0,end=-1,size,start;
	int s;
	char a[10010][105];
	scanf("%d",&size);
	while(1)
	{
		scanf("%c",&c);
		if(c=='A')
		{
			scanf("%d",&n);
			no=no+n;
			if(no>size)
				no=size;
			s=0;
			while(s<n)
			{
				end++;
				if(end==size)
					end=0;
				scanf("%s",a[end]);
				//printf("AAAAAAAAAAAAAA:%s\n",a[end]);
				s++;
			}
			int y=0;
			//while(y<size+2)
			//{
			//	printf("assdsa:%s\n",a[y]);
			//	y++;
			//}
			//printf("dlasdjfsdkjfs:%d\n",end);
		}

		else if(c=='R')
		{

			scanf("%d",&n);
			no-=n;
			//printf("YY%d\n",no);
//			if(no>n)
//				no=n;
		}

		else if(c=='Q')
		{
			break;
		}
		else if(c=='L')
		{
			//printf("dlasdjfsdkjfs:%d\n",end);
			int m;
			m=1;
			for(start=end-no+1;m<=no;m++)
			{
				if(start<0)
					start=size+start;
				if(start==size)
					start=0;
				printf("%s\n",a[start]);
				start++;
			}
			//printf("%s\n",a[start]);
		}
	}
	return 0;
}





