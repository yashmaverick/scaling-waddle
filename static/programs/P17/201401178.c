#include<stdio.h>
//int pre[10006],in[10006];
int main(){
	int nodes,i;
	scanf("%d",&nodes);
	int pre[nodes],in[nodes];
	for(i=0;i<nodes;i++){
		scanf("%d",&pre[i]);
	}
	for(i=0;i<nodes;i++){
		scanf("%d",&in[i]);
	}
	int test;
	scanf("%d",&test);
	for(i=0;i<test;i++){
		int jon,wal,ansestor,j,jin,win;
		scanf("%d %d",&jon,&wal);
		if(jon==wal){
			printf("%d\n",jon);
			continue;
		}
		int flag=0;
		for(j=0;j<nodes;j++){
			if(in[j]==jon){
				flag++;
				jin=j;
			}
			if(in[j]==wal){
				win=j;
				flag++;
			}
			if(flag==2){
				break;
               }

          }
		int size,arr[10006],pos=10007,a;
		if(jin>win){
			size=jin-win+1;
			//arr[size];
			for(j=0;j<size;j++)
				arr[j]=in[win+j];
		}
		if(win>jin){
			size=win-jin+1;
			//arr[size];
			for(j=0;j<size;j++)
				arr[j]=in[jin+j];
		}
		for(j=0;j<size;j++){
			for(a=0;a<nodes;a++){
				if(arr[j]==pre[a]){
					if(pos>a){
						pos=a;
					}
					//break;
				}
			}
		}
		printf("%d\n",pre[pos]);
		/*int preansestor=0,oldansestor=0,k=0;
		while(1){
			if(jin<ansestor && win<ansestor){
				for(j=ansestor;j>=0;j--){
					if(pre[preansestor+1]==in[j]){
						//oldansestor=ansestor;
						ansestor=j;
						break;
					}
				}
				preansestor++;
			}
			else if(jin>ansestor && win>ansestor){
				for(j=ansestor;j<nodes;j++){
					if(pre[preansestor+ansestor-oldansestor+1]==in[j]){
						//k=preansestor+ansestor-oldansestor;
						oldansestor=ansestor;
						ansestor=j;
						break;
					}
				}
				preansestor=preansestor+ansestor-oldansestor+1;
				//preansestor=k;
			}
			else{	
				printf("%d\n",in[ansestor]);
				break;
			}
		}*/
	}
	return 0;
}
