//C program to simulate Turing machine to add two integer numbers
#include <stdio.h>
#include <string.h>

#define MAX 100 

void simulateTM(char tape[]) {
    int head = 0;  // Tape head starts at the beginning
    int length = strlen(tape);
    
    // Step 1: Move the head to the '+' symbol
    while (tape[head] != '+' && head < length) {
        head++;
    }
    
    // Step 2: Erase the '+' symbol
    tape[head] = 'B';  // Replace '+' with a blank ('B')
    
    // Step 3: Move '1's from the second number to the first number
    int readHead = head + 1; // Start reading after the erased '+'
    while (tape[readHead] != 'B' && readHead < length) {
        if (tape[readHead] == '1') {
            // Move the '1' from the second number to the first
            tape[readHead] = 'B';  // Erase the '1' in the second number
            tape[head] = '1';      // Append '1' to the first number
            head++;                // Move head to the next position
        }
        readHead++;
    }
    
    printf("Final tape (result in unary): %s\n", tape);
}

int main() {
    char tape[MAX];
    // Input format: unary number, '+', unary number
    // Example: "111+11" represents 3 + 2
    printf("Enter the tape (e.g., 111+11 for 3 + 2): ");
    scanf("%s", tape);
    simulateTM(tape);

    return 0;
}

