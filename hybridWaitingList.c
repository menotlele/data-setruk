//HYBRID WAITING LIST FIFO (QUEUE) SINGLE LINKEDLIST

#include <stdio.h>
#include <stdlib.h>

struct nod{
	int x;
	struct nod *next;
};

struct nod initNod (struct nod *nod, int x){
	nod -> x = x;
	nod -> next = NULL;
};

struct linkedList{
	struct nod *head;
	struct nod *tail;
};

void initLinkedList(struct linkedList *list){
	list->tail = list->head=NULL;

}

void pushTail(struct linkedList *list, int id){
	struct nod *newNod = (struct nod*) malloc(sizeof(struct nod));
	initNod(newNod, id);
	
	if (list->head ==NULL){
		list->head=list->tail=newNod;
		return;
	}
	
	list->tail ->next=newNod;
	list->tail = newNod;
}

void gabungin(struct linkedList *hybrid, struct linkedList *online, struct linkedList *walkin){
	struct nod *curro = online ->head;
	struct nod *currw = walkin ->head;
	while(curro != NULL || currw != NULL){
		
		if(curro != NULL){
			pushTail(hybrid, curro->x);
			curro = curro ->next;

		}
		
		if(currw != NULL){
			pushTail(hybrid, currw->x);
			currw = currw ->next;
		}
		
	}
}

void popMid(struct linkedList *hybrid, int x){
	if(hybrid->head==NULL)return;
	
	if(hybrid->head->x == x){ //kalo di head
		struct nod *temp = hybrid->head;
		if(hybrid->head ==hybrid->tail){//kalo cuma 1 antrian
			hybrid->tail = hybrid->head = NULL;
		}else{
			hybrid->head = hybrid->head->next;
		}
		
		free(temp);
		return;
	}
	
	struct nod *cur = hybrid->head;
	while (cur->next!=NULL){
		if(cur->next->x ==x){
			struct nod *temp = cur->next;
			if(cur->next == hybrid->tail){ //di tail
				hybrid->tail = cur;
			}
			
			cur->next = cur->next->next;
			free(temp);
			return;
		}
		cur = cur->next;
	}
}

int main(){
	struct linkedList *online = (struct linkedList*) malloc(sizeof(struct linkedList));
	struct linkedList *walkin = (struct linkedList*) malloc(sizeof(struct linkedList));
	struct linkedList *hybrid = (struct linkedList*) malloc(sizeof(struct linkedList));
	
	initLinkedList(online);
	initLinkedList(walkin);
	initLinkedList(hybrid);
	
	int o, w, c, i, x;
	
	scanf("%d %d", &o, &w);
	for (i = 0 ; i< o ; i++){
		scanf("%d", &x);
		pushTail(online, x);
	}
	
	for (i = 0 ; i< w ; i++){
		scanf("%d", &x);
		pushTail(walkin, x);
	}
	
	gabungin(hybrid, online, walkin);
	
	scanf("%d", &c);
	for (i = 0 ; i< c ; i++){
		scanf("%d", &x);
		popMid(hybrid, x);
	}
	
	struct nod *cur = hybrid->head;
	while(cur!=NULL){
		printf("%d ", cur->x);
		cur = cur->next;
	}
	printf("\n");
}
