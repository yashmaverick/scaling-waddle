#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

long long int size,length = 0,head =-1,tail=-1;
char array[20000][300],input[10000];
void checking_the_input(char check[1000]);
void showing_output();
void adding(char *x);
void removing_from_circular();

int main()
{
	//scanning the maxsize of the circular
	scanf("%lld", &size);
	scanf("%s", input);
	while(input[0]!='Q')
	{       
 		checking_the_input(input); 
 		scanf("%s",input);
	}
        return 0;
}


void checking_the_input(char check[1000])
{
	long long int shortlength,i;
	if(check[0]=='A')
	{
        scanf("%lld", &shortlength);
        for(i=0;i<shortlength;i++)
        {
			scanf("%s", check);
			adding(check);
        }
	}
    else if(check[0]=='R')
    {
        scanf("%lld", &shortlength);
        for(i=0;i<shortlength;i++)
        {
			removing_from_circular();
        }
    }
	else if(check[0]=='L')
	{
		showing_output();
	} 
	return;
}


void showing_output()
{
	long long int temp,i;
	temp = head;
	//printf("%lld -- %lld\n",temp,length );
	for(i=0;i<length;i++)
	{
		printf("%s\n", array[temp]);
		temp=temp+1;
		temp=(temp)%size;
    }
}


void adding(char *x)
{
	if(length!=0)
	{
		tail= tail +1;
		tail = (tail)%size; 
		strcpy(array[tail],x);
		if(length<size)
		{	
		 	length++;
		}
        else if(length==size)
        {
         head=head+1;
         head = (head)%size;
        }
		return;	
	}
	tail=0;
	head=0;
	strcpy(array[tail],x);
	length++;
}
/*
void adding(char *x)
{
	if(length!=0)
	{
		tail=tail+1;
		tail = (tail)%size; 
		strcpy(array[tail],x);
		if(length = size)
        {
        	head=head+1;
        	head = (head)%size;
        }
        else if(length < size)
		{
		 	length++;
		}
		return;	
	}
		tail=0; 
		head=0;
		strcpy(array[tail],x);
		length++;
}
*/
void removing_from_circular()
{
	if(length==0)
	{
		head=tail; 
		return;
	}
	head=head+1;
	head = (head)%size; 
	length-=1;	
}

