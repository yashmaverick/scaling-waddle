#include<stdio.h>
#include<string.h>
typedef struct substrings
{
	long long int a,b;
}substring;
substring s[100009],u[100009];
void merge(int start,int mid,int end)
{
	int l;
	int k=start;
	int i=start;
	int j=mid+1;
	while(i<=mid && j<=end)
	{
		if(s[i].a<s[j].a || ((s[i].a==s[j].a)&&(s[i].b<s[j].b)) )
		{
			u[k].a=s[i].a;
			u[k].b=s[i].b;
			i++;
			k++;
		}
		else 
		{
			u[k].a=s[j].a;
			u[k].b=s[j].b;
			j++;
			k++;
			
		}
	}
	if(i>mid)
	{
		while(j<=end)
		{
			u[k].a=s[j].a;
			u[k].b=s[j].b;
			j++;
			k++;
		}
	}
	if(j>end)
	{
		while(i<=mid)
		{
			u[k].a=s[i].a;
			u[k].b=s[i].b;
			i++;
			k++;
		}
	}
	for(l=start;l<=end;l++)
	{
		s[l].a=u[l].a;
		s[l].b=u[l].b;
		//printf("%lld %lld\n",s[l].a,s[l].b);
	}
	return ;
}
void mergesort(int start,int end)
{
	int mid;
	if(start>=end)
		return ;
	else
	{
		mid=(start+end)/2;
		mergesort(start,mid);
		mergesort(mid+1,end);
		merge(start,mid,end);
		return ;
	}
}
int main()
{
	long long int t,len,i,plus,ans;
	char str[100005];
	substring last;
	scanf("%lld",&t);
	while(t--)
	{
		plus=0;
		ans=0;
		scanf("%s",str);
		len=strlen(str)-1;
		s[0].a=0;
		s[0].b=0;
		for(i=0;i<=len;i++)
		{
			if(str[i]=='J')
			{
				s[i+1].a=s[i].a + 1;
				s[i+1].b=s[i].b + 1;
			}
			else if(str[i]=='M')
			{
				s[i+1].a=s[i].a - 1;
				s[i+1].b=s[i].b;
			}
			else
			{
				s[i+1].b=s[i].b - 1;
				s[i+1].a=s[i].a;
			}
		//	printf("%lld %lld\n",s[i+1].a,s[i+1].b);
		}
		mergesort(0,len+1);
		/*for(i=0;i<=(len+1);i++)
		{
			printf("%lld %lld\n",s[i].a,s[i].b);
		}*/
		last.a=100002;
		last.b=100002;
		for(i=0;i<=(len+1);i++)
		{
			if(s[i].a!=last.a || s[i].b!=last.b)
			{
				last.a=s[i].a;
				last.b=s[i].b;
				plus=0;
			}
			ans+=plus;
			plus++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
