int makeBeautiful(string str) {
	int toZero = 0; // Operations to convert '1' to '0'
    int toOne = 0; // Operations to convert '0' to '1'

    // Start by assuming first character is '0'
    for (int i = 0; i < str.length(); i++) {
        char expectedChar = (i % 2 == 0) ? '0' : '1';
        if (str[i] != expectedChar) {
            toZero++;
        }
    }

    // Start by assuming first character is '1'
    for (int i = 0; i < str.length(); i++) {
        char expectedChar = (i % 2 == 0) ? '1' : '0';
        if (str[i] != expectedChar) {
            toOne++;
        }
    }

    // Return the minimum of the two counters
    return min(toZero, toOne);
}
