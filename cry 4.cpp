#include <stdio.h>
#include <ctype.h>
#include <string.h>
void vigenere_encrypt(char plaintext[], char keyword[]) {
    char ciphertext[1000];
    int i, j, keylen, plaintextlen;
    keylen = strlen(keyword);
    plaintextlen = strlen(plaintext);
    for (i = 0, j = 0; i < plaintextlen; ++i, ++j) {
        if (j == keylen)
            j = 0;
        if (isupper(plaintext[i]))
            ciphertext[i] = ((plaintext[i] - 'A' + keyword[j] - 'A') % 26) + 'A';
        else if (islower(plaintext[i]))
            ciphertext[i] = ((plaintext[i] - 'a' + keyword[j] - 'A') % 26) + 'a';
        else
            ciphertext[i] = plaintext[i];
    }
    ciphertext[i] = '\0';
    printf("Encrypted message: %s\n", ciphertext);
}
int main() {
    char plaintext[1000], keyword[100];
    printf("Enter message to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    keyword[strcspn(keyword, "\n")] = '\0';

    vigenere_encrypt(plaintext, keyword);

    return 0;
}

