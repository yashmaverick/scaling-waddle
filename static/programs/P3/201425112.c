//bear bull

#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	
	while(t>0)
	{
		int l;
		scanf("%d", &l);
		
		int arr[100000];
		
		int i;
		for (i=0; i<l; i++)
		{
			scanf("%d", &arr[i]);
		}
	
		int min=arr[0];
		int mdif=0;
		int dif;
		
		for (i=0; i<l; i++)
		{
			if (arr[i]<min)
			{
				min=arr[i];
			}
			else if (arr[i]>min)
			{
				dif=arr[i]-min;
				
				if (dif>mdif)
				{
					mdif=dif;
				}
			}
		}
		
		printf("%d\n", mdif);
	
		t--;
	}
	
	return 0;
}
