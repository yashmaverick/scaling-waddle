#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare (const void * a, const void * b)
{
    return ( *(long long int*)a - *(long long int*)b );
}

#define jhash -1000200
#define mhash 101
#define rhash 1000099

char s[1000006];
long long int arr[10000001];
	    
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
	    long long int len = strlen(s),i;
	    long long int count=1,ans=0,temp,countzero=0;
	    for (i = 0; i < len; i++)
	    	arr[i]=0;

			if(s[0]=='J')
	    		arr[0]=jhash;
	    	else if(s[0]=='M')
	    		arr[0]=mhash;
	    	else if(s[0]=='R')
	    		arr[0]=rhash;

	    for (i = 1; i < len; i++)
	    {
	    	if(s[i]=='J')
	    		temp=jhash;
	    	else if(s[i]=='M')
	    		temp=mhash;
	    	else if(s[i]=='R')
	    		temp=rhash;

	    	arr[i]=arr[i-1]+temp;
	    }

	    qsort(arr, len, sizeof(long long int), compare);
	    /*for(i=0;i<len;i++)
	    	printf("%lld ",arr[i]);
	    printf("\n");*/
	    	
	    for(i=0;i<len-1;i++)
        {
            if(arr[i]==arr[i+1])
          		count++;
            else
            {
                ans+=((count*(count-1))/2);
                count=1;
            }
            if(arr[i]==0){
            	countzero++;
            }
        }
        if(arr[len-1]==0)
        	countzero++;
        
        ans+=(count*(count-1))/2;
        
        printf("%lld\n",ans+countzero);
	}
	return 0;
}