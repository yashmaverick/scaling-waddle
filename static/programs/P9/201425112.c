#include <stdio.h>
#include <stdio.h>
#include <malloc.h>

typedef struct bag
{
	int start;
	int end;
	int netwt;
}bag;

int main()
{ 
	int n;
	scanf("%d", &n);
	
	long long int mod;
	scanf("%lld", &mod);
	
	int wt[2000000];
		
	struct bag *obj;
	obj = (struct bag *)malloc((sizeof(struct bag))*n);
	
	int index;
	index=0;
	
	int i;
	for(i=0; i<n; i++)
	{
		int m;
		scanf("%d", &m);
		
		obj[i].start=index;
		
		obj[i].end=(index+m-1);
		
		obj[i].netwt=0;
		
		int j;
		for(j=0; j<m; j++)
		{
			scanf("%d", &wt[index]);
			
			(obj[i].netwt)=(obj[i].netwt)+wt[index];
//			(obj[i].netwt)=((obj[i].netwt)%mod+wt[index]%mod)%mod;
			(obj[i].netwt)=(obj[i].netwt)%mod;
			index=index+1;
		}
		
		(obj[i].netwt)=(obj[i].netwt)%mod;		
	}
	
	for(i=0; i<n; i++)
	{
		int j;
		for(j=i+1; j<n; j++)
		{
			if((obj[j].netwt)<(obj[i].netwt))
			{
				struct bag temp;
				
				temp = obj[i];
				obj[i]=obj[j];
				obj[j]=temp;
			}
		}
	}
	
	for(i=0; i<n; i++)
	{
		printf("%d\n", (obj[i].netwt));
		
		int j;
		for(j=(obj[i].start); j<=(obj[i].end); j++)
		{
			printf("%d\n", wt[j]);
		}
		printf("\n");
	}
	
	return 0;
}
