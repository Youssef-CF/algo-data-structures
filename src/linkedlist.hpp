//
// Created by youssef on 1/1/21.
//

#ifndef ALGO_DATA_STRUCTURES_LINKEDLIST_HPP
#define ALGO_DATA_STRUCTURES_LINKEDLIST_HPP
typedef struct Node {
    int data;
    struct Node* next;
} Node;

bool isEmpty(Node* head);
std::string toString(Node* head);
Node* insert(Node* head, int n, char place);
Node* search(Node* head, int x);
Node* remove(Node* head, int n);
int occurrence(Node* head, int n);
void deleteList(Node* head);
Node* insertQueue(Node* head, int n);

#endif //ALGO_DATA_STRUCTURES_LINKEDLIST_HPP
