#include <stdio.h>
void print(int *a,int n)
{
	int i=0;
  for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n")	;
}
int main() {
	int i,j,n,t,k,st[1000005],val[1000005];
	scanf("%d",&t);
	while(t--)
	{
		int str=1;
		scanf("%d %d",&n,&k);
		st[0]=-1;
		j=0;
		for(i=1;i<k;i++)
		{
			scanf("%d",&val[i]);
			while(j>0 && val[st[j]]>val[i])
			j--;
			j++;
			st[j]=i;
//			print(st,j+1);
		}
		int r=k;
		for(i=1;i<=n-k+1;i++,r++)
		{
			scanf("%d",&val[r]);
			while(j>=str && val[st[j]]>val[r])
			j--;
			j++;
			st[j]=r;
			if(st[str]<i)
			str++;
			printf("%d",val[st[str]]);
			if(i!=n-k+1)
				printf(" ");
	//  printf("startis:%d\n",str);
//	print(st,j+1);
		}
		printf("\n");
	}
	return 0;
}
