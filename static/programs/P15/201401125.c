#include <stdio.h>
#include <limits.h>

#define s(x) scanf("%d", &x)

int a[11111];
int b[11111];
int seg[44444];

int min(int x, int y)
{
    return x > y ? y : x;
}

void create_seg_tree(int l, int r, int ind)
{
    if (l == r)
        seg[ind] = a[l];
    else {
        int m = (l+r)/2, p, q;
        p = 2*ind+1;
        q = p+1;
        create_seg_tree(l, m, 2*ind+1);
        create_seg_tree(m+1, r, 2*ind+2);
        seg[ind] = min(seg[p], seg[q]);
    }
}

int find_min(int st, int ed, int l, int r, int ind)
{
    if (r < st || ed < l)
        return INT_MAX;
    if (st <= l && r <= ed)
        return seg[ind];
    int m = (l+r)/2;
    return min(find_min(st, ed, l, m, 2*ind+1), find_min(st, ed, m+1, r, 2*ind+2));
}

int main()
{
    int t, n, k, i, j;
    s(t);
    while (t--) {
        s(n);
        s(k);
        for (i = 0; i < n; i++)
            s(a[i]);
        create_seg_tree(0, n-1, 0);
        for (i = 0; i < (n-k+1); i++)
            b[i] = find_min(i, i+k-1, 0, n-1, 0);
        for (j = 0; j < (i-1); j++)
            printf("%d ", b[j]);
        printf("%d\n", b[j]);
    }
    return 0;
}
