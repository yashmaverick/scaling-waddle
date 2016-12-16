#include<stdio.h>
long long int hl[1000001],hr[1000001],szl,szr,med;
void inshl(long long int ele)
{
	long long int k=szl,l;
	hl[szl]=ele;
	while(hl[k/2]<hl[k] && k>1)
	{
		l=hl[k/2];
		hl[k/2]=hl[k];
		hl[k]=l;
		k=k/2;
	}
	szl++;
	return;
}
void inshr(long long int ele)
{
	long long int k=szr,l;
	hr[szr]=ele;
	while(hr[k/2]>hr[k] && k>1)
	{
		l=hr[k/2];
		hr[k/2]=hr[k];
		hr[k]=l;
		k=k/2;
	}
	szr++;
	return;
}
long long int delhl()
{
	long long int k=1,l,val=hl[1];
	hl[1]=hl[szl-1];
	if(szl>1)
	{
		szl--;
		while((hl[k]<hl[2*k] || hl[k]<hl[(2*k)+1]) && (2*k)<szl)
		{
                        if(2*k+1==szl)
                        {
				l=hl[k];
				hl[k]=hl[2*k];
				hl[2*k]=l;
                                return val;
                        }
                        if(hl[2*k]>=hl[(2*k)+1])
			{
				l=hl[k];
				hl[k]=hl[2*k];
				hl[2*k]=l;
				k=k*2;
			}
			else if(hl[2*k]<hl[(2*k)+1])
			{
				l=hl[k];
				hl[k]=hl[(2*k)+1];
				hl[(2*k)+1]=l;
				k=(k*2)+1;
			}
		}
	}
	return val;
}
int delhr()
{
	long long int k=1,l,val=hr[1];
	hr[1]=hr[szr-1];
	if(szr>1)
	{
		szr--;
		while((hr[k]>hr[2*k] || hr[k]>hr[(2*k)+1]) && (2*k)<szr)
		{
                        if(2*k+1==szr)
                        {
				l=hr[k];
				hr[k]=hr[2*k];
				hr[2*k]=l;
                                return val;
                        }
                        if(hr[2*k]<=hr[(2*k)+1])
			{
				l=hr[k];
				hr[k]=hr[2*k];
				hr[2*k]=l;
				k=k*2;
			}
			else if(hr[2*k]>hr[(2*k)+1])
			{
				l=hr[k];
				hr[k]=hr[(2*k)+1];
				hr[(2*k)+1]=l;
				k=(k*2)+1;
			}
		}
	}
	return val;
}
void insert(long long int ele)
{
	long long int h;
	if(ele>=med)
		inshr(ele);
	else if(ele<med)
		inshl(ele);
	if((szl==szr) || (szl==szr+1) || (szr==szl+1))
	{
		if(szl+1==szr)
			med=hr[1];
		else
			med=hl[1];
	}
	else
	{
		if(szl>szr)
		{
			while(szl!=szr)
			{
				if((szl+1)==szr)
				{
					med=hl[1];
					return;
				}
				h=delhl();
				inshr(h);
			}
			med=hl[1];
			return;
		}
		while(szr!=szl)
		{
			if((szr+1)==szl)
			{
				med=hr[1];
				return;
			}
			h=delhr();
			inshl(h);
		}
		med=hl[1];
	}
	return;
} 
int main()
{
	int t;
	long long int n,sum,x,a,b,c,i,mod=1000000007;
	scanf("%d",&t);
	while(t--)
	{
		szr=1;
		sum=1;
		med=1;
		hl[1]=1;
		szl=2;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		for(i=2;i<n;i++)
		{
			x=(a*med+b*i+c)%mod;
			sum=sum+x;
			insert(x);
		}
		x=(a*med+b*i+c)%mod;
		sum=sum+x;
		printf("%lld\n",sum);
	}
	return 0;
}


