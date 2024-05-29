#include <iostream>
#include <string>
using namespace std;

struct Node {
    char element;
    Node* next;

    Node (char value, Node* nextvalue = nullptr) {
        element = value;
        next = nextvalue;
    }
};

struct LinkedList {
private:
    Node* head;
    Node* tail;
    Node* curr;
    int cont;

public:
    LinkedList() {
        curr = tail = head = new Node(0);
        cont = 0;
    }

    void insert(char value) {
        curr->next = new Node(value, curr->next);
        if (tail == curr) {
            tail = curr->next;
        }
        curr = curr->next; // move o cursor p o novo nó inserido
        cont++;
    }

    void clear() { // responsável por limpar todos os nós da lista, exceto o nó "dummy" inicial
        Node* temp;
        curr = head->next; // pula o nó dummy

        while (curr != nullptr) { // enquanto o cursor não for nulo
            temp = curr;
            curr = curr->next; // armazena o curr em temp para que possa deletar após mover curr p/ o próximo nó
            delete temp;
        }

        curr = tail = head; // indica novamente a lista vazia exceto pelo nó dummy
        head->next = nullptr;
        cont = 0;
    }

    void moveToStart() {
        curr = head;
    }

    void moveToEnd() {
        curr = tail;
    }

    void printList() { // pega o que tem até entao na lista ligada e printa na ordem em que se encontra
        Node* temp = head->next;

        while (temp != nullptr) { // enquanto houver proximo
            cout << temp->element; // printa o elemento
            temp = temp->next; // passa p próximo
        }
        cout << endl;
    }

    void processText(string text) {
        clear(); // limpa a lista antes de processar o novo texto
        moveToEnd(); // inicialmente, qlqr caracter será inserido no fim da lista
        
        for (char ch : text) { // *percorre cada caracter ch na string text*
            if (ch == '[') {
                moveToStart();
            } else if (ch == ']') {
                moveToEnd();
            } else {
                insert(ch); // insere normalmente o caracter na posicao atual do cursor
            }
        }
    }

};

int main () {
    string line;
    LinkedList textList;

    while (getline(cin, line)) { // le uma linha completa de entrada (cin) e a armazena na variavel line
        textList.processText(line);
        textList.printList();
    }

    return 0;
}
// se tiver executando o programa no terminal, pressionar ctrl+z (windows) para enviar um sinal de finalização de arquivo (EOF)