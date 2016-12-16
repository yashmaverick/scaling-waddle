#include<stdio.h>

long long int b[1005];

#define gc() getchar_unlocked()
int isSpaceChar(char c) {
	return c == ' ' || c == '\n' || c == '\r' ;
}
inline int FAST_IO()
{
	char ch;
	int val=0;
	ch=gc();
	while(isSpaceChar(ch))
		ch=gc();
	val=0;
	while(!isSpaceChar(ch))
	{
		val=(val*10)+(ch-'0');
		ch=gc();
	}
	return val;

}
void mergesort (long long int a[],long long int s,long long int e)
{
	long long int i;
	//printf ("s=%d e=%d\n",s,e);
	if (s==e)
		return;
	else
	{
		mergesort(a,s,(s+e)/2);
		mergesort(a,((s+e)/2)+1,e);
	}

	long long int x=s,y=((s+e)/2)+1,ct=0;

	while (x<=(s+e)/2 || y<=e)
	{
		if (x>((s+e)/2))
		{
			while (y<=e)
			{
				b[ct]=a[y];
				ct++;
				y++;
			}
		}
		if (y>e)
		{
			while (x<=((s+e)/2))
			{
				b[ct]=a[x];
				ct++;
				x++;
			}
		}
		else
		{
			if (a[x]>=a[y])
			{
				b[ct]=a[y];
				ct++;
				y++;
			}
			else
			{
				b[ct]=a[x];
				ct++;
				x++;
			}
		}
	}
	for (i=s;i<=e;i++)
	{
		a[i]=b[i-s];
		//printf ("%d ",a[i]);
	}//printf ("\n");
}



int main()
{
	long long int a[1003],n,i,t,ans,temp,ct,j,k,flag,sum;
	char s[10000];
	scanf ("%lld",&t);
	while (t--)
	{
		scanf ("%lld %lld",&n,&ans);
		ct=-1;flag=0;
		for (i=1;i<=n;i++)
		{
			scanf ("%s",s);
			scanf ("%lld",&temp);
			//temp=FAST_IO();
			if (temp<=ans)
			{
				ct++;
				a[ct]=temp;
			}
		}
		if (ct==-1)
			goto end;
		mergesort(a,0,ct);
/*			printf ("Sorted :\n");
			for (i=0;i<=ct;i++)
				printf ("%lld ",a[i]);
			printf ("\n");
*/		for (i=0;i<=(ct-2);i++)
		{
			j=i+1;k=ct;
			while (k>j)
			{
				sum=a[i]+a[j]+a[k];
//				printf ("sum = %lld\n",sum);
				if (sum==ans)
				{
					printf ("YES\n");
					flag=1;
					break;
				}
				else if (sum<ans)
					j++;
				else if (sum>ans)
					k--;
			}
			if (flag==1)
				break;
		}
end:
		if (flag==0)
			printf ("NO\n");
	}
	return 0;
}
