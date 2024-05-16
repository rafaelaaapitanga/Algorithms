#include <iostream>
using namespace std;

void SelectionSort(int arr[], int size) { // brute force
    for(int i=0; i < size-1; i++) {
        int min = i;
        for(int j=i+1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}


int main() {
    int arr[] = {34, 9, 1, 7, 3};
    int size = 5;
    SelectionSort(arr, size);
    for (int k = 0; k < size; k++) {
        cout << arr[k] << " ";
    }

    return 0;
}