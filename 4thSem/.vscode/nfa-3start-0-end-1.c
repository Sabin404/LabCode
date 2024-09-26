//start with 0 and end with 1
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// Define the states of the NFA
typedef enum {
q0, // Initial state
q1, // State after '0'
q2 // State after '01'
} State;
// Function to simulate the NFA transition
bool transition(State state, char input) {
switch (state) {
case q0:
if (input == '0')
return true; // Move to state q1
else
return false;
case q1:
if (input == '1')
return true; // Move to state q2
else if (input == '0')
return true; // Stay in state q1
else
return false;
case q2:
// Any input after reaching q2 remains in q2
return true;
default:
return false;
}

}
// Function to check if the string is accepted by the NFA
bool isAccepted(char *str) {
State currentState = q0;
int len = strlen(str);
for (int i = 0; i < len; ++i) {
if (!transition(currentState, str[i]))
return false;
if (currentState == q0 && str[i] == '0')
currentState = q1;
else if (currentState == q1 && str[i] == '1')
currentState = q2;
}
return currentState == q2;
}
int main() {
char input[100];
printf("Enter a string over {0, 1}: ");
scanf("%s", input);
if (strlen(input) < 2 || input[0] != '0' || input[strlen(input) - 1] != '1') {
printf("Rejected\n");
return 0;
}
if (isAccepted(input)) {
printf("Accepted\n");
} else {
printf("Rejected\n");
}
return 0;
}
