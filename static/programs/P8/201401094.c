#include<stdio.h>
#define od 1000000007
void print(int *A,int n)
{
	int i;
	for(i=0;i<n;i++)
  {
		printf("%d :%d\n",i,A[i]);
	}
	printf("\n");
}
int main()
{
	unsigned long long  int t;
	int i,n,D,m,d[45],j,a[100],b[100];
  int x,k,mod;
long long  int  l,q,r,s;
	long long ans,u;
	scanf("%llu",&t);
	while(t--)
	{
		j=0;
		ans=0;
		scanf("%lld %d %d %d",&u,&D,&m,&n);
		if(D==0)
		{
			if(m==(3%n))
				printf("%lld\n",(((u+1)*(u+1)*(u+1)))%od);
			else
				printf("0\n");
			continue;
		}
		while(D>0)
		{
			d[j++]=(D&01);
			D=(D>>1);
		}
//	print(d,j);
    for(i=0;i<n+1;i++)
		{
			a[i]=0;
			b[i]=0;
		}
	  a[0]=1;
	//	a[1]=((u-1)/n)+1;
		if(u<n)
			l=u+1;
		else
			l=n+1;
 // printf("%lld\n\n",l);
		for(i=1;i<l;i++)
		{  
			x=i;
			mod=1;
        for(k=0;k<j;k++)
				{
					if(d[k]==1)
						mod=(mod*x)%n;
					x=(x*x)%n;
				}
			a[mod]+=(((u-i)/n)+1);	
		}
	//	print(a,n);
		j=0;
		for(i=0;i<n;i++)
		{
			if(a[i]>0)
				b[j++]=i;
		}
	//	print(b,j);
		for(i=0;i<j;i++)	
		{
			for(k=0;k<j;k++)
			{
				for(l=0;l<j;l++)
				 {	
					 if((b[i]+b[k]+b[l])%n==m)
             {
							 q=a[b[i]];r=a[b[k]],s=a[b[l]];
								 ans=((((q*r)%od)*s)+ans)%od;		                     
//     printf("%d %d %d : %lld\n",b[i],b[k],b[l],ans);
						 }
				 }
			}
		}
      printf("%lld\n",ans%od);
	}
	return 0;
}
