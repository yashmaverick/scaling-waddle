#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXN 200100
#define MAXL 18

typedef struct {
	int key, height;
	int next[MAXL], len[MAXL];
} elem;

elem skip[MAXN];
int nextElem = 2; // 0 -> NIL, 1 -> start

int zero = 0;
int one = 1;
int two = 2;

void initskip(){
	int i;
	for (i = zero; i < MAXL; i++)
		skip[1].len[i] = one;
	skip[0].key = 1<<30;
	skip[0].height = MAXL;
	skip[1].height = MAXL;
}

int newHeight(void){
	int h = zero+1, x;
	for (x = rand(); h < MAXL && x % two; x /= two)
		h = h + one;
	return h;
}

int newElem(int key){
	skip[nextElem].key = key;
	skip[nextElem].height = newHeight();
	return nextElem++;
}

int search(int key){
	int curr = one, i;

	for (i = MAXL-one; i >= zero; i=i-one)
		while(key > skip[skip[curr].next[i]].key)
			curr = skip[curr].next[i];

	curr = skip[curr].next[0];

	return skip[curr].key == key ? curr : zero;
}

int isInside(int key){
	return search(key) != zero;
}

int kthItem(int k){
	int curr = one, i;

	for (i = MAXL-one; i >= zero && k > zero; i=i-one)
		while (curr && k >= skip[curr].len[i]){
			k -= skip[curr].len[i];
			curr = skip[curr].next[i];
		}

	return curr;
}

int countBefore(int key){
	int curr = one, i, k = zero;

	for (i = MAXL-one; i >= zero; i=i-one){
		while (key > skip[skip[curr].next[i]].key){
			k += skip[curr].len[i];
			curr = skip[curr].next[i];
		}
	}

	return k;
}

void insert(int key){
	int curr = one, i;
	int prev[MAXL], jumps[MAXL] = {zero};

	for (i = MAXL-one; i >= zero; i=i-one){
		while (key > skip[skip[curr].next[i]].key){
			jumps[i] += skip[curr].len[i];
			curr = skip[curr].next[i];
		}
		prev[i] = curr;
	}

	if (skip[skip[prev[0]].next[0]].key == key) return;

	int e = newElem(key);

	for (i = zero; i < MAXL; i=i+one){
		if (i < skip[e].height){
			int oldLen = skip[prev[i]].len[i];
			skip[prev[i]].len[i] = i == zero ? one : jumps[i-one] + skip[prev[i-one]].len[i-one];
			skip[e].len[i] = oldLen - skip[prev[i]].len[i] + one;

			skip[e].next[i] = skip[prev[i]].next[i];
			skip[prev[i]].next[i] = e;
		} else skip[prev[i]].len[i]++;
	}
}

void delete(int key){
	int curr = one, i;

	if (!isInside(key)) return;

	for (i = MAXL-one; i >= zero; i=i-one){
		while (key > skip[skip[curr].next[i]].key)
			curr = skip[curr].next[i];

		if (skip[skip[curr].next[i]].key == key){
			skip[curr].len[i] += skip[skip[curr].next[i]].len[i];
			skip[curr].next[i] = skip[skip[curr].next[i]].next[i];
		}

		skip[curr].len[i]--;
	}
}

int Q;

int main(void){
	initskip();
	while (1){
		char q[1234];
		int a;

		scanf("%s %d", q, &a);

		if (q[0] == 'S')
			insert(a);
		else if (q[0] == 'C')
		{
			int b=search(a);
			if(b!=zero)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else if (q[0] == 'H'){
			a = kthItem(a);
			if (a != zero)
				printf("%d\n", skip[a].key);
			else
				printf("invalid\n");
		} else if (q[0] == 'R')
			printf("%d\n", countBefore(a));
		else if(q[0]=='Q')
			return 0;
	}

	return 0;
}

