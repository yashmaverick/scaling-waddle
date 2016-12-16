#include<stdio.h>
#include<limits.h>
#define sc(n) scanf("%d",&n)
int main()
{
int t; 
sc(t);
while(t--){ int i,n,a[100003],m=INT_MAX,d,p=0;
	sc(n);
	for(i=0;i<n;i++)
	{sc(a[i]);
		if(m>a[i])m=a[i];
		else
		{d=a[i]-m;if(p<d)p=d;}
}
printf("%d\n",p);
}
}
