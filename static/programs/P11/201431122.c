

#include<stdio.h>
int s[100001];
int tp=0;
void push(int a)
{
	tp++;
	s[tp]=a;
}
int main()
{
	long long int a[100001],ma,ca
		;int n,i,j;
	while(1)
	{
		tp=0;
		ma=0;
		s[0]=-1;
		scanf("%d",&n);
		if(n==0)
			break;
		else
		{
			for(i=0;i<n;i++)
				scanf("%lld",&a[i]);
			j=0;
			while(j<n)
			{
	//			printf("s %d a %d\n",s[tp],a[j]);
				if(tp==0 || a[s[tp]]<=a[j])
				{
					push(j);
					j++;
				}
				else
				{
					int t = s[tp];
					tp--;
					ca = a[t]*(j-s[tp]-1);
					if(ca>ma)
					{
						ma=ca;
	//					printf("ma %d\n",ma);
					}
	//				printf("t %d tp %d a[t] %d *(j %d - %d s[tp] - 1\n",t,tp,a[t],j,s[tp]);

				}
	//			for(i=0;i<=tp;i++)
	//				printf("s %d\n",s[i]);
	//			printf("\n");
			}
			while(tp>0)
			{
				int t=s[tp];
				tp--;
				ca = a[t]*(n-s[tp]-1);
	//				printf("t %d tp %d a[t] %d *(j %d - %d s[tp] - 1\n",t,tp,a[t],j,s[tp]);
				if(ca>ma)
					ma=ca;
	//			for(i=0;i<=tp;i++)
	//				printf("s %d\n",s[i]);
	//			printf("\n");
			}
		}
			printf("%lld\n",ma);
		}
		return 0;
	}
