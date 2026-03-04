#include <iostream>

using namespace std;

const int MAX_BIRDS = 1000;

/**
 * @brief True if substring is the substring at index index in text
 */
bool string_at_index(string text, string substring, int index) {
    // Catch any potential out-of-bounds errors
    if (index + substring.length() > text.length())
        return false;

    // Check character by character
    for (int i = 0; i < substring.length(); i++) {
        if (text[i + index] != substring[i])
            return false;
    }

    return true;
}

/**
 * @brief True if substring is a substring of text
 */
bool contains_substring(string text, string substring) {
    for (int i = 0; i < text.length(); i++) {
        if (string_at_index(text, substring, i))
            return true;
    }

    return false;
}

/**
 * @brief Reads in birds from standard input line-by-line until a blank line.
 *        Fills all_birds array. Returns number of birds that were read in.
 */
int read_birds(string all_birds[]) {
    string bird = "blank";
    int num_birds = 0;

    while (bird != "") {
        getline(cin, bird);
        all_birds[num_birds] = bird;
        num_birds++;
    }

    // Ignores last increment of num_birds, which was for the blank line
    return num_birds - 1;
}

/**
 * @brief Prints all words in the list words that contain target. words_length
 *        is the number of strings in words
 */
void print_words_containing_target(string words[], int words_length, string target) {
    for (int i = 0; i < words_length; i++) {
        if (contains_substring(words[i], target)) {
            cout << words[i] << endl;
        }
    }
}

int main() {
    // Create array and read to it
    string all_birds[MAX_BIRDS];
    int num_birds = read_birds(all_birds);

    // Find birds containing red and bill
    cout << "The birds containing red:" << endl;
    print_words_containing_target(all_birds, num_birds, "red");

    cout << "The birds containing bill:" << endl;
    print_words_containing_target(all_birds, num_birds, "bill");

    return 0;
}