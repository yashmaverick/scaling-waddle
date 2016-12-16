#include<stdio.h>

char A[10000][101];
int N; 
int s;
int sz;

void print()
{
    int i;
    for(i=0; i<sz; i++)
    {
        int j = i+s; if(j>=N)j-=N;
        printf("%s\n",A[j]);
    }
}

void rm()
{
    int x;
    scanf("%d",&x);
    s+=x; 
    if(s>=N)s-=N;
    sz-=x;
}

void append()
{
    int n; scanf("%d",&n);
    while(n--)
    {
        int j = sz+s; if(j>=N)j-=N;
        scanf("%s",A[j]);
        sz++;
    }
}

int main()
{
    s=0; sz=0;
    scanf("%d",&N);
    while(1)
    {
        char ch[4]; 
        scanf("%s",ch);
        if(ch[0]=='L')print();
        if(ch[0]=='R')rm();
        if(ch[0]=='A')append();
        if(ch[0]=='Q')break;
    }
    return 0;
}
