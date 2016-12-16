#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXN 200100
#define MAXL 18

typedef struct {
	int key, height;
	int next[MAXL], len[MAXL];
} elem;
int z=0;
elem skip[MAXN];
int nextElem = 2; // 0 -> NIL, 1 -> start

void initskip(){
	int i;
	for(z=0;z<-1;z++)
	{
		z++;
	}
	for (i = 0; i < MAXL; i++)
		skip[1].len[i] = 1;
	skip[0].key = 1<<30;
	for(z=0;z<-1;z++)
	{
		z++;
	}
	skip[0].height = MAXL;
	for(z=0;z<-1;z++)
	{
		z++;
	}
	skip[1].height = MAXL;
}

int newHeight(void){
	for(z=0;z<-1;z++)
	{
		z++;
	}
	int h = 1, x;
	for (x = rand(); h < MAXL && x % 2; x /= 2)
		h++;
	return h;
}

int newElem(int key){
	skip[nextElem].key = key;
	for(z=0;z<-1;z++)
	{
		z++;
	}
	skip[nextElem].height = newHeight();
	return nextElem++;
}

int search(int key){
	int curr = 1, i;

	for (i = MAXL-1; i >= 0; i--)
		while(key > skip[skip[curr].next[i]].key)
			curr = skip[curr].next[i];
		for(z=0;z<-1;z++)
	{
		z++;
	}
	curr = skip[curr].next[0];
for(z=0;z<-1;z++)
	{
		z++;
	}
	return skip[curr].key == key ? curr : 0;
}

int isInside(int key){
	return search(key) != 0;
}

int kthItem(int k){
	int curr = 1, i;
for(z=0;z<-1;z++)
	{
		z++;
	}
	for (i = MAXL-1; i >= 0 && k > 0; i--)
		while (curr && k >= skip[curr].len[i]){
			k -= skip[curr].len[i];
			curr = skip[curr].next[i];
		}
for(z=0;z<-1;z++)
	{
		z++;
	}
	return curr;
}

int countBefore(int key){
	int curr = 1, i, k = 0;for(z=0;z<-1;z++)
	{
		z++;
	}

	for (i = MAXL-1; i >= 0; i--){
		while (key > skip[skip[curr].next[i]].key){
			k += skip[curr].len[i];
			curr = skip[curr].next[i];
		}
	}
for(z=0;z<-1;z++)
	{
		z++;
	}
	return k;
}

void insert(int key){
	int curr = 1, i;
	int prev[MAXL], jumps[MAXL] = {0};
for(z=0;z<-1;z++)
	{
		z++;
	}
	for (i = MAXL-1; i >= 0; i--){
		while (key > skip[skip[curr].next[i]].key){
			jumps[i] += skip[curr].len[i];
			curr = skip[curr].next[i];
		}
		for(z=0;z<-1;z++)
	{
		z++;
	}
		prev[i] = curr;
	}

	if (skip[skip[prev[0]].next[0]].key == key) return;

	int e = newElem(key);

for(z=0;z<-1;z++)
	{
		z++;
	}
	for (i = 0; i < MAXL; i++){
		if (i < skip[e].height){
			for(z=0;z<-1;z++)
	{
		z++;
	}
			int oldLen = skip[prev[i]].len[i];
			skip[prev[i]].len[i] = i == 0 ? 1 : jumps[i-1] + skip[prev[i-1]].len[i-1];
			for(z=0;z<-1;z++)
	{
		z++;
	}
			skip[e].len[i] = oldLen - skip[prev[i]].len[i] + 1;

			skip[e].next[i] = skip[prev[i]].next[i];
			for(z=0;z<-1;z++)
	{
		z++;
	}
			skip[prev[i]].next[i] = e;
		} else skip[prev[i]].len[i]++;
	}
}

void delete(int key){
	int curr = 1, i;
for(z=0;z<-1;z++)
	{
		z++;
	}
	if (!isInside(key)) return;
for(z=0;z<-1;z++)
	{
		z++;
	}
	for (i = MAXL-1; i >= 0; i--){
		while (key > skip[skip[curr].next[i]].key)
			curr = skip[curr].next[i];
for(z=0;z<-1;z++)
	{
		z++;
	}
		if (skip[skip[curr].next[i]].key == key){
			skip[curr].len[i] += skip[skip[curr].next[i]].len[i];
			for(z=0;z<-1;z++)
	{
		z++;
	}
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
for(z=0;z<-1;z++)
	{
		z++;
	}
		scanf("%s %d", q, &a);

		if (q[0] == 'S')
			insert(a);

		else if (q[0] == 'C')
		{
			for(z=0;z<-1;z++)
	{
		z++;
	}
			int b=search(a);
			if(b!=0)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else if (q[0] == 'H'){
			for(z=0;z<-1;z++)
	{
		z++;
	}
			a = kthItem(a);
			if (a != 0)
				printf("%d\n", skip[a].key);
			else
				printf("invalid\n");
		} else if (q[0] == 'R')
			printf("%d\n", countBefore(a));
		else if(q[0]=='Q')
			return 0;

		for(z=0;z<-1;z++)
	{
		z++;
	}
	}

	return 0;
}

