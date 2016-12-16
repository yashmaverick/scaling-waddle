#include<stdio.h>
//#include<math.h>
int powr(int p)
{		
	if(p<=0)
	return 1;
	else if(p%2==0)
	return powr(p/2)*powr(p/2);
	else if(p%2==1)
	return powr(p/2)*powr(p/2)*2;
}
/*int powr(int p)
{
    int v=1;

    int b=2;
    while (p!=0)
    {
        if(p&1)
            v=v*b;
        p >>= 1;
        b = b*b;
    }

    return v;
}*/	
int main()
{
	int t,d;
	scanf("%d",&d);
	for(t=0;t<d;t++)
	{
		int n,i,o,t,rep,ans;
		scanf("%d",&n);
		i=0;
		while(1)
		{
		if(n>=powr(i))
		i++;
		else
		break;	
		}
		if(n>=powr(i-1)&&n<=((powr(i)+powr(i-1)-2)/2))
		ans=2*i-3;
		else if(n>=(powr(i)+powr(i-1))/2&&n<=powr(i))
		ans=2*i-2;
		printf("%d\n",ans);
	}
	return 0;
}

		

