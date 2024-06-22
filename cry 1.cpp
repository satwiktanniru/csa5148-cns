#include <stdio.h>
#include <ctype.h>  
void caesar_encrypt(char message[], int key) {
    char ch;
    int i;
    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        if (isalpha(ch)) {
            if (isupper(ch)) {
                // Encrypt uppercase letters
                ch = ((ch - 'A' + key) % 26) + 'A';
            } else {
                // Encrypt lowercase letters
                ch = ((ch - 'a' + key) % 26) + 'a';
            }
        }

        message[i] = ch;
    }
}

void caesar_decrypt(char message[], int key) {
	
    caesar_encrypt(message, 26 - key);
}
int main() {
    char message[1000];
    int key, choice;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
printf("Enter key (1

