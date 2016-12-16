#include<stdio.h>
int main()
{
	int i,n,t,a,in[100005],temp,b,l,r;
	scanf("%d",&n);
	int posdfs[100005]={0},posin[100005]={0};
		for(i=0;i<n;i++)
			{
				scanf("%d",&a);
			  posdfs[a]=i;
			}
		for(i=0;i<n;i++)
		{
			scanf("%d",&in[i]);
			posin[in[i]]=i;
		}
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d %d",&a,&b);
			l=posin[a];r=posin[b];
			if(posin[a]>posin[b])
			{	r=posin[a];l=posin[b];
			  temp=a;
				a=b;
				b=temp;
			}
			for(i=r;i>=l;i--)
			{
				if(posdfs[in[i]]<=posdfs[a])
					{
						printf("%d\n",in[i]);
						break;
					}
			}
		}
return 0;
}
