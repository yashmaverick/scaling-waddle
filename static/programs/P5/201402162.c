#include<stdio.h>
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
		int n,k,i,j,l,m,s,ag=0,flag=0;
		scanf("%d%d",&n,&k);
		char ls[100000];
		int score[n+1];
		for(i=0;i<n;i++)
		{
			j=0;
			while(1)
			{
				scanf("%c",&ls[j]);
				if(ls[j]==' ')
					break;
				j++;
			}
			scanf("%d",&l);
			score[i]=l;
		}
		 qsort(score, n, sizeof(int), cmpfunc);		
		int a,b,c;
		for(a=0;a<n-2;a++)
		{
			b=a+1;
			c=n-1;
			s=score[a]+score[b]+score[c];
			ag=0;
			while(ag!=1)
			{
			if(s==k)
			{
				flag=1;
				break;
			}
			else if(s<k)
			{	
				if(b+1<c)
				b++;
				else 
					ag=1;
			}
			else
			{
				if(c-1>b)
				c--;
				else
					ag=1;
			}
			 s=score[a]+score[b]+score[c];
			 if(s==k)
			 {
				 flag=1;
				 break;
			 }
			}
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
