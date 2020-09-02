#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
} Node;

void print_list(Node *head) {
    while (head != NULL) {
        printf("%d", head->val);
        head = head->next;
    }
}

void insert_node(Node *head,int prevVal, int val) {
    Node * curr = head;
    while (curr->val != prevVal)
        curr = curr->next;

    Node * tmp = curr->next;
    curr->next = (Node *) malloc(sizeof(Node));
    curr->next->val = val;
    curr->next->next = tmp;
}

void delete_node(Node **head, int val) {
    Node *prev = NULL, *curr = NULL;

    if (*head == NULL)
        return;

    if ((*head)->val == val){
        printf("asdasd");
        prev = *head;
        *head = (*head)->next;
        free(*head);
        *head = prev;
    } else {
        prev = curr = (*head)->next;
        while (curr != NULL) {
            if (curr->val == val) {
                prev->next = curr->next;
                free(curr);
                return;
            }

            prev = curr;
            curr  = curr->next;
        }
    }


}

int main() {
    Node *head = NULL;
    head = (Node *) malloc(sizeof(Node));
    head->val = 3;
    head->next = NULL;
    // 3 10 2 1
    insert_node(head, 3, 10);
    insert_node(head, 10, 2);
    insert_node(head, 2, 1);
    delete_node(&head, 2);

    print_list(head);
    return 0;
}