#include <iostream>
using namespace std;

void merge(int *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int AbsoluteDiff(int *numeros, int n, int k) {
    mergeSort(numeros, 0, n - 1);

    int count = 0;
    int left = 0, right = 1;

    while (right < n) {
        int diff = numeros[right] - numeros[left];
        if (diff == k) {
            count++;
            left++;
            right++;
        } else if (diff < k) {
            right++;
        } else {
            left++;
        }
        if (left == right) {
            right++;
        }
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;

    int *numeros = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    int paresCount = AbsoluteDiff(numeros, n, k);
    cout << paresCount << endl;

    delete[] numeros;

    return 0;
}