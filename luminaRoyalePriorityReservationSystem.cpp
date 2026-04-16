#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nod {
	int x;
	char name[100];
	struct nod *next;
	struct nod *prev;
};

void initnod (struct nod *nod, char name[], int x){
	nod->x=x;
	strcpy(nod->name, name);
	nod->next=nod->prev=NULL;
}

struct linkedlist{
	struct nod *head;
	int size;
	struct nod *tail;
};

void initlinkedlist(struct linkedlist *list){
	list->head=list->tail=NULL;
	list->size=0;
}

void add(struct linkedlist *list, char name[], int x){
	struct nod *newnod = (struct nod*) malloc(sizeof(struct nod));
	initnod(newnod, name, x);
	
	if (list->head==NULL){
		list->head=list->tail=newnod;
		list->size++;
		return;
	}
	
	if (x ==3){
		list->tail->next=newnod;
		newnod->prev=list->tail;
		list->tail=newnod;
		list->size++;
		return;
	}
	
	struct nod *cur = list->head;
	while (cur!=NULL && cur->x<=x){
		cur = cur->next;
	}
	
	if (cur==NULL){
		list->tail->next=newnod;
		newnod->prev=list->tail;
		list->tail=newnod;
		list->size++;
		return;
	}
	
	if (cur==list->head){
		list->head->prev=newnod;
		newnod ->next=list->head;
		list->head=newnod;
		list->size++;
		return;
	}
	newnod ->next=cur;
	newnod->prev=cur->prev;
	cur->prev->next=newnod;
	cur->prev=newnod;
	list->size++;
	return;
}

void display(struct linkedlist *list){
	if (list->head==NULL){
		printf("DOUBLE LINKED-LIST EMPTY.\n");
		return;
	}
	struct nod *cur = list->head;
	printf("Waiting List:\n");
	while (cur!=NULL){
		printf("%s (%d)\n", cur->name, cur->x);
		cur = cur->next;
	}
}
void serve(struct linkedlist *list){
	if (list->head==NULL) {
		printf("DOUBLE LINKED-LIST EMPTY.\n");
		return;
	}
	
	struct nod *temp=list->head;
	printf("Served customer: %s (%d)\n", list->head->name, list->head->x);
	if (list->head==list->tail){
		free(list->head);
		list->head=list->tail=NULL;
		list->size--;
		return;
	}
	list->head->next->prev=NULL;
	list->head=list->head->next;
	free(temp);
	list->size--;
	return;
}

void erase(struct linkedlist *list, char target[]){
	if (list->head==NULL){
		printf("DOUBLE LINKED-LIST EMPTY.\n");
		return;
	}
	struct nod *cur = list->head;
	while (cur!=NULL && strcmp(cur->name, target)!=0){
		cur= cur->next;
	}
	
	if (cur==NULL){
		printf("%s not found\n", target);
		return;
	} 
	if (cur==list->head){
		list->head->next->prev=NULL;
		list->head=list->head->next;
		free(cur);
		list->size--;
		printf("Deleted customer: %s (%d)\n", cur->name, cur->x);
		return;
	}
	if (cur==list->tail){
		list->tail->prev->next=NULL;
		list->tail = list->tail->prev;
		free(cur);
		printf("Deleted customer: %s (%d)\n", cur->name, cur->x);
		list->size--;
		return;
	}
	
	cur->next->prev = cur->prev;
	cur->prev->next=cur->next;
	printf("Deleted customer: %s (%d)\n", cur->name, cur->x);
	free(cur);
	list->size--;
	return;
	
	
}


int main(){
	linkedlist list;
	initlinkedlist(&list);
	char nama[100], cmd[20], nametodelete[100];
	int i, n, x;
	scanf("%d", &n);
	for (i = 0 ; i < n ; i++){
		scanf("%s", cmd);
		if (strcmp(cmd, "ADD")==0){
			scanf(" %s %d", nama, &x);
			add(&list, nama, x);
			
		} else if(strcmp(cmd, "DISPLAY")==0){
			display(&list);
		} else if (strcmp(cmd, "NEXT")==0){
			printf("Next customer: %s (%d)\n", list.head->name, list.head->x);
		} else if (strcmp(cmd, "SERVE")==0){
			serve(&list);
		} else if (strcmp(cmd, "DELETE")==0){
			scanf(" %s", nametodelete);
			erase(&list, nametodelete);
		} else if(strcmp(cmd, "COUNT")==0){
			printf("Number of customer: %d\n", list.size);
		} else{
			printf("cmd not found\n");
		}
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}























