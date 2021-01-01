#include <iostream>
#include "linkedlist.hpp"

using namespace std;

int main() {
    int n, ans;
    Node* head = nullptr;
    Node* node = new Node();
    node->next = nullptr;


    do {
        cout << "0 créer une liste" << endl;
        cout << "1 tester si la liste est vide ou non" << endl;
        cout << "2 insérer un element " << endl;
        cout << "3 afficher la liste" << endl;
        cout << "4 nombre d'occurrence" << endl;
        cout << "5 rechercher une valeur" << endl;
        cout << "6 supprimer un element" << endl;
        cout << "7 quitter" << endl;
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
                if (isEmpty(head)) {
                    cout << "La list est vide" << endl;
                } else {
                    cout << "La list est non vide" << endl;
                }
                break;
            }
            case 2: {
                char place;
                cout << "donner la valeur: ";
                cin >> n;
                cout
                        << "si vous voulez insérer au début tapper 'd'\n si vous voulez insérer au milieu tappez'm'\n si vous voulez insérer a la fin tappez 'f': ";
                cin >> place;
                if ((place == 'd') || (place == 'm'))
                    insert(head, n, place);
                if (place == 'f')
                    insertQueue(head, n);

                break;
            }
            case 3: {
                cout << "liste: ";
                string s = toString(head);
                cout << s;
                break;
            }
            case 4: {
                int c;
                cout << "entrez une valeur: ";
                cin >> n;
                c = occurrence(head, n);
                cout << "l'occurrence de " << n << " est de " << c;
                break;
            }
            case 5: {
                cout << "choisissez la valeur à rechercher: ";
                cin >> n;
                Node* result = search(head, n);
                if (result != nullptr) {
                    cout << "la valeur " << result->data << " a bien été trouvée";
                } else {
                    cout << "la valeur " << n << " n'a pas été trouvée";
                }
                break;
            }
            case 6: {
                cout << "choisissez la valeur à supprimer: ";
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
