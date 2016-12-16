#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t!=0)
	{	
		int q,h,p1,p2;
		scanf("%d",&q);
		h= log10(q)/log10(2);
		//printf("%d\n",h);
		p1=pow(2,h);
		p2=pow(2,h+1);
		if(q< (p1+p2)/2 )
			printf("%d\n",2*h -1);
		else
			printf("%d\n",2*h);
		t--;
	}
return 0;
}
