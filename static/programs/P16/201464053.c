#include <stdio.h>

#define s(x) scanf("%d", &x)

int main()
{
    int n, x, cnt, tmp;
    s(n);
    while (n--) {
        s(x);
        if (x == 1) {
            printf("0\n");
            continue;
        }
        tmp = cnt = 0;
        while (x != 1) {
            cnt++;
            if (x == 3)
                tmp = 1;
            x /= 2;
        }
        cnt *= 2;
        if (!tmp)
            cnt--;
        printf("%d\n", cnt);
    }
    return 0;
}
