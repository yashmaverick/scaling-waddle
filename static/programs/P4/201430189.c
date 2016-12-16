#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
		return ( *(int*)a - *(int*)b );
}

int main(){
		int st,i,smallhash[2],testcases,numnum;
		long long num,combined[100001],answer;
		char str[100000];
		scanf("%d" ,&testcases);
		while(testcases--){
				scanf("%s" ,str);
				smallhash[0]=smallhash[1]=0;
				i=answer=0;
				combined[0]=0;
				while(str[i]!='\0'){
						if(str[i]=='R')
								smallhash[0]++;
						else if(str[i]=='J')
								smallhash[1]++;
						else if(str[i]=='M'){
								smallhash[0]--;
								smallhash[1]--;
						}
						combined[i+1]=(smallhash[0]*100000)+smallhash[1];
						i++;
				}
				qsort(combined, i+1, sizeof(long long int), cmpfunc);
				num=combined[0];
				numnum=1;
				st=1;
				while(st<=i){
						if(combined[st]==num)
								numnum++;
						else{
								answer+=(numnum*(numnum-1)/2);
								numnum=1;
								num=combined[st];
						}
						st++;
				}
				answer+=(numnum*(numnum-1)/2);
				printf("%lld\n" ,answer);
		}
		return 0;
}
