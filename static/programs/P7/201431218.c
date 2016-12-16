#include<stdio.h>
void merge(long long int [],long long int,long long int,long long int);
void part(long long int [],long long int,long long int);
int main()
{
	long long int test,n,abhi[1000007],i,j,count,p,answer=0;
	scanf("%lld",&test);
	while(test--)
	{
		answer=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&abhi[i]);
		}
		part(abhi,0,n-1);
		for(i=0;i<n;i++)
		{
			p=1;
			while(abhi[i]==abhi[i+1])
			{
				p++;
				i++;
			}
			answer=answer+(p*(p-1))/2;
		}
		printf("%lld\n",answer);
	}
	return 0;
}
void part(long long int abhi[],long long int low,long long int high)
{
	long long int middle;
	if(low<high)
	{
		middle=(high+low)/2;
		part(abhi,low,middle);
		part(abhi,middle+1,high);
		merge(abhi,low,middle,high);
	}
}
void merge(long long int abhi[],long long int low,long long int middle,long long int high)
{
	long long int tmp[1000007];
	long long int i,j,k,m; 
	j=low;
	m=middle+1;
	for(i=low; j<=middle && m<=high ; i++)
	{
		if(abhi[j]<=abhi[m])
		{
			tmp[i]=abhi[j];
			j++;
		}
		else
		{
			tmp[i]=abhi[m];
			m++;
		}
	}
	if(j>middle)
	{
		for(k=m; k<=high; k++)
		{
			tmp[i]=abhi[k];
			i++;
		}
	}
	else
	{
		for(k=j; k<=middle; k++)
		{
			tmp[i]=abhi[k];
			i++;
		}
	}
	for(k=low; k<=high; k++)
		abhi[k]=tmp[k];
}


