#include<stdio.h>
struct node{
	int jr;
	int jm;
};
int cmp(const void *p, const void *q)
{
	int nc1=((struct node *)p)->jr;
	int nc2=((struct node *)p)->jm;
	int np1=((struct node *)q)->jr;
	int np2=((struct node *)q)->jm;
	if(nc1==np1)
		return nc2-np2;
	else 
		return nc1-np1;
}
int main()
{
	long long int t,i,n1,n2,p,sum,n;
	char c;
	struct node a[100010];
	scanf("%lld",&t);
	getchar();
	while(t--)
	{
		i=1;
		a[0].jr=0;
		a[0].jm=0;
		while(((c=getchar())!='\n') && c!=EOF)
		{
	//		putchar(c);
			if(c=='J')
			{
					a[i].jr=a[i-1].jr+1;
					a[i].jm=a[i-1].jm+1;
//					printf("lol\n");
			}
			if(c=='M')
			{
					a[i].jr=a[i-1].jr;
					a[i].jm=a[i-1].jm-1;
			}
			if(c=='R')
			{
					a[i].jr=a[i-1].jr-1;
					a[i].jm=a[i-1].jm;
				
			}
//			printf(" i %d jr %d jm %d\n",i,a[i].jr,a[i].jm);
			i++;
		}
		n=i;
		qsort(a,n,sizeof(struct node),cmp);
		n1=a[0].jr;
		n2=a[0].jm;
		p=1;
		sum=0;
//		for(i=0;i<=n;i++)
//			printf(" i %lld jr %d jm %d\n",i,a[i].jr,a[i].jm);
		for(i=1;i<n;i++)
		{
			if((a[i].jr==n1) && (n2==a[i].jm))
			{

				p++;
//			printf("p %d\n",p);
			}
			else
			{
				n1=a[i].jr;
				n2=a[i].jm;
				sum += (p*(p-1)/2);
				p=1;
			}
		}
		sum += p*(p-1)/2;
		printf("%lld\n",sum);
	}
	return 0;
}
