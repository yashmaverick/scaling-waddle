#include<stdio.h>
typedef long long int z; 

	long long int p[100000];
	long long int q[100000];
	long long int r[100000];
	long long int s[100000];
	long long int* c;
	long long int* d;
	long long int m,n,w,res=0;
void lexograph(long long int p[100000],long long int s[100000],long long int* c,long long int* d,z m,z v)
{
	long long int u,h;
	if(d-c==0){
				for(u=v;u<m;u++)
		{
			*d=p[u];
			lexograph( q,s, c,(d+1),n,u);

		}
	}
	if(d-c==1)
	{
		for(u=v;u<m;u++)
		{
			*d=p[u];
			lexograph(r,s,c,(d+1),w,u);
		}
	}
	if(d-c==2)
	{
		for(u=v;u<m;u++)
		{
			*d=p[u];
			d=d-2;
			/*for(h=0;h<=2;h++)
			{
				/*if(h!=2){
				printf("%d ",*d);
				d++;}
				if(h==2){
					printf("%d",*d);
					printf("\n");
				}*/
				if(*d<=*(d+1))
				{
					if((*(d+1))<=(*(d+2)))
						res++;
				}
				d=d+2;

			
		}
	}
	
}
int main()
{
	long long int t,l,k;
	scanf("%lld",&t);
	for(l=0;l<t;l++)
	{
		
		
			scanf("%lld",&m);
			for(k=0;k<m;k++)
			{
				scanf("%lld",&p[k]);
			}
			c=&s[0];
			d=&s[0];
			scanf("%lld",&n);
			for(k=0;k<n;k++)
			{
				scanf("%lld",&q[k]);
			}
			scanf("%lld",&w);
			for(k=0;k<w;k++)
			{
				scanf("%lld",&r[k]);
			}
			lexograph(p,s,c,d,m,0);
			printf("%lld\n",res);

		

	}
	return 0;
}
