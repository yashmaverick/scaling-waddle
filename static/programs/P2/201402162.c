#include<stdio.h>
int binary_search(int* a,int l,int u,int val)
{
	if (u >= l)
	{
		int mid = (l+u)/2;
		if ((mid == l || a[mid-1] < val) && a[mid] >= val)
		{
			return mid;
		}
		else if (val > a[mid])
			return binary_search(a,mid+1,u,val);
		else
			return binary_search(a,l,mid-1,val);
	}
	return -1;	
}
int main()
{
	int t; 
	scanf("%d",&t);
	while(t--)
	{
		int i;
		long long int score=0;
		int ip;
		scanf("%d",&ip);
		int p[ip];
		for(i=0;i<ip;i++)
		{
			scanf("%d",&p[i]);
		}
		int iq;
		scanf("%d",&iq);
		int q[iq];
		for(i=0;i<iq;i++)
		{
			scanf("%d",&q[i]);
		}
		 int ir;
		scanf("%d",&ir);
		int r[ir];
		for(i=0;i<ir;i++)
		{
			scanf("%d",&r[i]);
		}
		int l,u,qmin,val,rmin,j;
		for(i=0;i<ip;i++)
		{
			val=p[i];
			qmin=binary_search(q,i,iq-1,val);
			if(qmin!=-1)
			for(j=qmin;j<iq;j++)
			{
				val=q[j];
				rmin=binary_search(r,j,ir-1,val);
				if(rmin!=-1)
				score+=ir-rmin;
				else break;
			}
			else break;
		}
		printf("%lld\n",score);
	}
	return 0;
}
