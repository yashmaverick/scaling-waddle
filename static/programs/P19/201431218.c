#include<stdio.h>
#include<string.h>
//void lexie(char str[100008][20],int);
char prefix(char *s1,char *s2);
int chs(char a[],char b[])
{
	int len1,len2;
	len1=strlen(a);
	len2=strlen(b);
	int iter;
	iter=0;
	while(iter<len1&&iter<len2&&a[iter]==b[iter])
	{
		iter++;
	}
	if(a[iter]=='\0')
	{
		return 1;
	}
	else if(b[iter]=='\0')
	{
		return 0;
	}
	else if(a[iter]<b[iter])
	{
		return 1;
	}
	return 0;
}
int partition(char n[][20],int l,int r)
{
	int i,j;
	int x,y;
	i=l;
	j=l-1;
	while(i<r)
	{
		if(chs(n[i],n[r]))
		{
			j++;
			int t;
			int w=0;
			while(w<15)
			{
				t=n[i][w];
				n[i][w]=n[j][w];
				n[j][w]=t;
				w++;
			}
		}
		i++;
	}
	j++;
	int t;
	int w=0;
	while(w<15)
	{
		t=n[i][w];
		n[i][w]=n[j][w];
		n[j][w]=t;
		w++;
	}
	return j;
}
void lexi(char n[][20],int l,int r)
{
	int q;
	if(l>=r)
	{
		return ;
	}
	else
	{
		q=partition(n,l,r);
		//printf("q:%d\n ",q);
		/*int w;
		w=0;
		int item=r;
		while(w<item)
		{
			printf("ewe:%s\n",n[w]);
			w++;
		}*/
		lexi(n,l,q-1);
		lexi(n,q+1,r);
	}
}		
int main()
{
	char n[100008][20];
	int i=0,item,test;
	scanf("%d",&test);
	while(test--)
	{
		i=0;
		scanf("%d",&item);
		while(i<item)
			scanf("%s",n[i++]);
		int w;
		/*w=0;
		while(w<item)
		{
			printf("%s\n",n[w]);
			w++;
		}*/
		lexi(n,0,item-1);
		for(i=0;i<item-1;i++)
		{
			if(prefix(n[i],n[i+1]))
				break;
		}
		if(i==item-1){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
/*void lexie(char str[100008][20],int num)
{
	int i,j;
	char temp[20];
	for(i=1;i<num;i++)
	{
		for(j=1;j<=num-i;j++)
		{
			if(strcmp(str[j-1],str[j])>0)
			{
				strcpy(temp,str[j-1]);
				strcpy(str[j-1],str[j]);
				strcpy(str[j],temp);
			}
		}
	}
/	printf("\nTHE SORTED LIST\n");
	for(i=0;i<num;i++)
	{
		printf("%s\n",str[i]);
	}/
}*/
char prefix(char *s1,char *s2){
	int i;
	for(i=0;s1[i]!='\0'&&s2[i]!='\0'&&s1[i]==s2[i];i++);
	if(s1[i]=='\0'){
		return 1;
	}
	else{
		return 0;
	}
}
