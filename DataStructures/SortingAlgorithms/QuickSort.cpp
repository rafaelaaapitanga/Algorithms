#include <iostream>
using namespace std;

int Partition(int* arr, int l, int r) {
    int p = arr[l];
    int i = l;
    int j = r+1;

    do {
        do {
            i = i + 1;
        } while (arr[i] < p and i < r);
        do {
            j = j - 1;
        } while (arr[j] > p);
        swap(arr[i], arr[j]);
        
    } while (i < j);

    swap(arr[i], arr[j]);
    swap(arr[l], arr[j]);
    return j;
}

void QuickSort(int* arr, int l, int r) {
    int s;
    if (l < r) {
        s = Partition(arr, l, r);
        QuickSort(arr, l, s-1);
        QuickSort(arr, s+1, r);
    }
}

int main() {
    int N; // numero de elementos a serem ordenados
    cin >> N;

    int* arr = new int[N]; // alocando memoria para o array de inteiros

    for (int i = 0; i < N; i++) { // elementos a serem ordenados
        cin >> arr[i];
    }

    QuickSort(arr, 0, N-1);

    for (int i = 0; i < N; i++) { // elementos ordenados
        cout << arr[i] << ' ';
    }

    delete[] arr;

    return 0;
}