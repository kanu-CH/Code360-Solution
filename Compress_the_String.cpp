string getCompressedString(string &input) {
    int n = input.length();
    int j = 0; // Write pointer
    for (int i = 0; i < n; i++) {
        char currentChar = input[i];
        int count = 1;

        // Count consecutive characters
        while (i + 1 < n && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Write the character
        input[j++] = currentChar;

        // Write the count if greater than 1
        if (count > 1) {
            string countStr = to_string(count);
            for (char c : countStr) {
                input[j++] = c;
            }
        }
    }

    // Resize the string to the new compressed length
    input.resize(j);
    return input;
}
