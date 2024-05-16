#include <iostream>
using namespace std;

int SequentialSearch(int* arr, int n, int K) { // brute force
    int i = 0;
    while (i < n && arr[i] != K) {
        i = i +1;
    }
    if (i < n) {
        return i;
    } else {
        return -1;
    }
}

int main () {
    int size;
    cout << "Tamanho do array: ";
    cin >> size; // tamanho do array

    int* arr = new int[size];

    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i]; // declarar o array desejado
    }

    int target;

    cout << "Valor que deseja encontrar: ";
    cin >> target; // valor que deseja encontrar

    int result = SequentialSearch(arr, size, target);

    if (result != -1) {
        cout << result << endl; // indice em que o número foi encontrado
    } else {
        cout << "Número não encontrado." << endl;
    }

    return 0;
}