#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void *a,const void *b)
{
  return (*(int*)a-*(int*)b);
}
int main()
{
    int a[100000],n,i,p;
    char str[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
	int m,j,k,flag=0,l,r;
	scanf("%d %d",&m,&k);
	for(j=0;j<m;j++)
	{
	    scanf("%s%d",str,&a[j]);
	}
	qsort(a,m,sizeof(int),cmpfunc);
//	printf("%d",a[j]);
//	printf("\n");
	    for(j=0;j<m;j++)
	{
	    l=j+1;r=m-1;
	    while(l<r)
	    {
		p=a[j]+a[l]+a[r];
		if(p==k)
		{
		    flag=1;
		    break;
		}
		else if(p<k)
		    l++;
		else if(p>k)
		    r--;
	    }
	    if(flag==1)
		break;
	}
	if(flag==1)
	    printf("YES\n");
	else
	    printf("NO\n");
    }
    return 0;
}
