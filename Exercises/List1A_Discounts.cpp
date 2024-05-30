#include <iostream>
#include <algorithm>
using namespace std;

int Partition(long long int* arr, long long int l, long long int r) {
    long long int p = arr[l];
    long long int i = l;
    long long int j = r+1;

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

void QuickSort(long long int* arr, long long int l, long long int r) {
    long long int s;
    if (l < r) {
        s = Partition(arr, l, r);
        QuickSort(arr, l, s-1);
        QuickSort(arr, s+1, r);
    }
}

void SomaCupom(long long int arr[], long long int bars, long long int num_coupons, long long int coupons[]) {
    QuickSort(arr, 0, bars - 1);

    long long int total = 0;
    for (long long int i = 0; i < bars; i++) {
        total += arr[i];
    }

    for (long long int k = 0; k < num_coupons; k++) {
        long long int menor = arr[bars - coupons[k]];
        long long int resultado = total - menor;
        cout << resultado << ' ';
    }
}

int main() {

    long long int bars;
    cin >> bars;

    long long int* arr = new long long int[bars];
    for (long long int i = 0; i < bars; i++) {
        cin >> arr[i];
    }

    long long int n_coupons;
    cin >> n_coupons;

    long long int* arr2 = new long long int[n_coupons];
    for (long long int k = 0; k < n_coupons; k++) {
        cin >> arr2[k];
    }

    SomaCupom(arr, bars, n_coupons, arr2);

    delete[] arr;
    delete[] arr2;

    return 0;
}