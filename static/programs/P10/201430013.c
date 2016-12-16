#include<stdio.h>
#include<stdlib.h>
int content,dest=0,track=0,LIMIT,state;
char a[10010][105];
void append()
{
	int n,i;
	scanf("%d",&n);
	if(n>=LIMIT-content)
		state=1;
	content+=n;
	for(i=dest;i<dest+n;i++)
	{
		scanf("%s",a[i%LIMIT]);
//		printf("%s\n",a[i%LIMIT]);
	}
	if(content>LIMIT)
		content=LIMIT;
	dest+=n;
	dest=dest%LIMIT;
	if(state==1)
		track=dest;
}
void remov()//O.K.
{
	int n;
	scanf("%d",&n);
	if(content<n)
		n=content;
	track+=n;
	track=track%LIMIT;
	content-=n;
}
void list()//O>K>
{
	if(content==0)
		return;
	int i;
	if(track<dest)
		for(i=track;i<dest;i++)
		{
//			if(a[i]!='\0')
				printf("%s\n",a[i]);
		}
	else if(track>dest||track==dest&& LIMIT==content)
	{
		for(i=track;i<LIMIT;i++)
		{
//			if(a[i]!=='\0')
				printf("%s\n",a[i]);
		}
		for(i=0;i<dest;i++)
		{
	//		if(a[i]!=='\0')
				printf("%s\n",a[i]);
		}
	}
}
int main()
{
	scanf("%d",&LIMIT);
	int c,i;
	getchar();
	while((c=getchar())!='Q')
	{
		state=0;
		if(c=='A')
			append();
		if(c=='R')
			remov();
		if(c=='L')
			list();
		if(c=='P')
			printf("dest=%d,track=%d\n",dest,track);
		if(c=='C')
			printf("content=%d\n",content);
	}
	return 0;
}



