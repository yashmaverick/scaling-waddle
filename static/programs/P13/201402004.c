#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int t,n,m,a[100010],val,ans,i,depmax,ans;

void make_tree(int l, int r, int depth) 
{
    if (r<l) return;
    int mid = lower_bound(l, r-1, a[r]);
    make_tree(l, mid,depth+1);
   	make_tree(mid + 1, r-1,depth+1);
	if(depth>depmax){ans=a[r];depmax=depth;}
	else if(depth==depmax)if(ans>a[r])ans=a[r];
    return;
}

int lower_bound(int first, int last,int cut) 
{

    if (last < first || a[first] > cut) return first - 1;

    int low = first, high = last, mid;
    while (low < high && a[high] > cut) 
	{
        int mid = low + (high-low+1)/2;
        if (a[mid] > cut)
            high = mid-1;
        else
            low = mid;
	}
    return high;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=100000000;
		depmax=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		make_tree(0,n - 1,0);	
		
		printf("%d %d\n",ans,depmax);		
	}
	return 0;
}
