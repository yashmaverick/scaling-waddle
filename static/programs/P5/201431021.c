#include<stdio.h>
int comp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
 int main(int argc, char const *argv[])
{
int i,j,k,l,m,n,p,a[200000],z;
char b[500];
scanf("%d",&j);
	for ( m = 0; m < j; m++)
	{ 
		p=0;
		scanf("%d%d",&k,&l);	
		for ( i = 0; i<k; ++i)
		{
			scanf("%s",b);
			scanf("%d",&a[i]);
		}
			qsort(a,k,sizeof(int),comp);
		for ( i = 0; i < k-2; i++)
		{
			int x=i;
			int y=i+1;
			int z=k-1;
			while(y<z)
			{
				if(a[x]+a[y]+a[z]==l)
				{
					p=1;
					printf("YES\n");
					break;
				}
				else if(a[x]+a[y]+a[z]<l)
				{
					y++;
				}
				else
				{
					z--;
				}
		
		}
	if(p==1)
	break;	
		}	
		if(p==0)
			printf("NO\n");
	}
		return 0;
}
