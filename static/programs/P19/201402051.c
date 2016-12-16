#include <stdio.h>
#include <string.h>
int comp(const void *a,const void *b){
	return strcmp(a,b);
}
int main() {
	int nt;
	scanf("%d",&nt);
	while(nt--){
	int n;
	int flag=0;
	scanf("%d",&n);
	int i;
	char a[n][15];
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	int x,y;
	qsort(a,n,15,comp);
	//for(i=0;i<n;i++){
	//	printf("%s",a[i]);
	//}
	for(x=0;x<n-1;x++){
		//for(y=0;y<n;y++){
			//if(x!=y)
			{
				char *var = strstr(a[x+1],a[x]);
				//printf("**\n");
				if(var == NULL){}
					
				else if(strcmp(var,a[x+1]) == 0)
				{	flag=1;
					break;
				}
			}		
		//}
		if(flag==1)
			break;
	}
	if(flag == 0)
		printf("YES\n");
	else if(flag == 1)
		printf("NO\n");
	}
	return 0;
}
