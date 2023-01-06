#ifndef ENCRYPTION_LIBRARY_LIBRARY_H
#define ENCRYPTION_LIBRARY_LIBRARY_H

#include <string>
#include <iostream>

int pgcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return pgcd(b, a % b);
}

unsigned modulo(int value, unsigned m) {
    int mod = value % (int) m;
    if (mod < 0) {
        mod += m;
    }
    return mod;
}

int modInverse(int A, int M)
{
    for (int X = 1; X < M; X++)
        if (((A % M) * (X % M)) % M == 1)
            return X;
    return 0;
}

std::string ceasar_encrypt(std::string message, int key) {
    std::string encrypted_message = "";
    for (int i = 0; i < message.length(); i++) {
        int index = int(message[i]);
        int new_index = modulo((index + key), 255);
        encrypted_message += char(new_index);
    }
    return encrypted_message;
}

std::string ceasar_decrypt(std::string message, int key) {
    std::string decrypted_message = "";
    for (int i = 0; i < message.length(); i++) {
        int index = int(message[i]);
        int new_index = modulo((index - key), 255);
        decrypted_message += char(new_index);
    }
    return decrypted_message;
}

bool ceasar_cipher(std::string encrypted_message, std::string decrypted_message, int key) {
    return ceasar_encrypt(decrypted_message, key) == encrypted_message;
}

std::string affine_encrypt(std::string message, int key1, int key2) {
    std::string encrypted_message = "";
    for (int i = 0; i < message.length(); i++) {
        int index = int(message[i]);
        int new_index = modulo((key1 * index + key2), 255);
        encrypted_message += char(new_index);
    }
    return encrypted_message;
}

std::string affine_decrypt(std::string message, int key1, int key2) {
    if (pgcd(key1, 255) == 1) {
        std::string decrypted_message = "";
        for (int i = 0; i < message.length(); i++) {
            int index = int(message[i]);
            int new_index = modulo((modInverse(key1, 255) * (index - key2)), 255);
            decrypted_message += char(new_index);
        }
        return decrypted_message;
    } else {
        return "Key1 is not coprime with 255";
    }
}

bool affine_cipher(std::string encrypted_message, std::string decrypted_message, int key1, int key2) {
    return affine_encrypt(decrypted_message, key1, key2) == encrypted_message;
}

std::string vigenere_encrypt(std::string message, std::string key) {
    std::string encrypted_message = "";
    for (int i = 0; i < message.length(); i++) {
        int index = int(message[i]);
        int key_index = int(key[modulo(i, key.length())]);
        int new_index = modulo((index + key_index), 255);
        encrypted_message += char(new_index);
    }
    return encrypted_message;
}

std::string vigenere_decrypt(std::string message, std::string key) {
    std::string decrypted_message = "";
    for (int i = 0; i < message.length(); i++) {
        int index = int(message[i]);
        int key_index = int(key[modulo(i, key.length())]);
        int new_index = modulo((index - key_index), 255);
        decrypted_message += char(new_index);
    }
    return decrypted_message;
}

#endif //ENCRYPTION_LIBRARY_LIBRARY_H
