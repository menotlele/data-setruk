#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nod{
	int x;
	char satuan;
	struct nod *left;
	struct nod *right;
};

struct nod *root =NULL;

void insert(int x, char satuan){
	struct nod *newnod = (struct nod*) malloc(sizeof(struct nod));
	newnod->x=x;
	newnod->satuan=satuan;
	newnod->left=NULL;
	newnod->right=NULL; 
	
	if (root==NULL){
		root=newnod;
		return;
	}
	
	struct nod *cur = root;
	struct nod *par = NULL;
	
	while (cur!=NULL){
		par=cur;
		
		if (x < cur->x){
			cur = cur->left;
		} else if(x >cur->x){
			cur = cur->right;
		} else{
			free(newnod);
			return;
		}
	}
	if (par->x > x){
		par->left=newnod;
	} else{
		par->right=newnod;
	}
}
void inorder(struct nod *cur){
	if (cur==NULL) return;
	inorder(cur->left);
	printf("%d ", cur->x);
	inorder(cur->right);
	return;
}

int hitung(struct nod *cur){
	if (cur==NULL) return 0;
	int count = 0;
	if(cur->satuan=='V'){
		if(cur->right !=NULL && cur->right->satuan=='R'){
			if(cur->left !=NULL && cur->left->satuan=='I'){
				count=1;
			}
		}
		
	}
	int kiri=hitung(cur->left);
	int kanan=hitung(cur->right);
	return count + kiri +kanan;
}

int main(){
	root = NULL;
	
	int n, i, x;
	char satuan;
	scanf("%d", &n);
	for (i = 0 ; i < n ; i++){
		scanf("%d %c", &x, &satuan);
		insert(x, satuan);
	}
//	inorder(root);  buat cek ajh
	
	int ans = hitung(root);
	printf("%d\n", ans);
		
}
















