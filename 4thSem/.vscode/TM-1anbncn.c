//C program to simulate Turing Machine that accepts the language L={a^nb^nc^n, n>=1 over{a,b,c}}


#include <stdio.h>
#include <string.h>

#define MAX 1000  
int simulateTuringMachine(char tape[]) {
    int i, j;
    int length = strlen(tape);

    while (1) {
        // Find the first 'a' and replace it with 'X'
        for (i = 0; i < length && tape[i] != 'a'; i++);
        if (i == length) break;  // No more 'a' left

        tape[i] = 'X';

        // Find the first 'b' after the 'X' and replace it with 'Y'
        for (j = i + 1; j < length && tape[j] != 'b'; j++);
        if (j == length) return 0;  // No 'b' found after 'a', reject

        tape[j] = 'Y';

        // Find the first 'c' after the 'Y' and replace it with 'Z'
        for (i = j + 1; i < length && tape[i] != 'c'; i++);
        if (i == length) return 0;  // No 'c' found after 'b', reject

        tape[i] = 'Z';
    }

    // After marking all 'a', 'b', and 'c', check for unmatched letters
    for (i = 0; i < length; i++) {
        if (tape[i] != 'X' && tape[i] != 'Y' && tape[i] != 'Z') {
            return 0;  // Reject if any unmarked letters are left
        }
    }

    return 1; 
}

int main() {
    char tape[MAX];
    printf("Enter a string over {a, b, c}: ");
    scanf("%s", tape);

    if (simulateTuringMachine(tape)) {
        printf("String is accepted by the TM.\n");
    } else {
        printf("String is rejected by the TM.\n");
    }

    return 0;
}

