#include<stdio.h>
long long int i,a[100000],b[100000],c[100000],d[100000],s[100000],p,q,r;
long long int binse(long long int l,long long int h,long long int k)
{
	if(h-l==1)
	{
		if(b[l]>=k)
			return l;
		else if(b[h]>=k)
		  return h;
		else if(h!=q-1)
			return h+1;
		else	
			return -1;

	}
	if(l==h)
	{
		if(l==q-1)
			if(b[l]>=k)
				return q-1;
			else
				return -1;
		if(l==0)
			if(b[0]>=k)
				return l;
			else
				return l+1;
	}
	if(b[(l+h)/2]>=k)
		return binse(l,((l+h)/2)-1,k);
	else if(b[(l+h)/2]<k)
		return binse(((l+h)/2)+1,h,k);
}
long long int binse2(long long int l,long long int h,long long int k)
{
	if(h-l==1)
	{
		if(c[l]>=k)
			return l;
		else if(c[h]>=k)
		  return h;
		else if(h!=r-1)
		return h+1;
		else
			return -1;

	}
	if(l==h)
	{
		
		if(l==r-1)
		{
			if(c[l]>=k)
				return r-1;
			else
				return -1;
		}
		if(l==0)
		{
			if(c[l]>=k)
				return l;
			else
				return l+1;
		}
	}
	if(c[(l+h)/2]>=k)
		return binse2(l,((l+h)/2)-1,k);
	else if(c[(l+h)/2]<k)
		return binse2(((l+h)/2)+1,h,k);
}
int main()
{
	long long int m,n,j,k,g,f,x,p;
	scanf("%lld",&g);
	while(g--)
	{
		p=0;
		x=0;
		scanf("%lld",&p);
		j=0;
		while(j<p)
		{
			scanf("%lld",&a[j]);

			j++;
		}

		scanf("%lld",&q);
		j=0;
		while(j<q)
		{
			scanf("%lld",&b[j]);

			j++;
		}

		scanf("%lld",&r);
		j=0;
		while(j<r)
		{
			scanf("%lld",&c[j]);

			j++;

		}
		j=0;
		while(j<=q-1)
		{
			x=binse2(0,r-1,b[j]);
			if(x!=-1)
			{
				if(j>x)
					s[j]=r-j;
				else
					s[j]=r-x;
			}
			else
			{
				s[j]=0;
			}
	//		printf("%lld\n",s[j]);
			j++;
		}
		j=q-2;
		while(j>=0)
		{
			s[j]=s[j]+s[j+1];
			j--;

		}
		j=0;
		f=0;
		while(j<p)
		{
			x=binse(0,q-1,a[j]);
			if(x!=-1)
			{
				if(j>x)
					f=f+s[j];
				else
					f=f+s[x];
			}
			else
			{
				break;
			}
			j++;

		}
	/*		j=0;
			while(j<q)
			{
			printf("%lld",s[j]);
			j++;
			}
printf("\n");*/
		
		printf("%lld\n",f);
	}
	return 0;

}
