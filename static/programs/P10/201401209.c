#include<stdio.h>
#include<string.h>
int n;
char a[10000][105];
int main()
{
	scanf("%d",&n);
	char test[10];
	int insertions,power,i;
	int s=0,e=0,size=0;
	while(1)
	{
		scanf(" %[^\n]s",test);
		if(test[0]=='A')
		{
			int l=strlen(test);
			insertions=0;
			power=1;
			for(i=l-1;i>=2;i--)
			{
				insertions=insertions+(test[i]-'0')*power;
				power=power*10;
			}
			while(insertions--)
			{
				if(s==e && size!=0) 
				{
					size++;
					if(size>n) size=n;
					scanf("%s",a[e]);
					e++;
					e=e%n;s=e;
				}
				else
				{
					size++;
					if(size>n) size=n;
					scanf("%s",a[e]);
					e++;
					e=e%n;
				}
			}
		}
		else if(test[0]=='L')
		{
			if(size==n) {for(i=s;i<n;i++) printf("%s\n",a[i]); for(i=0;i<=s-1;i++) printf("%s\n",a[i]);}
			else{ for(i=s;i!=e;i++,i=i%n) {   printf("%s\n",a[i]);    } }
		}
		else if (test[0]=='Q') break;
		else if(test[0]=='R')
		{
			
			int l=strlen(test);
			insertions=0;
			power=1;
			for(i=l-1;i>=2;i--)
			{
				insertions=insertions+(test[i]-'0')*power;
				power=power*10;
			}
			while(insertions--)
			{
				size--;
				if(size<0) size=0;
				s++;
				s=s%n;
			}
		}
		
	}
	return 0;
}
