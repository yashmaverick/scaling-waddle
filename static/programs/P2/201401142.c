#include<stdio.h>
#define LIM 100001
typedef long long int LL;
int a[LIM],b[LIM],c[LIM];
LL na,nb,nc,t,i,j,bstart,cstart,result,aend;
int absearch(int start,int end,int item);
int cbsearch(int start,int end,int item);
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		result = 0;
		//Scanning part
		scanf("%lld",&na);
		for(i=0;i<na;i++)
			scanf("%d",&a[i]);
		na-=1;
		scanf("%lld",&nb);
		for(i=0;i<nb;i++)
			scanf("%d",&b[i]);
		scanf("%lld",&nc);
		for(i=0;i<nc;i++)
			scanf("%d",&c[i]);
		//Scanning Done  --> Search for an element <=b[0]
		for(bstart = 0;b[bstart]<a[0];bstart++);
		for(cstart = 0;b[0]>c[cstart];cstart++);
		for(i=bstart;i<nb;i++)
		{
			LL aindex,cindex;
			//Search for the stable place to insert b[i], using binary search.
			//Ending point will be 'i' itself,starting point will be 0 for array a and ending point will be i.
			//For array c staring point will be start.
			aend = na<i?na:i;
			aindex = absearch(0,aend,b[i]);
			
			if(cstart<i)
				cstart = i;
			for(j = cstart;j<nc;j++)
			{
				if(b[i]<=c[j])
				{
					cstart = j;
					break;
				}
			}
			if(j>=nc)
				break;
			result += (aindex+1)*(nc-cstart);
		}
		printf("%lld\n",result);

	}
	return 0;
}
int absearch(int start,int end,int item)
{
	//Where can we insert b[i];
	//Returns the last occurrence of item.
	if(start==end)
	{
		if(a[start]<=item)
			return start;
		else
			return start-1;
	}
	int middle = (start + end+1)/2;
	if (a[middle]>item)
		return absearch(start,middle-1,item);
	else
		return absearch(middle,end,item);
}

/*int cbsearch(int start,int end,int item)
{
	//Returns the last occurrence of item.
	if(start==end)
		{
			if (1)
				return start;
			else
				return start-1;
		}
	int middle = (start + end)/2;
	if (c[middle]<item)
		return cbsearch(middle+1,end,item);
	else
		return cbsearch(start,middle,item);
}*/
