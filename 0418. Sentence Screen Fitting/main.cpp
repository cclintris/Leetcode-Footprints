#include <iostream>
#include <vector>
using namespace std;

/**
 * I: sentence = ["hello","world"], rows = 2, cols = 8
 * O: 1
 * Explanation:
    hello---
    world---
    The character '-' signifies an empty space on the screen.
 *
 * I: sentence = ["a", "bcd", "e"], rows = 3, cols = 6
 * O: 2
 * Explanation:
    a-bcd-
    e-a---
    bcd-e-
    The character '-' signifies an empty space on the screen.
 *
 * I: sentence = ["i","had","apple","pie"], rows = 4, cols = 5
 * O: 1
 * Explanation:
    i-had
    apple
    pie-i
    had--
    The character '-' signifies an empty space on the screen.
 */

int wordsTyping(vector<string>& sentence, int rows, int cols);

int main(int argc, char const* argv[]) {
    vector<string> sentence{"i", "had", "apple", "pie"};
    int rows = 4;
    int cols = 5;
    cout << wordsTyping(sentence, rows, cols) << endl;
    return 0;
}

int wordsTyping(vector<string>& sentence, int rows, int cols) {
    string all = "";
    for (string word : sentence) all += (word + " ");
    int start = 0, len = all.size();
    for (int i = 0; i < rows; ++i) {
        start += cols;
        if (all[start % len] == ' ') {
            ++start;
        } else {
            while (start > 0 && all[(start - 1) % len] != ' ') {
                --start;
            }
        }
    }
    return start / len;
}