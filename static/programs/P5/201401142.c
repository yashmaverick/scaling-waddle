#include<stdio.h>
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int x[1000];
char devnull[1000];
int main()
{
	int i,t,n,sum,temp,j,k,done;
	scanf("%d",&t);
	while(t--)
	{
		done = 0;
		scanf("%d%d",&n,&sum);
		for(i=0;i<n;i++)
			scanf("%s%d",devnull,&x[i]);
		qsort(x,n,sizeof(int),cmpfunc);
		for(i=0;i<n;i++)
		{
			j = i+1;
			k = n-1;
			temp = sum - x[i];	
			while((x[j]+x[k])!=temp)
			{
				//printf("%d %d %d\n",x[i],x[j],x[k]);
				if((x[j]+x[k])>temp)
					k--;
				else
					j++;
				if(j>=k)
					break;
			}
			if(x[j]+x[k]==temp && j<k)
			{
				printf("YES\n");
				done = 1;
				break;
			}
		}
		if(!done)
			printf("NO\n");
	}
	return 0;
}
