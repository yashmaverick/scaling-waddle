#include<stdio.h>
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int main()
{        int i,b,g,j,n,k,m,l,a[1005],t;
	char s[1005];
	scanf("%d",&t);
	while(t--)
	{       b=0,k=0,i=0;
		scanf("%d%d",&n,&m);
		while(n--)
		{ scanf("%s",s);
			scanf("%d",&a[k]);
			if(a[k]>=m)
				a[k]=0;
			k++;
		}               
		qsort(a,k,sizeof(int), cmpfunc);    
		for(i=0;i<(k-2)&&b==0;i++)
		{ if(a[i]==0)
			;
			else
			{j=i+1;g=(k-1);       
				while(j<g&&b==0)
				{   l=a[i]+a[j]+a[g];
					if(l>m)
						g--;
					else if(l<m)
						j++;
					else if(l==m)
						b=1;
				}
			}       
		}
		if(b==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
