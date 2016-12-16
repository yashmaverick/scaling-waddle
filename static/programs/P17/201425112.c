//p17: jon snow and the white walker

#include <stdio.h>
//#define MAX 1000000
//#include <stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);

	int pt[100000];
	int it[100000];

	int i;
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &pt[i]);
	}

/*/debug
	printf("\n");
	for(i=0; i<n; i++)
	{
		printf("%d ", pt[i]);
	}
	printf("\n");
/*/
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &it[i]);
	}
	
/*/debug
	printf("\n");
	for(i=0; i<n; i++)
	{
		printf("%d ", it[i]);
	}
	printf("\n");
/*/

	int t;
	scanf("%d", &t);
	
	int jprev;
			
	while(t!=0)
	{
		int jon;
		scanf("%d", &jon);

		int wkr;
		scanf("%d", &wkr);

		//int joni=0;
		//int wkri=0;

		int flag=0;

		for(i=0; i<n; i++)
		{

			int j;
			jprev=n;

			if(it[i]==jon)
			{
				for(; i<n && it[i-1]!=wkr ; i++)
				{
//				printf("jon %d\n", i);
					for(j=0; j<jprev; j++)
					{
						if(pt[j]==it[i])
						{
							jprev=j;
						}
					}
				}
				break;
			}

			else if(it[i]==wkr)
			{
				for(; i<n && it[i-1]!=jon; i++)
				{
					for(j=0; j<jprev; j++)
					{
						if(pt[j]==it[i])
						{
							jprev=j;
						}
					}
				}
				break;
			}
		}

		printf("%d\n", pt[jprev]);

		t--;
	}

	return 0;
}