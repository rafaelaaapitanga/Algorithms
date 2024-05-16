#include <iostream>

using namespace std;

int main() 
{
    int numbers[] = {4, 8, 15, 16}; // you can also put a size, like numbers[20]
    int numbers2[10];
    numbers2[0] = 1;

    cout << numbers[0] << endl; // number 4
    cout << numbers2[0] << endl; // number 1

    return 0;
}