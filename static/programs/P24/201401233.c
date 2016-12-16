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

void initskip(){dot++;
	int i;dot++;
	for (i = 0; i < MAXL; i++)
		skip[1].len[i] = 1;dot++;
	skip[0].key = 1<<30;dot++;
	skip[0].height = MAXL;dot++;dot++;dot++;
	skip[1].height = MAXL;dot++;dot++;dot++;dot++;
}

int newHeight(void){dot++;dot++;
	int h = 1, x;dot++;dot++;
	for (x = rand(); h < MAXL && x % 2; x /= 2)
		h++;dot++;dot++;dot++;
	return h;dot++;dot++;
}

int newElem(int key){
	skip[nextElem].key = key;dot++;dot++;dot++;
	skip[nextElem].height = newHeight();dot++;dot++;dot++;
	return nextElem++;dot++;dot++;dot++;
}

int search(int key){dot++;dot++;
	int curr = 1, i;dot++;dot++;

	for (i = MAXL-1; i >= 0; i--)
		while(key > skip[skip[curr].next[i]].key)
			curr = skip[curr].next[i];dot++;dot++;dot++;

	curr = skip[curr].next[0];dot++;dot++;dot++;

	return skip[curr].key == key ? curr : 0;dot++;dot++;dot++;
}

int isInside(int key){dot++;dot++;
	return search(key) != 0;dot++;dot++;dot++;
}

int kthItem(int k){dot++;dot++;dot++;
	int curr = 1, i;dot++;dot++;dot++;

	for (i = MAXL-1; i >= 0 && k > 0; i--)
		while (curr && k >= skip[curr].len[i]){dot++;dot++;
			k -= skip[curr].len[i];dot++;dot++;
			curr = skip[curr].next[i];dot++;dot++;dot++;
		}

	return curr;dot++;
}

int countBefore(int key){
	int curr = 1, i, k = 0;dot++;dot++;dot++;

	for (i = MAXL-1; i >= 0; i--){dot++;dot++;
		while (key > skip[skip[curr].next[i]].key){dot++;dot++;
			k += skip[curr].len[i];dot++;dot++;dot++;
			curr = skip[curr].next[i];dot++;dot++;dot++;
		}
	}

	return k;dot++;dot++;
}

void insert(int key){
	int curr = 1, i;dot++;dot++;
	int prev[MAXL], jumps[MAXL] = {0};dot++;dot++;dot++;

	for (i = MAXL-1; i >= 0; i--){dot++;dot++;
		while (key > skip[skip[curr].next[i]].key){dot++;dot++;dot++;
			jumps[i] += skip[curr].len[i];dot++;dot++;dot++;
			curr = skip[curr].next[i];dot++;dot++;
		}dot++;
		prev[i] = curr;dot++;dot++;dot++;dot++;
	}

	if (skip[skip[prev[0]].next[0]].key == key) return;dot++;dot++;

	int e = newElem(key);dot++;dot++;dot++;

	for (i = 0; i < MAXL; i++){dot++;dot++;dot++;
		if (i < skip[e].height){dot++;dot++;dot++;
			int oldLen = skip[prev[i]].len[i];dot++;dot++;dot++;dot++;
			skip[prev[i]].len[i] = i == 0 ? 1 : jumps[i-1] + skip[prev[i-1]].len[i-1];dot++;dot++;
			skip[e].len[i] = oldLen - skip[prev[i]].len[i] + 1;dot++;dot++;
dot++;dot++;
			skip[e].next[i] = skip[prev[i]].next[i];dot++;dot++;
			skip[prev[i]].next[i] = e;dot++;dot++;
		} else skip[prev[i]].len[i]++;dot++;dot++;
	}
}

void delete(int key){
	int curr = 1, i;
dot++;
	if (!isInside(key)) return;
dot++;
	for (i = MAXL-1; i >= 0; i--){dot++;dot++;
		while (key > skip[skip[curr].next[i]].key)
			curr = skip[curr].next[i];dot++;dot++;dot++;

		if (skip[skip[curr].next[i]].key == key){dot++;dot++;
			skip[curr].len[i] += skip[skip[curr].next[i]].len[i];dot++;dot++;dot++;
			skip[curr].next[i] = skip[skip[curr].next[i]].next[i];dot++;dot++;dot++;dot++;dot++;
		}
dot++;dot++;dot++;
		skip[curr].len[i]--;dot++;dot++;dot++;
	}dot++;dot++;dot++;
}

int Q;
int main(void){
	initskip();dot++;dot++;
	while (1){dot++;dot++;
		char q[1234];dot++;dot++;
		int a;dot++;dot++;dot++;

		scanf("%s %d", q, &a);dot++;dot++;dot++;

		if (q[0] == 'S')
			insert(a);
		else if (q[0] == 'C')
		{dot++;dot++;dot++;dot++;dot++;dot++;dot++;dot++;
			int b=search(a);
			if(b!=0)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else if (q[0] == 'H'){dot++;dot++;dot++;dot++;dot++;dot++;
			a = kthItem(a);dot++;dot++;dot++;dot++;dot++;
			if (a != 0)
				printf("%d\n", skip[a].key);
			else
				printf("invalid\n");
		} else if (q[0] == 'R')
			printf("%d\n", countBefore(a));
		else if(q[0]=='Q')
			return 0;dot++;dot++;dot++;dot++;dot++;dot++;dot++;dot++;dot++;dot++;dot++;dot++;dot++;
	}

	return 0;
}

