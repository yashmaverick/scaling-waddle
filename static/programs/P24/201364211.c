#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int mine=0;
int level=0;
int form=0;
#define MAXN 200100
#define MAXL 18
long long int str=0;
typedef struct {
	int key, height;
	int next[MAXL], len[MAXL];
} elem;

elem skip[MAXN];
int nextElem = 2; // 0 -> NIL, 1 -> start

void initskip(){
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	int i;
	for (i = 0; i < MAXL; i++)
		skip[1].len[i] = 1;
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	skip[0].key = 1<<30;
	skip[0].height = MAXL;
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	skip[1].height = MAXL;
}

int newHeight(void){
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	int h = 1, x;
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	for (x = rand(); h < MAXL && x % 2; x /= 2)
		h++;
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	return h;
}

int newElem(int key){
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	skip[nextElem].key = key;
	skip[nextElem].height = newHeight();
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	return nextElem++;
}

int search(int key){
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	int curr = 1, i;
for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	for (i = MAXL-1; i >= 0; i--)
		while(key > skip[skip[curr].next[i]].key)
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			curr = skip[curr].next[i];
		}
for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	curr = skip[curr].next[0];
for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	return skip[curr].key == key ? curr : 0;
}

int isInside(int key){
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	return search(key) != 0;
}

int kthItem(int k){
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	int curr = 1, i;

for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	for (i = MAXL-1; i >= 0 && k > 0; i--)
		while (curr && k >= skip[curr].len[i]){
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			k -= skip[curr].len[i];for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			curr = skip[curr].next[i];
		}
for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	return curr;
}

int countBefore(int key){
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	int curr = 1, i, k = 0;
for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	for (i = MAXL-1; i >= 0; i--){
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		while (key > skip[skip[curr].next[i]].key){
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			k += skip[curr].len[i];
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			curr = skip[curr].next[i];
		}
	}

	return k;
}

void insert(int key){
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	int curr = 1, i;
	int prev[MAXL], jumps[MAXL] = {0};
for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	for (i = MAXL-1; i >= 0; i--){
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		while (key > skip[skip[curr].next[i]].key){
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			jumps[i] += skip[curr].len[i];
			curr = skip[curr].next[i];
		}
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		prev[i] = curr;
	}

	if (skip[skip[prev[0]].next[0]].key == key) return;
for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	int e = newElem(key);
for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	for (i = 0; i < MAXL; i++){
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		if (i < skip[e].height){
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			int oldLen = skip[prev[i]].len[i];
			skip[prev[i]].len[i] = i == 0 ? 1 : jumps[i-1] + skip[prev[i-1]].len[i-1];
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			skip[e].len[i] = oldLen - skip[prev[i]].len[i] + 1;
for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			skip[e].next[i] = skip[prev[i]].next[i];
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			skip[prev[i]].next[i] = e;
		} else skip[prev[i]].len[i]++;
	}
}

void delete(int key){
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	int curr = 1, i;

	if (!isInside(key)) return;
for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	for (i = MAXL-1; i >= 0; i--){
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		while (key > skip[skip[curr].next[i]].key)
			curr = skip[curr].next[i];
for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		if (skip[skip[curr].next[i]].key == key){
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			skip[curr].len[i] += skip[skip[curr].next[i]].len[i];
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			skip[curr].next[i] = skip[skip[curr].next[i]].next[i];
		}

		skip[curr].len[i]--;
	}
}

int Q;

int main(void){
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	initskip();
	while (1){
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		char q[1234];
		int a;
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}

		scanf("%s %d", q, &a);
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}

		if (q[0] == 'S')
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			insert(a);
		}
		else if (q[0] == 'C')
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			int b=search(a);
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			if(b!=0)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else if (q[0] == 'H'){
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			a = kthItem(a);
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			if (a != 0)
				printf("%d\n", skip[a].key);
			else
				printf("invalid\n");
		} else if (q[0] == 'R')
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			printf("%d\n", countBefore(a));
		}
		else if(q[0]=='Q')
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			return 0;
		}
	}

	return 0;
}

