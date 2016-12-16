

#include<stdio.h>
#define em -999999;
#define ep 999999;
typedef struct node{
	int val;
	int l[2];
	int r[2];
}node;
node s[100001];

int main()
{
	int t,n,i,j,a[100001],k;
	scanf("%d",&t);
		while(t--)
		{
			int mtp=-1;
			int max=9999999;
			scanf("%d",&n);
			for(i=n-1;i>=0;i--)
				scanf("%d",&a[i]);
			i=0;
			int tp=0;
			while(i<n)
			{
				if(tp==0)
				{
					tp++;
					s[tp].val=a[i];
					s[tp].l[0]=-999999;
					s[tp].l[1]=a[i];
					s[tp].r[0]=a[i];
					s[tp].r[1]=999999;
					i++;
				}
				else if(a[i]>s[tp].l[0] && a[i]<=s[tp].l[1])
				{
					int prev = tp;
					tp++;
					s[tp].val=a[i];
					s[tp].l[0]=s[prev].l[0];
					s[tp].l[1]=a[i];
					s[tp].r[0]=a[i];
					s[tp].r[1]=s[prev].l[1];
					i++;
				}
				else if(a[i]>s[tp].r[0] && a[i]<s[tp].r[1])
				{
					int prev = tp;

					tp++;
					s[tp].val=a[i];
					s[tp].l[0]=s[prev].r[0];
					s[tp].l[1]=a[i];
					s[tp].r[0]=a[i];
					s[tp].r[1]=s[prev].r[1];
					i++;
				}
				else
					tp--;
					//for(k=0;k<3;k++)
					//	printf("s %d\n",s[k].val);
					 if(tp>=mtp)
					{
						if(tp==mtp)
						{
							if(max>s[tp].val)
								max=s[tp].val;
						}
						else
						max=s[tp].val;
						mtp=tp;
					}
				
			}
			mtp--;
			printf("%d %d\n",max,mtp);

		}
	return 0;
}
