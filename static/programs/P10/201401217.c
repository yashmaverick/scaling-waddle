#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N,app,insert,shift,place,i,rem,var;
	char r;
	scanf("%d",&N);
	getchar();
	char *s[N];
	for(i=0;i<N;i++)
		 s[i]=(char *)malloc(110*(sizeof(char)));
	place=0;
	while(1)
	{
		scanf("%c",&r);
		//getchar();
		//printf("dgrfgr%c\n",r);
		if(r=='Q')
			return 0;
		else if(r=='A')
		{
			scanf("%d",&app);
			if(app>N)
			{
				while(app-N)
				{
					scanf("%s",&s[0]);
					app--;
				}
				place=0;
			}
			if(app>(N-place))
			{
				shift=app+place-N;
				i=0;
				while((i+shift)<place)
				{
					s[i]=s[i+shift];
					i++;
				}
				place=place-shift;
			}
			var=app;
			for(i=place;app!=0;i++)
			{
				app--;
				scanf("%s",&s[i]);
				if(app==0)
					place=place+var;
			}
		}
		else if(r=='L')
		{
			if(place!=0)
			{
				for(i=0;i<place;i++)
					printf("%s\n",&s[i]);
			}
		}
		else
		{
			scanf("%d",&rem);
			shift=rem;
			for(i=0;;i++)
			{
				s[i]=s[i+shift];
				if((i+shift)==place)
				{
					place=place-shift;
					break;
				}
			}
		}
		getchar();
	}
	return 0;
}
