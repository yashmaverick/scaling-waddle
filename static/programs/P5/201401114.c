#include<stdio.h>
void bubblesort(int a[], int N)
{
	int i,j,temp;
	for(i=0; i<N; i++)
		for(j=0; j<N-i-1; j++)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
}		
int main()
{
	int T, K, N, i, n;
	int a[1001];
	char name[100000];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d",&N, &K);
		for(i=0; i<N; i++)
		{
			scanf("%s", name);
			scanf("%d", &a[i]);
		}

		bubblesort(a,N);
		int flag=0;
		int p1,p2;

		for(i=0; i<N-2; i++)
		{
			p1=i+1;
			p2=N-1;
			while(p1<p2)
			{
				if((a[i]+a[p1]+a[p2])==K)
				{
					printf("YES\n");
					flag=1; break; 
				}
				else if((a[i]+a[p1]+a[p2])<K)
					p1++;
				else 
					p2--;
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("NO\n");
	}
	return 0;
}




