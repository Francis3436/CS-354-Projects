/* Francis Lu
 * 9080557540
 */

// do not include other libraries
#include <stdio.h>
#include <stdlib.h>

// ***************************************
// *** struct definitions ****************
// *** do not change these ***************
// ***************************************
typedef struct NODE {int data; struct NODE* next;} NODE; // nodes of the linked list
typedef struct LINKED_LIST {struct NODE *head;} LINKED_LIST; // struct to act as the head of the list


// ***************************************
// *** provided functions  ****************
// ***************************************

// this function returns a LINKED_LIST struct to
// act as the head of the linked list.
// do not change this function
LINKED_LIST Create_List(void) {LINKED_LIST list = {NULL}; return list;}

// call this function to verify malloc worked when you create new nodes
void Verify_Malloc(NODE *node) {if (node == NULL) {printf("Malloc Failed\n"); exit(1);} return;}

// do not change this function
// this function prints out all of the nodes in the linked list
void Print_List(FILE *out, LINKED_LIST list) {
    if (list.head == NULL) {printf("\n"); return;} //empty list
    NODE *current = list.head;
    while (current->next != NULL) {
        fprintf(out, "%d -> ",current->data);
        current = current->next;
    }
    fprintf(out, "%d\n",current->data);
    return;
}

// ******************************************************
// *** Complete the following functions  ****************
// ******************************************************

// this function returns the number 
// of elements in the linked list
int Size(LINKED_LIST list){ //referenced : "https://www.geeksforgeeks.org/write-a-function-that-counts-the-number-of-times-a-given-int-occurs-in-a-linked-list/" to see how a counter might work in linked lists
  int counter = 0; //counter to keep track of number o elements
  
  //if loop to check if list is empty
  if(list.head == NULL){
    return counter;
  }
  
  NODE *current = list.head; //node to set a pointer to the head of the linked list
  
  //while loop to go through the entire list until the end
  while(current != NULL){
    counter++;
    current = current->next;
  }
  
    return counter;
}

// this function adds an element to
// the front of the list
void Push_Front(LINKED_LIST *list, int data){ //used https://www.programiz.com/dsa/linked-list-operations to see how to insert into a linked list
    NODE * newNode = malloc(sizeof(NODE));
    
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    return;
}

// this function adds an element 
// to the end of the linked list 
void Push_Back(LINKED_LIST *list, int data) {
  NODE *newNode = malloc(sizeof(NODE));
  newNode->data = data; //sets data into newNode
    
    //if loop to check if the list is empty. 
    //If empty, add new element into the head of the list
    if(list->head == NULL){
      list->head = newNode;
      return;
    }
    
    NODE *current = list->head;  
    
    //while loop to check if the next value is null or not. 
    while(current->next != NULL){
      current = current->next;
    }
    
    //adds to the end of the list and sets the next value to NULL.
    current->next = newNode; 
    newNode->next = NULL;
    return;
}


// if the list is not empty
// the value of the first element of the list is returned by reference in the parameter data
// the first element of the list is deleted
// returns 0 if the list is empty otherwise returns 1
// remember to free the deleted node
int Pop_Front(LINKED_LIST *list, int *data) {
    
    //checks if the head is null
    if(list->head == NULL){
      return 0;
    }
    
    NODE *temporary_holder = list->head; //sets a pointer to the address head of the list
    
    //load the data into the head, sets the new head address and frees the pointer that held the address of the head (which is being popped)
    *data = list->head->data;
    list->head = list->head->next;
    free(temporary_holder);
    return 1;
}


// if the list is not empty
// the value of the last element of the list is returned by reference in the parameter data
// the last element of the list is deleted
// returns 0 if the list is empty otherwise returns 1
// remember to free the deleted node
int Pop_Back(LINKED_LIST *list, int *data) {
    
    //if loop to check if list is empty return 0.
    if(list->head == NULL){
      return 0;
    }
    
    NODE* traverser = list->head;
    
    //if loop to check if the list only has 1 value
    if(traverser->next == NULL){
      Pop_Front(list, data); 
    }
    else if(traverser->next != NULL){
      while(traverser->next->next != NULL){
        traverser = traverser->next;
        }
        
      *data = traverser->next->data;
      free(traverser->next);
      traverser->next = NULL;
    }
    
    return 1;
}

// this function returns the number 
// of times that the value of the parameter 
// data appears in the list
int Count_If(LINKED_LIST list, int data) {
  int counter = 0; //counter
  
  //checks if list is empty, if so return. 
  if(list.head == NULL){
    return counter;
  }
  
  NODE *holder = (&list)->head;
  
  //while loop to check how many times a value appears in the list
  while(holder != NULL){
    if(holder->data == data){
      counter++;
    }
    holder = holder->next;
  }
  return counter;
}

// delete the first node containing the data value
// return 1 if something was deleted otherwise 0
// remember to free the deleted node
int Delete(LINKED_LIST *list, int data) {
  
    //if loop to check if list is empty
    if(list->head == NULL){
      return 0;
    }
    
    NODE *nextNode = list->head;
    
    //while loop to traverse list
    while(nextNode != NULL){
      if(nextNode->data == data){ //check if the first node contains the same data if so, use pop front funciton to save and clear it. 
        int *address = &data;
        Pop_Front(list, address);
        nextNode = nextNode->next;
        return 1;
      }
      else if(nextNode->next->data == data){ //checks next node to see if data matches, if so, set the next node to the one after that and delete the first occurance of the data match
        NODE *temporary = nextNode->next; 
        nextNode->next = nextNode->next->next;
        free(temporary);
        return 1;
      }
      nextNode = nextNode -> next;
    }
    return 0;
}

// return 1 if the list is empty otherwise returns 0
int Is_Empty(LINKED_LIST list) {
    
    //checks of head is null (list is empty) if so returns 1. 
    if(list.head == NULL){
      return 1;
    } 
    else{
      return 0;
    }
    return 0;
}

// delete all elements of the list
// remember to free the nodes
void Clear(LINKED_LIST *list) {

    int *addressHolder = malloc(sizeof(int)); //pointer to hold address of a data if needed
    
    //while loop to check if list is empty and if not, pops first element until list is empty
    while(Is_Empty(*list) == 0){
      Pop_Front(list, addressHolder);
    }
    free(addressHolder);                    
    return;
}


// if an element appears in the list 
// retain the first occurance but
// remove all other nodes with the same 
// data value
void Remove_Duplicates(LINKED_LIST *list) { //referenced https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/ to understand how removing dupes works
  struct NODE* current = list->head;
  struct NODE* nextNode;
  
  //if loop to check if head of list is null
  if(current == NULL){
    return;
  }
  
  //while loop to check if there are any dupes. If there are, remove them.
  while(current->next != NULL){
    if(current->data == current->next->data){
      nextNode = current->next->next;
      free(current->next);
      current->next = nextNode;
    }
    else{
      current = current->next;
    }
  }
    return;
}

// modify main to completely test your functions 
int main() {
    // create a linked list
    printf("creating linked list\n");
    LINKED_LIST list = Create_List();
   
    // add some data (hardcoded for testing)
    printf("hardcoding some data\n");
    NODE *first  = malloc(sizeof(NODE)); Verify_Malloc(first);
    NODE *second = malloc(sizeof(NODE)); Verify_Malloc(second);
    first->data  = 1;
    second->data = 2;
    list.head = first;
    first->next = second;
    second->next = NULL;

    // print the list
    printf("Testing Print_List\n");
    Print_List(stdout, list);

    // write a better test for Size
    printf("Testing Size\n");
    printf("size = %d\n",Size(list));

    // write a better test for Push_Front
    printf("Testing Push_Front\n");
    Push_Front(&list, 0);
    Print_List(stdout, list);
    
    // write a better test for Push_Back
    printf("Testing Push_Back\n");
    Push_Back(&list, 3);
    Print_List(stdout, list);

    // write a better test for Pop_Front
    printf("Testing Pop_Front\n");
    {
        int x; 
        int not_empty = Pop_Front(&list, &x);
        if (not_empty) {
            printf("Element popped was %d\n",x);
            Print_List(stdout,list);
            printf("size = %d\n",Size(list));
        }
        else 
            printf("List was empty\n");
    }

    // write a better test for Pop_Back
    printf("Testing Pop_Back\n");
    {
        int x; 
        int not_empty = Pop_Back(&list, &x);
        if (not_empty) {
            printf("Element popped was %d\n",x);
            Print_List(stdout,list);
            printf("size = %d\n",Size(list));
        }
        else 
            printf("List was empty\n");
    }

    // write a beter test for Count_If
    Push_Front(&list, 5);
    Push_Front(&list, 5);
    Print_List(stdout, list);
    printf("5 count = %d\n",Count_If(list, 5));
    
    // write a test for Delete 
    printf("Testing Delete\n");
    Print_List(stdout, list);
    Delete(&list, 1); 
    Print_List(stdout, list);

    // write a better test for Is_Empty
    printf("Testing Is_Empty\n");
    if (Is_Empty(list)) printf("List is Empty\n"); else printf("List is not empty\n");
    
    // write a better test for Clear
    Clear(&list);
    if (Is_Empty(list)) printf("List is Empty\n"); else printf("List is not empty\n");

    // write a better test for Remove_Duplicates
    Push_Back(&list, 1);
    Push_Back(&list, 1);
    Push_Back(&list, 1);
    Push_Back(&list, 2);
    Push_Back(&list, 2);
    Push_Back(&list, 3);
    Push_Back(&list, 3);
    Push_Back(&list, 3);
    Remove_Duplicates(&list);
    Print_List(stdout, list);
    return 0;
}
