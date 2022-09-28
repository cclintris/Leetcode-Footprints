#include <iostream>
#include <vector>
using namespace std;

/**
 * I: words = ["w","wo","wor","worl","world"]
 * O: "world"
 * Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
 *
 * I: words = ["a","banana","app","appl","ap","apply","apple"]
 * O: "apple"
 * Explanation: Both "apply" and "apple" can be built from other words in the dictionary.
 * However, "apple" is lexicographically smaller than "apply".
 */

class Solution {
   private:
    struct Node {
        Node* arr[26];
        bool end = false;
    };

   public:
    Node* root = new Node();
    void insert(string& word) {
        Node* tmp = root;
        for (int i = 0; i < word.length(); i++) {
            if (!tmp->arr[word[i] - 'a']) {
                tmp->arr[word[i] - 'a'] = new Node();
            }
            tmp = tmp->arr[word[i] - 'a'];
        }
        tmp->end = true;
    }

    int dfs(string& word, Node* root, int i) {
        if (i == word.length()) return i;
        if (!root->arr[word[i] - 'a']->end) return i;
        return dfs(word, root->arr[word[i] - 'a'], i + 1);
    }

    string longestWord(vector<string>& words) {
        int n = words.size();
        for (string word : words)
            insert(word);

        string res = "";
        int max = 0;
        for (string word : words) {
            int cur = dfs(word, root, 0);
            if (cur > max) {
                max = cur;
                res = word;
            }
            if (cur == max) {
                if (word < res) res = word;
            }
        }
        return res;
    }
};

int main(int argc, char const* argv[]) {
    return 0;
}
