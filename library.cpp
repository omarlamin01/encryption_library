#include "library.h"

#include <iostream>

using namespace std;

// create main method
int main() {
    string message1 = " @#%$^&*() _+{} |:<>?~`";
    string message2 = "INWSNDF";

    cout << "Ceasar encrypt: " << ceasar_encrypt(message1, -5) << endl;
    cout << "Ceasar decrypt: " << ceasar_decrypt(ceasar_encrypt(message1, -5), -5) << endl;

    return 0;
}