#include <stdio.h>

#define get getchar

char a[10000][110];

int scan()
{
    int n = 0, ch = get();
    while (ch < '0' || ch > '9')
        ch = get();
    while (ch >= '0' && ch <= '9') {
        n = (n << 3) + (n << 1) + ch - '0';
        ch = get();
    }
    return n;
}

char read()
{
    char ch = get();
    while (ch < 'A' || ch > 'Z')
        ch = get();
    return ch;
}

void readS(char x[])
{
    int n = 0;
    char ch = get();
    while (!((ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z')))
        ch = get();
    while ((ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z')) {
        x[n++] = ch;
        ch = get();
    }
    x[n] = '\0';
}

int main()
{
    int n, m, tmp;
    n = scan();
    char q;
    q = read();
    int st = -1;
    int ed = -1;
    while (q != 'Q') {
        if (q == 'A') {
            m = scan();
            while (m--) {
                st = (st+1)%n;
                if (st == ed && a[ed][0] != '\0')
                    ed = (ed+1)%n;
                readS(a[st]);
                if (ed == -1 && st >= 0)
                    ed = 0;
            }
        }
        else if (q == 'R') {
            m = scan();
            while (m--) {
                a[ed][0] = '\0';
                ed = (ed+1)%n;
            }
        }
        else if (a[ed][0] != '\0') {
            tmp = ed;
            while (tmp != st) {
                printf("%s\n", a[tmp]);
                tmp = (tmp+1)%n;
            }
            printf("%s\n", a[tmp]);
        }
        q = read();
    }
    return 0;
}
