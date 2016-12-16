#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		char st[100005];
		scanf("%s", st);
		long long int size = strlen(st);
		long long int J[100005]={0}, M[100005]={0}, R[100005]= {0};
		long long int i,j,k,ans = 0;
		for(i=0;i<size;i++)
		{
			J[i] = 0;
			M[i] = 0;
			R[i] = 0;
		}



		if(st[0]=='J')
			J[0]++;
		if(st[0]=='M')
			M[0]++;
		if(st[0]=='R')
			R[0]++;

		for(i=1;i<size;i++)
		{
			if(st[i]=='J')
				J[i] = J[i-1]+1;
			else
				J[i] = J[i-1];
			if(st[i]=='M')
				M[i] = M[i-1]+1;
			else
				M[i] = M[i-1];
			if(st[i]=='R')
				R[i] = R[i-1]+1;
			else
				R[i] = R[i-1];
		}

		for(i=2;i<size;i++)
		{
			if(J[i]==M[i])
			{
				if(M[i]==R[i])
					ans++;
			}
		}



		for(i=1;i<size;i++)
		{
			for(j=i+1;j<size;j++)
			{
			//for(k=i;k<=j;k++)
			//	printf("%c",st[k]);
			//printf("\n");
			//printf("J = %lld\n", J[j]-J[i-1]);
			//printf("M = %lld\n", M[j]-M[i-1]);
			//printf("R = %lld\n", R[j]-R[i-1]);


				if((J[j]-J[i-1])== (M[j]-M[i-1]) && (R[j]-R[i-1]) == (J[j]-J[i-1]))
					ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}