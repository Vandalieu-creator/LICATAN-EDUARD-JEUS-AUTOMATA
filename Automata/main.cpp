#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int state = 0;
    int i;

    printf("Enter a C-style comment: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    for (i = 0; input[i] != '\0'; i++) {

        switch (state) {
        case 0:
            if (input[i] == '/') {
                state = 1;
            }
            else {
                state = -1;
            }
            break;
        case 1:
            if (input[i] == '*') {
                state = 2;
            }
            else {
                state = -1;
            }
            break;
        case 2:
            if (input[i] == '*') {
                state = 3;
            }
            else {
                state = 2;
            }
            break;
        case 3:
            if (input[i] == '/') {
                state = 4;
            }
            else if (input[i] == '*') {
                state = 3;
            }
            else {
                state = 2;
            }
            break;


        case 4:
     
            state = -1;
            break;
        }

        if (state == -1) {
            break;
        }
    }

    if (state == 4) {
        printf("Accepted: Valid C-style comment\n");
    }
    else {
        printf("Rejected: Invalid C-style comment\n");
    }

    return 0;
}
