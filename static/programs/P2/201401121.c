#include<stdio.h>
typedef long long int LL;
//#include<iostream>
//using namespace std;
int p;
/*long long int bisearch(int size,int el,int a[])
  {
  int low=0,high=size;
  long long  int mid=(low+high)/2;
  while(low<=high)
  {

  mid=(low+high)/2;

  if(a[mid]>el)
  {
  high=mid-1;
  }
  else if(a[mid]<el)
  {
  low=mid+1;
  }
  else
  {
  cout<<"mid  "<<mid<<"\n";
  if(mid+1<p)
  {
  if(a[mid+1]>el)
  return mid+1;
  else
  low=mid+1;
  }
  else
  return mid+1;
  }
//	mid=(low+high)/2;
}
cout<<"mid  "<<mid<<"\n";
if(a[mid]>el)
return mid;
else return mid+1;
}*/
LL bis(int A[], int l, int r, int key)
{
	if(key<A[0])
		return 0;
	int m;

	while( r - l > 0)
	{
		m = (l +r+1)/2;

		if( A[m] > key )
			r=m-1;
		else
			l=m;
	}
	if(A[m]>key)
		return l;

	return l+1;
}
LL bisearch(int low,int high,int item,int  a[])
{
	if(low==high)
	{
		if(a[high]>item)
		{
			//	cout<<"high "<<high<<"\n";
			return high;
		}
		else
		{
			//	cout<<"high "<<high+1<<"\n";
			return high+1;
		}
	}
	int mid=(low+high+1)/2;
	//	cout<<"mid  "<<mid<<endl;
	if(a[mid]>item)
		return bisearch(low,mid-1,item,a);
	else
		return bisearch(mid,high,item,a);
}
int main()
{
	int a[100005],b[100005],c[100005];
	long long int cnt;
	int q,r;
	int t,m=0,n=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&p);
		int i=0;
		cnt=0;
		for(;i<p;i++)
			scanf("%d",&a[i]);

		scanf("%d",&q);
		for(i=0;i<q;i++)

			scanf("%d",&b[i]);

		scanf("%d",&r);
		for(i=0;i<r;i++)
			scanf("%d",&c[i]);
		m=0;
		n=0;
		while(m<q&&n<r)
		{
			if(c[n]>=b[m]&&n>=m)
			{
				int q=m;
				if(m>=p)
					q=p-1;

				cnt+=bisearch(0,q,b[m],a)*(long long int)(r-n);
						
				//		cout<<"val "<<b[m]<<endl;
				//			cout<<"cnt "<<cnt<<endl;

				//		cout<<"cnt "<<cnt<<endl;
				m++;
			}
			else
			{
				n++;
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}



