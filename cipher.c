#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // guard clause to validate args
    if (argc != 3) {
        fprintf(stderr, "Usage: cipher shift str");
        printf("\n");
        exit(1);
    }

    // create ciphered alphabet
    char alph[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *a = alph;

    char cipher[27];

    int n = atoi(argv[1]);
    // wrapping n around to be within 0-26
    while (n < 0) {
        n += 26;
    }
    while (n > 26) {
        n -= 26;
    }
    // when we get passed 26, this goes from the beginning
    int wrap = 0;
    for (int i = 0; i < 26; i++) {
        if (i + n < 26) {
            cipher[i] = alph[i + n];
        } else {
            cipher[i] = alph[wrap];
            wrap++;
        }
    }

    char *msg = argv[2];  // the message to encrypt
    int msg_len = strlen(msg);

    char enc[msg_len + 1];
    enc[msg_len] = '\0';

    // convert each char to upper case
    for (int i = 0; i < msg_len; i++) {
        *(msg + i) = toupper(msg[i]);
    }

    for (int m = 0; m < msg_len; m++) {
        // is m alph
        if (isalpha(msg[m])) {
            puts("state happened");
            // loop over alphabet
            for (int a = 0; a < strlen(alph); a++) {
                // if msg[i]=alph[i], then msg[i]=cipher[i]
                if (msg[m] == alph[a]) {
                    enc[m] = cipher[a];
                }
            }
        } else {
            puts("state didn't happen");
            enc[m] = msg[m];
        }
    }

    puts(enc);
    
    return 0;
}