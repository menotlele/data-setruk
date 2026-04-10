///kanan kanannnn kannannn

#include <stdio.h>
#include <stdlib.h>

const int inf = 1e9;

struct nod{
	int key;
	struct nod *left;
	struct nod *right;
};

int max (int a, int b){
	if (a>b) return a;
	return b;
}

void initnod(struct nod *nod, int key){
	nod ->key = key;
	nod->left=nod->right = NULL;
}

struct bst{
	struct nod *root;
};

void initbst(struct bst *bst){
	bst->root=NULL;
}

struct nod* insertutil(struct nod *nod, int x){
	if (nod==NULL){
		nod = (struct nod*) malloc(sizeof(struct nod));
		initnod(nod, x);
		return nod;
	}
	//ke kiri
	if (x < nod->key){
		nod -> left = insertutil(nod->left, x);
		return nod;
	}
	
	//ke kanan
	if (x > nod->key){
		nod -> right = insertutil(nod->right, x);
		return nod;
	}
	return nod;
}
int findMax(struct nod *nod){
	if (nod==NULL) return -inf;
	return max(nod->key, findMax(nod->right));
}

void insert(struct bst *bst, int x){
	bst->root = insertutil(bst->root, x);
}

int main(){
	struct bst *bts = (struct bst*) malloc(sizeof(struct bst));
	initbst(bts);
	int i, x;
	scanf("%d", &i);
	while (i--){
		scanf("%d", &x);
		insert(bts, x);
		printf("%d\n", findMax(bts->root));
	}
	
}




















