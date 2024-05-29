#include <iostream>
using namespace std;

struct Node {
    int entryTime;
    int toleranceTime;
    Node* next;

    Node(int entry, int tolerance, Node* nextValue = nullptr) {
        entryTime = entry;
        toleranceTime = tolerance;
        next = nextValue;
    }
};

struct Queue {
private:
    Node* front; // inicio da fila
    Node* rear; // final da fila
    int size;

public:
    Queue() {
        front = rear = new Node(0, 0);
        size = 0;
    }

    void enqueue(int entryTime, int toleranceTime) {
        rear->next = new Node(entryTime, toleranceTime);
        rear = rear->next;
        size++;
    }

    void dequeue() {
        Node* temp = front->next;
        front->next = front->next->next;

        if (front->next == nullptr) {
            rear = front;
        }
        delete temp;
        size--;
    }

    bool isEmpty() {
        return size == 0;
    }

    Node* getFront() {
        return front->next;
    }
};

int main() {
    int t;
    cin >> t; // número de casos

    for (int i = 0; i < t; i++) {        
        Queue fila;
        int n;
        cin >> n; // número de estudantes

        for (int j = 0; j < n; j++) {
            int l, r;
            cin >> l >> r;
            fila.enqueue(l, r);
        }

        int currentTime = 0;

        while (!fila.isEmpty()) { // enquanto a fila tiver estudante
            Node* s = fila.getFront(); // primeiro estudante é armazenado no ponteiro s

            currentTime = max(currentTime, s->entryTime); // garante que o tempo atual avance até pelo menos o momento em que o próximo estudante na fila chega

            if (currentTime > s->toleranceTime) { // se o tempo atual do estudante for maior que seu tempo de tolerância
                cout << 0 << " "; // estudante desiste
            } else {
                cout << currentTime << " "; // estudante pega o chá
                currentTime++; // tempo é incrementado
            }
            fila.dequeue();
        }
        cout  << endl;
    }
    return 0;
}