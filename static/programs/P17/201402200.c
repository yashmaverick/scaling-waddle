#include<stdio.h>
#include<stdlib.h>
int main()
{

    int test_cases,no_nodes;
    int *p,*i;
    scanf("%d",&no_nodes);
    p=(int *)malloc(sizeof(int)*no_nodes);
    i=(int *)malloc(sizeof(int)*no_nodes);
    int j=0;
    while(j!=no_nodes)
    {
	scanf("%d",&p[j]);
	j++;
    }
    j=0;
    while(j!=no_nodes)
    {
	scanf("%d",&i[j]);
	j++;
    }
    scanf("%d",&test_cases);
    while(test_cases--)
    {
	int js,ww,k,jsi,wwi,flag=0;
	int pno=100000;
	scanf("%d",&js);
	scanf("%d",&ww);
	if(js==ww)
	    printf("%d\n",js);
	else if(js==p[0]||ww==p[0])
	{
	    printf("%d\n",p[0]);
	}
	else
	{
	for(k=0 ;k<no_nodes ;k++)
	{
	    if(i[k]==js)
	    {
		jsi=k;
		if(flag==1)
		    break;
		flag=1;
	    }
	    if(i[k]==ww)
	    {
		wwi=k;
		if(flag==1)
		    break;
		flag=1;
	    }
	}
	if(wwi<jsi)
	{
	    int n=jsi-wwi+1;
	    int l=wwi;
	    while(n--)
	    {
		for(k=0 ; k<no_nodes ;k++ )
		{
		    if(p[k]==i[l])
		    {
			if(pno>k)
			{
			    pno=k;
			}

		    }
		}
		l++;
	    }
	}
	
	else
	{
	    int n=wwi-jsi+1;
	    int l=jsi;
	    while(n--)
	    {
		for(k=0 ; k<no_nodes ; k++ )
		{
		    if(p[k]==i[l])
		    {
			if(pno>k)
			{
			    pno=k;
			}
		    }
		}
		l++;
	    }
	}

		printf("%d\n",p[pno]);
    }
}
}
