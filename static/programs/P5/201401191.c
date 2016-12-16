#include<stdio.h>
void merge(int c[],int start,int mid,int end)
{
	int i,j,k=start;
	int tmp[end+1];
	i=start;j=mid+1;
	while(i<=mid&&j<=end)
	{
		if(c[i]<c[j])
		{
			tmp[k++]=c[i];
			i++;
		}
		else
		{
			tmp[k++]=c[j];
			j++;
		}
	}
	while(i<=mid)
	{
		tmp[k++]=c[i];
		i++;
	}
	while(j<=end)
	{
		tmp[k++]=c[j];
		j++;
	}
	for(i=start;i<=end;i++)
	{
		c[i]=tmp[i];
	}
	return;
}
void mergesort(int a[],int start,int end)
{
	int i,j,k;
	int mid;
	mid=(start+end)/2;
	if(start==end)
	{
		return;
	}
	mergesort(a,start,mid);
	mergesort(a,mid+1,end);
	merge(a,start,mid,end);
	return;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j,k,l;
        int count=0;
        scanf("%d%d",&n,&l);
        int a[n];
        char s[10000];
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            scanf("%d",&a[i]);
        }
	mergesort(a,0,n-1);
	int state=0;
        for(i=0;i<n;i++)
        {
	k=n-1;
            for(j=i+1,k=n-1;j<k;)
            {
                    if(a[i]+a[j]+a[k]>l)
                    {
                        k--;
                        continue;
                    }
                    else if(a[i]+a[j]+a[k]==l)
                    {
                        printf("YES\n");
                        state=1;
                        break;
                    }
                    else
                    {
                            j++;
                    }

            }
            if(state==1)
                break;
        }
        if(state==0)
	{
            printf("NO\n");
	}
       // printf("%d\n",count);
    }
    return 0;
}
