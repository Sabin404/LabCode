//C program to simulate Turing machine to multiply two integer numbers
#include <stdio.h>
#include <string.h>
#define MAX 100
// Function to simulate Turing Machine for multiplication of two unary numbers
void turingMachineMultiplication(char *input) {
char result[MAX] = ""; // To store the final result of multiplication
int i = 0, j = 0, num1_count = 0, num2_count = 0;
// Step 1: Count the number of '1's before the '0' (this is the first number)
while (input[i] != '0' && input[i] != '\0') {
if (input[i] == '1') {
num1_count++;
}
i++;
}
// Step 2: Move past the '0' separator and count the number of '1's after it (this is the second number)
if (input[i] == '0') {
i++; // Move past the '0'
}
while (input[i] != '\0') {
if (input[i] == '1') {
num2_count++;
}
i++;
}
// Step 3: Perform multiplication by repeating the first number's '1's for the second number's count
for (i = 0; i < num2_count; i++) {
for (j = 0; j < num1_count; j++) {
strcat(result, "1"); // Append '1' for each multiplication
}
}
// Output the result of multiplication in unary form
printf("Result after multiplication in unary: %s\n", result);
}
int main() {
// Input format: two unary numbers separated by '0' (e.g., "111011" for 3 * 2)
char input[MAX];
printf("Enter the unary representation of two numbers separated by 0 (e.g., 111011 for 3 * 2): ");
scanf("%s", input);
// Call the function to simulate the Turing Machine multiplication
turingMachineMultiplication(input);
return 0;
}
