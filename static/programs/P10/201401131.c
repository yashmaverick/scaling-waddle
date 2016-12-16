#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
typedef struct aos
{
	char *c;
}buffer;
int main()
{
	ll n,ns,start=0,end=0,ne=0,i,j=0,k,d;
	char m;
	scanf("%Ld",&n);
	buffer a[n+100];
	for(i=0;i<n;i++)
		  a[i].c=(malloc(sizeof(char)*150));
	scanf("%c",&m);
	//scanf("%c",&m);
	while(m!='Q')
	{

		 if(m=='A')
		{
			/*if(end==n-1)
			end=0;
			if(start==n-1)
			start=0;
			scanf("%Ld",&ns);
			if(end + ns < n)
			{
				for(i=end;i<end+ns;i++)
					scanf("%s",a[i].c);
				ne=ne+ns;
				end=end+ns;
				start=0;
			}
			else 
			{
				k=n-end;
				for(i=end;i<n;i+=1)
					scanf("%s",a[i].c);
					end=0;
					j=i;
				for(i=n;i<ns-k;i++)
				{
					scanf("%s",a[i].c);
					if(start==n-1)
						start=0;
					start=start+1;
					end=end+1;
				}
			}*/
			scanf("%Ld",&ns);
			while(ns--)
			{
				if(ne < n)
				{
					scanf("%s",a[j].c);
					ne=ne+1;
					j=(j+1)%n;
				}
				else
				{	
					j=j%n;
					start=(start+1)%n;
					scanf("%s",a[j].c);
					ne=n;
					j=j+1;
					//printf("%lld\n", j);
				}
			}
		}
		else if(m=='L')
		{	
			if(ne!=0)
			{
			if(j > start)
			{
				for(i=start;i<j;i++)
					printf("%s\n",a[i].c);
			}
			else
			{
				for(i=start;i<n;i++)
					printf("%s\n",a[i].c);
				for(i=0;i<j;i+=1)
					printf("%s\n",a[i].c);
			}
			}
		}	
		else if(m=='R')		
		{
			scanf("%Ld",&d);
			for(i=0;i<d;i++)
			{	
				if(ne!=0)
				{
				if(start==n-1)
					start=0;		
				else
					start=start+1;
				ne=ne-1;
				if(ne==0)
				{
					start=0;
					j=0;	
					break;
				}
				}
			}	
		}

scanf("%c",&m);
	}	
return 0;
	
}

