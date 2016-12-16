#include<stdio.h>
typedef long long int ll;
//due to tle we have to use much space , otherwise there's no need to for such big space
ll a[100005]={0},c[100005]={0},b[100005]={0};

//calculating upper bound;;hbond-lbond+1==size of array
int gone(ll key,ll low,ll high,ll l)
{       ll j;
	if(c[l]!=0)
		return;

	if(low>high)
	{    j=-1;
		c[l]=-1;
		return j;
	}

	else if(key>a[low])
	{       j=gone(a[low],low+1,high,low);
		j=low;
	}

	else if(key==a[low])
		j=gone(a[low],low+1,high,low);

	else if(key<a[low])
	{ j=gone(a[low],low+1,high,low);
		j=gone(key,low+1,high,l);       
	}        

	c[l]=j;
	//        printf("'o-%lld-%lld'",c[l],key);
	return j;
}

//calculating lower bound;;hbond-lbond+1==size of array 
int go(ll key,ll low,ll high,ll l,ll lbond,ll hbond)
{       ll i;

//	if(b[l]!=0)
//		return;
	if(low>high)
	{    i=-1;
		b[l]=-1;
		return -1;
	}

	else if(key>a[high])
	{        i=go(a[high],low,high-1,high,lbond,hbond);
		i=high;
	}

	else if(key==a[high])
		i=go(a[high],low,high-1,high,lbond,hbond);

	else if(key<a[high])
	{       i=go(a[high],low,high-1,high,lbond,hbond);
		i=go(key,low,high-1,l,lbond,hbond);
	}

	/*	if(i!=-1 &&c[l]!=-1)
		{  if(b<(key*(c[l]-i-1)))
		b=key*(c[l]-i-1);
		}

		else if(i==-1 && c[l]!=-1)
		{  if(b<(key*(c[l]-lbond)))
		b=key*(c[l]-lbond);
		}

		else if(i!=-1 && c[l]==-1)
		{  if(b<(key*(hbond-i)))
		b=key*(hbond-i);
		}

		else if(i==-1&&c[l]==-1)
		{  if(b<(key*(hbond-lbond)))
		b=key*(hbond-lbond+1);
		}

	//	printf("'%lld %lld-%lld' ",i,key,l);
	 */
	b[l]=i;
	return i;
}

//i==lower bound
//c[]==upper bound

int main()
{       ll  n,i,j,d,l;
	while(1)
	{	scanf("%lld",&n);

		if(n==0)
			break;

		d=0;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		n--;i--;i--;
		j=gone(a[0],1,n,0);
		j=go(a[n],0,i,n,0,n);

		//i=b[l]=lbond ;;j=c[l]==hbond;;  hbond=n lbond=0

		for(l=0;l<=n;l++)
		{	        if(b[l]!=-1 &&c[l]!=-1)
			{  if(d<(a[l]*(c[l]-b[l]-1)))
				d=a[l]*(c[l]-b[l]-1);
			}

			else if(b[l]==-1 && c[l]!=-1)
			{  if(d<(a[l]*(c[l])))
				d=a[l]*(c[l]);
			}

			else if(b[l]!=-1 && c[l]==-1)
			{  if(d<(a[l]*(n-b[l])))
				d=a[l]*(n-b[l]);
			}

			else if(b[l]==-1&&c[l]==-1)
			{  if(d<(a[l]*(n-0+1)))
				d=a[l]*(n-0+1);
			}
		}	
		printf("%lld\n",d);

		//again intializing b&c array with 0; to decrease time
		n++;
		for(i=0;i<=n;i++)
		{ b[i]=0;
		   c[i]=0;
		   }
		//		n++;            
		//		for(i=0;i<n;i++)
		//			printf("'%lld-%lld' ",c[i],b[i]);


		//ll key,ll low,ll high,int l,int lbond,int hbond	
	}
	return 0;

}       
