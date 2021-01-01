#include <iostream>

using namespace std;
typedef struct Node {
    int data;
    struct Node *next;
} Node;

void isEmpty(Node *head) {
    if (head == NULL)
        cout << "liste est vide" << endl;
    else
        cout << "liste non vide" << endl;
}

void printList(Node *head) {
    Node *p = head;
    while (p != NULL) {
        cout << "\t=> " << p->data;
        p = p->next;
    }
}

Node *insert(Node *head, int n, char place) {
    Node *ptr = head;
    Node *new_node = new Node();
    new_node->next = NULL;
    new_node->data = n;
    if (head == NULL) {
        new_node = head;
        return head;
        return head;

    }
    if (place == 'd') {
        new_node->next = head;
        head = new_node;
        return head;
    } else
        while (ptr != NULL) {

            if (place == 'm') {
                head = head->next;
                new_node->next = head->next;
            }
            return head;
        }

}

Node *insertQueue(Node *head, int n) {
    Node *new_node = new Node();
    Node *queu = head;
    new_node->next = NULL;
    new_node->data = n;
    if (head == NULL) {
        new_node = head;
        return head;
    }

    while (queu->next != NULL)
        queu = queu->next;
    queu->next = new_node;
    return head;
}

void search(Node *head, int x) {
    Node *node = head;
    node = head;
    while (node != NULL) {
        if (node->data == x) {
            cout << x << "\test trouvé\n";
            return;
        }
        node = node->next;
    }
    cout << x << "\tpas trouvé\n";
}

Node *remove(Node *head, int n) {
    if (head == NULL) {
        cout << "liste est deja vide" << endl;
    }

    Node *ptr = head, *p = ptr;
    while (ptr != NULL) {
        if (ptr->data == n)
            break;
        else {
            p = ptr;
            ptr = ptr->next;
        }
    }
    if (ptr == NULL) {
        cout << "valeure non trouve" << endl;
    }
    if (ptr == p) {
        head = head->next;
        delete ptr;
        delete p;
        return head;
    }
    if (ptr->next == NULL) {
        p->next = NULL;
        delete ptr;
        return head;
    } else {
        p->next = ptr->next;
        delete ptr;
        return head;
    }

}

int occurrence(Node *head, int n) {
    Node *ptr = head;
    int c = 0;
    while (ptr != NULL) {
        if (ptr->data == n) { c++; }
    }
    return c;
}

void deleteList(Node *head) {
    Node *p = head;
    if (p != NULL) {

        Node *tmp = p->next;
        delete p;
        p = tmp;
    }
    delete head;
    head = NULL;
}

int main() {
    int n, ans;
    Node *head = NULL;
    Node *node = new Node();
    node->next = NULL;


    do {
        cout << "0 crier liste" << endl;
        cout << "1 tester si la liste est vide ou non" << endl;
        cout << "2 inserer un element " << endl;
        cout << "3 afficher la liste" << endl;
        cout << "4 nombre d'acurance" << endl;
        cout << "5 search un element" << endl;
        cout << "6 remove un element" << endl;
        cout << "7 exite" << endl;
        cout << "donner votre choix: ";
        cin >> ans;
        switch (ans) {
            case 0: {
                cout << "donner la valeur: ";
                cin >> n;
                node->data = n;
                head = node;
                break;
            }
            case 1: {
                isEmpty(head);
                break;
            }
            case 2: {
                char place;
                cout << "donner la valeure: ";
                cin >> n;
                cout
                        << "si vous voulez insert au debut tapper 'd'\n si vous voulez insert au mileiu tappez'm'\n si vous voulez inserer a la fin tappez 'f': ";
                cin >> place;
                if ((place == 'd') || (place == 'm'))
                    insert(head, n, place);
                if (place == 'f')
                    insertQueue(head, n);

                break;
            }
            case 3: {
                cout << "liste: ";
                printList(head);
                break;
            }
            case 4: {
                int c;
                cout << "donner le nombre: ";
                cin >> n;
                c = occurrence(head, n);
                cout << "nombre d'acurence de" << n << "est" << c;
                break;
            }
            case 5: {
                cout << "donner la valeure pour search: ";
                cin >> n;
                search(head, n);
                break;
            }
            case 6: {
                cout << "donner la valeure pour remove: ";
                cin >> n;
                remove(head, n);
                break;
            }
            case 7: {
                deleteList(head);
                break;
            }

        }
        cout << "\n***********\n" << endl;
    } while (((ans == 1) || (ans == 2) || (ans == 3) || (ans == 4) || (ans == 5)) || (ans == 6) || (ans != 7));


    return 0;


}
