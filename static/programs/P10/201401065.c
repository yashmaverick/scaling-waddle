#include<stdio.h>
#include<stdlib.h>

int main()
{
	long long int N,n,fl=1,h=0,t=0,i,j,pfl=0,size=0;
	scanf("%d",&N);
	char **b;
	char c;
	b=(char **)calloc(N,sizeof(char *));
	if(N==0)
		return 0;
	while(1)
	{
		scanf("%c",&c);
		if(c=='Q')
			break;
		else if(c=='A')
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				if(fl==1)
				{
					b[t]=(char *)calloc(100,sizeof(char));
					if(t==N-1)
						fl=0;
				}
				scanf("%s",b[t]);
				size++;
				t=(t+1)%N;
				if(t==h)
					pfl=1;
			}
			if(pfl==1)
				h=t;
		}
		else if(c=='R')
		{
			scanf("%d",&n);
			if(n==0)
				continue;
			h=(h+n)%N;
			size-=n;
			pfl=0;
		}
		else if(c=='L')
		{
			if(size==0)
				continue;
			i=h;
			if(pfl==1)
				j=((t-1)>=0)?(t-1):(N-1);
			else
				j=t;
			//printf("%d %d\n",i,j);
			while(i!=j)
			{
				printf("%s\n",b[i]);
				i=(i+1)%N;
			}
			if(pfl==1&&i==j)
				printf("%s\n",b[i]);
		}
		//printf("%d\n",pfl);
	}
	return 0;
}
