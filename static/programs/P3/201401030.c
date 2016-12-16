#include<stdio.h>
int main()
{
	int n,test,na,price[100010];
	int i,j,buy,sell,diff,x,y;
	scanf("%d",&n);
	for(test=1;test<=n;test++)
	{
		scanf("%d",&na);
		for(j=0;j<na;j++)
		{
			scanf("%d",&price[j]);
		}
		buy=price[0];
		sell=price[1];
		i=0;j=1;
		if(sell-buy>=0)
			diff=sell-buy;
		else
			diff=0;
		x=0;y=0;
		i=1;j=2;
		while(i<na && j<na)
		{
//			printf("i=%d j=%d buy=%d sell=%d and price[%d]=%d x=%d y=%d\n",i,j,buy,sell,i,price[i],x,y);
			if(buy>price[i])
			{
				buy=price[i];
				x=i;
				sell=price[i+1];
				y=i+1;
			}
			if(price[j]>sell)
			{
				sell=price[j];
				y=j;
			}
			if(x<y && diff<price[j]-buy)
			{
				diff=price[j]-buy;
			}
			i++;
			j++;
		}
		if(diff>0)
			printf("%d\n",diff);
		else
			printf("0\n");
	}
	return 0;
}



