#include<stdio.h>

int main()
{
	int n,v,start,end,i;
	char a[10010][105],inp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
				{
					a[i][0]='N';
					a[i][1]='U';
					a[i][2]='L';
					a[i][3]='L';					 
				}
	start=end=0;
	while(1)
	{
		scanf("%c",&inp);
		
		if(inp=='Q')break;
		else if(inp=='L')
		{
			//printf("start -> %d end-> %d\n",start,end); 
			if(start<end)
				for(i=start;i<end;i++){if(a[i][0]=='N'&&a[i][1]=='U'&&a[i][2]=='L'&&a[i][3]=='L')break;printf("%s\n",a[i]);}
			else
				for(i=start;i<n+end;i++){if(a[i][0]=='N'&&a[i][1]=='U'&&a[i][2]=='L'&&a[i][3]=='L')break;printf("%s\n",a[i%n]);}

		}
		if(inp=='A'||inp=='R')
		{
			scanf("%d",&v);
			if(inp=='A')
			{
				for(i=0;i<v;i++)
				{
					if(a[end][0]=='N'&&a[end][1]=='U'&&a[end][2]=='L'&&a[end][3]=='L')
						{scanf("%s",a[end]);}
					else
					{
						start++;scanf("%s",a[end]);start%=n;
					}
					//printf("end -> %d\n",end);
					end++;
					end%=n;
				}
			}
			if(inp=='R')
			{
				for(i=0;i<v;i++)
				{
					a[start][0]='N';
					a[start][1]='U';
					a[start][2]='L';
					a[start][3]='L';					
					start++; 
					start%=n; 
				}
			}
		}	
	}
	return 0;
}
