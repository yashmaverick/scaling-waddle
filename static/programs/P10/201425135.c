#include<stdio.h>
int main()
{
	int n,i,first=0,end=-1,n1,j=0,loop=0,size=0;
	scanf("%d",&n);
	char a[n+1][100+1],c;
	scanf("%c",&c);
	//scanf("%c",&c);
	while(c!='Q')
	{
		if(c=='A')
		{
		//	printf("stat:%d   rend:%d\n",first,end);
			scanf("%d",&n1);
			while(n1--) 
			{
				if(size>=n)
					{
					first=(first+1)%n;
					size--;
					}
				scanf("%s",a[j]);
				size++;
				j++;
				end++;
				end=end%n;
				j=j%n;
			}

		//	printf("//stat:%d   rend:%d\n",first,end);

		}
		else if(c=='L')
		{
			//			printf("end:%d  start:%d\n",end,first);
			if(size==0)
			{
			}
			else if(end>=first)
			{
				for(i=first;i<=end;i++)
				{	
					//pr//intf("end:%d\n",end);
					printf("%s\n",a[i]);
				}
			}
			else
			{
				for(i=first;i<n;i++)
				{
					//	printf("end:%d\n",end);
					printf("%s\n",a[i]);
				}
				for(i=0;i<=end;i++)
				{
					//	printf("end:%d\n",end);
					printf("%s\n",a[i]);
				}
			}
		}
		else if(c=='R')
		{
			scanf("%d",&n1);
		//	printf("size:%d  remove:%d\n",size,n1);
			first=(first+n1);
			if(size<=n1)
			{
				first=0;
				end=-1;
				j=0;
			}
			size=(size-n1);
			if(size<0)
			size=0;
		//	printf("size after change:%d\n",size);
			first=first%n;	
		}
		scanf("%c",&c);
	}
	return 0;
}
