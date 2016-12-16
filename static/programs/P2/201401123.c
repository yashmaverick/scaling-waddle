#include<stdio.h>
typedef long long int L;
#define s(n) scanf("%lld",&n)

L binary(L arr[], L start, L end, L x)
{
	L mid;
		if(arr[start]==x)
			return start;

	if(arr[end-1] < x)
		return end;

	while( start < end )
	{
		mid = start+(end-start)/2;
		if(arr[mid] < x)
			start= mid + 1;
		else if(arr[mid]>x)
			end = mid;
		else if(arr[mid]==x)
			return mid;

	}
	return end;		
}

int main()
{
	L test,p,q,r,a1[100004],i,j,k,Q,temp;
	s(test);
	while(test--)
	{
		s(p);
		L a[p];
		for(i=0;i<p;i++)
			s(a[i]);
		s(q);
		L b[q];
		for(i=0;i<q;i++)
			s(b[i]);
		s(r);
		L c[r];
		for(i=0;i<r;i++)
			s(c[i]);
		if(q>r)
			q=r;
		a1[r]=0;
		for(i=q-1;i>=0;i--)
		{	
			temp = binary(c,i,r,b[i]);
			if(temp!=r)
				a1[i]=a1[i+1]+ r - temp;
			else
				a1[i]= a1[i+1];
		}	
		if(p>q)
			p=q;
		L ans =0;
		for(i=p-1;i>=0;i--)
			ans = ans + a1[binary(b,i,q,a[i])];
		printf("%lld\n",ans);
	}
	return 0;
}
