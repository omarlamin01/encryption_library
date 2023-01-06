#include "library.h"

#include <iostream>

using namespace std;

// create main method
int main() {
    string message1 = "Hello World";
    string message2 = "INWSNDF";

    cout << "Affine encrypt: " << affine_encrypt(message1, 23, 19) << endl;
    cout << "Affine decrypt: " << affine_decrypt(affine_encrypt(message1, 23, 19), 23, 19) << endl;

    return 0;
}