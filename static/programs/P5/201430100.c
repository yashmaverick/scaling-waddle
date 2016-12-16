#include<stdio.h>
int compare_function(const void *a,const void *b)
{
	return (*(int *)a-*(int *)b);
}

int main()
{
	int t,z;
	scanf("%d",&t);

	for(z=0;z<t;z++)
	{
		int flag=0;
		int n,k,c,i;
		scanf("%d %d",&n,&k);  
		getchar();

		int a[n];

		for(i=0;i<n;i++)
		{
			while((c=getchar())!=' ')
				{ ;}

			scanf("%d",&a[i]);
			getchar();
		}

		qsort(a,n,sizeof(int),compare_function);

		//for(i=0;i<n;i++) printf("%d ",a[i] );
		//printf("\n");

		if((a[n-3]+a[n-2]+a[n-1])<k || (a[0]+a[1]+a[2])>k) printf("NO\n");
		else if((a[n-3]+a[n-2]+a[n-1])==k || (a[0]+a[1]+a[2])==k) printf("YES\n");
		else
		{

		for(i=0;i<n-2;i++)
		{
			int temp,j;
			temp=a[i];
			if(temp>=k) { flag=-1; break; }

			for(j=i+1;j<n;j++)
			{
				int temp2=temp+a[j];
				int last=k-temp2;
			//	printf("last%d\n",last);
				if(last<a[j+1]) { break; }
				else if(last==a[j+1] || last==a[n-1]) { flag=1; break; }

				int p=j+1,q=n-1;
				while(1)
				{
					if(p>=q) break;

					int m=(p+q)/2;

					if(a[m]==last) { flag=1; break;}
					else if(last<a[m]) { q=m; }
					else { p=m; }

					if(p==(p+q)/2) break;
				} 
				/*	int u=j+1;
				while(a[u]<=last)
				{
					if(a[u]==last)
					{
						flag=1;
						break;
					}
					u++;
				}*/	

			//	printf("%d\n",flag);

				if(flag!=0) break;

			//	printf("%d\n",flag);
			}
			//	printf("%d\n",flag);

			if(flag!=0) break;

		}

		if(flag==1) printf("YES\n");
		else printf("NO\n");
		}	
	}

	return 0;
}
