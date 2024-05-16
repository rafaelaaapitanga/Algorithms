#include <iostream>
#include <string>

using namespace std;

int main() 
{
    char grade = 'A';
    string phrase = "I'm beautiful";
    int age = 20;
    double number = 2.3;
    bool choice = false;

    cout << "Grade: " << grade << endl;
    cout << "Phrase: " << phrase << endl;
    cout << "Age: " << age << endl;
    cout << "Number: " << number << endl;
    cout << "Choice: " << (choice ? "true" : "false") << endl;

    return 0;
}