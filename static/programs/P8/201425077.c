#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 1000000007

long long int n;
long long int power(long long int a,long long int b);//finds a^b

int main()
{
long long int t,u,d,m,aa,i,j,k;
long long count,counti,countj,countk,ans,countt;
scanf("%lld",&t);

while(t--)
	{
	 countt=count=countj=countk=counti=0;

	scanf("%lld %lld %lld %lld",&u,&d,&m,&n);
	long long int l=n,z=0;
//ci=cj=ck=-1;
if(u<n)
	l=u+1;
	for(i=0;i<l;i++)
		for(j=0;j<l;j++)
			for(k=0;k<l;k++)
				{
				
				ans=((power(i,d)%n + power(j,d)%n)%n + power(k,d)%n)%n;
				if(ans==m)
					{
					z++;
//					printf("%lld %lld %lld %lld\n",i,j,k,ans);
				//	if(u-i>1)	
					counti=((u-i)/n) +1 ; //counti%=MAX;
					//if(u%n>=i) counti++;
				//	if(u-j>1)
					countj=((u-j)/n) +1  ;  //countj%=MAX;
				//	if(u%n>=j) countj++;
				//	if(u-k>1)
					countk=((u-k)/n) +1 ; // countk%=MAX;
				//	if(u%n>=k) countk++;
						
					countt=((counti*countj)%MAX * countk)%MAX;
						
					count=(countt+count)%MAX;
					}
				}
//count=((counti*countj)%MAX *countk)%MAX;
if(u<n)
	count=z;
printf("%lld\n",count);
	}
return 0;
}


long long int power(long long int a, long long int b)//finds a^b

{
long long temp;

if(b==0)
	return 1%n;

temp=power(a,b/2)%n;

if(b%2==0)
	return (temp*temp)%n;
else
	return (((a*temp)%n)*temp)%n;


}
