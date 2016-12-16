#include<stdio.h>
#include<string.h>
struct xyz
{
	 int mval;
	 int rval;
};//b[100003];
static int comp (const void *m1, const void *m2)
{
	struct xyz *mi1 = (struct xyz *) m1;
	struct xyz *mi2 = (struct xyz *) m2;
	if ((mi1->mval)>(mi2->mval))
		return 1;
	else if ((mi1->mval)<(mi2->mval))
		return -1;
/*	else if ((mi1->mval)==(mi2->mval))
	{
		if ((mi1->rval)>(mi2->rval))
			return 1;
		else if ((mi1->rval)<(mi2->rval))
			return -1;
		else if ((mi1->rval)==(mi2->rval))
			return 0;
	}*/
	return mi1->rval - mi2-> rval;
}
int main()
{
	struct xyz a[100003];
	long long int ct,t,len,i,j,k,m,r,flag;
	char s[100005],c;
//	printf ("%lld\n",ncr(1,2));
	scanf ("%lld",&t);
	while (t--)
	{
		scanf ("%s",s);
		ct=0;
		len=strlen(s);
		if(s[0]=='J')
		a[0].mval=-1,
		a[0].rval=-1;
		else if(s[0]=='M')
		a[0].mval=1,
		a[0].rval=0;
		else
		a[0].mval=0,
		a[0].rval=1;
		for (i=1;i<len;i++)
		{
//			a[i].mval=0;
//			a[i].rval=0;
//			b[i].mval=0;
//			b[i].rval=0;
			if (s[i]=='J')
			{
//				if (i==0)
//				{
//					a[i].mval--;
//					a[i].rval--;
//				}
//				else
				
					a[i].mval=a[i-1].mval-1;
					a[i].rval=a[i-1].rval-1;
				
			}
			else if (s[i]=='M')
			{
//				if (i==0)
//					a[i].mval++;
//				else
				
					a[i].mval=a[i-1].mval+1;
					a[i].rval=a[i-1].rval;
			
			}
			else if (s[i]=='R')
			{
//				if (i==0)
//					a[i].rval++;
//				else
				
					a[i].rval=a[i-1].rval+1;
					a[i].mval=a[i-1].mval;
				
			}
		}
/*		printf ("len = %lld\n",len);
		for (i=0;i<len;i++)
			printf ("i = %lld ==> mval = %lld rval = %lld\n",i,a[i].mval,a[i].rval);
		printf ("------------------------------------\n");
*/		qsort(a,len,sizeof(struct xyz),comp);
/*		for (i=0;i<len;i++)
			printf ("i = %lld ==> mval = %lld rval = %lld\n",i,a[i].mval,a[i].rval);
*/		m=a[0].mval;
		r=a[0].rval;
		k=0;
		flag=0;
		for (j=0;j<len;)
		{
			k=0;flag=0;
			m=a[j].mval;
			r=a[j].rval;
//			printf("j = %lld  m = %lld r = %lld\n",j,m,r);
			while (m==a[j].mval && r==a[j].rval && j<len)
			{
				k++;
				if (m==0&&r==0)
					flag=1;
				j++;
			}
//			printf ("k = %lld\n",k);
				ct+=(((k+flag)*(k+flag-1))/2);
//			printf ("ct = %lld\n",ct);
		}
		printf ("%lld\n",ct);
	}
	return 0;
}
