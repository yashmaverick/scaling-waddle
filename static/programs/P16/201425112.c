//Diameter of Binary tree

#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	while(n!=0)
	{
		int q;
		scanf("%d", &q);
		
		int i;
		int j=0;
		int k=1;
		
		for(i=0; i<q;)
		{
			i=i+k;
			j++;
			k=k*2;
		}
		
		int diam;
		
		if((i-q)==0)
		{
			diam=(j-1)*2;
		}
		else
		{
			if((k/2-(i-q))>(k/2)/2)
			{
				diam=(j-1)*2;
			}
			else
			{
				diam=j-1+j-2;
			}
		}
		
		printf("%d\n", diam);
		
		n--;
	}
	
	return 0;
}
