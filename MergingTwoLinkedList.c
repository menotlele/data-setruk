//merging two linked list
#include <stdio.h>
#include <stdlib.h>

struct nod{
	int x;
	struct nod *next;
	struct nod *prev;
};

struct nod initNod(struct nod *nod, int x){
	nod -> x = x;
	nod -> next = nod ->prev = NULL;
};


struct linkedList{
	struct nod *head;
	struct nod *tail;
};

void initLinkedList(struct linkedList *list){
	list->head = list->tail = NULL;
}


void pushTail(struct linkedList *list, int x){
	struct nod *newNod = (struct nod*) malloc(sizeof(struct nod));
	initNod(newNod, x);
	
	if (list->head==NULL){
		list->head = list->tail = newNod;
		return;
	}
	
	list->tail->next=newNod;
	newNod->prev = list->tail;
	list->tail = newNod;
	
}

void gabungin(struct linkedList *a, struct linkedList *b){
	if (b->head==NULL){
		return;
	}
	
	if (a->head==NULL){
		a->head = b->head;
		a->tail = b->tail;
		b->head = b->tail = NULL;
		return;
	}
	
	a->tail -> next = b->head;
	b->head->prev = a->tail;
	a->tail = b->tail;
	b->head = b->tail = NULL;
}

void ngeprint(struct linkedList *aa){
	if (aa ->head==NULL){
		return;
	}
	struct nod *cur = aa->head;
	while (cur != NULL){
		printf("%d ", cur->x);
		cur = cur->next;
	}
	printf("\n");
	
}

 
int main(){
	struct linkedList *aa = (struct linkedList*) malloc(sizeof(struct linkedList));
	struct linkedList *bb = (struct linkedList*) malloc(sizeof(struct linkedList));
	initLinkedList(aa);
	initLinkedList(bb);
	int i, j, wle, mbe, x;
	
	scanf("%d %d", &wle, &mbe);
	
	for (i = 0 ; i < wle ;i++){
		scanf("%d", &x);
		pushTail(aa, x);
	}
	
	for (i = 0 ; i < mbe ;i++){
		scanf("%d", &x);
		pushTail(bb, x);
	}
	
	gabungin(aa, bb);
	
	ngeprint(aa);
}
