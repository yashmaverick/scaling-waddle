#include<stdio.h>
long long int a[1000000],s,g,q[1000000],v[100000],n[1000000],c;
void depth(long long int l,long long int h,long long int d)
{
	int j,x,z;
	x=0;
	z=0;
	j=0;
	if(l>h)
	{
		return;
	}
	if(l==h)
	{
		if(d>g)
		{
			g=d;
			s=a[l];
		}
		else if(d==g)
		{
			if(s>a[l])
			{
				s=a[l];
			}
		}
		return;
	}
	d++;
	j=v[h];
	depth(l,j,d);
	depth(j+1,h-1,d);

}
void stack(long long int m)
{
	long long int i,j,k;
	i=m-1;
	j=0;
	q[0]=a[m-1];
	n[0]=m-1;
	while(i>0)
	{
            if(q[j]>a[i-1] )
	    {
		    if(j==0)
		    {
			    q[j]=a[i-1];
			    v[n[0]]=i-1;
			    if(v[n[0]]!=0)
			    {
				    c=1;
			    }
			    n[0]=i-1;
			    i--;
		    }
		    else
		    {
			   // q[j]=a[i-1];
			    v[n[j]]=i-1;
			    if(v[n[j]]!=0)
			    {
				    c=1;
			    }
			    j--;
		    }
            }
	    else
	    {
		    j++;
		    i--;
		    q[j]=a[i];
		    n[j]=i;
	    }

	}
	if(j!=0)
	{
		
		while(j>=0)
		{
			v[n[j]]=0;			
			j--;
		}

	}
	v[0]=0;
	



}
int main()
{
	long long int i,j,m,n;
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld",&m);
		i=0;
		while(i<m)
		{
                 scanf("%lld",&a[i]);
		 i++;
		}
		stack(m);
		depth(0,m-1,0);
                
/*		i=0;
		while(i<m)
		{
			printf("%lld ",v[i]);
			i++;
		}
		printf("\n");*/
		
	        if((c==0)&&(a[0]>a[1]))
		{
			printf("%lld %lld\n",a[0],m-1);

		}
		else
		{
		printf("%lld %lld\n",s,g);
		}
		c=0;
		g=0;
		s=99999999;

//		printf("\n");
	}

	return 0;
}
