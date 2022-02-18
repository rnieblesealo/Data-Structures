

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

struct Node* HEAD = NULL;

void Insert(int value){
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    new_node->value = value;
    new_node->next = HEAD;
    
    HEAD = new_node;
}

void Print(){
    Node* current = HEAD;
    
    printf("List: ");
    
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
        Insert(v);
        Print();
    }
}