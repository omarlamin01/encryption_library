#include "library.h"

#include <iostream>

using namespace std;

// create main method
int main() {
    string message1 = "LICENCEINFO";
    string message2 = "INWSNDF";

    cout << message1 + " ==> " + ceasar_cipher(5, message1, 0) << endl;
    cout << message2 + " ==> " + ceasar_cipher(5, message2, 1) << endl;

    return 0;
}