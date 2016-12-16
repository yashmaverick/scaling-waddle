#include <stdio.h>
#include <string.h>

#define add 10000000

long long int a[20000020];

int main()
{
    int t, n, i, x, tmp;
    long long int ans;
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            tmp = x+add;
            ans += a[tmp];
            a[tmp]++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
