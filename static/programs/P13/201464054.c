#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define ll long long int
#define sint(n); scanf("%d",&n);
#define pint(n); printf ("%d\n",n);
#define sll(n); scanf("%lld",&n);
#define pll(n); printf("%lld\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define TEST scanf("%lld",&test);while(test--)
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)


ll arr[100005],lev[100005],n,maxlevel,minelement;
struct pair
{
	ll x;
	ll y;
};
struct pair binsearch ( ll st2, ll end2, ll value , ll index_val)
{
	struct pair temp;
	ll index,mid,st,end;
	index=end;	st=st2;	end=end2;
//	printf ("bin search starts for %lld %lld root = %lld\n",st,end,value);
	if (st==end || st< 0 || end<0)
	{
		temp.x=end;
		temp.y=st;
		return temp;
	}
	if (end-st==1)
	{
		if (arr[end]>value && arr[st]<value)
		{
			temp.x=st;
			temp.y=end;
		}
		else if (arr[st]>value && arr[end]>value)
		{
			temp.x=-1;
			temp.y=st2;
		}
		else if (arr[st]<value && arr[end]<value)
		{
			temp.x=end2;
			temp.y=-1;
		}
//		printf ("returns on end-st==1 condition. st = %lld end = %lld\n",temp.x,temp.y);
		return temp;
	}
	while (end-st>1)
	{
//		printf ("st = %lld end = %lld\n",st,end);
		mid=(st+end)/2;
		if (value>arr[mid])
			st=mid;
		else if (value<arr[mid])
			end=mid;
	}
	if (arr[st]<value && arr[end]>value)
	{
		temp.x=st;
		temp.y=end;
	}
	else if (arr[st]<value && arr[end]<value)
	{
		temp.x=end2;
		temp.y=-1;
	}
	else if (arr[st]>value && arr[end]>value)
	{
		temp.x=-1;
		temp.y=st2;
	}
//	printf ("bin search ends at %lld %lld\n",temp.x,temp.y);
	return temp;
}
void findlevel ( ll startindex, ll endindex, ll val, ll valindex, ll ct)
{
//	printf ("findlevel starts at startindex = %lld endindex = %lld val = %lld valindex = %lld\n",startindex,endindex,val,valindex);
	ct++;
	if (ct==maxlevel)
		if (arr[startindex]<minelement)
			minelement=arr[startindex];
	if (ct>maxlevel)
	{
		maxlevel=ct;
		//if (arr[startindex]<=minelement)
			minelement=arr[startindex];
//		printf("new maxlev = %lld , new minelement = %lld\n",maxlevel,minelement);

	}
	if (startindex==endindex && startindex==valindex)
		return;
	if (startindex>endindex)	//	remove this condition and fix it in binsearch. binsearch should not give such output.
		return;
/*	if (startindex==endindex)
		return;
*/	struct pair tmp;
	tmp=binsearch(startindex, endindex, val, valindex);
	/*if (tmp.x==tmp.y)
	{
		return;
	}*/
	if (tmp.x==startindex /*|| startindex==tmp.x*/)
	{
		findlevel(startindex,tmp.x,arr[tmp.x],tmp.x,ct);
	//	findlevel(startindex, 0, arr[tmp.x], tmp.x, ct);
	}
	if (tmp.x>0 && startindex>=0 && tmp.x!=startindex)
		findlevel(startindex, tmp.x-1, arr[tmp.x], tmp.x, ct);
	if (endindex==tmp.y /*|| endindex==tmp.y*/)
	{
		findlevel(tmp.y,endindex,arr[tmp.y],tmp.y,ct);
	}
	else if (endindex>0 && tmp.y>=0 && tmp.y!=endindex)
		findlevel(tmp.y, endindex-1, arr[endindex], endindex, ct);
	return;
}
int main()
{
	ll test,i,ct;
	scanf ("%lld",&test);
	while (test--)
	{
		scanf ("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		maxlevel=-1;	minelement=INT_MAX;	ct=-1;	//check ct value
		if (n==1)
		{
			printf ("1 1\n");
			continue;
		}
//		struct pair initial;
//		initial = binsearch(0,n-2,arr[n-1],n-1);	// check if no elements are greater/less than val (i.e. BST is either completely to the left or to the right)
		findlevel(0,n-2,arr[n-1],n-1,ct);
//		printf ("intital = %lld %lld\n",initial.x,initial.y);
//		printf ("minelement = %lld maxlevel = %lld\n",minelement,maxlevel);
		printf ("%lld %lld\n",minelement,maxlevel);
	}
	return 0;
}
