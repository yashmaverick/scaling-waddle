#include<stdio.h>
int main()
{
	long long int sum,j,l,u,t,p,q,r,i,mid,pa[100001],qa[100001],ra[100001],ans2[100002];
	scanf ("%lld",&t);
	while (t--)
	{
		scanf ("%lld",&p);		for (i=1;i<=p;i++)scanf ("%lld",&pa[i]);
		scanf ("%lld",&q);		for (i=1;i<=q;i++)scanf ("%lld",&qa[i]);
		scanf ("%lld",&r);		for (i=1;i<=r;i++)scanf ("%lld",&ra[i]);
		sum=0;
		for (i=0;i<=(q+2);i++)ans2[i]=0;
		for (i=q;i>=1;i--)
		{
			l=i;u=r;
		/*	if (ra[i]>=qa[i])
			{
				ans2[i]=ans2[i+1]+r-i+1;
	//			printf ("continue loop i=%lld ans2=%lld\n",i,ans2[i]);
			}
			else*/
			{
				while(l<=u)
				{
					mid=(l+u)/2;
					if (qa[i]<=ra[mid] && ( (mid==i) ||(qa[i]>ra[mid-1])))
					{
						ans2[i]=ans2[i+1]+r-mid+1;	//should +1 be added here ???
						break;
					}
					//if(qa[i]<=ra[mid] && (qa[i]<=ra[mid-1] || mid==i))
					//{
					//	ans2[i]=ans2[i+1]+r-mid;
					//	printf ("%lld ",ans2[i]);
					//	break;
					//}
					else if(qa[i]<ra[mid])
						u=mid-1;
					else
						l=mid+1;
				}
	//			printf ("i=%lld ans2=%lld\n",i,ans2[i]);
			}
		}
		for (i=p;i>=1;i--)
		{
			l=i;u=q;
		/*	if (pa[i]<=qa[i])
			{
				sum+=ans2[i];
	//			printf ("continue loop i=%lld sum=%lld\n",i,sum);
			}
			else*/
			{
				while (l<=u)
				{
					mid=(l+u)/2;
					
					if (pa[i]<=qa[mid] && ( (mid==i) ||(pa[i]>qa[mid-1])))
					{
						sum+=ans2[mid];
						break;
					}
					else if(pa[i]<qa[mid])
						u=mid-1;
					else
						l=mid+1;
				}
	//			printf ("i=%lld sum=%lld\n",i,sum);
			}
		}
		printf ("%lld\n",sum);
	}
	return 0;
}
