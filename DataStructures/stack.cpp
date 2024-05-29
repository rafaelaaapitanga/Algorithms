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

struct Stack { // LIFO
private:
    Node* top; // primeiro elemento
    int size;

    void createStack() {
        top = NULL;
        size = 0;
    }

public:
    Stack() {
        createStack();
    }

    void push (int value) {
        top = new Node(value, top);
        size++;
    }

    int pop() {
        if (top == NULL) {
            cout << "A pilha esta vazia." << endl;
        }
        int value = top->element;
        Node* temp = top;

        top = top->next;

        delete temp;
        size--;

        return value;
    }

    int getSize() {
        return size;
    }

};


int main() {

    int c;
    cout << "Numero de casos: ";
    cin >> c;

    for (int i=0; i < c; i++) {
        Stack p;
        string comando;

        while (cin >> comando) {
            if (comando == "push") {
            int x;
            cin >> x;
            p.push(x);

        } else if (comando == "pop") {
            int n;
            cin >> n;
            
            int soma = 0;
            for (int j=0; j < n; j++) {
                if (p.getSize() > 0) {
                    soma += p.pop();
                }
            }
            cout << soma << endl;

        } else if (comando == "end") {
            break;
            }
        }
    }

    return 0;
}