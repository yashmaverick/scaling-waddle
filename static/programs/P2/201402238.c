#include<stdio.h>
long long int binary1(long long int c,long long int a[],long long int j,long long int p,long long int high,long long int low,long long int i)
{       if(high>p)//when p<q
	high=p;
	if(high<0)
		return -1;
	if(low>i)//when ith element>pth element
		return (low-1);
	if(j>=p)
		return p;
	j=(high+low)/2;
	if(c>a[j])
		low=j+1;        
	else if(c==a[j])
	{ while(a[j]==a[j+1]&&(j+1)<=high)
		{j++;}
		return j;
	}
	else//c<a[j]
	{ 	if(c>=a[j-1])
		return (j-1);
		high=j-1;
	}   
	binary1(c,a,j,p,high,low,i);
}

long long int binary2(long long int c,long long int a[],long long int j,long long int p,long long int high,long long int low,long long int i)
{ 	if(low>p)
	return 0;
	if(high<low)//checked
	{	if(low==p)
		return 1;
		return (p-low+1);
	}
	//if(low==p)
	//return low;
	j=(high+low)/2;
	if(c>a[j])
		low=j+1;        
	else if(c==a[j])
	{ while(a[j]==a[j-1]&&(j-1)>=low)
		{j--;}
		return (p-j+1);
	}
	else if(c<a[j])
	{ 	high=j-1;
		//low=j+1;
	}   
	binary2(c,a,j,p,high,low,i);
}

int main()
{ 	long long int k,count,t,i,j,d,p,q,z,r,a[100005],b[100005],c[100005];
	scanf("%lld",&t);
	while(t--)
	{       i=0;count=0;
		scanf("%lld",&p);
		while(i<p)
			scanf("%lld",&a[i++]);
		i=0;
		scanf("%lld",&q);
		while(i<q)
			scanf("%lld",&b[i++]);
		i=0;
		scanf("%lld",&r);
		while(i<r)
			scanf("%lld",&c[i++]);

		p--;r--;i=0;

		for(i=0;i<q;i++)
		{ j=0;d=b[i];
			k=binary1(d,a,j,p,i,0,i)+1;
			z=binary2(d,c,j,r,r,i,i);
//				printf("%lld %lld\n",k,z);
			count=count+(k*z);
		}
		printf("%lld\n",count);
	}
	return 0;
}
