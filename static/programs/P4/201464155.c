#include<stdio.h>
#include<string.h>
struct c
{
	int a,b;
}m[100001];
int cmpfunc (const void *c, const void *d)
{
	   struct c ia=*(struct c *)c;
	   struct c ib=*(struct c *)d;
	   if(ia.a==ib.a)
		   return (ia.b-ib.b);
	   else
		   return (ia.a-ib.a);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int ba=0,ca=0;
	char s[100001];
	scanf("%s",s);
	int d=strlen(s);
	//int m1[100001]={100001},m2[100001]={100001},i;
	long long int ans=0,bns,i;
	for(i=0;i<100001;i++)
	{
		m[i].a=0;
		m[i].b=0;
	}
	for(i=0;i<d;i++)
	{
		if(s[i]=='J')
		{
			ba--;
			ca--;
		}
		else if(s[i]=='M')
			ba++;
		else
			ca++;
		//cout<<ba<<" "<<ca<<endl;
		m[i].a=ba;
		m[i].b=ca;
	}
	qsort(m,d+1,sizeof(struct c),cmpfunc);
	/*for(i=0;i<d+1;i++)
	{
		printf("%d ",m[i].a);
	}
	printf("\n");
	for(i=0;i<d+1;i++)
	{
		printf("%d ",m[i].b);
	}
	printf("\n");*/
	for(i=0;i<d+1;)
	{
		bns=0;
		ba=m[i].a;
		ca=m[i].b;
		while(m[i].a==ba&&m[i].b==ca&&i<d+1)
		{
			//cout<<myv[i].F<<" "<<myv[i].S<<endl;
			i++;
			bns++;
		}
		// cout<<bns<<endl;
		ans+=(bns*(bns-1))/2;
	}
	printf("%lld\n",ans);
	}
	return 0;
}
