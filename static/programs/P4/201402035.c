#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return *(int*)a -*(int*)b;
}

int main()
{
	int i,ct,x,sum1,sum,fin[100000],l,t;
	char a[100000];
	scanf("%d",&t);

	while(t--)
	{
		scanf("%s",a);
		fin[0]=0;
		sum =0;

		l=strlen(a);
		for(i=0;i<l;i++)
		{
			if(a[i]=='M')
				sum+=(-100000);

			if(a[i]=='J')
				sum+=-1;

			if(a[i]=='R')
				sum+= 100001;

			fin[i+1]=sum;
		}

		qsort(fin,l+1,sizeof(int),compare);
//for(i=0;i<n;i++)
//printf("%d ",a[i]);

		ct=1;
		sum1=0;
		for(i=1;i<l+1;i++)
		{
			if(fin[i]==fin[i-1])
				ct++;
			
			else
			{
				sum1 = sum1 + ((ct)*(ct-1))/2;
					ct=1;
			}

		}
		sum1= sum1 + ((ct)*(ct-1))/2;

		printf("%d\n",sum1);
	}
	return 0;
}

