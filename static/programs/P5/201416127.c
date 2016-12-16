#include<stdio.h>
#include<stdlib.h>
int a[1000000];
int function( const void * a, const void * b)
{return (*(int*)a - *(int*)b );
}
void search(int a[],int n,int t);
int main()
{
	int k,l;
	scanf("%d",&k);
	for(l=0;l<k;l++)
	{
		int n,i,t,j,k,flag=0,element;
		scanf("%d%d",&n,&t);
		char tra[100000];
		for(i=0;i<n;i++)
		scanf("%s%d",tra,&a[i]);
		qsort(a,n,sizeof(int),function);
		search(a,n,t);
	}
	return 0;
}
	void search(int a[],int n,int t)
	{
		int i,j,element,k;int flag=0;
		for(i=0;i<n;i++)
		{
			j=i+1;
			k=n-1;
			while(j<k)
			{
				element=a[i]+a[j]+a[k];
				if(element==t)
				{
					flag=1;
					break;
				}
				if(element<t)
				{
					j++;
				}
				if(element>t)
				{
					k--;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
