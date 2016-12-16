#include<stdio.h>

int main()
{

char s[10005][105],c;
int i,n,m,size=0,start=0;

	for(i=0;i<10005;i++)
		s[i][0]='\0';

	scanf("%d",&n);

	while(1)
	{
		scanf("%c",&c);

		if(c=='A')
		{
//		printf("start=%d size=%d\n",start,size);
			scanf("%d",&m);

			for(i=0;i<m;i++)
			{
				scanf("%s",s[(start+i+size)%n]);

			//	size++;
		
			}
				size+=m;
				

				if(size>n) { start=(start+size); size=n; }

				start%=n;


					

		}

		else if(c=='R')
		{

	
//		printf("start=%d size=%d\n",start,size);
			scanf("%d",&m);

			if(m!=size)
			{
				for(i=0;i<m;i++)
				{
					s[start%n][0]='\0';
			
					start++;  

					size--;

					start%=n;

					if(size<0) size=0;
				}
			}

			else
			{
				for(i=0;i<m;i++)
				{
					s[start%n][0]='\0';
			
					start++;  

					size--;

					start%=n;

					if(size<0) size=0;
				}

				start=0; size=0;
			}


		}

		else if(c=='L')
		{
//		printf("start=%d size=%d\n",start,size);
			for(i=0;i<size;i++)
			{
//				if(s[(start+i)%n][0] != '\0')

					printf("%s\n",s[(start+i)%n]);
			}

		}

		else if(c=='Q')

			break;


		
		
	}


	return 0;
}
