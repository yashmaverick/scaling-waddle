#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	 int test,t=0,u=0,v=0,p,q,r,s,i1,i2,i3,i4,m,n;
	char c[1000000];
	scanf("%d",&i3);
	for(i4=0;i4<i3;i4++)
	{
		i2=0;t=0;u=0;v=0,n;
		scanf("%s",c);
		i2=strlen(c);
		for(i1=0;i1<i2;i1++)
		{
			if(c[i1]=='J')
				t++;
			if(c[i1]=='M')
				u++;
			if(c[i1]=='R')
				v++;	
		}
		n=t*u*v;
		p=t+u+v;
		s=i2/u;
		if(t==u  && t==v && p==i2)
		{
//			n++;
//			printf("%d\n",n);
			if(n==1)
			{	
				printf("%d\n",1);
			}
			else
			{	
				printf("%d\n",s);
			}
		}
		else
			printf("%d\n",0);

	}
	return 0;
}
