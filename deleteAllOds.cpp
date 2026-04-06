//delete all ods (double linked list)

#include <stdio.h>
#include <stdlib.h>


struct nod{
	int x;
	struct nod *next;
	struct nod *prev;
};

struct nod initNod(struct nod *nod, int x){
	nod -> x = x;
	nod -> next = nod -> prev = NULL;
}

struct linkedList{
	struct nod *head;
	struct nod *tail;
};

void initLinkedList(struct linkedList *list){
	list -> head = list -> tail = NULL;
}

void pushTail(struct linkedList *list, int x){
	struct nod *newNod = (struct nod*) malloc(sizeof(struct nod));
	initNod(newNod, x);
	
	if (list->head ==NULL){
		list->head = list->tail = newNod;
		return;
	}
	
	newNod ->prev=list->tail;
	list->tail ->next = newNod;
	list->tail = newNod;
}

void popHead(struct linkedList *list){
	if (list->head==NULL) return;
	if (list->head==list->tail){
		free(list->head);
		list->head = list->tail = NULL;
		return;
	}
	
	struct nod *temp = list->head;
	list->head ->next->prev = NULL;
	list->head = list->head->next;
	free(temp);
}

void popTail(struct linkedList *list){
	if (list->head==NULL) return;
	if (list->head==list->tail){
		free(list->head);
		list->head = list->tail = NULL;
		return;
	}
	
	struct nod *temp = list->tail;
	list->tail->prev->next = NULL;
	list->tail = list->tail->prev;
	free(temp);
}

void popOds(struct linkedList *list){
	if (list->head==NULL) return;
	struct nod *cur = list->head;
	
	while (cur!=NULL){
		struct nod *nextNod = cur->next;
		if ((cur->x)%2 != 0){
			if (cur->prev == NULL){//kalo di head
				popHead(list);
			} else if(cur->next==NULL){ //kalo di tail
				popTail(list);
			} else{ //kl di tengah
				cur->prev->next=cur->next;
				cur->next->prev =cur->prev;
				struct nod *temp = cur;
				free(temp);
	
			}
		}
		cur = nextNod;
	}
}

int main(){
	struct linkedList *a = (struct linkedList*) malloc(sizeof(struct linkedList));
	initLinkedList(a);
	
	int wle, i, x;
	
	scanf("%d", &wle);
	
	for (i = 0; i < wle; i++){
		scanf("%d", &x);
		pushTail(a, x);
	}
	popOds(a);
	
	if (a->head ==NULL){ //kl gd isi
		printf("-1");
	} else{
		struct nod *cur = a->head;
		while (cur != NULL){
			printf("%d ", cur->x);
			cur = cur->next;
		}
	}
	printf("\n");
}


