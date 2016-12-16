#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int n,cum;
    int temp;
    char nights[1005];
    int value[1005];
    int i,j,l,k;
    //int *s,*m,*e;
    for(i=0;i<t;i++)
    {
	scanf("%d%d",&n,&cum);
	for(j=0;j<n;j++)
	    scanf("%s%d",&nights,&value[j]);
	for(j=0;j<n-1;j++)
	    for(k=0;k<n-j-1;k++)
		if(value[k]>value[k+1])
		{
		    temp=value[k];
		    value[k]=value[k+1];
		    value[k+1]=temp;
		}
	int sum=0;	
	int flag=0;
	for(j=0;j<n-2;j++)
	{
	    for(k=j+1,l=n-1;k<l;)
	    {
		sum =value[j]+value[k]+value[l];

		if(sum==cum)
		{
		    printf("YES\n");
		    flag=1;
		    break;
		}
		else if (sum>cum)
		    l--;
		else
		    k++;
	    }
	    if(flag==1)
		break;
	}
	if (flag==0)
	    printf("NO\n");
    }
    return 0;
}


