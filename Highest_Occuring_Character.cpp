char highestOccurringChar(char input[]) {
    int frequency[26] = {0}; 

    // Calculate frequencies
    for (int i = 0; input[i] != '\0'; i++) {
        int index = input[i] - 'a'; 
        frequency[index]++;
    }

    // Find the character with the highest frequency
    int maxFrequency = 0;
    char result = '\0';

    for (int i = 0; input[i] != '\0'; i++) {
        int index = input[i] - 'a';
        if (frequency[index] > maxFrequency) {
            maxFrequency = frequency[index];
            result = input[i];
        }
    }

    return result;
}
