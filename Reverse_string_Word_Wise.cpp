#include <cstring>
#include <iostream>
void reverseStringWordWise(char input[]) {
    int n = strlen(input);
    char result[n + 1]; 
    int wordStart = n - 1; 
    int resultIndex = 0;   

    for (int i = n - 1; i >= 0; i--) {
        if (input[i] == ' ' || i == 0) {
            int start = (i == 0) ? i : i + 1; 
            for (int j = start; j <= wordStart; j++) {
                result[resultIndex++] = input[j];
            }
            if (i != 0) { 
                result[resultIndex++] = ' ';
            }
            wordStart = i - 1; 
        }
    }

    result[resultIndex] = '\0';
    strcpy(input, result);
}
