#include <stdio.h>
#include <string.h>


const char *morse_alphabet[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

const char *morse_digits[] = {
    "-----", ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----."
};


char decodeMorse(const char *morse) {
    
    for (int i = 0; i < 26; i++) {
        if (strcmp(morse, morse_alphabet[i]) == 0) {
            return 'A' + i;  
        }
    }
    // Check in digits
    for (int i = 0; i < 10; i++) {
        if (strcmp(morse, morse_digits[i]) == 0) {
            return '0' + i;  
    }
    return '?';  
}

int main() {
    char input[1024], morse_code[10];
    printf("Enter Morse Code (separate letters by spaces, words by '/'): \n");
    fgets(input, sizeof(input), stdin);

    printf("Decoded Text: ");
    
    int index = 0;
    for (int i = 0; i <= strlen(input); i++) {
        if (input[i] == ' ' || input[i] == '/' || input[i] == '\0' || input[i] == '\n') {
            if (index > 0) {
                morse_code[index] = '\0';
                printf("%c", decodeMorse(morse_code));
                index = 0;
            }
            if (input[i] == '/') {
                printf(" ");  
            }
        } else {
            morse_code[index++] = input[i];
        }
    }

    printf("\n");
    return 0;
}
