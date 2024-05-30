#include <iostream>
using namespace std;

int main() {
    int c;
    cout << "Número de casos: ";
    cin >> c;

    for (int i = 0; i < c; i++) {
        int num;
        cin >> num;

        int dezenas = num / 10; // pega o menor - 23/10 = 2.3 = 2
        int unidades = num % 10; // pega o resto - 23%10 = 3
        cout << dezenas << " " << unidades << endl;
    }
    return 0;
}