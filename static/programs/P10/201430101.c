//GABBAR STUDIOWORKS
//01-03-2015
//FINAL ATTEMPT
#include<stdio.h>
int main()
{
	char arr[10001][101];
	char b[101];
	int size,k,n,i;
	int head=0;
	int cur=0;
	int op=0;
	scanf("%d",&size);
	while(3)
	{
		getchar();
		k=getchar();
		if(k=='A')
		{

			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				if(op>=size)
					head++;
				if(op<size)
				op++;

				scanf("%s",arr[cur]);
				cur++;
				cur=cur%size;
				//	if(op>=size)
				//		head++;
				head=head%size;

			}

		}
		else if(k=='R')
		{
			scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					head++;
					head=head%size;
					op--;
					op=op%size;
				}
		}
		else if(k=='L')
		{
				if(cur>head)
				{
					for(i=head;i<cur;i++)
					{
						printf("%s\n",arr[i]);
					}
				}
				else if(head>=cur && op!=0)
				{
					for(i=head;i<size;i++)
						printf("%s\n",arr[i]);
					for(i=0;i<cur;i++)
						printf("%s\n",arr[i]);
				}
		}	
		else
			break;
	}
	return 0;
}




