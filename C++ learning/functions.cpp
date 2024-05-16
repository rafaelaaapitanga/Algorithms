#include <iostream>
using namespace std;

void sayHi(string name, int age) { // only the function
    cout << "Hello, " << name << " you are " << age << " years old";
}


int main() 
{
    sayHi("Rafa,", 22); // calling the function
    sayHi("Celo", 29);

    return 0;
}