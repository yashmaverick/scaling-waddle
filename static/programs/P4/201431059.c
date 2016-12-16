#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long int  s[100005];
char a[100005];
 int cmpfunc(const void *a,const void *b)
{
	return ( *(long long int *)a-*(long long int *)b );
}
void storewithval()
{
	int i=0;
	for(;a[i]!='\0';i++)
		if(a[i]=='J')
			s[i]=1000000+1;
		else if(a[i]=='M')
			s[i]=1-1000000;
		else s[i]=-2;
}
void prefix(int n)
{
	int i=1;
	for(;i<n;i++)
		s[i]+=s[i-1];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		int l=strlen(a);
		storewithval();
		prefix(l);
		qsort(s,l,sizeof(long long int),cmpfunc);
		int i;
//		for(i=0;i<l;i++)
//			printf("%lld\t",s[i]);
		long long int cnt,ans=0;
		long long int f=s[0];
		if(f==0)
			cnt=2;
		else cnt=1;
	//	int i;
		for(i=1;i<l;i++)
		{
			if(f==s[i])
				cnt++;
			else
			{

				ans+=(cnt*(cnt-1))/2;
				f=s[i];
				if(f==0)
					cnt=2;
				else
					cnt=1;

		//		printf("%lld",cnt);

			}
		}
		printf("%lld\n",ans+(cnt*(cnt-1))/2);
	}
	return 0;
}

			
			
		


		
		
	

	

	

