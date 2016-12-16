#include<stdio.h>

//#include<math.h>

int p(int m)
{
	int i,p=1;
	for(i=1;i<=m;i++)
		p*=2;
	return p;
}

int main()
{
	int power,x,t,dia,k,q;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++)
	{
//		printf("\ncheck1\n");
		power=0;
		scanf("%d",&q);
//		printf("q=%d\n",q);
			k=q;
//		printf("k=%d\n",k);
			while(k>0)
		 	{
//			printf("k=%d\n",k);
				k=k>>1;
				power++;
			}
			power--;
//		printf("m=%d\n",m);
			k=p(power);
			if(q<(k+k/2))
				dia=2*power-1;
			else
				dia=2*power;
	printf("%d\n",dia);
	}
	return 0;
}

