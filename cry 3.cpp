#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 5  
void prepare_key(char key[], char matrix[SIZE][SIZE]) {
    int i, j, k;
    char *ptr, *seen = "ABCDEFGHIKLMNOPQRSTUVWXYZ";

    ptr = key;
    for (i = 0; i < strlen(key); ++i) {
        if (!strchr(seen, *ptr)) continue;
        seen[strchr(seen, *ptr++) - seen] = 0;
        matrix[i / SIZE][i % SIZE] = i + 'A';
    }
    for (j = i; j < SIZE * SIZE; ++j) {
        while (!seen[k] || (j == strlen(key) + 5 && seen[k] == 'J')) ++k;
        matrix[j / SIZE][j % SIZE] = seen[k++];
    }
}
void find_positions(char matrix[SIZE][SIZE], char ch1, char ch2, int *row1, int *col1, int *row2, int *col2) {
    int i, j;

    for (i = 0; i < SIZE; ++i)
        for (j = 0; j < SIZE; ++j) {
            if (matrix[i][j] == ch1) *row1 = i, *col1 = j;
            if (matrix[i][j] == ch2) *row2 = i, *col2 = j;
        }
}
void playfair_encrypt(char plaintext[], char matrix[SIZE][SIZE]) {
    char ciphertext[1000];
    int i, row1, col1, row2, col2;

    for (i = 0; plaintext[i] != '\0'; ++i)
        if (plaintext[i] == ' ') strcpy(plaintext + i, plaintext + i + 1);
    for (i = 0; plaintext[i] != '\0'; ++i)
        plaintext[i] = toupper(plaintext[i]);
    for (i = 0; plaintext[i + 1] != '\0'; i += 2) {
        if (plaintext[i] == plaintext[i + 1])
            strncpy(plaintext + i + 1, "X", 2);
        find_positions(matrix, plaintext[i], plaintext[i + 1], &row1, &col1, &row2, &col2);
        if (row1 == row2) plaintext[i] = matrix[row1][(col1 + 1) % SIZE],
            plaintext[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        else if (col1 == col2) plaintext[i] = matrix[(row1 + 1) % SIZE][col1],
            plaintext[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        else plaintext[i] = matrix[row1][col2], plaintext[i + 1] = matrix[row2][col1];
    }
    
    printf("Encrypted message: %s\n", plaintext);
}

int main() {
    char key[SIZE], matrix[SIZE][SIZE], plaintext[1000];

    printf("Enter the key (no J in key): ");
    fgets(key, sizeof(key), stdin);
    prepare_key(key, matrix);

    printf("Enter message to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    playfair_encrypt(plaintext, matrix);

    return 0;
}

