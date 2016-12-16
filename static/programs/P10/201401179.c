#include<stdio.h>
#include<string.h>
#define cout(n) printf("%d\n",n)
#define cin(n) scanf("%d", &n)

int main()
{
	char CircularBuffer[10000][10],Operation; 
	int i,startpointer=0,endpointer=0,Total,N;

	//scanf("%d",&Total);
	cin(Total);
	while(1)
	{
		scanf("%c",&Operation);
		if(Operation=='A')
		{
			scanf(" "); // scaning the space btw A  and the number
			cin(N);
			//printf("%d\n",N);
			for(i=0;i<N;i++)
			{
				scanf("%s", CircularBuffer[(startpointer+endpointer)%Total]);
				/*if(endpointer==Total)
					startpointer=(startpointer+1)%Total;
				else if(endpointer!=Total)
						endpointer++;*/

				(endpointer==Total) ? (startpointer=(startpointer+1)%Total) : endpointer++ ;

			}
		}

		else if(Operation=='L')
			for (i = 0; i <endpointer ; i++)
				printf("%s\n",CircularBuffer[(startpointer+i)%Total]);


		else if(Operation=='Q')
			break;	

		else if(Operation=='R')
		{
			scanf(" "); // scaning the space btw R  and the number
			cin(N);
			//printf("working\n");
			endpointer=endpointer-N;
			startpointer=(startpointer+N)%Total; // skiping the 'N' numbers and thus moving the startpointer ahead (but not deleting the elements!)
		}

	}
	return 0;
}