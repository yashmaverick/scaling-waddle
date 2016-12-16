#include<stdio.h>
#include<math.h>
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		int Q,k,j,i,cnt=0;
		scanf("%d",&Q);
		if(Q==1){
			printf("%d\n",0);
			continue;
		}
		i=Q/2;
		while(i>1)
		{
			i=i/2;
			cnt++;
		}
		cnt++;
		k=1<<cnt;
		j=1<<cnt-1;
		if(Q>=k+j)
			printf("%d\n",cnt*2);
		else
			printf("%d\n",cnt*2-1);
	}
	return 0;
}
