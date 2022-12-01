// Linked list
// 1 way linked list
// 2 way linked list
#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"

#define Null ((void*)0)

typedef struct Node Node;

struct Node{
	u32 data;
	Node *Prev;
	Node *Next;
};

Node *first = Null;
Node *last = Null;



Node *create(u32 value);
void add(Node *ptr);
void DisaplyAll(void);
Node *search(u32 value);
void delete(Node *delete);
void insert(Node *New,s8 index);

void main(void){
	u32 data;
	u8 checker,flag=0;
	s8 index;
	Node *New;
	while(flag != 1){
	printf("Create: press 1\n");
	printf("Search: press 2\n");
	printf("Insert: press 3\n");
	printf("Delete: press 4\n");
	printf("Display all: press 5\n");
	printf("Exit: press 6\n");
	scanf("%d",&checker);
	switch(checker){
		case 1:
		printf("Enter the value you wish to add in the node: \n");
		scanf("%d",&data);
		New = create(data);
		add(New);
		printf("Node is Successfully added\n");
		break;
		case 2:
		printf("Enter the value you wish to Search for in the node: \n");
		scanf("%d",&data);
		New = search(data);
		if(New==Null){
			printf("The node does not exist\n");
		}
		else{printf("Node is Found\n");}

		break;
		case 3:
		printf("What is the index in which you wish to add your Node\n");
		scanf("%d",&index);
		printf("Enter the value you wish to add in the node: \n");
		scanf("%d",&data);
		New=create(data);
	    insert(New,index);
		break;
	case 4:
	printf("Enter the value you wish to Search for in the node: \n");
	scanf("%d",&data);
	New= search(data);
	if(New!=Null)
	delete(New);
	else
	printf("Node not found\n");
	break;
		case 5:
		DisaplyAll();
		printf("end of Display\n");
		break;
		case 6:
		flag=1;
		printf("You chose to exit the program\n");
		break;

		default:
		printf("You have entered an invalid input\n");
		break;
	}
	
	}
	
	
}

Node *create(u32 value){
	Node *New = (Node*)malloc(sizeof(Node));
	New->data = value;
	New->Prev = Null;
	New->Next = Null;
	return New;
}

void add(Node *ptr){
	if(first==Null){
		first = last = ptr;
	}else{
		ptr->Prev = last;
		last->Next = ptr;
		last = ptr;
	}
}

void DisaplyAll(void){
	u8 count=0;
	
	Node *display = first;
	
	while(display!=Null){
		count++;
	printf("%d\n", display->data);
	display=display->Next;
	}
	
	
	
	if(count==0){
		printf("Linked list empty\n");
	}
	else{printf("number of elemets = %d\n", count);}
	/*if(first==Null){
		printf("Linked list empty");
	}*/
}

Node *search(u32 value){
	Node *search = first;
	while(search!=Null){
		if(search->data == value){
			return search;
		}else{
			search= search->Next;
		}
	}
	return Null;	
}

void insertAfter(Node *after, Node *new){
	new->Prev = after;
	new->Next =  after->Next;
	after->Next->Prev = new;
	after->Next = new;
}


void delete(Node *delete){
	if(delete==first){
		if(delete==last){
			first = last = Null;
		}else{
			first = first->Next;
			first->Prev = Null;
		}
	}else if(delete == last){
		last=last->Prev;
		last->Next = Null;
	}else{
		delete->Prev->Next = delete->Next;
		delete->Next->Prev = delete->Prev;
	}
	free(delete);
}

void insert(Node *New,s8 index){
	u8 flag=0;
	Node * After=first;
	printf("The index entered is %d\n",index);
	while(index != -1){
		if(After==Null){
			break;
		}
		else if(index==0){
			insertAfter(After,New);
			flag=1;

		}
		else{After=After->Next;}
		printf("value curr node is %d\n",After->data);
		index--;
	}
	if(flag==0){
		printf("The node wasnt found\n");
	}
	else
	printf("Node is Inserted\n");
}

