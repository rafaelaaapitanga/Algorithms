#include <iostream>
using namespace std;

struct Node {
    int element;
    Node* next;

    Node (int value, Node* nextvalue = nullptr) { //parâmetro opcional - tem um valor padrão nullptr indicando que se não for fornecido, next será inicializado como nullptr.
        element = value;
        next = nextvalue; // se nextvalue não for fornecido, next será nullptr.
    }
};

struct LinkedList {
private:
    Node* head; // ponteiro p primeiro nó da lista
    Node* tail; // ponteiro p último nó da lista
    Node* curr; // ponteiro p cursor
    int cont; // contador p dizer o número de elementos da lista

    void createList() { // inicializa a linked list
        curr = tail = head = new Node(0);
        cont = 0;
    }

public:
    LinkedList() {
        createList();
    }

    void insert(int value) {
        curr->next = new Node(value, curr->next);
        if (tail == curr) {
            tail = curr->next;
        }
        cont++;
    }

    void moveToStart() {
        curr = head;
    }

    void prev() {
        if (curr == head) {
            return;
        }
        Node* temp = head;
        while (temp->next != curr) {
            temp = temp->next;
        }
        curr = temp;
    }

    void next() {
        if (curr != tail) { // se o cursor nao for o último nó
            curr = curr->next;
        }
    }

    int remove() {
        if (curr->next == NULL) {
            return -1;
        }
        int value = curr->next->element;
        Node* ntemp = curr->next; // guardando a loc do node em uma variável

        if (tail == curr->next) {
            tail = curr;
        }
        curr->next = curr->next->next;
        delete ntemp; // recuperar o espaço
        cont--;

        return value;
    }

    int count(int value) {
        int count = 0;
        Node* temp = head->next; // iniciar após o nó fictício
        while (temp != nullptr) {
            if (temp->element == value) {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
};


int main() {

    int c;
    cout << "Numero de casos: ";
    cin >> c;

    for(int i = 0; i < c; i++) {
        LinkedList list;

        int n;
        cout << "Numero de operacoes a serem realizadas: ";
        cin >> n;

        for (int j = 0; j < n; j++) {
            string comando;
            cin >> comando;

            if (comando == "insert") {
                int x;
                cin >> x;
                list.insert(x);
            } else if (comando == "remove") {
                list.remove();
            } else if (comando == "count") {
                int x;
                cin >> x;
                cout << list.count(x) << endl;
            } else if (comando == "prev") {
                list.prev();
            } else if (comando == "next") {
                list.next();
            }
        }
    }

    return 0;
}