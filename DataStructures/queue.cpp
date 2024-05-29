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

struct Queue { // FIFO
private:
    Node* front;
    Node* rear;
    int size; 

    void createQueue() {
        front = rear = new Node(0);
        size = 0;
    }

public:
    Queue() {
        createQueue();
    }

    void enqueue(int value) {
        rear->next = new Node(value, NULL);
        rear = rear->next;
        size++;
    }

    int dequeue() {
        if (size == 0) {
            cout << "Fila vazia." << endl;
        }
        int value = front->next->element;
        Node* temp = front->next; // guardando a loc do node em uma variável
        front->next = front->next->next;

        if (front->next == NULL) {
            rear = front;
        }
        delete temp; // recuperar o espaço
        size--;
        return value;
    }

};

int main() {

    Queue fila;

    fila.enqueue(10);
    fila.enqueue(20);
    fila.enqueue(30);

    cout << "Dequeued: " << fila.dequeue() << endl;
    cout << "Dequeued: " << fila.dequeue() << endl;
    cout << "Dequeued: " << fila.dequeue() << endl;
    cout << "Dequeued: " << fila.dequeue() << endl;

    return 0;
}