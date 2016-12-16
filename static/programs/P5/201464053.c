#include <stdio.h>
#include <limits.h>

void merge_sort(int a[], int l, int m, int r)
{
    int i, j, k;
    int x[r-l+10], y[r-l+10];
    for (i = l, j = 0; i <= m; i++, j++)
        x[j] = a[i];
    x[j] = INT_MAX;
    for (i = m+1, j = 0; i <= r; i++, j++)
        y[j] = a[i];
    y[j] = INT_MAX;
    for (i = l, j = 0, k = 0; i <= r; i++) {
        if (x[j] < y[k]) {
            a[i] = x[j];
            j++;
        }
        else {
            a[i] = y[k];
            k++;
        }
    }
}

void merge(int a[], int l, int r)
{
    if (l < r) {
        int m = (l+r)/2;
        merge(a, l, m);
        merge(a, m+1, r);
        merge_sort(a, l, m, r);
    }
}

int main()
{
    int t, a[10000], n, sum, i, j, k, tmp;
    char s[10000];
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &sum);
        for (i = 0; i < n; i++)
            scanf("%s%d", s, &a[i]);
        merge(a, 0, n-1);
        for (i = 0; i < (n-2); i++) {
            for (j = i+1, k = n-1; j < k;) {
                tmp = a[i] + a[j] + a[k];
                if (tmp == sum) {
                    printf("YES\n");
                    goto l1;
                }
                else if (tmp < sum)
                    j++;
                else
                    k--;
            }
        }
        printf("NO\n");
        l1: ;
    }
    return 0;
}
