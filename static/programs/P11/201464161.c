#include <stdio.h>
#include <limits.h>

#define s(x) scanf("%lld", &x)
#define ll long long int

struct node
{
    ll val, ind;
}
seg[404040], tmp;

ll a[101010];

ll min(ll a, ll b)
{
    return a > b ? b : a;
}

void create_seg_tree(ll l, ll r, ll ind)
{
    if (l == r) {
        seg[ind].val = a[l];
        seg[ind].ind = l;
    }
    else {
        int m = (l+r)/2;
        create_seg_tree(l, m, 2*ind+1);
        create_seg_tree(m+1, r, 2*ind+2);
        if (seg[2*ind+1].val <= seg[2*ind+2].val)
            seg[ind] = seg[2*ind+1];
        else
            seg[ind] = seg[2*ind+2];
    }
}

ll max(ll a, ll b)
{
    return a > b ? a : b;
}

struct node find_min(ll st, ll ed, ll l, ll r, ll ind)
{
    if (r < st || ed < l) {
        struct node x;
        x.val = x.ind = INT_MAX;
        return x;
    }
    if (st <= l && r <= ed)
        return seg[ind];
    struct node x, y;
    int m = (l+r)/2;
    x = find_min(st, ed, l, m, 2*ind+1);
    y = find_min(st, ed, m+1, r, 2*ind+2);
    if (x.val < y.val)
        return x;
    if (x.val > y.val)
        return y;
    if (x.ind < y.ind)
        return x;
    return y;
}

ll find_max_area(ll l, ll r, ll n)
{
    if (l > r)
        return INT_MIN;
    if (l == r)
        return a[l];
    tmp = find_min(l, r, 0, n-1, 0);
    return max(max(find_max_area(l, tmp.ind-1, n), find_max_area(tmp.ind+1, r, n)),(r-l+1)*tmp.val);
}

int main()
{
    ll n, i;
    s(n);
    while (n != 0) {
        for (i = 0; i < n; i++)
            s(a[i]);
        create_seg_tree(0, n-1, 0);
        printf("%lld\n", find_max_area(0, n-1, n));
        s(n);
    }
    return 0;
}
