#include <iostream>
using namespace std;

void InsertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int value = arr[i];
        int j = i-1;

        while(j >= 0 and arr[j] > value) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = value;
    }
}


int main() {
    int arr[] = {20, 13, 10, 98, 1};
    int size = 5;
    InsertionSort(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}