#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * head;
void InsertAtBeginning(int x);
void Print();
void InsertAtEnd(int x);
void Insert(int x,int n);
int Length();
void Delete(int n);
void ReversedLinkedList();

int main(){
    head=NULL;
    InsertAtBeginning(1);
    InsertAtBeginning(2);
    InsertAtBeginning(3);
    InsertAtBeginning(10);
    Print();
    printf("%d\n",Length());

    printf("------\n");

   /*Delete(1);
    Print();
    printf("%d\n",Length());

    Delete(-2);

    printf("------\n");

    Delete(3);
    Print();
    printf("%d\n",Length());*/

    ReversedLinkedList();
    Print();

    return 0;
}

//Insert a element into start of the linked list
void InsertAtBeginning(int x){
    struct Node * temp =(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=head;
    head = temp;
}

//Print all the elements in the linked list
void Print(){

    struct Node* temp=head;

    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

//Insert a data into end of the linked list
void InsertAtEnd(int x){
    struct Node* temp =head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    struct Node* lastNode=(struct Node*)malloc(sizeof(struct Node));
    lastNode->data=x;
    lastNode->next=NULL;
    temp->next=lastNode;
}

//Insert a data into given position/index
void Insert(int x, int n){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    newNode->data = x;

    if(n==1){
        newNode->next = head;
        head = newNode;
        return;
    }

    else if(n>Length()+1){
        printf("Invalid Index. Can't add %d to %d index\n",x,n);
        return;
    }

    for(int i=0;i<n-2;i++){
        temp=temp->next;
    }
    newNode->next = temp->next;
    temp->next=newNode;
}

//Return length of the linked list
int Length(){
    struct Node* temp = head;
    int n=0;

    while(temp !=NULL){
        temp = temp->next;
        n++;
    }
    return n;
}

//Delete a node in a given position/index.
void Delete(int n){
    struct Node* temp = head;
    struct Node* deleteNode;
    if(n==1){
        head=temp->next;
        deleteNode = temp;
    }

    else if(n>Length() || n<1){
        printf("Invalid Index %d\n",n);
        return;
    }

    else{
        for(int i=0;i<n-2;i++){
            temp=temp->next;
        }

        deleteNode=temp->next;
        temp->next = temp->next->next;
    }

    free(deleteNode);
}

// Reversed the linked list
void ReversedLinkedList(){
    struct Node* current;
    struct Node* next;
    struct Node* prev = NULL;
    current = head;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current= next;
    }
    head = prev;
}
