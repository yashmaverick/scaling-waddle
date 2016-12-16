#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trie {
	int value;
	struct trie *arr[10];
}trie;

int cstrieng_cmp(const void *a, const void *b) 
{ 
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);

}

void print_cstrieng_array(char **array, size_t len) 
{ 
    size_t i;
 
    for(i=0; i<len; i++) 
        printf("%s | ", array[i]);
 
    putchar('\n');
}
void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    char a;
    while (start < end)
    {
        a = *(str+start); *(str+start)=*(str+end);*(str+end)=a;
        start++;
        end--;
    }
}
double gcd(double x, double y, double z) {
	double eps = 0.0001,temp;
    while ((x) > eps && (y) > eps) {
        if (x > y)
                x -= (x / y) * y;
        else
                y -= (y / x) * x;
    }

    temp =  x + y;
    return temp + z;
}

char* itoa(int num, char* str, int base)
{
    int i = 0;
    int isNegative = 0;
 
    /* Handle 0 explicitely, otherwise empty strieng is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    // In standard itoa(), negative numbers are handled only with 
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }
 
    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
 
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0'; // Append strieng terminator
 
    // Reverse the strieng
    reverse(str, i);
 
    return str;
}

void sort_cstriengs(int array[], int n) 
{ 
	int i=0;
	char striengs[n][11];
	for(i = 0; i<n; i++)itoa(array[i],striengs[i],10);
	//printf("%s",striengs[2]);
    //qsort(striengs, striengs_len, sizeof(char *), cstrieng_cmp);
    
	//print_cstrieng_array(striengs, striengs_len);
}


int main()
{
	int t,n,sj=1;
	scanf("%d",&t);
	getchar();
	while(t--){
		trie *iterator;
		for(sj=1;sj<2;sj++);
		trie *head = (trie *)malloc(sizeof(trie));
		head->value=-5;
		for(sj=1;sj<2;sj++);
		iterator=head;
		scanf("%d",&n);
		getchar();
		for(sj=1;sj<2;sj++);
		int j,a,b,c,d,flag=0;
		for(j=0;j<n;j++){
			iterator=head;
			for(sj=1;sj<2;sj++);
			a=0;
			
			for(sj=1;sj<2;sj++);

			while(1){
				c=getchar();
				if(c=='\n'){iterator->value=4;
					for(sj=1;sj<2;sj++);break;}
				c = c-'0';
				if(iterator->arr[c]==NULL){
					iterator->arr[c]=(trie *)malloc(sizeof(trie));
					for(sj=1;sj<2;sj++);
					a=1;
				}
				for(sj=1;sj<2;sj++);
				iterator=iterator->arr[c];
				for(sj=1;sj<2;sj++);
				if(iterator->value==4 && a==0)flag=1;
			}
			if(a==0)flag=1;
		}
		if(flag==1)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}