#include<stdio.h>
int main()
{
	int instr[100000],t,i,l;
	int max,m,diff,n;
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&instr[i]);
		}
		m=0;
		max=instr[n-1];
		for(i=n-1;i>=0;i--)
		{
			diff=max-instr[i];
			if(diff>m)
				m=diff;
			if(instr[i]>max)
				max=instr[i];
		}
		printf("%d\n",m);
	}
	return 0;
}
