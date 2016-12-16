#include <stdio.h>

#define mod 1000000007

long long int power(long long int a, long long int b, long long int m)
{
    if (b == 0)
        return 1;
    long long int x = power(a, b/2, m);
    if (b%2)
        return (((x*x)%m)*a)%m;
    else
        return (x*x)%m;
}

int main()
{
    long long int t, ans, j, k, a[400], u, d, m, n, tmp, i;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld%lld%lld", &u, &d, &m, &n);
        tmp = u/n;
        memset(a, 0, sizeof(a));
        for (i = 0; i < n; i++)
            a[power(i,d,n)] += tmp;
        for (i = tmp*n; i <= u; i++)
            a[power(i,d,n)]++;
        ans = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < n; k++) {
                    if ((i+j+k)%n == m)
                        ans = (ans + (((a[i]*a[j])%mod)*a[k])%mod)%mod;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
