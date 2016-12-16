#include<stdio.h>
#include<string.h>


#define N  100012


long long int ASCII[N];


int QUICK_SORT( int end , int start)
{
	long long int TEMP;
	int anchor, wall,i;

	if(start >= end)
		return 0;

	TEMP=ASCII[(start+end)/2];
	ASCII[(start+end)/2]=ASCII[end];
	ASCII[end]=TEMP;
	anchor = end; wall=start;
	i=start;
	while( i<anchor)
	{
			if(ASCII[i] <= ASCII[anchor])
			{
				TEMP=ASCII[i];
				ASCII[i]=ASCII[wall];
				ASCII[wall]=TEMP;
				wall++;
			}
		i++;
	}
	TEMP=ASCII[wall];
	ASCII[wall]=ASCII[anchor];
	ASCII[anchor]=TEMP;
	QUICK_SORT(wall-1 , start);
	QUICK_SORT(end , wall+1);

	return 0;
}
int main()
{
	long long int t, i, j, n, TEST;
	char string[N];
	int Aplha=100001,Beta=1,Omega=-100002;

	scanf("%lld",&TEST);
	while(TEST>0)
	{
		long long int Count=1,sum=0;
		scanf("%s",&string);
		n = strlen(string)+1;
		ASCII[0] = 0;
		for(i=1;i<n;i++)
		{
			if(string[i-1] =='J')
				ASCII[i] = ASCII[i-1] + Aplha;
			if(string[i-1]=='R')
				ASCII[i] = ASCII[i-1] + Beta;
			else if(string[i-1]=='M')
				ASCII[i] = ASCII[i-1] + Omega;
		//ASCII[i] = ASCII[i-1] + ( s[i-1] =='J' ? Jn : ( s[i-1]=='R' ? Rn : Mn ) );
		}

		QUICK_SORT(n-1,0);
		i=1;
		while(i<n)
		{
			if(ASCII[i]==ASCII[i-1])
				Count++;
			else
			{
				sum += Count*(Count-1)/2;
				Count = 1;
			}
			i++;
		}
		
		printf("%lld\n",(sum + Count*(Count-1)/2));
		TEST--;
	}
}
