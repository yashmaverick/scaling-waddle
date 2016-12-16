#include<stdio.h>
typedef long long int lld;
lld q2=0;
lld flag=0,flag1=0;
lld binary1(lld b[],lld c[],lld i,lld n3)
{lld f,l,mid,q1=0;
	f=i;
	l=n3-1;
	while(f<=l)
	{   mid=(f+l)/2;
//		printf("midb1=%lld\n",mid);
		if(c[mid]>=b[i])
		{       if(mid==0)
			{flag=1;
			return 0;}
			if(c[mid]>=b[i])
			{  	if(mid-1<i)
			{q1=mid;
				flag=1;
			break;
			}
		
			if(mid-1>=i)
			{if(c[mid-1]<b[i])
				{ 	q1=mid;
				flag=1;
				break;
			}
			else
				l=mid-1;
			}
			}
		}
		else
			f=mid+1;
	}
		return q1;
}
lld binary2(lld a[],lld b[],lld i,lld n1)
{lld f,l,mid,q=0;
f=0;
if(i>n1-1)
l=n1-1;
if(i<=n1-1)
	l=i;
   	while(f<=l)
	{mid=(f+l)/2;
//	printf("midb2=%lld\n",mid);
		if(a[mid]<=b[i])
		{
			
		//printf("a=1\n");
		if(mid==n1-1)
		{	q=mid;
			q2=mid;
		flag1=1;
		break;}
			if(mid+1>i)
			{q=mid;
				flag1=1;
				q2=mid;
			//	q2=q;
		//printf("a=2\n");
				break;
			
			}
			if(mid+1<=i)
			{if(a[mid+1]>b[i])
				{	q=mid;
		//printf("a=3\n");
				flag1=1;
			
			q2=mid;
			break;
			
				}
			
			
			else
				f=mid+1;
			}
		}
		
		else
			l=mid-1;
	} 
	return q;
	
	//else
		//if(flag1==1);
	//	printf("a=5\n");
	//	flag1=1;
	//	return q2;}

return 0;
}
int main()
{long long int i,t,n1,n2,n3,a[100010],b[100010],c[100010];
long long int q=0,q1=0;
unsigned long long int sum;
	scanf("%lld",&t);
	while(t--)
	{       scanf("%lld",&n1);
		for(i=0;i<n1;i++)
	         scanf("%lld",&a[i]);
                scanf("%lld",&n2);
		for(i=0;i<n2;i++)
	         scanf("%lld",&b[i]);
		scanf("%lld",&n3);
		for(i=0;i<n3;i++)
	         scanf("%lld",&c[i]);
        sum=0;
		for(i=0;i<n2;i++)
		{ flag=0;
		  flag1=0;	
                     if(b[i]>=a[0]) 
                        q=binary2(a,b,i,n1);
			if(flag1==1)
			q1=binary1(b,c,i,n3);
		//printf("q=%lld q1=%lld\n",q,q1);
                     if(flag==1&&flag1==1)
			     sum=sum+(n3-q1)*(q+1);

		}
		printf("%llu\n",sum);
	}
	return 0;
}


