#include<stdio.h>
#define ll long long int 

int max(int a,int b)
{
	if(a>b)return a;
	else return b;
}
int main()
{
	int i,j,c,n,k;
	int p=1,po[37],q;
	po[0]=1;
	for(i=1;i<=35;i++)
	{
		p=p*2;
		po[i]=p;
	}
	scanf("%d",&n);
	while(n--)
	{
		k=0;
		scanf("%d",&q);
		if(q==1)
			printf("0\n");
		else
		{
			p=q;c=0;
			while(p/2>0)
			{
				p=p/2;
				c++;
			}
			j=(po[c+1]-1-po[c])/2;
			if(po[c]+j<q)
				printf("%d\n",2*c);
			else
			{
				/*while(po[c]+j>=q)
				  {
				  k--;
				  j=j/2;
				  }
				  printf("%d\n",max(c,2*c+2*k));
				  */
				//if(c%2==0)
					printf("%d\n",2*c-1);
				//else
					//printf("%d\n",2*c-2);
			}
		}
	}
	return 0;
}
