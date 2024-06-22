#include <stdio.h>
#include <ctype.h> 
void monoalphabetic_encrypt(char message[], char key[]) {
    char ch;
    int i;

    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if (isalpha(ch)) {
            if (isupper(ch)) {
                // Encrypt uppercase letters
                message[i] = key[ch - 'A'];
            } else {
                // Encrypt lowercase letters
                message[i] = tolower(key[ch - 'a']);
            }
        }
    }
}
void monoalphabetic_decrypt(char message[], char key[]) {
    char ch;
    int i;

    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if (isalpha(ch)) {
            if (isupper(ch)) {
            
                message[i] = 'A' + (strchr(key,ch) - key);
            } else {
        
                
                message[i] = 'a' + (strchr(key, tolower(ch)) - key);
            }
        }
    }
}

int main() {
    char message[1000];
    char key[26];  
