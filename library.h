#ifndef ENCRYPTION_LIBRARY_LIBRARY_H
#define ENCRYPTION_LIBRARY_LIBRARY_H

#include <string>
#include <iostream>

std::string ceasar_encrypt(std::string message, int key) {
    std::string encrypted_message = "";
    for (int i = 0; i < message.length(); i++) {
        if (isupper(message[i])) {
            encrypted_message += char(int(message[i] + key - 65) % 26 + 65);
        } else {
            encrypted_message += char(int(message[i] + key - 97) % 26 + 97);
        }
    }
    return encrypted_message;
}



std::string affine_cipher(int key1, int key2, std::string message, int mode) {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    switch (mode) {
        case 0: {
            std::string encrypted_message = "";
            message = message;
            for (int i = 0; i < message.length(); i++) {
                int index = alphabet.find(tolower(message[i]));
                int new_index = (key1 * index + key2) % 26;
                encrypted_message += alphabet[new_index];
            }
            return encrypted_message;
        }

        case 1: {
            std::string decrypted_message = "";
            message = message;
            for (int i = 0; i < message.length(); i++) {
                int index = alphabet.find(tolower(message[i]));

                int new_index = (26 + (index - key2) * key1) % 26;
                decrypted_message += alphabet[new_index];
            }
            return decrypted_message;
        }

        default: {
            std::cout << "Invalid mode" << std::endl;
            return NULL;
        }
    }
}

std::string vigenere_cipher(std::string key, std::string message, int mode) {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    switch (mode) {
        case 0: {
            std::string encrypted_message = "";
            message = message;
            for (int i = 0; i < message.length(); i++) {
                int index = alphabet.find(tolower(message[i]));
                int key_index = alphabet.find(tolower(key[i % key.length()]));
                int new_index = (index + key_index) % 26;
                encrypted_message += alphabet[new_index];
            }
            return encrypted_message;
        }

        case 1: {
            std::string decrypted_message = "";
            message = message;
            for (int i = 0; i < message.length(); i++) {
                int index = alphabet.find(tolower(message[i]));
                int key_index = alphabet.find(tolower(key[i % key.length()]));

                int new_index = (26 + (index - key_index)) % 26;
                decrypted_message += alphabet[new_index];
            }
            return decrypted_message;
        }

        default: {
            std::cout << "Invalid mode" << std::endl;
            return NULL;
        }
    }
}

#endif //ENCRYPTION_LIBRARY_LIBRARY_H
