#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define elif else if
#define ss(t) scanf("%s",t)
#define sc(t) scanf("%c",&t)
#define sd(t) scanf("%d",&t)
#define f(i,n) for(i=0;i<n;i++)
#define p(t) printf("%s\n",t)
#define w(t) while(t)
#define agar if
#define warna else
#define ret(a) return a
char a[1000][1000];
char input[1000];
char command;
int main(void)
{int size, n, oldest=0, k=0, done=6;sd(size);w(done){int i;sc(command);agar(!(command-'Q'))done=0;elif(!(command-'A')){sd(n);f(i,n){ss(input);strcpy(a[(oldest+k)%size],input);agar (k!=size) k++; warna oldest=(oldest+1)%size;}}elif(!(command-'R')){sd(n);oldest=(oldest+n)%size;k-=n;}elif(!(command-'L'))f(i,k)p(a[(oldest+i)%size]);} ret(0);}

