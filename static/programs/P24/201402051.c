#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int dot=0;
int lev=0;
int fo=0;
#define MAXN 200100
#define MAXL 18

typedef struct {
	int key, height;
	int next[MAXL], len[MAXL];
} elem;

elem skip[MAXN];
int nextElem = 2; // 0 -> NIL, 1 -> start

void initskip(){
	dot++;
	lev++;
	fo--;
	int i;
	dot++;
	lev++;
	fo--;
	for (i = 0; i < MAXL; i++)
		skip[1].len[i] = 1;
	dot++;
	lev++;
	fo--;
	skip[0].key = 1<<30;
	dot++;
	lev++;
	fo--;
	skip[0].height = MAXL;
	dot++;
	lev++;
	fo--;
	skip[1].height = MAXL;
}

int newHeight(void){
	dot++;
	lev++;
	fo--;
	int h = 1, x;
	dot++;
	lev++;
	fo--;
	for (x = rand(); h < MAXL && x % 2; x /= 2)
		h++;
	dot++;
	lev++;
	fo--;
	return h;
}

int newElem(int key){
	dot++;
	lev++;
	fo--;
	skip[nextElem].key = key;
	dot++;
	lev++;
	fo--;
	skip[nextElem].height = newHeight();
	dot++;
	lev++;
	fo--;
	return nextElem++;
}

int search(int key){
	dot++;
	lev++;
	fo--;
	int curr = 1, i;

	dot++;
	lev++;
	fo--;
	for (i = MAXL-1; i >= 0; i--)
		while(key > skip[skip[curr].next[i]].key)
			curr = skip[curr].next[i];
	dot++;
	lev++;
	fo--;

	curr = skip[curr].next[0];
	dot++;
	lev++;
	fo--;

	return skip[curr].key == key ? curr : 0;
}

int isInside(int key){
	dot++;
	lev++;
	fo--;
	return search(key) != 0;
}

int kthItem(int k){
	dot++;
	lev++;
	fo--;
	int curr = 1, i;

	dot++;
	lev++;
	fo--;
	for (i = MAXL-1; i >= 0 && k > 0; i--)
		while (curr && k >= skip[curr].len[i]){
			dot++;
			lev++;
			fo--;
			k -= skip[curr].len[i];
			dot++;
			lev++;
			fo--;
			curr = skip[curr].next[i];
		}

	return curr;
	dot++;
	lev++;
	fo--;
}

int countBefore(int key){
	dot++;
	lev++;
	fo--;
	int curr = 1, i, k = 0;
	dot++;
	lev++;
	fo--;

	for (i = MAXL-1; i >= 0; i--){
		dot++;
		lev++;
		fo--;
		while (key > skip[skip[curr].next[i]].key){
			dot++;
			lev++;
			fo--;
			k += skip[curr].len[i];
			dot++;
			lev++;
			fo--;
			curr = skip[curr].next[i];
			dot++;
			lev++;
			fo--;
		}
	}

	return k;
}

void insert(int key){
	dot++;
	lev++;
	fo--;
	int curr = 1, i;
	int prev[MAXL], jumps[MAXL] = {0};
	dot++;
	lev++;
	fo--;

	for (i = MAXL-1; i >= 0; i--){
		dot++;
		lev++;
		fo--;
		while (key > skip[skip[curr].next[i]].key){
			dot++;
			lev++;
			fo--;
			jumps[i] += skip[curr].len[i];
			dot++;
			lev++;
			fo--;
			curr = skip[curr].next[i];
			dot++;
			lev++;
			fo--;
		}
		dot++;
		lev++;
		fo--;
		prev[i] = curr;
	}

	if (skip[skip[prev[0]].next[0]].key == key) return;
	dot++;
	lev++;
	fo--;

	int e = newElem(key);

	dot++;
	lev++;
	fo--;
	for (i = 0; i < MAXL; i++){
		dot++;
		lev++;
		fo--;
		if (i < skip[e].height){
			dot++;
			lev++;
			fo--;
			int oldLen = skip[prev[i]].len[i];
			dot++;
			lev++;
			fo--;
			skip[prev[i]].len[i] = i == 0 ? 1 : jumps[i-1] + skip[prev[i-1]].len[i-1];
			skip[e].len[i] = oldLen - skip[prev[i]].len[i] + 1;
			dot++;
			lev++;
			fo--;

			skip[e].next[i] = skip[prev[i]].next[i];
			skip[prev[i]].next[i] = e;
			dot++;
			lev++;
			fo--;
		} else skip[prev[i]].len[i]++;
		dot++;
		lev++;
		fo--;
	}
}

void delete(int key){
	dot++;
	lev++;
	fo--;
	int curr = 1, i;
	dot++;
	lev++;
	fo--;
	if (!isInside(key)) return;
	dot++;
	lev++;
	fo--;
	for (i = MAXL-1; i >= 0; i--){
		while (key > skip[skip[curr].next[i]].key)
			curr = skip[curr].next[i];
		dot++;
		lev++;
		fo--;

		if (skip[skip[curr].next[i]].key == key){
			dot++;
			lev++;
			fo--;
			skip[curr].len[i] += skip[skip[curr].next[i]].len[i];
			skip[curr].next[i] = skip[skip[curr].next[i]].next[i];
			dot++;
			lev++;
			fo--;
		}
		dot++;
		lev++;
		fo--;
		skip[curr].len[i]--;
	}
}

int Q;

int main(void){dot++;
	lev++;
	fo--;
	initskip();
	while (1){
		dot++;
		lev++;
		fo--;
		char q[1234];
		int a;dot++;
		lev++;
		fo--;
		scanf("%s %d", q, &a);
		dot++;
		lev++;
		fo--;
		if (q[0] == 'S')
			insert(a);
		else if (q[0] == 'C')
		{dot++;
			lev++;
			fo--;
			int b=search(a);
			if(b!=0)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else if (q[0] == 'H'){dot++;
			lev++;
			fo--;
			a = kthItem(a);

			dot++;
			lev++;
			fo--;
			if (a != 0)
			{
				dot++;
				lev++;
				fo--;
				printf("%d\n", skip[a].key);
			}
			else
				printf("invalid\n");
		} else if (q[0] == 'R')
		{
			dot++;
			lev++;
			fo--;
			printf("%d\n", countBefore(a));
		}
		else if(q[0]=='Q')
		{
			dot++;
			lev++;
			fo--;
			return 0;
		}
	}

	return 0;
}

