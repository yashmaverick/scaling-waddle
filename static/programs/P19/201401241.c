#include<stdio.h>
#include<string.h>
#define tempiarrl for(st=0;st<12;st++)temp[i][st]=arr[l][st];
#define tempiarrm for(st=0;st<12;st++)temp[i][st]=arr[m][st];
#define tempiarrk for(st=0;st<12;st++)temp[i][st]=arr[k][st];
#define arrktempk for(st=0;st<12;st++)arr[k][st]=temp[k][st];
int kkkk;
void mergeSort(char arr[][12],int low,int mid,int high);
void partition(char arr[][12],int low,int high);
int compare(char*s1,char*s2)
{
	int i,l1=strlen(s1);
	int l2=strlen(s2);
	for(i=0;s1[i]==s2[i] && i<((l1<l2)?l1:l2);)
	{
		i++;
	}
	if(s1[i]=='\0')return 1;
	else if(s2[i]=='\0')return 0;
	else if(s1[i]<=s2[i])
		return 1;
	return 0;
}
void partition(char arr[][12],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		mergeSort(arr,low,mid,high);

	}
}
void mergeSort(char arr[][12],int low,int mid,int high)
{
	int i,m,k,l;
	char temp[100005][12];
	int st;
	l=low;
	i=low;
	m=mid+1;
	while((l<=mid)&&(m<=high)){
		if(compare(arr[l],arr[m])){
			tempiarrl;
			l++;
		}
		else{
			tempiarrm;
			m++;
		}
		i++;
	}
	if(l>mid){
		for(k=m;k<=high;k++){
			tempiarrk;
			i++;
		}
	}
	else{
		for(k=l;k<=mid;k++){
			tempiarrk;
			i++;
		}
	}
	for(k=low;k<=high;k++){
		arrktempk;
	}
}
int prefix(char*s1,char*s2)
{
	int l1=strlen(s1),l2=strlen(s2);
	//if(l1>l2)
	//	return 0;
	int min=l1<l2?l1:l2;
	int i,count=0;
	for(i=0;i<min;)
	{
		if(s1[i]==s2[i])
		{
			i++;
			count++;
		}
		else
			break;
	}
	if(count==min)
		return 1;
	return 0;
}
int main()
{

	int l,k;
	char merge[100005][12];
	int n,i;
	scanf("%d",&l);
	for(k=0;k<l;k++)
	{
		scanf("%d",&n);
		kkkk=n;
		for(i=0;i<n;i++)
		{
			scanf("%s",merge[i]);
		}
		partition(merge,0,n-1);
		int h=0;
		h=0;
		int flag=0;
		for(i=0;i<n-1;i++)
		{
			char s=prefix(merge[i],merge[i+1]);
			//printf("%d\n",s);
			if(s==1)
			{
				printf("NO\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("YES\n");
		}
	}
	return 0;
}
