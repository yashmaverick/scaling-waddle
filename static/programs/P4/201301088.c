#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ss(s) fastRead_string(s)
#define s(n) fastRead_int(&n)


typedef struct compare
{
	int b_a,c_b;
}pair;
pair till[1000001];

inline void fastRead_int(int *a)
{
	register char c=0;
	while (c<33) c=getchar_unlocked();
	*a=0;
	while (c>33)
	{
		*a=*a*10+c-'0';
		c=getchar_unlocked();
	}
}

inline void fastRead_string(char *str)
{
	register char c=0;
	register int i = 0;
	while (c < 33)
		c = getchar_unlocked();
	while (c > 65)
	{
		str[i] = c;
		c = getchar_unlocked();
		i = i + 1;
	}

	str[i] = '\0';
}

int comp(const void *a,const void *b)
{
	struct compare *c=(struct compare *)a;
	struct compare *d=(struct compare *)b;
	if(c->b_a==d->b_a) return (c->c_b-d->c_b);
	else
		return (c->b_a-d->b_a);
}

int main()
{
	char s[1000001];
	int i,t,a,b,c,len,j;
	long long tmp,ans;
	s(t);
	while(t--)
	{
		ss(s);
		a=b=c=0;
		for(i=0;s[i];i++)
		{
			till[i].b_a=b-a;
			till[i].c_b=c-b;
			if(s[i]=='J') a++;
			else if(s[i]=='M') b++;
			else c++;
		}
		till[i].b_a=b-a;
		till[i].c_b=c-b;
		len=i+1;
		qsort(till,len,sizeof(struct compare),comp);
		tmp=ans=0;
		for(i=0;i<len;)
		{
			for(j=i+1;j<len && till[j].b_a==till[i].b_a && till[j].c_b==till[i].c_b;j++);
			tmp=j-i;
			ans+=tmp*(tmp-1)/2;
			i=j;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
