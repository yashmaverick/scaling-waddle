#include<string.h>

#include<stdio.h>
#include<stdlib.h>

char A[10010][211];
char str[10100];
long long int ownvar,dude=-1000000000,variabl=100,var2=10000,max=1000000000,size_now=0,maxsizeofqueue,head=-1,tail=-1;
char stringinput[1000];

void subtracting()
{
	if(size_now==0)
	{
		head=tail; return;
	}
	head=(head+1)%maxsizeofqueue; size_now-=1;
}

void adding(char *x)
{
	if(size_now!=0)
	{
		tail=(tail+1)%maxsizeofqueue; strcpy(A[tail],x);
		if(size_now<maxsizeofqueue) size_now++;
        	else if(size_now==maxsizeofqueue) head=(head+1)%maxsizeofqueue;
		return;	
	}
	tail=0; head=0; strcpy(A[tail],x); size_now++;
}

void gettingvalues()
{
	long long int tmpbond=head,i,pp,qq,mm,man,stur;
	for(pp=0;pp<size_now;pp++)
	{
		printf("%s\n", A[tmpbond]); tmpbond=(tmpbond+1)%maxsizeofqueue;
        }
}

void frontofqueue()
{
	if(size_now!=0)
		printf("%s", A[head]);
}

void functchecker(char s[1000])
{
	long long int el,i,j,assign,show,inter=0;
	if(s[0]=='L')
		gettingvalues();
        else if(s[0]=='R')
        {
                scanf("%lld", &el);
                for(i=0;i<el;i++)
			subtracting();
        }
	else if(s[0]=='A')
	{
                scanf("%lld", &el);
                for(i=0;i<el;i++)
                {
			scanf("%s", s); adding(s);
                }
	}
	return;
}

int main()
{
	scanf("%lld", &maxsizeofqueue);
	long long int instat,j,k,kk,pp,qqq;
	scanf("%s", stringinput);
	while(stringinput[0]!='Q')
	{       
 		functchecker(stringinput); scanf("%s", stringinput);
	}
        return 0;
}
