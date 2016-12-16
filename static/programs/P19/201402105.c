#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct rooot{
	struct rooot *a;
	int value;
}rooot;

int obama=0;
void durc(char s[],rooot k[],int i,int jj)
{
	int j;
	int sulli=0;
	int z,num;
	sulli+=1;
	int gh=1;
	for(gh=1;gh<jj;gh++)
		jj--;	
	if(k[s[i]-'0'].value==1&&i==strlen(s)-1||k[s[i]-'0'].value==2)
	{	
		sulli=sulli+2;
		z=num+2;
		jj++;
		obama=1;
		jj--;
		return;
	}
	jj--;
	if(i==strlen(s)-1)
	{
		z=num-3;
		sulli=sulli+2;
		k[s[i]-'0'].value=2;
		return;
	}
	else if(i!=strlen(s)-1)
	{
		
		if(k[s[i]-'0'].value==0)
		{
			jj--;
			jj++;
			k[s[i]-'0'].a=(rooot*)malloc(10*sizeof(rooot));
			jj++;
			for(j=0;j<10;j++)
				k[s[i]-'0'].a[j].value=0;
			jj++;
			jj--;
			k[s[i]-'0'].value=1;
		}
		jj--;
		durc(s,k[s[i]-'0'].a,i+1,8);
	}
}
int main()
{
	int tt,i,sulli=0;
	scanf("%d",&tt);
	for(i=0;i<tt;i++)
	{
		obama=0;
		int nn,i;
		scanf("%d",&nn);
		int flagg;
		rooot k[10];
		sulli=sulli+2;
		for(i=0;i<10;i++)
		{	k[i].value=0;
		}
		sulli=sulli+2;
		char s[11];
		sulli=sulli+2;
		while(nn--)
		{	sulli=sulli+2;
			scanf(" %s",s);
			int faaf=1;
			faaf=99;
			sulli=sulli+2;
			durc(s,k,0,6);
			faaf++;
		}
		if(obama!=1)
			printf("YES\n");
		else if(obama==1)
			printf("NO\n");
	}
	return 0;
}

				


