#include<stdio.h>
void quick(int a[],int w,int p);
int a[100001];
int main()
{
	int t,i,j,p,n,k,ans;
	char b[2000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&p);
		for(i=0;i<n;i++)
		{
			scanf("%s",b);
			scanf("%d",&a[i]);
		}
		quick(a,0,n-1);
		ans=-1;
		for(i=0;i<n-2;i++)
		{
			j=i+1;
			k=n-1;
			while(j<k)
			{
				if(a[i]+a[j]+a[k]==p)
				{
					ans=0;
			//		printf("Found with :\n");
			//		printf("%d %d %d %d %d %d\n",a[i],a[j],a[k],i,j,k);
					break;
				}
				else if(a[i]+a[j]+a[k]>p)
					k--;
				else
					j++;
			}
			if(ans==0)
				break ;
		}
		if(ans==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}


void quick(int a[],int w,int p)
{
	int wall,piv,temp;
	piv=p;
	if(w>=p)
		return;
	wall=w;
	while(wall<=piv)
	{
		if(a[wall]<=a[piv])
			wall++;
		else
		{
			temp=a[wall];
			a[wall]=a[piv-1];
			a[piv-1]=a[piv];
			a[piv]=temp;
			piv--;
		}
	}
		quick(a,w,piv-1);
		quick(a,piv+1,p);
}
