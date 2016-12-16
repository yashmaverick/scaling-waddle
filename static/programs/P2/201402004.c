#include <stdio.h>

int lower_bound(int a[],int l, int r,int val)
{
	int mid=l+r;
	mid/=2;
	//printf("%d %d ",l,r);
	if(l>=r)return l;
	if(val>a[mid])
		return lower_bound(a,mid+1,r,val);
	else if(val<a[mid])
		return lower_bound(a,l,mid-1,val);
	else 
		return mid;
}
int t,p,a[100000],b[100000],c[100000],q,r,ans,i,mid,mid2,j;
int main(void) {
        scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&p);
		for(i=0;i<p;i++)scanf("%d",&a[i]);
		scanf("%d",&q);
		for(i=0;i<q;i++)scanf("%d",&b[i]);
		scanf("%d",&r);
		for(i=0;i<r;i++)scanf("%d",&c[i]);
		ans=0;
		
		for(i=0;i<p;i++)
		{
			mid=lower_bound(b,i,q-1,a[i]);
			//printf("%d\t",mid);
			if(b[mid]<a[i])break;
			for(j=mid;j<q;j++)
			{
				mid2=lower_bound(c,j,r-1,b[j]);
				//int jn=lower_bound(b,j,q-1,c[mid2]);
				//printf("%d\n",jn);
				if(c[mid2]<b[j])break;
				ans+=(r-mid2);
				//j=jn+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

