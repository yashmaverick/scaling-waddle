#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI M_PI
struct compare
{ int b_a,c_b;
}till[100001];
int comp(const void *a,const void *b)
{ struct compare *c=(struct compare *)a;
    struct compare *d=(struct compare *)b;
    if(c->b_a==d->b_a) return (c->c_b-d->c_b);
    else
	return (c->b_a-d->b_a);
}
int main()
{   
    char s[100001];
    int i,a,b,c,len,j,test,k;
    long long tmp,ans;
    scanf("%d",&test);
    for (k=1;k<=test;k++)
    {
	scanf("%s",s);
	a=b=c=0;
	for(i=0;s[i];i++)
	{ till[i].b_a=b-a;
	    till[i].c_b=c-b;
	    if(s[i]=='J') a++;
	    else if(s[i]=='M') b++;
	    else if(s[i]=='R')c++;
	}
	till[i].b_a=b-a;
	till[i].c_b=c-b;
	len=i+1;
	qsort(till,i+1,sizeof(struct compare),comp);
	tmp=0;
	ans=0;
	for(i=0;i<len;)
	{ for(j=i+1;j<len&&till[j].b_a==till[i].b_a&&till[j].c_b==till[i].c_b;j++);
	    tmp=j-i;
	    ans+=tmp*(tmp-1)/2;
	    i=j;
	}
	printf("%lld\n",ans);
    }
    return 0;
}
