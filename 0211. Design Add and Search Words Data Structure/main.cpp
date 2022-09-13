#include <iostream>
#include <string>
using namespace std;

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

struct Node {
    Node* arr[26];
    bool end;
};

class Trie {
   public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        int l = word.length();
        Node* tmp = root;
        for (int i = 0; i < l; i++) {
            if (!tmp->arr[word[i] - 'a']) {
                tmp->arr[word[i] - 'a'] = new Node();
            }
            tmp = tmp->arr[word[i] - 'a'];
        }
        tmp->end = true;
    }

    // .ad matches pad, bad
    // b.. matches bad
    bool search(string word) {
        return dfsSearch(root, word, 0);
    }

    bool dfsSearch(Node* root, string& word, int i) {
        if (i == word.length()) return root->end;
        if (word[i] == '.') {
            for (auto it : root->arr) {
                if (it && dfsSearch(it, word, i + 1)) return true;
            }
            return false;
        } else {
            return root->arr[word[i] - 'a'] && dfsSearch(root->arr[word[i] - 'a'], word, i + 1);
        }
        return true;
    }

   private:
    Node* root;
};

class WordDictionary {
   public:
    WordDictionary() {
        trie = new Trie();
    }

    void addWord(string word) {
        trie->insert(word);
    }

    bool search(string word) {
        return trie->search(word);
    }

   private:
    Trie* trie;
};

int main(int argc, char const* argv[]) {
    cout << '.' - 'a' << endl;  // -51
    return 0;
}
