//C program to simulate PDA for language L={a^nb^mc^n, m,n>=1 over {a,b,c}}
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char symbol) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = symbol;
}

char pop() {
    if (top == -1) {
        return '\0'; 
    }
    return stack[top--];
}

int isStackEmpty() {
    return top == -1;
}

int simulatePDA(char input[]) {
    int i;
    int len = strlen(input);

    
    for (i = 0; i < len; i++) {
        if (input[i] == 'a') {
            // Push 'a' onto the stack
            push('a');
        } else if (input[i] == 'b') {
            // Ignore 'b' (no stack operation)
            continue;
        } else if (input[i] == 'c') {
            // Pop 'a' from the stack for each 'c'
            if (pop() != 'a') {
                return 0;  // Error: more 'c's than 'a's or stack empty
            }
        } else {
            // Invalid character in the input
            return 0;
        }
    }

    if (isStackEmpty()) {
        return 1;  
    } else {
        return 0;  
    }
}

int main() {
    char input[MAX];
    printf("Enter a string over the alphabet {a, b, c}: ");
    scanf("%s", input);

    if (simulatePDA(input)) {
        printf("String is accepted by the PDA.\n");
    } else {
        printf("String is rejected by the PDA.\n");
    }

    return 0;
}
