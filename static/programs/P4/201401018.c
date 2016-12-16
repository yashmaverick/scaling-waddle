#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
//int j='J';
//int m='M';
//int r='R';
//j=-1001;
//m=1;
//r=1000;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int i,A[100001],c=0,d=1,sum=0,temp;
		char S[100001];
		scanf("%s",S);
		int l=strlen(S);
		for(i=0;i<l;i++)
		{
			//A[i]=S[i];
			if(S[i]=='J')
				A[i]=100000;
			if(S[i]=='M')
				A[i]=100001;
			if(S[i]=='R')
				A[i]=-200001;
		}
		for(i=1;i<l;i++)
			A[i]=A[i]+A[i-1];
		qsort(A, l, sizeof(long long int), cmpfunc);
	//	for(i=0;i<l;i++)
	//		printf("%lld ",A[i]);
/*		if(A[0]==0)
			c=1;
		temp=A[0];
		for(i=1;i<l;i++)
		{
			if(A[i]==0)
				c++;
			if(A[i]==temp)
				d++;
			else
			{
				temp=A[i];
				sum=sum+(d*(d-1))/2;
				d=1;
			}
		}*/
			//while(A[i]-A[i-1]==0)
			//{
			//	d++;
			//	i++;
			//}
		/*	while(1==1)
			{
				if(A[i]==A[i-1] && i<l)
				{
					d++;
					i++;
				}
				else
					break;
			}
			sum=sum+(d*(d+1))/2;
			d=0;
		}*/
		/*i=1;
		while(i<l)
		{
			if(A[i]==0)
				c++;
			while(A[i]==A[i-1])
			{
				d++;
				i++;
			}

			i++;

		}*/
		long long ans=0,count=1,cnt=0;
		if(!A[0])cnt++;
		for(i=1;i<l;i++)
		{
			if(A[i]==A[i-1])
				count++;
			else
			{
				ans+=(count*(count-1))/2;
				count=1;
			}
			if(A[i]==0)
				cnt++;
		}
		ans+=(count*(count-1))/2;
		ans+=cnt;
		printf("%lld\n",ans);
		//printf("%lld\n",d);
	}
	return 0;
}

