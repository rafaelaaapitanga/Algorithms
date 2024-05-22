#include <iostream>
using namespace std;

class Lista {
private:
    int maxSize; // capacidade máxima do array
    int listSize; // numero atual de elementos
    int curr; // posicao atual do cursor
    int* listArray; // ponteiro p array c/ valores

public:
    Lista (int size) {
        maxSize = size;
        listSize = curr = 0;
        listArray = new int[size];
    }

    void insert(int valor) { // elemento é sempre adicionado à direita
        if (listSize >= maxSize) { // se o número de elementos do array for maior que a capacidade máxima dele
            cout << "Sem espaço na lista.";
            return;
        }
        else {
            for (int i = listSize; i > curr; i--) {
                listArray[i] = listArray[i-1];
            }
            listArray[curr] = valor;
            listSize++;
        }
    }

    int remove() { // vai remover o elemento que está no cursor e levar o elemento da direita para o cursor
        if (curr < 0 || curr >= listSize) { // cursor não terá elemento à direita 
            return -1;
        } else {
            int value = listArray[curr];
            for (int i = curr; i < listSize-1; i++) {
                listArray[i] = listArray[i+1];
            }
            listSize--;
            return value;
        }
    }

    void prev() {
        if (curr != 0) {
            curr--;
        }
    }

    void next() {
        if (curr < listSize) {
            curr++;
        }
    }

    int count(int valor) {
        int count = 0;
        for (int i = 0; i < listSize; i++) {
            if (listArray[i] == valor) {
                count++;
            }
        }
        return count;
    }

};

int main() {
    int C;
    cout << "Numero de casos: ";
    cin >> C;

    for (int i = 0; i < C; i++) {
        int N;
        cout << "Numero de operacoes a serem realizadas: ";
        cin >> N;

        Lista lista1(1000); // tamanho maximo da lista

        for (int j = 0; j < N; j++) {
            string comando;
            cin >> comando;

            if (comando == "insert") {
                int x;
                cin >> x;
                lista1.insert(x);
            } else if (comando == "remove") {
                lista1.remove();
            } else if (comando == "count") {
                int x;
                cin >> x;
                cout << lista1.count(x) << endl;
            } else if (comando == "prev") {
                lista1.prev();
            } else if (comando == "next") {
                lista1.next();
            }
        }
    }

    return 0;
}