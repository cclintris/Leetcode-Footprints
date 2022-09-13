#include <iostream>
using namespace std;

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
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

    bool search(string word) {
        int l = word.length();
        Node* tmp = root;
        for (int i = 0; i < l; i++) {
            if (!tmp->arr[word[i] - 'a'])
                return false;
            tmp = tmp->arr[word[i] - 'a'];
        }
        if (tmp->end)
            return true;
        return false;
    }

    bool startsWith(string prefix) {
        int l = prefix.length();
        Node* tmp = root;
        for (int i = 0; i < l; i++) {
            if (!tmp->arr[prefix[i] - 'a'])
                return false;
            tmp = tmp->arr[prefix[i] - 'a'];
        }
        return true;
    }

   private:
    Node* root;
};

int main(int argc, char const* argv[]) {
    cout << 'e' - 'a' << endl;
    return 0;
}
