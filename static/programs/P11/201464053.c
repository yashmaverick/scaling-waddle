#include <stdio.h>

#define s(x) scanf("%lld", &x)
#define ll long long int

ll a[101010];
ll stck[101010];

ll max(ll a, ll b)
{
    return (a > b ? a : b);
}

ll find_max_area(ll n)
{
    ll mxArea = 0, tmpArea, i, tmp;
    ll top = 0;
    for (i = 0; i < n; ) {
        if (!top || a[stck[top-1]] <= a[i]) {
            stck[top] = i;
            i++;
            top++;
        }
        else {
            top--;
            tmp = stck[top];
            tmpArea = a[tmp] * (top == 0 ? i : i - stck[top-1] - 1);
            mxArea = max(tmpArea, mxArea);
        }
    }
    while (top) {
        top--;
        tmp = stck[top];
        tmpArea = a[tmp] * (top == 0 ? i : i - stck[top-1] - 1);
        mxArea = max(tmpArea, mxArea);
    }
    return mxArea;
}

int main()
{
    ll n, i;
    s(n);
    while (n != 0) {
        for (i = 0; i < n; i++)
            s(a[i]);
        printf("%lld\n", find_max_area(n));
        s(n);
    }
    return 0;
}
