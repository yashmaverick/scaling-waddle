#include<stdio.h>
#include<string.h>
int ar[100001];
int cmpfunc(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b);
}
int main()
{
	int t,i,j,k;
	scanf("%d",&t);
	ar[0]=0;
	char ch[100000];
	while(t--)
	{
		scanf("%s",ch);
		k=strlen(ch);
		for(i=0;i<k;i++)
		{
			if(ch[i]=='J')
				ar[i+1]=ar[i]+100000;
			else if(ch[i]=='M')
				ar[i+1]=ar[i]+111111;
			else
				ar[i+1]=ar[i]-211111;
		}
		qsort(ar,k+1,sizeof(int),cmpfunc);
		int ct,ans;
		ct=1;
		ans=0;
		for(i=0;i<k+1;i++)
		{
			if(i>0)
			{
				if(ar[i]==ar[i-1])
					ct++;
				else
				{
					if(ct%2==0)
						ans=ans+ct/2*(ct-1);
					else
						ans=ans+ct*(ct-1)/2;
					ct=1;
				}
				if(i==k)
				{
					if(ct%2==0)
						ans=ans+(ct/2*(ct-1));
					else
						ans=ans+ct*(ct-1)/2;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
