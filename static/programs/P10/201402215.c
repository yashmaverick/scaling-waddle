#include<stdio.h>
#include<string.h>
int main()
{
	int no,end=0,start=0,flag1=0;
	char x;
	scanf("%d",&no);
	char s[10004][101];
	int n,i,j,flag=0;
	for(i=0;i<10004;i++)
	{
		s[i][0]='@';
	}
	scanf(" %c",&x);
	while(1)
	{
		if(x == 'Q')
			break;
		if( x == 'A'){
			scanf("%d",&n);
			if(end-start+n>no)
				start+=end-start+n-no;
			for(i=0;i<n;i++)
			{	
				//if(end-start+1+n>no)
				//	start+=end-start+1+n-no;
				scanf(" %s",s[end%no]);
				end++;
				//		printf("%d %d\n",start%no,end%no);
			}
		}
		if( x=='R')
		{	
			scanf("%d",&n);
			start+=n;

			//		printf("%d %d\n",start%no,end%no);
		}
		if( x=='L')		
		{		
				for(j=start;j<end;j++)
				{
						printf("%s\n",s[j%no]);
				}
		}

		x=getchar();
	}
	return 0;
}
