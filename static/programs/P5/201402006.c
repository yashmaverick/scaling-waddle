#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*int comp(int a, int b)
{
	if(a>b)
		return 1;
	else
		return 0;
}*/
int comp (const void * a, const void * b)
{
           return ( *(int*)a - *(int*)b );
}
int main()
{
	char instr[100000];
	int t,p,i,n,k,value[100000],l,lower,upper,mid,d,flag;
	scanf("%d",&t);
	for(p=0;p<t;p++)
	{
		flag=0;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s",instr);
			scanf("%d",&value[i]);
		}
		qsort(value,n,sizeof(int),comp);
		for(i=0;i<n-2;i++)
		{
			for(l=i+1;l<n-1;l++)
			{
				d=k-value[i]-value[l];
				if(d>=0)
				{
				        lower=l+1;
		        		upper=n-1;
					while(lower<=upper)
					{
						mid=(lower+upper)/2;
						if(value[mid]==d)
						{
							printf("YES\n");
							flag=1;
							break;
						}
						else if(value[mid]>d)
							upper=mid-1;
						else
							lower=mid+1;
					}
				}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		if(flag==0)
		{	
			printf("NO\n");
		}
	}
	return 0;
}		
