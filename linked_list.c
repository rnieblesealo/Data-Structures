/* A basic linked list implementation! */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

struct Node* HEAD = NULL;

void Append(int value){
    // Adds a new value at the beginning of the list.
    
    /*
        How this works:

        (Let [N] represent the new node)

        (1)    HEAD -> NULL          // Starts empty
        (2)    [N], HEAD -> NULL     // Create a new node which exists outside the list
        (3)    [N] -> HEAD -> NULL   // Make the new node point to current HEAD
        (4)    HEAD = [N]            // New node added now becomes the HEAD
        (5)    HEAD -> [N] -> NULL   // Voila!
    */

    Node* new_node = (Node*)malloc(sizeof(Node));
    
    new_node->value = value;
    new_node->next = HEAD;
    
    HEAD = new_node;
}

void Insert(int value, int index){
    // Inserts a new value such that it is at position @index on the list.
    
    /*
        How this works:

        (1)    HEAD -> [A] -> [B]          // Let us have a list with elements
        (2)    [N], HEAD -> [A] -> [B]     // We create N and want to insert it at index 1, so between A and B
        (3)    [N] -> [B]                  // Make N point to B, which is A's next
        (4)    [A] -> [N]                  // Since N is now after A, make A point to N
        (5)    HEAD -> [A] -> [N] -> [B]   // Voila!
    */

    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->value = value;
    new_node->next = NULL;

    if (index == 0){
        new_node->next = HEAD;
        HEAD = new_node;
        return;
    }
    
    Node* current = HEAD;
    
    for (int i = 0; i < index--; ++i){
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

void Print(){
    // Prints all current elements in the list.
        
    printf("List: ");
    
    Node* current = HEAD;
    
    while (current != NULL){
        printf("%i ", current->value);
        
        current = current->next;
    }

    printf("\n");
}

int main(){
    int n;
    int v;

    printf("Enter value count:\n");
    scanf("%i", &n);

    for (int i = 0; i < n; ++i){
        printf("Enter value:\n");
        scanf("%i", &v);
        Append(v);
        Print();
    }

    printf("Inserting 1000 at position 3!\n");
    Insert(1000, 3);
    Print();
}