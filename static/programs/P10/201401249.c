#include<stdio.h>
int capacity,size=0,e=-1,f=0,i;
int input;



void app(char s[][100])
{
	scanf("%d",&input);
	while(input--)
	{
//		printf("size:%d capacity:%d head:%d end:%d\n",size,capacity,f,e);
		if(size<capacity)
		{
			e=(e+1)%capacity;
			scanf("%s",s[e]);
			size=size+1;
		}

		else
		{
			e=(e+1)%capacity;
			scanf("%s",s[e]);
			f=(f+1)%capacity;
		}
	}
}

void list(char s[][100])
{
	if(size==0)
	return ;
	if(f<=e)
		for(i=f;i<=e;i++)
			printf("%s\n",s[i]);

	else
	{
		for(i=f;i<capacity;i++)
			printf("%s\n",s[i]);

		for(i=0;i<=e;i++)
			printf("%s\n",s[i]);
	}
}

void rem(char s[][100])
{
	scanf("%d",&input);
	while(input--)
	{
		if(size==0)
			break;

		else
{
			f=(f+1)%capacity;
size--;
}

	}
}

int main()
{
	scanf("%d",&capacity);

	char s[capacity][100],c;

	scanf("%c",&c);
	scanf("%c",&c);
	while(c!='Q')
	{
		if(c=='A')
			app(s);
		else if(c=='L')
			list(s);
		else if(c=='R')
			rem(s);
		scanf("%c",&c);
		scanf("%c",&c);
	}
	return 0;
}
