#include<stdio.h>
char A[10001][101];
int size;
int first=0;
int last=0;
int jugad=0;
inline void insert(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
	if(jugad<size)
	{
	    jugad++;
	}
	scanf("%s",A[last%size]);
	last++;
	if(last>size&&(first%size)==(last-1)%size)
	{
	    first++;
	}
    }
}
inline void delete(int n)
{
    first=first+n;
    jugad=jugad-n;
}
inline void print()
{
    int j=jugad;
    int i=first;
    while(j--)
    {
	printf("%s\n",A[i%size]);
	i++;
    }
}
int main()
{
    int n,i;
    char c;
    scanf("%d",&size);
    while((c=getchar_unlocked())!='Q')
    {
	if(c=='A')
	{
	    scanf("%d",&n);
	    insert(n);
	}
	else if(c=='L')
	{
	    print();
	}
	else if(c=='R')
	{
	    scanf("%d",&n);
	    delete(n);
	    if(first==last)
	    {
		first=last=0;
	    }
	}
    }
    return 0;
}
