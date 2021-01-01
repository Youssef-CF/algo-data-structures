//
// Created by youssef on 1/1/21.
//
#include <cstdlib>
#include <string>
using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node;

bool isEmpty(Node* head) {
    return head == nullptr;
}

string toString(Node* head) {
    string s;
    Node* p = head;
    while (p != nullptr) {
        s +=  " => " + to_string(p->data);
        p = p->next;
    }
    return s;
}

Node* insert(Node* head, int n, char place) {
    Node* ptr = head;
    Node* new_node = new Node();
    new_node->next = nullptr;
    new_node->data = n;
    if (head == nullptr) {
        new_node = head;
        return head;
        return head;

    }
    if (place == 'd') {
        new_node->next = head;
        head = new_node;
        return head;
    } else
        while (ptr != nullptr) {

            if (place == 'm') {
                head = head->next;
                new_node->next = head->next;
            }
            return head;
        }

}

Node* insertQueue(Node* head, int n) {
    Node* new_node = new Node();
    Node* queu = head;
    new_node->next = nullptr;
    new_node->data = n;
    if (head == nullptr) {
        new_node = head;
        return head;
    }

    while (queu->next != nullptr)
        queu = queu->next;
    queu->next = new_node;
    return head;
}

Node* search(Node* head, int x) {
    Node* node = head;
    while (node != nullptr) {
        if (node->data == x) {
            return node;
        }
        node = node->next;
    }
    return nullptr;
}

Node* remove(Node* head, int n) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* ptr = head, *p = ptr;
    while (ptr != nullptr) {
        if (ptr->data == n)
            break;
        else {
            p = ptr;
            ptr = ptr->next;
        }
    }
    if (ptr == nullptr) {
        return nullptr;
    }
    if (ptr == p) {
        head = head->next;
        delete ptr;
        delete p;
        return head;
    }
    if (ptr->next == nullptr) {
        p->next = nullptr;
        delete ptr;
        return head;
    } else {
        p->next = ptr->next;
        delete ptr;
        return head;
    }

}

int occurrence(Node* head, int n) {
    Node* ptr = head;
    int c = 0;
    while (ptr != nullptr) {
        if (ptr->data == n) { c++; }
    }
    return c;
}

void deleteList(Node* head) {
    Node* p = head;
    if (p != nullptr) {

        Node* tmp = p->next;
        delete p;
        p = tmp;
    }
    delete head;
    head = nullptr;
}
