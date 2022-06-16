#include <iostream>
#include <vector>
using namespace std;

/**
 * I: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
 * O: [
        "This    is    an",
        "example  of text",
        "justification.  "
      ]
 *


 * I: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
 * O: [
        "What   must   be",
        "acknowledgment  ",
        "shall be        "
      ]
 *


 * I: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
 * O: [
        "Science  is  what we",
        "understand      well",
        "enough to explain to",
        "a  computer.  Art is",
        "everything  else  we",
        "do                  "
      ]
 */

vector<string> fullJustify(vector<string>& words, int maxWidth);

void printVec(vector<string>& vec);

void printVecUnitLength(vector<string>& vec);

int main(int argc, char const* argv[]) {
    int maxWidth = 16;
    int m = 6;
    string arr[] = {"What", "must", "be", "acknowledgment", "shall", "be"};
    vector<string> words(m);
    for (int i = 0; i < m; i++)
        words[i] = arr[i];

    vector<string> res = fullJustify(words, maxWidth);
    printVec(res);
    printVecUnitLength(res);
    return 0;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int c = 0;
    vector<string> ans;
    string t = "";
    for (auto i : words) {
        if (i.size() + t.size() <= maxWidth) {
            t += i;
            t += ' ';
        } else {
            t.pop_back();
            ans.push_back(t);
            t = i;
            t += ' ';
        }
    }
    if (t.size() > 1) {
        t.pop_back();
        ans.push_back(t);
    }
    for (int i = 0; i < ans.size(); i++) {
        c = ans[i].size();
        int spaces = 0;
        for (auto j : ans[i]) {
            if (j == ' ') {
                spaces++;
            }
        }
        int extra = maxWidth - c;
        c = 0;
        if (spaces == 0 || i == ans.size() - 1) {
            for (int j = 0; j < extra; j++) {
                ans[i] += ' ';
            }
            continue;
        }
        string fans = "";
        for (auto j : ans[i]) {
            if (j == ' ') {
                if (c < (extra % spaces)) {
                    fans += ' ';
                }
                for (int k = 0; k <= (extra / spaces); k++) {
                    fans += ' ';
                }
                c++;
            } else {
                fans += j;
            }
        }
        ans[i] = fans;
    }
    return ans;
}

void printVec(vector<string>& vec) {
    int len = vec.size();
    cout << "[" << endl;
    for (int i = 0; i < len; i++) {
        if (i == len - 1)
            cout << vec[i] << endl;
        else
            cout << vec[i] << ',' << endl;
    }
    cout << "]" << endl;
}

void printVecUnitLength(vector<string>& vec) {
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i].length() << " ";
}
