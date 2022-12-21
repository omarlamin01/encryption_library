#include "library.h"

#include <iostream>

using namespace std;

// create main method
int main() {
    string message1 = "LICENCEINFO";
    string message2 = "INWSNDF";

    cout << "Ceasar Cipher: " << ceasar_encrypt(message1, 5) << endl;
    cout << "Ceasar Cipher: " << ceasar_encrypt(message2, 5) << endl;

    return 0;
}