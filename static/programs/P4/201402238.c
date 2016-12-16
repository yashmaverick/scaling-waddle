#include<stdio.h>
#include<string.h>
int main()
{ int t,n,i=3,k,l,m,count=0,j;
	char s[100005];
	scanf("%d",&t);
	while(t--)
	{ i=3;count=0;j=0;       
		scanf("%s",s);
		n=strlen(s);
		while(i<=n)
		{ for(j=0;j<=n-i;j++)
			{k=j;
				l=i;
				m=0;
				while(l--)
				 m=m+s[k++];
				if(m%233==0)
					count++;
			}
			i=i+3;
		}
		printf("%d\n",count);
	}
	return 0;
}
