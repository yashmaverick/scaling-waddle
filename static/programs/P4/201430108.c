#include<stdio.h>
#include<string.h>
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[100001];
		scanf("%s",s);
		long long int map[100001],i,j=0,m=0;
		int l=strlen(s);
		map[0]=0;
		int p=1;
		for(i=0;i<l;i++)
		{
			if(s[i]=='J')
			j++;
			if(s[i]=='M')
			m++;
			if(s[i]=='R')
			{
				j--;
				m--;
			}
			map[p]=(j*100000)+m;
			//map[p]= (j>= m )? (j * j + j + m ): (j + m * m);
			//map[p]=(j + m) * (j + m + 1) / 2 + j;
			p++;
		}
		qsort(map,p,sizeof(long long int),cmpfunc);
	
		long long int sum=0;
		int c=0,flag=0;
		for(i=0;i<p-1;i++)
		{
			if(map[i]==map[i+1])
				{
					c++;
					flag=1;
				}
			else
			{
				for(;c>0;c--)
					sum+=c;
				c=0;
				flag=0;
			}
		}
		if(flag==1)
		{
			for(;c>0;c--)
					sum+=c;
		}
			printf("%lld\n",(sum) );
	}
	return 0;
}
	