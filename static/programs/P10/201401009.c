#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	char a[105];
}node;
int main()
{	int n,start=0,end=-1,total=0;
	scanf("%d",&n);
	node s[n];
	while(1)
	{

		char q;
		scanf("%c",&q);
		if(q=='Q')
			break;
		else if(q=='A')
		{
			int m,c;
			scanf("%d",&m);
//			total+=m;
			while(m--)
			{
				end++;
				if(end==n)
					end=0;
				total++;
				if(start-c==1 && total!=1)
				{
					start++;
					if(start==n)
						start=0;
					total--;
				}
				scanf("%s",s[end].a);
				c=end;
				if(c==n-1)
					c=-1;
				//printf("%d %d %d %d\n",start,end,total,c);
			}
		}
		else if(q=='R')
		{
			int w;
			scanf("%d",&w);
			while(w--)
			{
				total--;
	//			free(s[start].a);
				start++;
				if(start==n)
					start=0;
			}
		}
		else if(q=='L')
		{
			int j,o;
			j=total;
	//		printf("\n%d %d %d\n",start,end,total);
			while(j)
			{	
				o=(total-j+start)%n;
				printf("%s\n",s[o].a);
				j--;
			}
		}
	}
//	free(s);
	return 0;
}
				

