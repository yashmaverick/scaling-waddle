#include<stdio.h>
#include<string.h>
long long int B[1000010],A[1000001];
char s[1000001];
void mergesort(long long int A[],long long int min,long long int mid,long long int max)
{
	long long int i,j,k,m;
	i=min;
	j=mid+1;
	m=i;
	while(i<=mid && j<=max)
	{
		if(A[i]>A[j])
		{
			B[m]=A[j];
			j++;
		}
		else
		{
			B[m]=A[i];
			i++;
		}
		m++;
	}
	if(i>mid)
	{
		for(k=j;k<=max;k++)
		{
			B[m]=A[k];
			i++;
			m++;
		}
	}
	else
	{
		for(k=i;k<=mid;k++)
		{
			B[m]=A[k];
			i++;
			m++;
		}
	}
	for(i=min;i<=max;i++)
	{
		A[i]=B[i];
	}					   
}
void divide(long long int A[],long long int min,long long int max)
{
	long long int mid=(min+max)/2;
	if(min<max)
	{
		divide(A,min,mid);
		divide(A,mid+1,max);
		mergesort(A,min,mid,max);
	}
}
int main()
{
	long long int i,l,j,E,k;
	long long int n,u,t;
	scanf("%lld ",&t);
	for(u=0;u<t;u++)
	{
		l=0;
		gets(s);
		n=strlen(s);
		for(i=0;i<n;i++)
		{
			if(s[i]=='J')
			{
				A[i]=-100001;
				//printf("%lld ",A[i]);
			}
			else if(s[i]=='M')
			{
				A[i]=-1;
				//printf("%lld ",A[i]);
			}
			else
			{
				A[i]=100002;
				//printf("%lld",A[i]);
			}
		}
		for(i=0;i<n-1;i++)
			A[i+1]=A[i]+A[i+1];
		divide(A,0,n-1);
	//	for(j=0;j<n;j++)printf("%lld ",A[j]);printf("\n");
		j=0;
		while(j<=n-1)
		{
			E=1;
			k=j+1;
			while(k<=n-1)
			{
				if(A[j]==A[k])
				{
					E++;
					k++;
				}
				else
					break;
			}
			if(A[j]==0)
			{
				//printf("case 1: %lld\n",E);
				E = (E*(E-1))/2 + E;
				l=l+E;
			}
			else
			{
				//printf("Case 2 :%lld\n",E);
				E =(E*(E-1))/2;
				l=l+E;
			}
			j=k;
		}
		printf("%lld\n",l);
	}
	return 0;
}
