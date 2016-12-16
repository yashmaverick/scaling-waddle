#include<stdio.h>
#define MOD 1000000007
typedef long long int ll;
ll a1[100];
int search2(int b[10000],int n1,int k1)
{int f,l,mid;
	f=0;
	l=n1-1;
	while(f<=l)
	{mid=(f+l)/2;
		if(b[mid]==k1)
		{if(mid==n1-1)
			return n1-1;
			if(b[mid+1]>k1)
			return mid;
			if(b[mid+1]==k1)
				f=mid+1;
		
		}
		else	
			if(b[mid]>k1)
			{l=mid-1;
	
			}
			else	
				if(b[mid]<k1)
							f=mid+1;
	}
	return 0;
}
int search1(int a[10000],int n,int k)
{int f,l,mid;
	f=0;
	l=n-1;
	while(f<=l)
	{mid=(f+l)/2;
		if(a[mid]==k)
		{if(mid==0)
			return 0;
			if(a[mid-1]<k)
			return mid;
			if(a[mid-1]==k)
				l=mid-1;
	             	     
		}
		else
		if(a[mid]>k)
			{l=mid-1;}
           else
              if(a[mid]<k)
                  f=mid+1;
            }
return 0;
}

ll mpow(ll base,ll expo,ll mod);

int main()
{
ll upper, d, ans;
	ll t, m, n, i, j, k, temp;
	scanf("%lld", &t);
	while(t--) {
		ans = 0;
		for (i = 0; i < 40; i++) {
			a1[i] = 0;
		}
		scanf("%lld%lld%lld%lld", &upper, &d, &m, &n);
		k = upper / n;
		if (k != 0) {
			for (i = 0; i < n; i++) {
				temp = mpow(i, d, n);
				a1[temp] += k;
			}
		}
		k = upper%n;
		for (i = 0; i <= k; i++) {
			temp = mpow(i, d, n);
			a1[temp]++;
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				for (k = 0; k < n; k++) {
					if (((i+j+k)%n) == m) {
						if (a1[i] != 0 && a1[j] != 0 && a1[k] != 0) {
							ans = (ans+(((a1[i]*a1[j])%MOD)*a1[k])%MOD)%MOD;
						}
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
ll mpow(ll base,ll expo,ll mod)
{
	if (base == 0 && expo == 0) {
		if (mod == 1) {
			return 0;
		} else {
			return 1;
		}
	}
	ll res = 1;
	while (expo > 0) {
		if (expo%2) {
			res = (res * base) % mod;
		}
		expo = expo/2;
		base = (base*base) % mod;
	}
	return res;
}

