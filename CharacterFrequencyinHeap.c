#include <stdio.h>
#include <string.h>

struct data {
	char huruf;
	int freq;
};
struct data hep[105];
int size=0;

void swap(int u, int v){
	struct data temp = hep[u];
	hep[u] = hep[v];
	hep[v] = temp;
}

void push(char huruf, int freq){
	size++;
	hep[size].huruf = huruf;
	hep[size].freq = freq;
	int cur = size;
	while (cur!=1){
		int menang = 0;
		if (hep[cur].freq>hep[cur/2].freq){
			menang = 1;
		} else if (hep[cur].freq == hep[cur/2].freq){
			if (hep[cur].huruf> hep[cur/2].huruf){
				menang=1;
			}
		}
		if (menang==0){
			break;
		}
		swap(cur, cur/2);
		cur=cur/2;
	}
}

void pop(){
	if(size==0) return;
	hep[1] = hep[size];
	size--;
	
	int induk = 1;
	while (induk<=size){
		int idx=induk;
		int kiri = induk*2;
		int kanan = induk*2+1;
		if(kiri<=size){
			if(hep[idx].freq < hep[kiri].freq){
				idx = kiri;
			} else if(hep[idx].freq == hep[kiri].freq && hep[idx].huruf < hep[kiri].huruf){
				idx = kiri;
			}
		}
		
		if (kanan <= size){
			if(hep[idx].freq < hep[kanan].freq){
				idx = kanan;
			} else if(hep[idx].freq == hep[kanan].freq && hep[idx].huruf < hep[kanan].huruf){
				idx = kanan;
			}
		}
		if (idx==induk) break;
		swap(idx, induk);
		induk = idx;
	}
}

int main(){
	int n, i;
	int mncl[26]={0};
	char kata[105];
	scanf("%d", &n);
	scanf("%s", kata);
	int len = strlen(kata);
	for (i = 0 ; i < len ; i++){
		mncl[kata[i]-'A']++;
	}
	
	for (i = 0 ; i < 26 ; i++){
		if (mncl[i]>0){
			push(i+'A', mncl[i]);
		}
	}
	
	for (i = 0; i < n ;i++){
		if (size>0){
			printf("%c %d\n", hep[1].huruf, hep[1].freq);
			pop();
		}
	}
	
	
}












