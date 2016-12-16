#include<stdio.h>
#include<string.h>
void qsort(int ab[10000],int start,int end);
int main()
{
	int s;
	for(s=0;s<30;s++)
	{
	}
	int test,max=100000;
	scanf("%d",&test);
	while(test--)
	{
		int n,i,j,k,p=0,q,f[100007],ans=0;
		char c[100007];
		scanf("%s",c);
		n=strlen(c);
		for(i=0;i<n;i++)
		{
			if(c[i]=='J')
				f[i]=(max-2);
			else if(c[i]=='M')
				f[i]=1;
			else if(c[i]=='R')
				f[i]=(-max+1);
			if(i!=0)
				f[i]+=f[i-1];
			if(f[i]==0)
				p++;
		}
			qsort(f,0,n-1);
			//for(i=0;i<n;i++)
				//printf("%d ",f[i]);
			for(i=0;i<n;i++)
			{
				q=1;
				while(f[i]==f[i+1])
				{
					q++;
					i++;
				}
				ans=ans+(q*(q-1))/2;
			}
				//ans+=(q*(q-1))/2;	
			printf("%d\n",ans+p);	
	}	
	return 0;
}
void qsort(int ab[],int start,int end)
{
	int i,j,abhi,tmp;
	if(start>end)
		return;
	abhi=start;
	i=start;
	j=end;
	while(i<j)
	{
		while(ab[i]<=ab[abhi] && i<end)
			i++;
		while(ab[j]>ab[abhi])
			j--;
		if(i<j)
		{
			tmp=ab[i];
			ab[i]=ab[j];
			ab[j]=tmp;
		}
	}
	tmp=ab[abhi];
	ab[abhi]=ab[j];
	ab[j]=tmp;
		qsort(ab,start,j-1);
		qsort(ab,j+1,end);
}
