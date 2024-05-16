#include <iostream>
using namespace std;

void Merge(int arr[], int l, int r) {
    int temp[l+r+1];
    for (int i = l; i <= r; i++) {
        temp[i] = arr[i];
    }
    int m = (l+r)/2;
    int i1 = l;
    int i2 = m+1;

    for (int curr = l; curr <=r; curr++) {
        if (i1 == m+1) {
            arr[curr] = temp[i2++];
        } else if (i2 > r) {
            arr[curr] = temp[i1++];
        } else if (temp[i1] <= temp[i2]) {
            arr[curr] = temp[i1++];
        } else {
            arr[curr] = temp[i2++];
        }
    }
}

void MergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        MergeSort(arr, l, m);
        MergeSort(arr, m+1, r);
        Merge(arr, l, r);
    }
}

int main(){

    int C;
    cout << "Numero de casos: ";
    cin >> C;

    for (int i = 0; i < C; i++) {
        int N;
        cout << "\nTamanho do array a ser ordenado: ";
        cin >> N;

        int* arr = new int[N];

        for (int j = 0; j < N; j++) {
            cin >> arr[j];
        }

        MergeSort(arr, 0, N-1);

        for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
        }

        delete[] arr;

    }

    return 0;
}