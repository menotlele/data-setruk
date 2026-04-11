#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct nod {
	int id;
	char name[30];
	struct nod *prev;
	struct nod *next;
};

void initnod(struct nod *nod, int id, char name[]){
	strcpy(nod->name, name);
	nod->id=id;
	nod->prev=nod->next=NULL;
}

struct linkedlist{
	struct nod *head;
	struct nod *tail;
};

void initlinkedlist(struct linkedlist *list){
	list->head=list->tail=NULL;
}

void peek(struct linkedlist *list){
	if (list->head==NULL){
		printf("Printer Idle\n");
		return;
	}
	printf("%d %s\n", list->head->id, list->head->name);
}

void process(struct linkedlist *list){
	if (list->head==NULL){
		printf("Printer Idle\n");
		return;
	}
	printf("%d %s\n", list->head->id, list->head->name);
	
	//pophead
	if (list->head==list->tail){ //kl isinya cm 1
		free(list->head);
		list->head=list->tail=NULL;
		return;
	}
	
	struct nod *temp = list->head;
	list->head->next->prev=NULL;
	list->head=list->head->next;
	free(temp);
	return;
}

void pushtail(struct linkedlist *list, int id, char name[]){
	struct nod *newnod = (struct nod*) malloc(sizeof(struct nod));
	initnod(newnod, id, name);
	
	if(list->head==NULL){
		list->head=list->tail=newnod;
		return;
	}
	
	list->tail->next = newnod;
	newnod->prev=list->tail;
	list->tail = newnod;
	return;	
}



void debug(struct linkedlist *list){
	if(list->head==NULL) return;
	struct nod *cur = list->head;
	while (cur!= NULL){
		printf("%d %s\n", cur->id, cur->name);
		cur = cur->next;
	}	
}


int main(){
	struct linkedlist *list = (struct linkedlist*) malloc(sizeof(struct linkedlist));
	initlinkedlist(list);
	int i, x, num;
	char name[30];
	scanf("%d", &i);
	while (i--){
		scanf("%d", &x);
		if (x == 1){ //push tail wllelele
			scanf("%d %s", &num, name);
			pushtail(list, num, name);
		} else if(x==2){ // remove and print
			process(list);
		} else if(x==3){
			peek(list);
		} else{
			printf("ga valid wo\n");
		}
		
	}
	
}











