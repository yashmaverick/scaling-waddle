#include<stdio.h>
#include<string.h>
#include<stdio.h>

long long int max;
char a[100000][100];
long long int count;
int main()
{

long long int firstptr=0,pindex=-1,NUM,val1,spare; char use;
scanf("%lld",&NUM);
//getchar();
scanf("%c",&use);
	while(use!='Q')
	{
		if(use=='A')
		{
			long long int i;
			scanf("%lld",&val1);
			for(i=0;i<val1;i++)
			{
				count++;
				
				if(count>NUM){
					firstptr++;
					if(firstptr==NUM)
						firstptr=0;
					count--;
				}
				pindex++;
				if(pindex==NUM)
					pindex=0;
				scanf("%s",a[pindex]);
			}
            //printf("done\n");
		}
		else if(use=='R')
		{
			long long int j=0,n1;
			scanf("%lld",&n1);
			while(count!=0&&j<n1)
			{
				count--;
				firstptr++;
				if(firstptr==NUM)
					firstptr=0;
				j++;
			}

		}
		else if(use=='L')
		{
            //printf("loading FIRSTPTR %lld\n",firstptr);
			spare=firstptr;
            int i=0;
			while(i<count)
			{
				printf("%s\n",a[spare]);
				spare++;
				if(spare==NUM)
					spare=0;
                i++;
			}
		}
		//scanf("%c",&use);
		use=getchar();

	}
	if(use=='Q')
		return 0;
return 0;
}
