#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int w,i;
		scanf("%d",&w);
		if(w==1)
			printf("0\n");
		else
		{
			int j;
			j=0;
			for(i=1;i<w;i++)
			{
				if(w>=pow(2,i))
					j++;
				else break;
			}
			if(w<(3*pow(2,j-1)))
				printf("%d\n",(2*j)-1);
			else
				printf("%d\n",(2*j));
		}
	}
	return 0;
}
