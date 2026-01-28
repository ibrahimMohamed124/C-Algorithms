#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

float solve_linear(char eq[]) {
    // Remove spaces
    char cleaned[100];
    int idx = 0;

    for (int i = 0; eq[i] != '\0'; i++) {
        if (eq[i] != ' ')
            cleaned[idx++] = eq[i];
    }
    cleaned[idx] = '\0';

    // Split left and right at '='
    char *left = strtok(cleaned, "=");
    char *right = strtok(NULL, "=");

    float R = atof(right); // right side

    // Detect variable character (x,y,z,...)
    char variable = 'x';
    for (int i = 0; left[i] != '\0'; i++) {
        if (isalpha(left[i])) {
            variable = left[i];
            break;
        }
    }

    // Extract a (coefficient) and b (constant)
    float a = 0, b = 0;
    int sign = 1;
    char number[100];
    int nIndex = 0;
    int mode = 0; // 0: reading a-term, 1: reading b-term

    for (int i = 0; ; i++) {
        char ch = left[i];

        if (isdigit(ch) || ch == '.') {
            number[nIndex++] = ch;
        }
        else if (ch == variable) {
            number[nIndex] = '\0';
            if (nIndex == 0)
                a += 1 * sign;  // e.g., "+x" or "-x"
            else
                a += atof(number) * sign;

            nIndex = 0;
            sign = 1;
        }
        else if (ch == '+' || ch == '-') {
            if (nIndex > 0) {
                number[nIndex] = '\0';
                b += atof(number) * sign;
                nIndex = 0;
            }
            sign = (ch == '+') ? 1 : -1;
        }
        else if (ch == '\0') {
            if (nIndex > 0) {
                number[nIndex] = '\0';
                b += atof(number) * sign;
            }
            break;
        }
    }

    // Solve ax + b = R → x = (R - b) / a
    float x = (R - b) / a;
    return x;
}

int main() {
    char eq[100];

    printf("Enter equation (example: 2x - 10 = 0):\n");
    fgets(eq, sizeof(eq), stdin);

    float x = solve_linear(eq);
    printf("Solution: x = %.2f\n", x);

    return 0;
}
