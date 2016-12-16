#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a,b,c=0,d=0,e,f,g,h,pre[1000000],in[1000000],tcase,num,fis,las,i,j,z;

	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&pre[i]);
	}
	for(i=0;i<num;i++)
	{
		scanf("%d",&in[i]);
	}
	scanf("%d",&tcase);
	while(tcase--)
	{
		scanf("%d %d",&a,&b);
		for(i=0;i<num;i++)
		{
			if(in[i]==a)
			{
				c=i;
			}
			if(in[i]==b)
			{
				d=i;
			}
		}
//		printf("Ok\n");
		for(i=0;i<num;i++)
		{
			if(pre[i]==a || pre[i]==b)
			{
				z=i;
				break;
			}
		}
//		printf("c=%d d=%d\n",c,d);
		if(c>d)
		{
			fis=d;
			las=c;
		}
		else if(d>c)
		{
			fis=c;
			las=d;
		}
		else
		{
			printf("%d\n",a);
			continue;
		}
//		printf("fis=%d las=%d\n",fis,las);
		h=999999999;
/*		if(a==pre[0] || b==pre[0])
		{
			printf("%d\n",pre[0]);
			continue;
		}
*/
/*		else if(las-fis==2)
		{
			printf("%d\n",in[fis+1]);
			continue;
		}
*/
/*		else if(las-fis==1)
		{
			for(i=0;i<num;i++)
			{
				if(in[las]==pre[i])
				{
					e=i;
				}
				if(in[fis]==pre[i])
				{
					f=i;
				}
			}
			if(e>f)
				printf("%d\n",pre[f]);
			else
				printf("%d\n",pre[e]);
			continue;
		}
*/
	
		
//			printf("fis=%d las=%d\n",fis,las);
			for(i=fis;i<=las;i++)
			{
				for(j=0;j<=z;j++)
				{
//					printf("i=%d pre(j)=%d\n",i,pre[j]);
					if(in[i]==pre[j])
					{
						if(j<h)
							h=j;
//						printf("in if h=%d\n",h);
					}
				}
			}
			printf("%d\n",pre[h]);
	
	}
	return 0;
}
