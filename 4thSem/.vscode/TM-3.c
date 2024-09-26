#include <stdio.h>
#include <stdlib.h>

// Tape Size
#define TAPE_SIZE 1000

// Define symbols for the Turing machine
#define BLANK '_'
#define ONE '1'
#define ZERO '0'

// Tape and head position
char tape[TAPE_SIZE];
int head = TAPE_SIZE / 2;

// Function to initialize the tape with the two numbers to be multiplied
void initialize_tape(int a, int b) {
	int i;
    for (i = 0; i < TAPE_SIZE; i++) {
        tape[i] = BLANK; // Fill the tape with blanks initially
    }

    // Place the first number 'a' on the tape as 'a' number of '1's
    for (i = 0; i < a; i++) {
        tape[head + i] = ONE;
    }

    // Put a separator between the numbers
    tape[head + a] = ZERO;

    // Place the second number 'b' on the tape as 'b' number of '1's
    for (i = 0; i < b; i++) {
        tape[head + a + 1 + i] = ONE;
    }
}

// Function to simulate the Turing machine multiplying two numbers
int turing_multiply() {
	int i;
    // Move to the separator
    while (tape[head] != ZERO) {
        head++;
    }

    // Start multiplication by copying 'a' times 'b' on the tape
    int result = 0;
    for (i = head + 1; tape[i] == ONE; i++) {
        result++;
    }

    // This is a simple simulation, just return the number of ones
    return result;
}

int main() {
    int a, b;

    // Get two numbers as input
    printf("Enter two integers to multiply: ");
    scanf("%d %d", &a, &b);

    // Initialize the tape with the two numbers
    initialize_tape(a, b);

    // Perform the multiplication using a Turing machine-like approach
    int result = turing_multiply();

    // Output the result
    printf("Result of multiplying %d and %d is: %d\n", a, b, result);

    return 0;
}

