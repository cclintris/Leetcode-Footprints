#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class WordFilter {
   public:
    WordFilter(vector<string>& words) {
        int v = 0;
        for (const string word : words) {
            int n = word.length();
            vector<string> prefixes(n + 1, "");
            vector<string> suffixes(n + 1, "");
            for (int i = 0; i < n; i++) {
                prefixes[i + 1] = prefixes[i] + word[i];
                suffixes[i + 1] = word[n - 1 - i] + suffixes[i];
            }
            for (const string prefix : prefixes) {
                for (const string suffix : suffixes) {
                    string k = prefix + "_" + suffix;
                    ht[k] = v;
                }
            }
            v++;
        }
    }

    int f(string prefix, string suffix) {
        string k = prefix + "_" + suffix;
        if (ht.find(k) == ht.end()) return -1;
        return ht[k];
    }

   private:
    unordered_map<string, int> ht;
};

int main(int argc, char const* argv[]) {
    return 0;
}
