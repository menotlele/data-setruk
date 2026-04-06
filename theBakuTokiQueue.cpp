#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nod {
	int x;
	char name[100];
	struct nod *prev;
	struct nod *next;
};

struct nod initNod(struct nod *nod, int x, char name[]){
	nod -> x = x;
	strcpy(nod->name, name);
	nod -> prev = nod -> next = NULL;
};

struct linkedList{
	struct nod *head;
	struct nod *tail;
};

void initLinkedList(struct linkedList *list){
	list -> head = list -> tail = NULL;
}

void pushHead(struct linkedList *list, int x, char name[]){
	struct nod *newNod = (struct nod*) malloc(sizeof(struct nod));
	initNod(newNod, x, name);
	if (list->head == NULL){ //kalo linkedListnya kosong
		list->head = list->tail = newNod;
		return;
	} 
	
	newNod ->next= list->head;
	list->head->prev = newNod;
	list->head = newNod;
	return;
}

void pushTail(struct linkedList *list, int x, char name[]){
	struct nod *newNod = (struct nod*) malloc(sizeof(struct nod));
	
	
	initNod(newNod, x, name);
	if (list->head == NULL){ //kalo linkedListnya kosong
		list->head = list->tail = newNod;
		return;
	} 
	
	newNod ->prev= list->tail;
	list->tail->next = newNod;
	list->tail = newNod;
	return;
}

void pushh(struct linkedList *list, int x, char name[]){
	struct nod *newNod = (struct nod*) malloc(sizeof(struct nod));
	initNod(newNod, x, name);
	
	if (list->head == NULL){ //kalo linkedListnya kosong
		list->head = list->tail = newNod;
		return;
	} 
	if (x == 0){
		pushTail(list, x, name);
		free(newNod);
		return;
	}
	if (x==1){
		struct nod *cur = list->head;
		while (cur != NULL && cur -> x == 1){
			cur = cur->next;
		}
		
		if (cur == NULL){
			pushTail(list, x, name);
			free(newNod);
			return;
		}
		
		if(cur == list->head){
			pushHead(list, x, name);
			free(newNod);
			return;
		}
		
		
		newNod->next=cur;
		newNod->prev=cur->prev;
		cur->prev->next = newNod;
		cur->prev = newNod;
		
		return;
	}
}



void pop(struct linkedList *list, int x, char name[]){
	if (list ->head ==NULL){
		printf("%s is not exist\n", name);
		return;
	}
	
	if(list->head ==list->tail && strcmp(name, list->head->name) == 0){
		free(list->head);
		list->head = list->tail=NULL;
		printf("%s is removed\n", name);
		return;
	}
	
	struct nod *cur = list->head;
	
	while (cur !=NULL && strcmp(name, cur->name)!=0){
		cur = cur->next;
	}
	
	if (cur == NULL){
		printf("%s is not exist\n", name);
		return;
	}
	
	if (strcmp(list->head ->name, name) == 0){//kalo di head
		struct nod *temp = cur;
		cur ->next->prev = NULL;
		list->head = cur->next;
		free(temp);
		printf("%s is removed\n", name);
		return;
	}
	
	if (strcmp(list->tail->name, name) == 0){//kalo di tail
		struct nod *temp = cur;
		cur ->prev->next = NULL;
		list->tail = cur->prev;
		free(temp);
		printf("%s is removed\n", name);
		return;
	}
	
	struct nod *temp = cur;
	cur->next->prev=cur->prev;
	cur->prev->next= cur->next;
	free(temp);
	printf("%s is removed\n", name);
	return;
	
}

void display(struct linkedList *list){
	int index = 1;
	struct nod *cur = list->head;
	while (cur != NULL){
		printf("%d %s %d\n", index, cur->name, cur->x);
		cur = cur->next;
		index++;
	}
}
void popHead(struct linkedList *list){
	if (list->head ==NULL){
		return;
	}
	if (list->head == list->tail){
		free(list->tail);
		list->tail = list->head=NULL;
		return;
	}
	struct nod *temp = list->head;
	list->head->next->prev = NULL;
	list->head = list->head->next;
	free(temp);
	return;
}

void call(struct linkedList *list){
	if (list->head == NULL){
		return;
	}
	
	char name1[100];
	strcpy(name1, list->head->name);
	popHead(list);
	if (list->head==NULL){
		printf("%s", name1);
	} else{
		char name2[100];
		strcpy(name2, list->head->name);
		popHead(list);
		printf("%s - %s", name1, name2);
	}
	printf("\n");
}

int main(){
	
	struct linkedList *list = (struct linkedList*) malloc(sizeof(struct nod));
	initLinkedList(list);
	int a, b, i, id, x;
	char name[100], cmd[10], namaHapus[100];
	
	scanf("%d %d", &a, &b);
	getchar();
	for (i = 0; i< a ; i++){
		scanf("%d %[^\n]", &id, name); getchar();
		pushh(list, id, name);
	}
	
	display(list);
	
	
	for (i = 0; i< b ; i++){
		scanf("%s", cmd);
		
		if (strcmp("CANCEL", cmd) == 0){
			scanf(" %[^\n]", namaHapus);
		} else if(strcmp("CALL", cmd) == 0){
			call(list);
		}
		getchar();

	}
	
}

