#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
//Global Variables
typedef struct Node Node;
struct Node{
	int data;
	Node *link;
};

Node *head;

//Functions 
void Insert_Head(int x){
	Node *temp = malloc(sizeof(Node));
	temp->data = x;
	
	temp->link = head;
	head = temp;
} //---> Constant Time


void Shift(){
	if(head == NULL) {
		printf("The list is already empty!\n");
		return;
	}
	Node *temp = head;
	head = temp->link;
	
	temp->link = NULL;
	free(temp);
}// ---> Constant Time, deletion from the head

void Insert_Tail(int x){
	Node *temp = malloc(sizeof(Node));
	temp->data = x;
	temp->link = NULL;
	
	if(head == NULL){
		head = temp;
	} else{
		Node *walk = head;
		while(walk->link != NULL) walk = walk->link;
		walk->link = temp;
	}
}// ---> O(n)

void Pop(){
	if(head == NULL) {
		printf("The list is already empty!\n");
		return;
	}
	Node *temp = head;
	Node *before = NULL;
	while(temp->link != NULL){
		before = temp;
		temp = temp->link;	
	}
	if(before == NULL){
		head = NULL;
	} else{
		before->link = NULL;
	}
	free(temp);
}// ---> O(n)

void Insert_Position(int x, int p){
	Node *temp = malloc(sizeof(Node));
	temp->data = x; temp->link = NULL;
	
	Node *current = head; 
	
	if(p < 1) printf("Position not valid!\n");
	else if(p == 1){
		temp->link = head;
		head = temp;
	} else {
		int n;
		for(n = p - 2; n > 0; n--){
			if(current == NULL){
				printf("Position bigger than the list!\n");
				return;
			}
			current = current->link;
		}
		temp->link = current->link;
		current->link = temp;
	}
}

void Delete_Position(int p){
	Node *current = head;
	Node *prev = NULL;
	if(current == NULL) {printf("The list is already empty!\n"); return;}
	if(p == 1){
		head = current->link;
		free(current);
	} else{
			while(--p){
				if(current == NULL){ printf("Position bigger than the list!\n"); return;}
				prev = current;
				current = current->link;
			}		
			prev->link = current->link;
			free(current);
	}
}

void Reverse(){
	Node *prev = NULL;
	Node *current = head;
	Node *next;
	
	while(current != NULL){
		next = current->link;
		current->link = prev;
		prev = current;
		current= next;
	}
	head = prev;
}

void Print(){
	Node *temp = head;
	while(temp != NULL){
		printf("%d ",temp->data);			
		temp = temp->link;
	}	
}

void Menu(){
		printf("Press CTRL + C to get out of the program!\n");
		printf("1 - Insert element in the head\n");
		printf("2 - Insert element in the tail\n");
		printf("3 - Insert element in a specific position\n");
		printf("4 - Remove element in a specific position\n");
		printf("5 - Remove element from the head\n");
		printf("6 - Remove element from the tail\n");
		printf("7 - Reverse your list\n");
		printf("--->");
}


int main() {
	head = NULL;
	
	while(1){
		Menu();
		int x; scanf("%d",&x); 
		int n; int p;
		printf("\n");
		switch(x){
			case 1 : printf("Press the number to be inserted :");
					 scanf("%d",&n);
					 Insert_Head(n); 
					 break;
			case 2 : printf("Press the number to be inserted :");
					 scanf("%d",&n);
					 Insert_Tail(n); 
					 break; 
			case 3 : printf("Press the number to be inserted followed by the postion :");
					 scanf("%d",&n);
					 scanf("%d",&p);
					 Insert_Position(n,p);
					 break;
			case 4 : printf("Press the number of the position to be deleted :");
					 scanf("%d",&p);
					 Delete_Position(p); 
					 break;
			case 5 : Shift(); 
					 break;
			case 6 : Pop(); 
			         break;
			case 7 : Reverse(); 
					 break;
			default : printf("This option doesnt exist\n");
		}
		printf("Lista : ");
		Print();
		printf("\n\n\n");
	}
	return 0;
}
