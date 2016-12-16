#include <stdio.h>
#include <string.h>

int main()
{
    int t, k, top, ans, i, p[100010];
    char a[100010], s[100010];
    scanf("%d", &t);
    while (t--) {
        scanf("%s", a);
        k = strlen(a);
        top = 1;
        memset(p, 0, sizeof(p));
        ans = 0;
        for (i = 0; i < k; i++) {
            if (top >= 3) {
                s[top++] = a[i];
                if ((s[top-1] == 'J' || s[top-2] == 'J' || s[top-3] == 'J') && (s[top-1] == 'R' || s[top-2] == 'R' || s[top-3] == 'R') && (s[top-1] == 'M' || s[top-2] == 'M' || s[top-3] == 'M')) {
                    top -= 3;
                    p[top-1]++;
                    ans += p[top-1];
                }
            }
            else
                s[top++] = a[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
