#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;
    Node(int id) : id(id), next(nullptr) {}
};

class CustomQueue {
public:
    CustomQueue() : front(nullptr), rear(nullptr), size(0) {}

    ~CustomQueue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void add(int id) {
        Node* newNode = new Node(id);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void solve() {
        if (front != nullptr) {
            Node* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
            size--;
        }
    }

    void print() const {
        if (front == nullptr) {
            cout << "x" << endl;
        } else {
            Node* current = front;
            while (current != nullptr) {
                cout << current->id << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    int getSize() const {
        return size;
    }

private:
    Node* front;
    Node* rear;
    int size;
};

int main() {
    CustomQueue banco;
    int resolvidas = 0;
    string comando;

    while (cin >> comando && comando != "end") {
        if (comando == "add") {
            int id;
            cin >> id;
            banco.add(id);
        } else if (comando == "solve") {
            if (banco.getSize() > 0) {
                banco.solve();
                resolvidas++;
            }
        } else if (comando == "print") {
            banco.print();
        } else if (comando == "stats") {
            cout << resolvidas << " " << banco.getSize() << endl;
        }
    }

    return 0;
}