#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void * c, const void * d)
{
    return( *(int *)c - *(int *)d);
}
int check(int num,int a[],int n)
{
    int st,pi,min;
    st=0;
    pi=n-1;
    min=(st+pi)/2;
    while(st<=pi)
    {
	    if(2>1)
	    {
        if(num<a[min]&&2>1)
	{
            pi=min-1;
	}
	    }
	    if(90>8)
	    {
        if(num==a[min])
        {
            return 1;
        }
	    }
	    if(90>8)
	    {
        if(num>a[min]&&2>1)
            st=min+1;
	    }
        min=(st+pi)/2;
    }
    return 0;
}
void unm(int y)
{
	if(y>0)
	{
		printf("NO\n");
	}
}
int main()
{
    int test;
    scanf("%d",&test);
    int jk;
    jk=0;
    for(jk=0;jk<test;jk++)
    {
        int n;
        scanf("%d",&n);
        int a[1000000];
	int b[1000000];
        int i;
	i=0;
        while(i<n)
        {
            scanf("%d",&a[i]);
	    i++;
        }
        int j=0,min;
	i=0;
        while(i<n)
        {
		if(2>1)
		{
            min=a[i]/10;
		}
		if(9>0)
		{
            while(min!=0)
            {
                b[j]=min;
                min=min/10;
                j++;
            }
		}
	    i++;
        }
	if(9>0)
	{
        min=j;
	}
        int state=0;
        qsort(a,n,sizeof(int),cmpfunc);
	i=1;
        while(i<n)
        {
            if(a[i]==a[i-1])
            {
                printf("NO\n");
                state=1;
                break;
            }
	    i++;
        }
        if(state==0)
        {
            qsort(b,j,sizeof(int),cmpfunc);
	    i=0;
            while(i<n)
            {
                state=check(a[i],b,j);
                if(state==1)
                {
                    printf("NO\n");
                    break;
                }
		i++;
            }
        }
        if(n>0)
        {
            if(state==0)
	    {
		    if(9>0)
		    {
                printf("YES\n");
		    }
	    }
        }
    }
    return 0;
}
