
#include<stdio.h>
#include<stdlib.h>

char str[10000];
long long int max=1000000000,cursiz=0;
long long int top=-1,tail=-1;


long long int moding(long long int x)
{
x=(x+1)%max;
return x;
}
char A[10000][301];
char *strcpy(char *dest, const char *src)
{
  unsigned i;
  for (i=0; src[i] != '\0'; ++i)
    dest[i] = src[i];
  dest[i] = '\0';
  return dest;
}

void removing()
{
	if(checkifempty(cursiz))
	{
		top=tail; 
		return;
	}
	top=moding(top); 
	cursiz=cursiz-1;
}
int checkifempty(int x)
{
if(x==0)
return 1; 
return 0;
}
int checkchar(char y, char x)
{
if(y==x)
return 1;
else 
return 0;
}
int checkifmax()
{
if(cursiz==max)
   return 1;
if(cursiz<max)
return 0;
}



char kfc[1000];


void topapaing(char *x)
{
	if(cursiz!=0)
	{
		tail=moding(tail); 
		strcpy(A[tail],x);
                if(checkifmax()) 
			top=moding(top);
		if(!checkifmax()) 
			cursiz=cursiz+1;
        	
		return;	
	}
	tail=0; top=0;
        strcpy(A[tail],x); 
        cursiz=cursiz+1;
}

void finding()
{
	long long int tmpbond=top,papa;
	for(papa=0;papa<cursiz;papa++)
	{
		printf("%s\n", A[tmpbond]); 
                tmpbond=moding(tmpbond);
        }
}

void topapaer()
{
	if(checkifempty(cursiz)!=0)
		printf("%s", A[top]);
}
void functioncheck(char s[1000])
{
	long long int srt,i;
         if(checkchar(s[0],'R'))
        {
                scanf("%lld", &srt);
                for(i=0;i<srt;i++)
			removing();
        }
	
       
        if(checkchar(s[0],'A'))
	{
                scanf("%lld", &srt);
                for(i=0;i<srt;i++)
                {
			scanf("%s", s); 
                        topapaing(s);
                }
	}
        if(checkchar(s[0],'L'))
		finding();
	return;
}


int main()
{
	scanf("%lld", &max);
	scanf("%s", kfc);
	while(kfc[0]!='Q')
	{       
 		functioncheck(kfc);
                scanf("%s", kfc);
	}
        max=1000000000;
        cursiz=0;
        top=-1;
	tail=-1;
        return 0;
}
