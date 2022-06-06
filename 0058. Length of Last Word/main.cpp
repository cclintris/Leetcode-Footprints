#include <iostream>
using namespace std;

/**
 * I: s = "Hello World"
 * O: 5
 *
 * I: s = "   fly me   to   the moon  "
 * O: 4
 *
 * I: s = "luffy is still joyboy"
 * O: 6
 */

int lengthOfLastWord(string s);

int main(int argc, char const *argv[]) {
    string s = "   fly me   to   the moon  ";
    cout << lengthOfLastWord(s) << endl;
    return 0;
}

int lengthOfLastWord(string s) {
    int len = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ' ')
            continue;
        else {
            while (s[i] != ' ') {
                i--;
                len++;
                if (i < 0)
                    return len;
            }
            return len;
        }
    }

    return len;
}
