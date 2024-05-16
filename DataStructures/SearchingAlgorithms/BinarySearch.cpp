#include <iostream>
using namespace std;
// array já ordenado em ordem crescente

int BS(int arr[], int l, int r, int K) { // busca binária recursiva - pode ter um custo maior devido ao overhead da pilha
    if (r >= l) {
        int m = (l+r)/2;

        if (K == arr[m]) {
            return m;
        } else if (K < arr[m]) {
            return BS(arr, l, m-1, K);
        } else {
            return BS(arr, m+1, r, K);
        }
    } else {
        return -1;
    }
}

int BS(int arr[], int n, int K) { // busca binária iterativa - mais eficiente em termos de consumo de memória
    int l = 0;
    int r = n-1;

    while (l <= r) {
        int m = (l+r)/2;

        if (K == arr[m]) {
            return m;
        } else if (K < arr[m]) {
            r = m-1;
        } else {
            l = m+1;
        }
    }
    return -1;
}


int main() {

    int N;
    cout << "Número de elementos do array: ";
    cin >> N;

    int* arr = new int[N];

    cout << "Os " << N << " elementos do array em ordem crescente: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Valor no array que você deseja encontrar: ";
    cin >> target;

    int recursiveBS = BS(arr, 0, N-1, target);
    int iterativeBS = BS(arr, N, target);

    if (recursiveBS != -1) {
        cout << recursiveBS;
    } else {
        cout << "Valor não encontrado.";
    }

    if (iterativeBS != -1) {
        cout << "\n" << iterativeBS;
    } else {
        cout << "Valor não encontrado.";
    }

    delete[] arr;
    return 0;
}