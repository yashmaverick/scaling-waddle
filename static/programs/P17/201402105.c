#include<stdio.h>
int main()
{
	int num;
	int i;
	scanf("%d",&num);
	int A[100000];
	int B[100000];
	for(i=0;i<num;i++)
		scanf("%d",&A[i]);
	for(i=0;i<num;i++)
		scanf("%d",&B[i]);
	int test,j,temp;
	scanf("%d",&test);
	while(test--)
	{
		int state=1;
		int stat1=1;
		int stat2=1;
		int a,b,fi,li;
		scanf("%d%d",&a,&b);
		for(i=0;i<num;i++)
		{
			if(B[i]==a)
			{
				stat1=0;
				fi=i;
			}
			if(B[i]==b)
			{
				stat2=0;
				li=i;
			}
			if(stat1==0&&stat2==0)
			{
				break;
			}
		}
		if(fi>li)
		{
			temp=fi;
			fi=li;
			li=temp;
		}
		//		printf("%d%d",fi,li);
		int ans;
		for(i=0;i<num;i++)
		{
			for(j=fi;j<=li;j++)
			{
				if(A[i]==B[j])
				{
					state=0;
					ans=A[i];
					break;

				}
			}
			if(state==0)
			{
				break;
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}

