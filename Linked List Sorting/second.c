#include <stdio.h>
#include <stdlib.h>


struct Node {
	int data;
	struct Node* next;
};

struct Node* head = NULL;

void push(int data){ // puts new node at the beginning of linked list
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = head;
	head = temp;
}
	
void freeLL(struct Node* curr) { // frees allocated memory
	if (curr == NULL) {
		return;
	}
	freeLL(curr->next);
    	free(curr);
}

void printLL(struct Node *head1){  // print linked list, back to front
	while (head1 != NULL) {
		printf("%d\t", head1->data);
		head1 = head1->next;
	}
	printf("\n");
}

int checkOrder(struct Node *headOne){ // check if linked list is in ascending order
	struct Node* newptr = headOne;
	struct Node* ptrnext = newptr->next;
	
	while (ptrnext != NULL){
		if (newptr->data > ptrnext->data){
		 	return 0;
		} else {
			newptr = ptrnext;
			ptrnext = newptr->next;
		}
	}

	return 1;
}

void sortLL(struct Node *head1){ // sorts into ascending order
	struct Node* newHead = head1; 
	struct Node* ptr = newHead;
	struct Node* nextP = ptr->next;
	struct Node* prev = NULL; 
	
	int first = 1;
	int inorder = checkOrder(head1);
	
	while (inorder == 0){
		if (ptr->data > nextP->data){ // if curr is bigger than next
			if (prev == NULL){
				struct Node* temp = nextP->next;
				nextP->next = ptr;
				ptr->next = temp;
				newHead = nextP;
				prev = NULL;
				ptr = newHead;
				nextP = ptr->next;
				nextP->next = temp;			
			} else {
				struct Node* temp = nextP->next;
				prev->next = nextP;
				nextP->next = ptr;
				ptr->next = temp;
				prev = nextP;
				nextP = temp;
			}
			first = 0;
			printLL(newHead);
		} else if (ptr->data < nextP->data){   // can merge w the last else lol
			if (first == 1){  // keep going, just move pointer
				prev = ptr;
				ptr = nextP;
				nextP = ptr->next;  
			} else { // go back to beginning 
				ptr = newHead;
				nextP = ptr->next;
				prev = NULL;
				//prev->next = ptr;
				first = 1;
			}
			
		} else {  // theyre equivilant, just move pointer
			if (first == 1){  // keep going, just move pointer
				prev = ptr;
				ptr = nextP;
				nextP = ptr->next;
			} else { // go back to beginning
				ptr = newHead;
				nextP = ptr->next;
				prev = NULL;
				first = 1;
			}
		}
		inorder = checkOrder(newHead);
		if (inorder == 0 && nextP == NULL){ // if it is NOT in order AND were at the end, go back to beginning
			ptr = newHead;
			nextP = ptr->next;
			prev = NULL;
			first = 1;
		}
	}
	head = newHead;
}



int main(int argc, char**argv){  
	FILE *fp = fopen(argv[1], "r"); // takes in file input (list of numbers separated by tabs
	
	// int oops;
	// fscanf(fp, "%d\n", &oops);
	// int num;
	// num = oops;
	
	while(fscanf(fp, "%d\n", &num) != EOF){ // prints elements as read in file
		push(num);
		printf("%d\t", num);
	}
	printf("\n");
	
	printLL(head);  
	
	sortLL(head);
	
	freeLL(head);
	
	fclose(fp);

	return EXIT_SUCCESS;
}
