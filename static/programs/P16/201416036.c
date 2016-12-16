#include<stdio.h>
int main()
{
	int i, n, p, score=1;

	// scan test cases

	scanf("%d",&n);

	// test cases loop

	for(i=0;i<n;i++)
	{
		score = 1;
		scanf("%d",&p);
		if(p!=1)
		{
			while(p>3)
			{
				p = p/2;
				score++;
			}
			if(p==2)
			{
				score = score+score-1;
				printf("%d\n", score);
			}
			if(p==3)
			{
				score = score+score;
				printf("%d\n", score);
			}
		}
		if(p==1)
			printf("0\n");
	}
	return 0;
}
