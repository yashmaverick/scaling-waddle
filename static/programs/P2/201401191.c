#include<stdio.h>
typedef long long int ll;
ll a[100001],b[100001],c[100001];
ll tot[100001];
ll new[100001];
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		ll i,j,k;
		ll p,q,r;
		scanf("%Ld",&p);
		for(i=0;i<p;i++)
		{
			scanf("%Ld",&a[i]);
		}
		scanf("%Ld",&q);
		for(i=0;i<q;i++)
		{
			scanf("%Ld",&b[i]);
			//    printf("A:%Ld \t",b[i]);
			tot[i]=0;
			new[i]=0;
		}
		scanf("%Ld",&r);
		for(i=0;i<r;i++)
		{
			scanf("%Ld",&c[i]);
			new[i]=0;
		}
		ll p2=0;
		ll p1=0;
		while(p1<p&&p2<q)
		{
			if(p1>p2)
			{
				p2++;
				continue;
			}
			if(a[p1]<=b[p2])
			{
				tot[p2]++;
				p1++;
			}
			else
			{
				p2++;
			}
		}
		//  printf("First:%Ld",tot[0]);
		for(i=1;i<q;i++)
		{
			//    printf("First:%Ld ",tot[i]);
			tot[i]+=tot[i-1];
		}
		//  for(i=0;i<q;i++)
		//    printf("New:%Ld ",tot[i]);
		p2=0;
		ll p3=0;
		while(p2<q&&p3<r)
		{
			if(p2>p3)
			{
				p3++;
			}
			if(b[p2]<=c[p3])
			{
				 new[p3]+=tot[p2];
		/*		ll tmp;
				tmp=r-p3;
				new[p2]+=tmp; 
				p3=p2; */
				p2++; 

			}
			else
			{
				//  p2++;
				p3++;
			}
		}  
		/*		while(p2>=0&&p3>=0)
				{
				if(b[p2]<=c[p3])
				{
				while(b[p2]<=c[p3])
				{
				p3--;
				}
				ll tmp;
				tmp=r-p3;
				new[p2]+=tmp;
				if(b[p2]>c[p3])
				{
				while(b[p2]<=c[p3])
				{
				p2--;
				}
				}
				}
				} */
		ll fin=0;
		for(i=0;i<r;i++)
		{
//			printf("Temp: %Ld\t",new[i]);
				    new[i]+=new[i-1];
		} 
		for(i=0;i<r;i++)
		{
			       fin+=new[i];
	//		fin+=(new[i]*tot[i]);
			//   printf("Final: %Ld\t",new[i]);
		}
		printf("%Ld\n",fin);
	}
	return 0;
}
