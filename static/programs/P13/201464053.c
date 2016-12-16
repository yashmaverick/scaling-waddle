#include <stdio.h>
#include <limits.h>

#define s(x) scanf("%d", &x)

int seg[404040];
int a[101010];
int tmp[101010];
int mx, mn;

void create_seg_tree(int l, int r, int ind)
{
    if (l == r)
        seg[ind] = a[l];
    else {
        int m = (l+r)/2;
        int p = 2*ind+1;
        int q = p+1;
        create_seg_tree(l, m, p);
        create_seg_tree(m+1, r, q);
        seg[ind] = seg[p] > seg[q] ? seg[p] : seg[q];
    }
}

int find_max(int st, int ed, int l, int r, int ind)
{
    if (st > ed)
        return INT_MIN;
    if (r < st || ed < l)
        return INT_MIN;
    if (st <= l && r <= ed)
        return seg[ind];
    int m = (l+r)/2;
    int p = 2*ind+1;
    int q = p+1, tmp1, tmp2;
    tmp1 = find_max(st, ed, l, m, p);
    tmp2 = find_max(st, ed, m+1, r, q);
    return tmp1 > tmp2 ? tmp1 : tmp2;
}

void find_deepest_node(int l, int r, int depth, int n, int lv, int rv)
{
    if (l == r) {
        if (mx < depth) {
            mx = depth;
            mn = tmp[l];
        }
        else if (mx == depth && mn > tmp[l])
            mn = tmp[l];
    }
    else if (l < r) {
        int tmp2 = tmp[r];
        r--;
        int ind = find_max(lv, tmp2-1, 0, n, 0);
        if (ind < l)
            find_deepest_node(l, r, depth+1, n, lv+1, rv);
        else {
            find_deepest_node(l, ind, depth+1, n, lv, tmp2-1);
            find_deepest_node(ind+1, r, depth+1, n, tmp2+1, rv);
        }
    }
}

int main()
{
    int t, n, i, y;
    s(t);
    while (t--) {
        s(n);
        for (i = 0; i < n; i++) {
            s(y);
            tmp[i] = y-1;
            a[y-1] = i;
        }
        create_seg_tree(0, n-1, 0);
        mx = INT_MIN;
        mn = INT_MAX;
        find_deepest_node(0, n-1, 0, n-1, 0, n-1);
        printf("%d %d\n", mn+1, mx);
    }
    return 0;
}
