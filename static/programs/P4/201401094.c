#include<stdio.h>
#include<stdlib.h>
typedef struct invariant{
	int a;int b;
}inv;
int  compare(const void *p1,const void *p2)
{
	const inv *e1=p1;
	const inv *e2=p2;
	if(e1->a==e2->a)
		return (e1->b - e2->b);
	else
		return (e1->a - e2->a);
}
print(inv *c,int i)
{
	int j;
	for(j=0;j<i;j++)
		printf("%d :a:%d  b:%d\n",j,c[j].a,c[j].b);
}
int main()
{
  int t,m=0,j=0,r=0,q;
	long long int sum=0;
	scanf("%d",&t);
	inv c[100003];
	char d[100003];
	while(t--)
	{	
		int i=1;
		m=0;j=0;r=0,sum=0;
		c[0].a=0;
		c[0].b=0;
	//	q=getchar();
		scanf("%s",d);
//		printf("%s",d);
		while(d[i-1]!='\0')
		{
			if(d[i-1]=='M')
				m++;
			else if(d[i-1]=='J')
				j++;
			else if(d[i-1]=='R')
				r++;
			c[i].a=m-j;
			c[i].b=j-r;
			i++;
		}
//print(c,i);
		qsort(c,i,sizeof(inv),compare);
  //rint(c,i);
		inv prev;
		prev.a=c[0].a;
		prev.b=c[0].b;
		c[i].a=-1000000;
		c[i++].b=-1000000;
		int cnt=0;
    for(j=1;j<i;j++)
		{
			if(compare(&prev,&c[j])!=0)
			{
				prev.a=c[j].a;
				prev.b=c[j].b;
				sum+=((cnt*(cnt+1))/2);
       cnt=0; 
			}
			else
			cnt++;
	//printf("%d : %d\n",j,cnt);
		}
		printf("%lld\n",sum);
	}
	return 0;
}

