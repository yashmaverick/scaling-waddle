#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MOD 1000000007
#define ll long long int

int compare (const void * a, const void * b)
{
  return ( *(ll*)a - *(ll*)b );
}

ll t,n,k,in[1010],a[1010][1010],flag=0,i,j,val=0;
ll * pItem;
char s[100100];

int main()
{
    scanf("%lld",&t);
    while(t--)
    {
    	scanf("%lld %lld",&n,&k);
    	for(i=0;i<n;i++)scanf("%s %lld",s,&in[i]);
    	qsort (in,n, sizeof (ll), compare);
    	for(i=0;i<n;i++)for(j=0;j<n;j++)if(i!=j)a[i][j]=in[i]+in[j];
    	flag=0;
    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<i;j++)
  			{
  				if(i!=j)
  				{
  					val=k-a[i][j];
  					pItem = (ll*) bsearch (&val, in, n, sizeof (ll), compare);
  					if(pItem==NULL)continue;
  					while(*pItem==*(pItem-1))pItem--;
  					while(*pItem+a[i][j]==k&&(pItem-in)==i&&(pItem-in)==j)pItem++;
  					if(*pItem+a[i][j]==k&&(pItem-in)!=i&&(pItem-in)!=j){printf("YES\n",*pItem);flag=1;break;}
  				}
  			}
  			if(flag)break;
    	}
    	if(!flag)printf("NO\n");
    }
    	
	return 0;
} 
