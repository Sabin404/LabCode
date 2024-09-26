#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int transition(int state, char input) {
    switch (state) {
        case 0:
            if (input == '0')
                return 1;
            else
                return 0;
        case 1:
            if (input == '1')
                return 2;
            else
                return 1;
        case 2:
            if (input == '0')
                return 1;
            else
                return 0;
        default:
            return 0;
    }
}

bool isAccepted(char *str) {
    int currentState = 0, i;
    int len = strlen(str);
    for (i = 0; i < len; ++i) {
        currentState = transition(currentState, str[i]);
    }
    return (currentState == 2 && len >= 2 && str[len-1] == '1' && str[len-2] == '0');
}

int main() {
    char input[100];
    printf("Enter a string over {0, 1}: ");
    scanf("%s", input);
    if (isAccepted(input)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }
    return 0;
}

