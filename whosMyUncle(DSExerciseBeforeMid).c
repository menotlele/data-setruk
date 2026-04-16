#include <stdio.h>
#include <stdlib.h>

struct nod {
	int x;
	struct nod *left;
	struct nod *right;
};

struct nod *root=NULL;

void insert(int x){
	
	struct nod *newnod = (struct nod*) malloc(sizeof(struct nod));
	newnod->x=x;
	newnod->left=NULL;
	newnod->right=NULL;
	
	
	if (root==NULL){
		root=newnod;
		return;
	}
	
	struct nod *par = NULL;
	struct nod *cur = root;
	
	while (cur!=NULL){
		par= cur;
		if (x<cur->x){
			cur = cur->left;
		} else if (x > cur->x){
			cur = cur->right;
		} else{
			free(newnod);
			return;
		}
	}
	
	if (x < par->x){
		par->left = newnod;
	} else{
		par->right=newnod;
	}
}

void search(struct nod *root, int target){
	if (root==NULL) printf("kosong mok\n");
	struct nod *cur = root;
	struct nod *par = NULL;
	struct nod *grandpar =NULL;
	
	while (cur!=NULL && cur->x!=target){
		grandpar = par;
		par = cur;
		
		if (target < cur->x){
			cur= cur->left;
		} else{
			cur = cur->right;
		}
	}
	
	if (cur ==NULL){
		printf("Not Found\n");
		return;
	}
	
	if(grandpar ==NULL){
		printf("-1\n");
		return;
	}
	
	struct nod *uncle;
	if (grandpar->right==par){
		uncle = grandpar->left;
	} else if (grandpar->left==par){
		uncle = grandpar->right;
	}
	
	if (uncle ==NULL){
		printf("-1\n");
		return;
	} else{
		printf("%d\n", uncle->x);
		return;
	}
	
}

void inorder(struct nod *cur){
	if (cur==NULL) return;
	inorder(cur->left);
	printf("%d ", cur->x);
	inorder(cur->right);
	return;
}

int main(){
	root=NULL;
	int n, i, x, t;
	scanf("%d", &n);
	for (i = 0 ; i < n ; i++){
		scanf("%d", &x);
		insert(x);
	}
	scanf("%d", &t);
	
	for (i = 0 ; i < t; i++){
		scanf("%d", &x);
		search(root, x);
	}
//	inorder(root);
}






































